/////////////////////////////////////////////////////////////////////////////
// func_ai.cpp
//
// Web, JSON, base64, clipboard, and point-cloud helpers for AI and
// web-service work from AutoLISP. Added in the truevis fork of DOSLib.
//
// Copyright (c) 2026 truevis. Released under the MIT License (see LICENSE).
// Based on DOSLib, Copyright (c) 1992-2026, Dale Fugier and
// Robert McNeel & Associates. DOSLib is a trademark of Robert McNeel & Associates.
//

#include "StdAfx.h"
#include "DOSLibApp.h"
#include <winhttp.h>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#pragma comment(lib, "winhttp.lib")

/////////////////////////////////////////////////////////////////////////////
// UTF-8 helpers

static std::string ToUtf8(const CString& ws)
{
  int n = WideCharToMultiByte(CP_UTF8, 0, ws, ws.GetLength(), NULL, 0, NULL, NULL);
  std::string s;
  if (n > 0)
  {
    s.resize(n);
    WideCharToMultiByte(CP_UTF8, 0, ws, ws.GetLength(), &s[0], n, NULL, NULL);
  }
  return s;
}

static CString FromUtf8(const std::string& s)
{
  CString w;
  int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
  if (n > 0)
  {
    wchar_t* buf = w.GetBuffer(n);
    MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), buf, n);
    w.ReleaseBuffer(n);
  }
  return w;
}

static void AppendUtf8(std::string& out, unsigned cp)
{
  if (cp < 0x80)
    out += (char)cp;
  else if (cp < 0x800)
  {
    out += (char)(0xC0 | (cp >> 6));
    out += (char)(0x80 | (cp & 0x3F));
  }
  else if (cp < 0x10000)
  {
    out += (char)(0xE0 | (cp >> 12));
    out += (char)(0x80 | ((cp >> 6) & 0x3F));
    out += (char)(0x80 | (cp & 0x3F));
  }
  else
  {
    out += (char)(0xF0 | (cp >> 18));
    out += (char)(0x80 | ((cp >> 12) & 0x3F));
    out += (char)(0x80 | ((cp >> 6) & 0x3F));
    out += (char)(0x80 | (cp & 0x3F));
  }
}

/////////////////////////////////////////////////////////////////////////////
// base64

static const char kB64[] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string B64Encode(const std::string& in)
{
  std::string out;
  size_t n = in.size();
  size_t i = 0;
  for (; i + 2 < n; i += 3)
  {
    unsigned v = ((unsigned char)in[i] << 16) | ((unsigned char)in[i + 1] << 8) | (unsigned char)in[i + 2];
    out += kB64[(v >> 18) & 63];
    out += kB64[(v >> 12) & 63];
    out += kB64[(v >> 6) & 63];
    out += kB64[v & 63];
  }
  if (n - i == 1)
  {
    unsigned v = (unsigned char)in[i] << 16;
    out += kB64[(v >> 18) & 63];
    out += kB64[(v >> 12) & 63];
    out += "==";
  }
  else if (n - i == 2)
  {
    unsigned v = ((unsigned char)in[i] << 16) | ((unsigned char)in[i + 1] << 8);
    out += kB64[(v >> 18) & 63];
    out += kB64[(v >> 12) & 63];
    out += kB64[(v >> 6) & 63];
    out += '=';
  }
  return out;
}

static std::string B64Decode(const std::string& in)
{
  std::string out;
  unsigned buf = 0;
  int bits = 0;
  for (size_t i = 0; i < in.size(); i++)
  {
    char c = in[i];
    int v;
    if (c >= 'A' && c <= 'Z') v = c - 'A';
    else if (c >= 'a' && c <= 'z') v = c - 'a' + 26;
    else if (c >= '0' && c <= '9') v = c - '0' + 52;
    else if (c == '+') v = 62;
    else if (c == '/') v = 63;
    else if (c == '=') break;
    else continue; // skip whitespace and anything else
    buf = ((buf << 6) | (unsigned)v) & 0xFFFFFF;
    bits += 6;
    if (bits >= 8)
    {
      bits -= 8;
      out += (char)((buf >> bits) & 0xFF);
    }
  }
  return out;
}

