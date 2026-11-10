#!/usr/bin/env python3
"""Clean CHM-derived Markdown in docs/functions (empty fences, example blocks)."""

from __future__ import annotations

import html
import re
from pathlib import Path

DOCS_DIR = Path(__file__).resolve().parents[1] / "docs" / "functions"


def join_soft_wrapped_prose(text: str) -> str:
    """Join lines where the next line is an indented continuation."""

    lines = text.splitlines(keepends=True)
    out: list[str] = []
    i = 0
    in_fence = False

    while i < len(lines):
        line = lines[i]
        if line.startswith("```"):
            in_fence = not in_fence
            out.append(line)
            i += 1
            continue
        if in_fence:
            out.append(line)
            i += 1
            continue
        if i + 1 < len(lines) and re.match(r"^ +\S", lines[i + 1]):
            cur = line.rstrip("\n\r")
            if cur and not cur.endswith((".", ":", ")", "]", ">", "`")):
                merged = cur + " " + lines[i + 1].lstrip()
                out.append(merged + "\n")
                i += 2
                continue
        out.append(line)
        i += 1

    return "".join(out)


def normalize_lisp_block(body: str) -> str:
    stripped = body.strip()
    if not stripped:
        return ""
    if stripped.startswith("(") and "\n" in stripped and not stripped.startswith("Command:"):
        return " ".join(stripped.split())
    return stripped


def merge_example_section(body: str) -> str:
    blocks = re.findall(r"```lisp\n(.*?)```", body, flags=re.DOTALL)
    if not blocks:
        return body
    parts = [normalize_lisp_block(b) for b in blocks]
    parts = [p for p in parts if p]
    if not parts:
        return ""
    return "```lisp\n" + "\n\n".join(parts) + "\n```\n\n"


def remove_duplicate_heading(text: str, heading: str) -> str:
    pattern = rf"(### {re.escape(heading)}\n\n)### {re.escape(heading)}\n\n"
    while re.search(pattern, text):
        text = re.sub(pattern, r"\1", text)
    return text


def clean_markdown(text: str) -> str:
    text = html.unescape(text)
    text = re.sub(
        r"- Functions return \s*\n\s*il on error",
        "- Functions return nil on error",
        text,
    )
    text = remove_duplicate_heading(text, "Returns")

    def repl_example(match: re.Match[str]) -> str:
        merged = merge_example_section(match.group(1))
        return "### Example\n\n" + merged

    text = re.sub(
        r"### Example\n\n(.*?)(?=\n---\n|\n## |\Z)",
        repl_example,
        text,
        flags=re.DOTALL,
    )

    # Drop any remaining empty lisp fences (e.g. outside Example)
    def repl_fence(match: re.Match[str]) -> str:
        body = match.group(1)
        if not body.strip():
            return ""
        normalized = normalize_lisp_block(body)
        if not normalized:
            return ""
        return f"```lisp\n{normalized}\n```"

    text = re.sub(r"```lisp\n(.*?)```", repl_fence, text, flags=re.DOTALL)
    text = join_soft_wrapped_prose(text)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text


def main() -> None:
    for path in sorted(DOCS_DIR.glob("*.md")):
        original = path.read_text(encoding="utf-8")
        cleaned = clean_markdown(original)
        if cleaned != original:
            path.write_text(cleaned, encoding="utf-8", newline="\n")
            print(f"updated {path.name}")


if __name__ == "__main__":
    main()
