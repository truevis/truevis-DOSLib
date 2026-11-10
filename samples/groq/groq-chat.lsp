;;; groq-chat.lsp - Chat with a free LLM hosted by Groq, from AutoCAD.
;;;
;;; Requires the DOSLib module with the AI functions (DOSLib26x64.arx for
;;; AutoCAD 2027, DOSLib25x64.arx for AutoCAD 2026).
;;;
;;; Commands:
;;;   GROQCHAT  Ask a question. Prompts for your Groq API key the first time.
;;;   GROQPTS   Pick a .pts point cloud and ask the model to describe it.
;;;
;;; You need your own Groq API key (https://console.groq.com/keys).
;;; The key is kept in memory for this AutoCAD session only. It is never
;;; written to a file or to the drawing.
;;;
;;; Load with APPLOAD, or (load "path/to/groq-chat.lsp") at the command line.

(setq *groq-url*   "https://api.groq.com/openai/v1/chat/completions")
(setq *groq-model* "openai/gpt-oss-20b") ; check GET /openai/v1/models for models your key can use
(if (not *groq-key*) (setq *groq-key* nil))    ; session-only; never saved

;; Load the DOSLib module that matches this AutoCAD release.
(defun groq-load-doslib (/ acadv fname loaded)
  (setq acadv (substr (getvar "ACADVER") 1 2))
  (setq fname (strcat "DOSLib" acadv "x64.arx"))
  (setq loaded (member (strcase fname T)
                       (mapcar '(lambda (s) (strcase s T)) (dos_arxlist))))
  (cond
    (loaded T)
    ((findfile fname) (arxload fname nil) T)
    (t (princ (strcat "\n" fname " not found on the AutoCAD support path."))
       nil)))

;; Ask for the API key once per session. The input is masked.
(defun groq-get-key (/ key)
  (if *groq-key*
    *groq-key*
    (progn
      (setq key (dos_getpassword "Groq API key"
                                 "Paste your Groq API key (kept for this session only):"))
      (if (and key (/= key ""))
        (setq *groq-key* key)
        nil))))

;; Send one user message to Groq and return the reply text, or nil.
(defun groq-ask (prompt / key body resp status text)
  (setq key (groq-get-key))
  (if (null key)
    (progn (princ "\nNo API key entered.") nil)
    (progn
      (setq body
        (strcat "{\"model\":" (dos_json_string *groq-model*)
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
         ;; The error body is JSON with an "error.message" field.
         (setq text (dos_json_get (cadr resp) "error.message"))
         (princ (strcat "\nGroq returned HTTP " (itoa (car resp)) ": "
                        (if text text (cadr resp))))
         nil)
        (t
         (setq text (dos_json_get (cadr resp) "choices.0.message.content"))
         text)))))

;; GROQCHAT: ask a question and print the answer on the command line.
(defun c:groqchat (/ question answer)
  (if (groq-load-doslib)
    (progn
      (setq question (getstring T "\nAsk Groq: "))
      (if (and question (/= question ""))
        (progn
          (princ "\nWaiting for Groq...")
          (setq answer (groq-ask question))
          (if answer
            (progn
              (princ (strcat "\nGroq: " answer))
              (dos_clipboard_set answer)
              (princ "\n(Answer copied to the clipboard.)")))))))
  (princ))

;; GROQPTS: summarize a .pts point cloud with its statistics.
(defun c:groqpts (/ fname stats count mins maxs question prompt answer)
  (if (groq-load-doslib)
    (progn
      (setq fname (dos_getfiled "Select a point cloud" "C:\\"
                                "PTS files (*.pts)|*.pts|All files (*.*)|*.*||"))
      (if fname
        (progn
          (setq stats (dos_pts_stats fname))
          (if (null stats)
            (princ "\nCould not read point statistics from that file.")
            (progn
              (setq count (car stats)
                    mins  (cadr stats)
                    maxs  (caddr stats))
              (setq prompt
                (strcat "I have a point cloud with " (itoa count) " points. "
                        "Its minimum corner is ("
                        (rtos (car mins) 2 2) ", " (rtos (cadr mins) 2 2) ", "
                        (rtos (caddr mins) 2 2) ") and its maximum corner is ("
                        (rtos (car maxs) 2 2) ", " (rtos (cadr maxs) 2 2) ", "
                        (rtos (caddr maxs) 2 2) "). "
                        "In two or three sentences, describe what kind of scene this "
                        "might be and what a CAD user should check before modeling it."))
              (princ "\nAsking Groq about the point cloud...")
              (setq answer (groq-ask prompt))
              (if answer
                (progn
                  (princ (strcat "\nGroq: " answer))
                  (dos_clipboard_set answer)
                  (princ "\n(Answer copied to the clipboard.)")))))))))
  (princ))

(princ "\nGroq chat loaded. Commands: GROQCHAT, GROQPTS.")
(princ)
