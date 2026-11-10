# Using OpenRouter from AutoCAD with DOSLib

[OpenRouter](https://openrouter.ai) gives one API to many hosted models, including some with a free tier. This guide shows how to call it from AutoLISP using the DOSLib AI functions.

Requires the DOSLib module built from this fork (`DOSLib26x64.arx` for AutoCAD 2027, `DOSLib25x64.arx` for AutoCAD 2026).

## 1. Get an API key

Create a key at [openrouter.ai/keys](https://openrouter.ai/keys). Keep it private. Do not put it in a drawing, a `.lsp` file, or a shared repository. The sample asks for it each session.

## 2. The request

OpenRouter's chat endpoint takes the same JSON shape as the OpenAI chat API:

| Part | Value |
|---|---|
| Method | `POST` |
| URL | `https://openrouter.ai/api/v1/chat/completions` |
| Headers | `Content-Type: application/json`, `Authorization: Bearer <your key>` |
| Optional headers | `HTTP-Referer: <your site>`, `X-Title: <app name>` (used for OpenRouter rankings) |
| Body | `{"model": "...", "messages": [{"role": "user", "content": "..."}]}` |

The model is a provider-prefixed ID, such as `google/gemma-2-9b-it:free`. A `:free` suffix marks a free variant. Free models and their limits change, so check the [model list](https://openrouter.ai/models) before you rely on one.

## 3. The DOSLib calls

Build the body with `dos_json_string` so quotes and line breaks in your text are escaped. Send it with `dos_http_request`, which returns `(status body)`. Read the answer from the response with `dos_json_get`.

```lisp
(setq body
  (strcat "{\"model\":" (dos_json_string "google/gemma-2-9b-it:free")
          ",\"messages\":[{\"role\":\"user\",\"content\":"
          (dos_json_string "Name three uses for a point cloud in architecture.")
          "}]}"))

(setq resp
  (dos_http_request "POST" "https://openrouter.ai/api/v1/chat/completions"
                    (list "Content-Type: application/json"
                          (strcat "Authorization: Bearer " key))
                    body))

;; resp = (200 "{...json...}") on success
(if (= (car resp) 200)
  (princ (dos_json_get (cadr resp) "choices.0.message.content"))
  (princ (strcat "HTTP " (itoa (car resp)) ": "
                 (dos_json_get (cadr resp) "error.message"))))
```

On failure, OpenRouter returns a JSON body with an `error.message` field. The code above prints that message.

## 4. Reading the answer

- `choices.0.message.content` is the reply text.
- `dos_json_get` returns a string for string values, a real number for numbers, `T` for `true`, and `nil` for `false`, `null`, or a missing path. For objects and arrays it returns the raw JSON text.
- Paths use dots, and array positions are zero-based numbers, such as `choices.0`.

## 5. Ready-made command

[`openrouter-chat.lsp`](openrouter-chat.lsp) adds an `ORCHAT` command. It:

1. Loads the DOSLib module that matches your AutoCAD release.
2. Asks for your key once per session, with masked input (`dos_getpassword`).
3. Sends your question and prints the answer.
4. Copies the answer to the clipboard (`dos_clipboard_set`).

Load it with `APPLOAD`, then run `ORCHAT`. To try a different model, change `*or-model*` at the top of the file.

## Notes

- Keep the key out of files you share. Anyone with the key can spend your credits.
- Free models can be slow or unavailable at times. If one fails, try another model ID.
- Other providers work the same way: change the URL, the key, and the model ID. The [Groq sample](../groq/README.md) uses the same calls.
- This guide describes the calls and the sample. The sample has not been run against the live OpenRouter API yet, because it needs your key.