/////////////////////////////////////////////////////////////////////////////
// JSON: escaping and lookup

static std::string JsonEscape(const std::string& s)
{
  std::string out = "\"";
  for (size_t i = 0; i < s.size(); i++)
  {
    unsigned char c = (unsigned char)s[i];
    switch (c)
    {
    case '"':  out += "\\\""; break;
    case '\\': out += "\\\\"; break;
    case '\n': out += "\\n"; break;
    case '\r': out += "\\r"; break;
    case '\t': out += "\\t"; break;
    default:
      if (c < 0x20)
      {
        char b[8];
        sprintf_s(b, sizeof(b), "\\u%04x", c);
        out += b;
      }
      else
        out += (char)c;
    }
  }
  out += '"';
  return out;
}

static void SkipWsAt(const std::string& s, size_t& p)
{
  while (p < s.size() && isspace((unsigned char)s[p]))
    p++;
}

// p must be at an opening quote. On success p is just past the closing quote.
static bool SkipString(const std::string& s, size_t& p)
{
  if (p >= s.size() || s[p] != '"')
    return false;
  p++;
  while (p < s.size())
  {
    if (s[p] == '\\')
      p += 2;
    else if (s[p] == '"')
    {
      p++;
      return true;
    }
    else
      p++;
  }
  return false;
}

// Moves p past one complete JSON value.
static bool SkipValue(const std::string& s, size_t& p)
{
  SkipWsAt(s, p);
  if (p >= s.size())
    return false;
  char c = s[p];
  if (c == '"')
    return SkipString(s, p);
  if (c == '{' || c == '[')
  {
    bool isObj = (c == '{');
    char close = isObj ? '}' : ']';
    p++;
    while (true)
    {
      SkipWsAt(s, p);
      if (p >= s.size())
        return false;
      if (s[p] == close)
      {
        p++;
        return true;
      }
      if (s[p] == ',')
      {
        p++;
        continue;
      }
      if (isObj)
      {
        if (!SkipString(s, p))
          return false;
        SkipWsAt(s, p);
        if (p >= s.size() || s[p] != ':')
          return false;
        p++;
      }
      if (!SkipValue(s, p))
        return false;
    }
  }
  // number, true, false, or null
  while (p < s.size() && s[p] != ',' && s[p] != ']' && s[p] != '}' && !isspace((unsigned char)s[p]))
    p++;
  return true;
}

// Decodes the JSON string at p (which must be an opening quote).
static bool JsonUnescape(const std::string& s, size_t& p, std::string& out)
{
  out.clear();
  if (p >= s.size() || s[p] != '"')
    return false;
  p++;
  while (p < s.size())
  {
    char c = s[p];
    if (c == '"')
    {
      p++;
      return true;
    }
    if (c != '\\')
    {
      out += c;
      p++;
      continue;
    }
    p++;
    if (p >= s.size())
      return false;
    char e = s[p++];
    switch (e)
    {
    case '"':  out += '"'; break;
    case '\\': out += '\\'; break;
    case '/':  out += '/'; break;
    case 'b':  out += '\b'; break;
    case 'f':  out += '\f'; break;
    case 'n':  out += '\n'; break;
    case 'r':  out += '\r'; break;
    case 't':  out += '\t'; break;
    case 'u':
    {
      if (p + 4 > s.size())
        return false;
      unsigned cp = (unsigned)strtoul(s.substr(p, 4).c_str(), NULL, 16);
      p += 4;
      // UTF-16 surrogate pair
      if (cp >= 0xD800 && cp <= 0xDBFF && p + 6 <= s.size() && s[p] == '\\' && s[p + 1] == 'u')
      {
        unsigned lo = (unsigned)strtoul(s.substr(p + 2, 4).c_str(), NULL, 16);
        if (lo >= 0xDC00 && lo <= 0xDFFF)
        {
          cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
          p += 6;
        }
      }
      AppendUtf8(out, cp);
      break;
    }
    default:
      out += e;
    }
  }
  return false;
}

