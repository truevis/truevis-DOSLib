;;; openrouter-chat.lsp - Chat with models on OpenRouter from AutoCAD.
;;;
;;; Requires the DOSLib module with the AI functions (DOSLib26x64.arx for
;;; AutoCAD 2027, DOSLib25x64.arx for AutoCAD 2026).
;;;
;;; Command:
;;;   ORCHAT  Ask a question. Prompts for your OpenRouter API key the first time.
;;;
;;; You need your own OpenRouter API key (https://openrouter.ai/keys).
;;; The key is kept in memory for this AutoCAD session only. It is never
;;; written to a file or to the drawing.
;;;
;;; Load with APPLOAD, or (load "path/to/openrouter-chat.lsp") at the command line.

(setq *or-url*   "https://openrouter.ai/api/v1/chat/completions")
(setq *or-model* "google/gemma-2-9b-it:free") ; any OpenRouter model ID; ":free" variants cost nothing
(if (not *or-key*) (setq *or-key* nil))       ; session-only; never saved

;; Load the DOSLib module that matches this AutoCAD release.
(defun or-load-doslib (/ acadv fname loaded)
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
(defun or-get-key (/ key)
  (if *or-key*
    *or-key*
    (progn
      (setq key (dos_getpassword "OpenRouter API key"
                                 "Paste your OpenRouter API key (kept for this session only):"))
      (if (and key (/= key ""))
        (setq *or-key* key)
        nil))))

;; Send one user message and return the reply text, or nil.
;; OpenRouter uses the same request and response shape as the OpenAI chat API.
(defun or-ask (prompt / key body resp text)
  (setq key (or-get-key))
  (if (null key)
    (progn (princ "\nNo API key entered.") nil)
    (progn
      (setq body
        (strcat "{\"model\":" (dos_json_string *or-model*)
                ",\"messages\":[{\"role\":\"user\",\"content\":"
                (dos_json_string prompt) "}]}"))
      (setq resp
        (dos_http_request "POST" *or-url*
                          (list "Content-Type: application/json"
                                (strcat "Authorization: Bearer " key)
                                "HTTP-Referer: https://truevis.com"
                                "X-Title: AutoCAD DOSLib sample")
                          body))
      (cond
        ((null resp)
         (princ "\nNo response from OpenRouter. Check your internet connection.")
         nil)
        ((/= (car resp) 200)
         (setq text (dos_json_get (cadr resp) "error.message"))
         (princ (strcat "\nOpenRouter returned HTTP " (itoa (car resp)) ": "
                        (if text text (cadr resp))))
         nil)
        (t
         (setq text (dos_json_get (cadr resp) "choices.0.message.content"))
         text)))))

;; ORCHAT: ask a question and print the answer on the command line.
(defun c:orchat (/ question answer)
  (if (or-load-doslib)
    (progn
      (setq question (getstring T "\nAsk OpenRouter: "))
      (if (and question (/= question ""))
        (progn
          (princ "\nWaiting for OpenRouter...")
          (setq answer (or-ask question))
          (if answer
            (progn
              (princ (strcat "\nAnswer: " answer))
              (dos_clipboard_set answer)
              (princ "\n(Answer copied to the clipboard.)")))))))
  (princ))

(princ "\nOpenRouter chat loaded. Command: ORCHAT.")
(princ)
