;;; groq-text.lsp - Spell-check or translate TEXT and MTEXT with Groq.
;;;
;;; Requires the DOSLib module with the AI functions (DOSLib26x64.arx for
;;; AutoCAD 2027, DOSLib25x64.arx for AutoCAD 2026).
;;;
;;; Command:
;;;   GROQTEXT  Select TEXT and MTEXT. Spell-check them, or translate them
;;;             into a language you name. Uses openai/gpt-oss-120b on Groq.
;;;
;;; You need your own Groq API key (https://console.groq.com/keys).
;;; The key is kept in memory for this AutoCAD session only. It is never
;;; written to a file or to the drawing. If groq-chat.lsp is already loaded,
;;; this command reuses the key you entered there.
;;;
;;; Replacing the text writes plain characters back. MTEXT font, color, and
;;; stacked-fraction formatting in the original is not kept.
;;;
;;; Load with APPLOAD, or (load "path/to/groq-text.lsp") at the command line.

(vl-load-com)

(setq *groq-url*      "https://api.groq.com/openai/v1/chat/completions")
(setq *groqtxt-model* "openai/gpt-oss-120b")
(if (not *groq-key*) (setq *groq-key* nil)) ; session-only; never saved

;; True when this session has the AI helpers from this fork.
(defun groqtxt-ai-ready ()
  (car (atoms-family 1 '("DOS_JSON_STRING"))))

;; Load a DOSLib build that defines dos_json_string.
;; An older DOSLib already on the support path defines the classic
;; functions and hides a newer file of the same name, so unload it
;; and load the AI build (DOSLibAI) or the Release output of this repo.
(defun groqtxt-load-doslib (/ acadv fname ai bin loaded)
  (if (groqtxt-ai-ready)
    T
    (progn
      (setq acadv (substr (getvar "ACADVER") 1 2))
      (setq fname (strcat "DOSLib" acadv "x64.arx"))
      (setq ai (strcat "DOSLibAI" acadv "x64.arx"))
      (setq bin (strcat "C:/GitHub/truevis-DOSLib/bin/Release/arx/" fname))
      (if (member (strcase fname) (mapcar 'strcase (arx)))
        (arxunload fname))
      (cond
        ((findfile ai) (setq loaded (arxload (findfile ai) nil)))
        ((findfile bin) (setq loaded (arxload bin nil)))
        ((findfile fname) (setq loaded (arxload (findfile fname) nil)))
        (t (setq loaded nil)))
      (cond
        ((groqtxt-ai-ready) T)
        (t (princ "\nLoaded DOSLib has no dos_json_string. Build this fork and load DOSLibAI or bin/Release/arx.")
           nil)))))

;; Ask for the API key once per session. The input is masked.
(defun groqtxt-get-key (/ key)
  (if *groq-key*
    *groq-key*
    (progn
      (setq key (dos_getpassword "Groq API key"
                                 "Paste your Groq API key (kept for this session only):"))
      (if (and key (/= key ""))
        (setq *groq-key* key)
        nil))))

;; Send one user message to Groq and return the reply text, or nil.
(defun groqtxt-ask (prompt / key body resp status text)
  (setq key (groqtxt-get-key))
  (if (null key)
    (progn (princ "\nNo API key entered.") nil)
    (progn
      (setq body
        (strcat "{\"model\":" (dos_json_string *groqtxt-model*)
                ",\"messages\":[{\"role\":\"user\",\"content\":"
                (dos_json_string prompt) "}]}"))
      (setq resp
        (dos_http_request "POST" *groq-url*
                          (list "Content-Type: application/json"
                                (strcat "Authorization: Bearer " key))
                          body))
      (cond
        ((null resp)
         (princ "\nNo response from Groq. Check your internet connection.")
         nil)
        ((/= (car resp) 200)
         (setq text (dos_json_get (cadr resp) "error.message"))
         (princ (strcat "\nGroq returned HTTP " (itoa (car resp)) ": "
                        (if text text (cadr resp))))
         nil)
        (t
         (setq text (dos_json_get (cadr resp) "choices.0.message.content"))
         (groqtxt-unwrap text))))))

;; Drop one pair of wrapping quotes or a trailing blank line the model added.
(defun groqtxt-unwrap (s / n)
  (if (null s)
    nil
    (progn
      (setq n (strlen s))
      (if (and (>= n 2)
               (= (substr s 1 1) "\"")
               (= (substr s n 1) "\""))
        (setq s (substr s 2 (- n 2))))
      s)))

;; Plain text from a TEXT or MTEXT entity. MTEXT codes are stripped.
(defun groqtxt-read (en / ed typ chunks)
  (setq ed (entget en)
        typ (cdr (assoc 0 ed)))
  (cond
    ((= typ "MTEXT")
     (setq chunks "")
     (foreach pair ed
       (if (or (= (car pair) 3) (= (car pair) 1))
         (setq chunks (strcat chunks (cdr pair)))))
     (groqtxt-unformat chunks))
    (t (cdr (assoc 1 ed)))))

;; Turn MTEXT control codes into plain characters.
(defun groqtxt-unformat (s / i n ch nxt out)
  (setq i 1 n (strlen s) out "")
  (while (<= i n)
    (setq ch (substr s i 1))
    (cond
      ((or (= ch "{") (= ch "}"))
       (setq i (1+ i)))
      ((= ch "\\")
       (setq nxt (if (< i n) (substr s (1+ i) 1) ""))
       (cond
         ((or (= nxt "P") (= nxt "p"))
          (setq out (strcat out "\n") i (+ i 2)))
         ((= nxt "~")
          (setq out (strcat out " ") i (+ i 2)))
         ((or (= nxt "\\") (= nxt "{") (= nxt "}"))
          (setq out (strcat out nxt) i (+ i 2)))
         ((or (= nxt "L") (= nxt "l") (= nxt "O") (= nxt "o")
              (= nxt "K") (= nxt "k"))
          (setq i (+ i 2)))
         (t
          (setq i (+ i 2))
          (while (and (<= i n) (/= (substr s i 1) ";"))
            (setq i (1+ i)))
          (if (<= i n) (setq i (1+ i))))))
      (t (setq out (strcat out ch) i (1+ i)))))
  out)

;; Escape a plain string so it can be stored as MTEXT.
(defun groqtxt-to-mtext (s / i n ch out)
  (setq i 1 n (strlen s) out "")
  (while (<= i n)
    (setq ch (substr s i 1))
    (cond
      ((= ch "\\") (setq out (strcat out "\\\\")))
      ((= ch "{")  (setq out (strcat out "\\{")))
      ((= ch "}")  (setq out (strcat out "\\}")))
      ((= ch "\n") (setq out (strcat out "\\P")))
      (t           (setq out (strcat out ch))))
    (setq i (1+ i)))
  out)

;; TEXT entities are a single line.
(defun groqtxt-oneline (s / i n ch out)
  (setq i 1 n (strlen s) out "")
  (while (<= i n)
    (setq ch (substr s i 1))
    (setq out (strcat out (if (= ch "\n") " " ch)))
    (setq i (1+ i)))
  out)

;; Write the new string back onto the entity.
(defun groqtxt-put (en s / ed typ)
  (setq ed (entget en)
        typ (cdr (assoc 0 ed)))
  (cond
    ((= typ "MTEXT")
     (vla-put-TextString (vlax-ename->vla-object en) (groqtxt-to-mtext s))
     T)
    ((> (strlen (groqtxt-oneline s)) 250)
     (princ "\nThat result is longer than a TEXT entity can hold. It was not written back.")
     nil)
    (t
     (setq s (groqtxt-oneline s))
     (entmod (subst (cons 1 s) (assoc 1 ed) ed))
     (entupd en)
     T)))

(defun groqtxt-prompt (mode lang source)
  (if (= mode "Translate")
    (strcat "Translate the text below into " lang ". "
            "Return only the translation. Keep line breaks. "
            "Do not add notes, quotes, or a language label.\n\n"
            source)
    (strcat "Correct the spelling and grammar of the text below. "
            "Keep the original language and meaning. Keep line breaks. "
            "Return only the corrected text, with no notes and no quotes.\n\n"
            source)))

;; GROQTEXT: spell-check or translate selected TEXT and MTEXT.
(defun c:groqtext (/ ss mode lang replace i n en source answer wrote clip)
  (if (groqtxt-load-doslib)
    (progn
      (princ "\nSelect TEXT and MTEXT to spell-check or translate.")
      (setq ss (ssget '((0 . "TEXT,MTEXT"))))
      (if ss
        (progn
          (initget "Spellcheck Translate")
          (setq mode (getkword "\nSpell-check or translate [Spellcheck/Translate] <Spellcheck>: "))
          (if (null mode) (setq mode "Spellcheck"))
          (setq lang nil)
          (if (= mode "Translate")
            (progn
              (setq lang (getstring T "\nTranslate into: "))
              (if (= lang "") (setq lang nil))))
          (if (and (= mode "Translate") (null lang))
            (princ "\nNo language entered.")
            (progn
              (initget "Yes No")
              (setq replace (getkword "\nReplace the selected text with the result? [Yes/No] <Yes>: "))
              (if (null replace) (setq replace "Yes"))
              (setq i 0 n (sslength ss) clip "")
              (repeat n
                (setq en (ssname ss i)
                      i (1+ i)
                      source (groqtxt-read en))
                (if (or (null source) (= source ""))
                  (princ (strcat "\n" (itoa i) " of " (itoa n) ": empty, skipped."))
                  (progn
                    (princ (strcat "\n" (itoa i) " of " (itoa n) ": waiting for Groq..."))
                    (setq answer (groqtxt-ask (groqtxt-prompt mode lang source)))
                    (if answer
                      (progn
                        (princ (strcat "\n---\n" answer))
                        (setq clip (if (= clip "") answer (strcat clip "\n" answer)))
                        (if (= replace "Yes")
                          (progn
                            (setq wrote (groqtxt-put en answer))
                            (if wrote (princ "\n(Text updated.)")))))))))
              (if (/= clip "")
                (progn
                  (dos_clipboard_set clip)
                  (princ "\n(Results copied to the clipboard.)")))))))))
  (princ))

(princ "\nGroq text tools loaded. Command: GROQTEXT (model openai/gpt-oss-120b).")
(princ)