// Walks a dotted path such as "choices.0.message.content".
// Object keys are names; array elements are zero-based indexes.
// On success p points at the start of the value.
static bool JsonFindPath(const std::string& s, const std::string& path, size_t& p)
{
  p = 0;
  SkipWsAt(s, p);
  if (path.empty())
    return true;

  size_t start = 0;
  while (start <= path.size())
  {
    size_t dot = path.find('.', start);
    std::string seg = path.substr(start, dot == std::string::npos ? std::string::npos : dot - start);
    start = (dot == std::string::npos) ? path.size() + 1 : dot + 1;

    SkipWsAt(s, p);
    if (p >= s.size())
      return false;

    if (s[p] == '{')
    {
      p++;
      bool found = false;
      while (true)
      {
        SkipWsAt(s, p);
        if (p >= s.size() || s[p] == '}')
          return false;
        if (s[p] != '"')
          return false;
        size_t kstart = p;
        if (!SkipString(s, p))
          return false;
        std::string key = s.substr(kstart + 1, p - kstart - 2);
        SkipWsAt(s, p);
        if (p >= s.size() || s[p] != ':')
          return false;
        p++;
        SkipWsAt(s, p);
        if (key == seg)
        {
          found = true;
          break;
        }
        if (!SkipValue(s, p))
          return false;
        SkipWsAt(s, p);
        if (p >= s.size())
          return false;
        if (s[p] == ',')
        {
          p++;
          continue;
        }
        return false; // reached '}' without a match
      }
      if (!found)
        return false;
    }
    else if (s[p] == '[')
    {
      int idx = atoi(seg.c_str());
      p++;
      SkipWsAt(s, p);
      int i = 0;
      while (true)
      {
        if (p >= s.size())
          return false;
        if (i == idx)
          break;
        if (s[p] == ']')
          return false;
        if (!SkipValue(s, p))
          return false;
        SkipWsAt(s, p);
        if (p >= s.size() || s[p] != ',')
          return false;
        p++;
        SkipWsAt(s, p);
        i++;
      }
      if (s[p] == ']')
        return false;
    }
    else
      return false;

    if (dot == std::string::npos)
      break;
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////
// dos_base64_encode
int CDOSLibApp::ads_dos_base64_encode()
{
  CAdsArgs args;
  CString str;
  if (!args.GetString(str))
    return RSERR;

  acedRetStr(FromUtf8(B64Encode(ToUtf8(str))));
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_base64_decode
int CDOSLibApp::ads_dos_base64_decode()
{
  CAdsArgs args;
  CString str;
  if (!args.GetString(str))
    return RSERR;

  acedRetStr(FromUtf8(B64Decode(ToUtf8(str))));
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_json_string
// Returns a JSON string literal (with quotes and escapes) for the input text.
int CDOSLibApp::ads_dos_json_string()
{
  CAdsArgs args;
  CString str;
  if (!args.GetString(str))
    return RSERR;

  acedRetStr(FromUtf8(JsonEscape(ToUtf8(str))));
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_json_get
// (dos_json_get json path) -> string, real, T/nil, or raw JSON text for
// objects and arrays. Returns nil if the path is not found.
int CDOSLibApp::ads_dos_json_get()
{
  CAdsArgs args;
  CString jsonText, path;
  if (!args.GetString(jsonText))
    return RSERR;
  args.Next();
  if (!args.GetString(path))
    return RSERR;
  args.Next();

  std::string s = ToUtf8(jsonText);
  size_t pos = 0;
  if (!JsonFindPath(s, ToUtf8(path), pos))
  {
    acedRetNil();
    return RSRSLT;
  }
  SkipWsAt(s, pos);
  if (pos >= s.size())
  {
    acedRetNil();
    return RSRSLT;
  }

  char c = s[pos];
  if (c == '"')
  {
    std::string out;
    if (JsonUnescape(s, pos, out))
      acedRetStr(FromUtf8(out));
    else
      acedRetNil();
  }
  else if (c == '{' || c == '[')
  {
    size_t end = pos;
    if (SkipValue(s, end))
      acedRetStr(FromUtf8(s.substr(pos, end - pos)));
    else
      acedRetNil();
  }
  else if (c == 't')
    acedRetT();
  else if (c == 'f' || c == 'n')
    acedRetNil();
  else
    acedRetReal(strtod(s.c_str() + pos, NULL));

  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// HTTP helper (WinHTTP, HTTPS supported)
static bool DosHttpSend(const CString& method, const CString& url, const CStringArray& headers,
                        bool hasBody, const std::string& bodyUtf8, int& status, std::string& response)
{
  URL_COMPONENTS uc;
  memset(&uc, 0, sizeof(uc));
  uc.dwStructSize = sizeof(uc);
  uc.dwSchemeLength = (DWORD)-1;
  uc.dwHostNameLength = (DWORD)-1;
  uc.dwUrlPathLength = (DWORD)-1;
  uc.dwExtraInfoLength = (DWORD)-1;
  if (!WinHttpCrackUrl(url, (DWORD)url.GetLength(), 0, &uc))
    return false;

  std::wstring host(uc.lpszHostName, uc.dwHostNameLength);
  std::wstring path(uc.lpszUrlPath, uc.dwUrlPathLength);
  if (uc.dwExtraInfoLength > 0)
    path.append(uc.lpszExtraInfo, uc.dwExtraInfoLength);
  bool secure = (uc.nScheme == INTERNET_SCHEME_HTTPS);

  HINTERNET hSession = WinHttpOpen(L"DOSLib/AutoCAD", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                   WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
  if (!hSession)
    return false;
  WinHttpSetTimeouts(hSession, 10000, 10000, 30000, 60000);

  HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), uc.nPort, 0);
  HINTERNET hRequest = NULL;
  bool ok = false;
  if (hConnect)
  {
    hRequest = WinHttpOpenRequest(hConnect, method, path.c_str(), NULL, WINHTTP_NO_REFERER,
                                  WINHTTP_DEFAULT_ACCEPT_TYPES, secure ? WINHTTP_FLAG_SECURE : 0);
  }
  if (hRequest)
  {
    for (int i = 0; i < headers.GetSize(); i++)
      WinHttpAddRequestHeaders(hRequest, headers[i], (DWORD)-1L, WINHTTP_ADDREQ_FLAG_ADD);

    DWORD bodyLen = hasBody ? (DWORD)bodyUtf8.size() : 0;
    LPVOID bodyPtr = hasBody ? (LPVOID)bodyUtf8.data() : WINHTTP_NO_REQUEST_DATA;
    if (WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, bodyPtr, bodyLen, bodyLen, 0)
        && WinHttpReceiveResponse(hRequest, NULL))
    {
      DWORD code = 0;
      DWORD sz = sizeof(code);
      WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                          WINHTTP_HEADER_NAME_BY_INDEX, &code, &sz, WINHTTP_NO_HEADER_INDEX);
      status = (int)code;

      DWORD avail = 0;
      while (WinHttpQueryDataAvailable(hRequest, &avail) && avail > 0)
      {
        std::vector<char> buf(avail);
        DWORD got = 0;
        if (!WinHttpReadData(hRequest, buf.data(), avail, &got))
          break;
        response.append(buf.data(), got);
      }
      ok = true;
    }
  }

  if (hRequest) WinHttpCloseHandle(hRequest);
  if (hConnect) WinHttpCloseHandle(hConnect);
  WinHttpCloseHandle(hSession);
  return ok;
}

/////////////////////////////////////////////////////////////////////////////
// dos_http_request
// (dos_http_request method url headers body) -> (status body) or nil.
//   method   "GET", "POST", "PUT", "DELETE"
//   url      full URL, http:// or https://
//   headers  list of "Name: value" strings, or nil
//   body     request body string, or nil
int CDOSLibApp::ads_dos_http_request()
{
  CAdsArgs args;
  CString method, url, body;
  CStringArray headers;

  if (!args.GetString(method))
    return RSERR;
  args.Next();
  if (!args.GetString(url))
    return RSERR;
  args.Next();

  if (!args.IsNil())
  {
    if (!args.GetStringList(headers, true))
      return RSERR;
  }
  args.Next();

  bool hasBody = !args.IsNil();
  if (hasBody && !args.GetString(body))
    return RSERR;
  args.Next();

  int status = 0;
  std::string response;
  if (!DosHttpSend(method, url, headers, hasBody, ToUtf8(body), status, response))
  {
    acedRetNil();
    return RSRSLT;
  }

  CAdsRetList result;
  result.AddLB();
  result.Add((long)status);
  result.Add(FromUtf8(response), true);
  result.AddLE();
  acedRetList(result);
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_clipboard_set
int CDOSLibApp::ads_dos_clipboard_set()
{
  CAdsArgs args;
  CString text;
  if (!args.GetString(text))
    return RSERR;

  bool ok = false;
  if (OpenClipboard(NULL))
  {
    EmptyClipboard();
    size_t bytes = (text.GetLength() + 1) * sizeof(wchar_t);
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (hMem)
    {
      void* p = GlobalLock(hMem);
      if (p)
      {
        memcpy(p, (LPCWSTR)text, bytes);
        GlobalUnlock(hMem);
        if (SetClipboardData(CF_UNICODETEXT, hMem))
          ok = true;
        else
          GlobalFree(hMem);
      }
      else
        GlobalFree(hMem);
    }
    CloseClipboard();
  }

  if (ok)
    acedRetT();
  else
    acedRetNil();
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_clipboard_get
int CDOSLibApp::ads_dos_clipboard_get()
{
  CString text;
  bool ok = false;
  if (OpenClipboard(NULL))
  {
    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData)
    {
      const wchar_t* p = (const wchar_t*)GlobalLock(hData);
      if (p)
      {
        text = p;
        GlobalUnlock(hData);
        ok = true;
      }
    }
    CloseClipboard();
  }

  if (ok)
    acedRetStr(text);
  else
    acedRetNil();
  return RSRSLT;
}

/////////////////////////////////////////////////////////////////////////////
// dos_pts_stats
// (dos_pts_stats filename) -> (count (minx miny minz) (maxx maxy maxz)) or nil.
// Counts lines whose first three fields are numbers. Other lines, such as the
// ReCap point-count header, are ignored.
int CDOSLibApp::ads_dos_pts_stats()
{
  CAdsArgs args;
  CString fname;
  if (!args.GetString(fname))
    return RSERR;

  FILE* fp = _wfopen(fname, L"r");
  if (!fp)
  {
    acedRetNil();
    return RSRSLT;
  }

  long count = 0;
  double mn[3] = { 1e300, 1e300, 1e300 };
  double mx[3] = { -1e300, -1e300, -1e300 };
  char line[4096];
  while (fgets(line, sizeof(line), fp))
  {
    double v[3];
    int nums = 0;
    char* ctx = NULL;
    char* tok = strtok_s(line, " \t\r\n", &ctx);
    while (tok && nums < 3)
    {
      char* end = NULL;
      v[nums] = strtod(tok, &end);
      if (end == tok || *end != '\0')
        break;
      nums++;
      tok = strtok_s(NULL, " \t\r\n", &ctx);
    }
    if (nums < 3)
      continue;

    count++;
    for (int i = 0; i < 3; i++)
    {
      if (v[i] < mn[i]) mn[i] = v[i];
      if (v[i] > mx[i]) mx[i] = v[i];
    }
  }
  fclose(fp);

  if (count == 0)
  {
    acedRetNil();
    return RSRSLT;
  }

  CAdsRetList result;
  result.Add(count);
  result.AddLB();
  result.Add(mn[0]);
  result.Add(mn[1]);
  result.Add(mn[2]);
  result.AddLE();
  result.AddLB();
  result.Add(mx[0]);
  result.Add(mx[1]);
  result.Add(mx[2]);
  result.AddLE();
  acedRetList(result);
  return RSRSLT;
}
