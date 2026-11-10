# DOSLib: Path functions

[Back to index](README.md)

## dos_absolutepath

Creates an absolute path from one file or folder to another.

### Syntax

```lisp
(dos_absolutepath path_from path_to)
```

### Parameters

```lisp
path_from
```

A string that contains the path that defines the start of the absolute path.

```lisp
path_to
```

The relative path to convert to an absolute path.

### Returns

A string containing an absolute path or filename if successful.

nil on error.

### Example

```lisp
Command: (dos_absolutepath "C:\\Program Files\\AutoCAD 2006\\" "..\\..\\Drawings\\Xrefs\\")

"C:\\Drawings\\Xrefs"
```

---

## dos_compactpath

Truncates a path to fit within a certain number of characters by replacing path components with ellipses.

### Syntax

```lisp
(dos_compactpath path maxchars)
```

### Parameters

```lisp
path
```

A string containing a qualified path.

```lisp
maxchars
```

The maximum number of characters to be contained in the new string.

### Returns

A string containing a qualified, compact path if successful.

nil on error.

### Example

```lisp
Command: (dos_compactpath "C:\\Program Files\\AutoCAD 2006\\acad.exe" 30)

"C:\\Program Files\\...\\acad.exe"

Command: (dos_compactpath "C:\\Windows\\win.ini" 12)

"...\\win.ini"
```

---

## dos_fullpath

Converts a partial path to a fully qualified path. Unlike the dos_makepath function, this function can be used with .\\ and ..\\ in the path.

The dos_fullpath function merges the name of the current drive and directory with the specified file name to determine the full path and file name of the specified file. It also calculates the address of the file name portion of the full path and file name. This function does not verify that the resulting path and file name are valid or that they refer to an existing file on the associated volume.

### Syntax

```lisp
(dos_fullpath path)
```

### Parameters

```lisp
path
```

If the path argument specifies a drive (C:, D:, etc.), the current directory of this drive is combined with the path.

### Returns

A fully qualified path if successful.

nil on error.

### Example

```lisp
Command: (dos_fullpath "acad.exe")

"C:\\Program Files\\AutoCAD 2006\\acad.exe"

Command: (dos_fullpath "..\\..\\Windows\\win.ini")

"C:\\Windows\\win.ini"
```

---

## dos_ispathnetwork

Determines whether a path string represents a network resource.

### Syntax

```lisp
(dos_ispathnetwork path)
```

### Parameters

```lisp
path
```

A path to verify.

### Returns

T if the path is a network path.

nil if the path is not a network path, or on error.

### Example

```lisp
Command: (dos_ispathnetwork "C:\\Program Files\\AutoCAD
 2010\\")

nil

Command: (dos_ispathnetwork "Z:\\Program Files\\AutoCAD
 2010\\")

T
```

---

## dos_ispathrelative

Searches a path and determines if it is relative.

### Syntax

```lisp
(dos_ispathrelative  path)
```

### Parameters

```lisp
path
```

A path to search.

### Returns

T if the path is relative.

nil if the path is not relative, or on error.

### Example

```lisp
Command: (dos_ispathrelative "C:\\Program Files\\AutoCAD 2006\\")

nil

Command: (dos_ispathrelative "..\\..\\drawings\\xrefs\\")

T
```

---

## dos_ispathroot

Parses a path to determine if it is a directory root.

### Syntax

```lisp
(dos_ispathroot  path)
```

### Parameters

```lisp
path
```

The path to be validated.

### Returns

T if the path is a root path.

nil if the path is not a root path, or on error.

### Example

```lisp
Command: (dos_ispathroot "C:\\Program Files\\AutoCAD 2006\\")

nil

Command: (dos_ispathroot "C:\\")

T
```

---

## dos_ispathsameroot

Compares two paths to determine if they have a common root component.

### Syntax

```lisp
(dos_ispathsameroot path1 path2)
```

### Parameters

```lisp
path1
```

The first path to be compared.

```lisp
path2
```

The second path to be compared.

### Returns

T if the paths share the same root component.

nil if the path do not share the same root component, or on error.

### Example

```lisp
Command: (dos_ispathsameroot "C:\\Program Files\\AutoCAD 2006\\")

T

Command: (dos_ispathsameroot "C:\\Program Files\\AutoCAD 2006\\" "e:\\drawings\\xrefs\\")

nil
```

---

## dos_ispathslow

Determines whether a file path is a high-latency network connection.

### Syntax

```lisp
(dos_ispathslow path)
```

### Parameters

```lisp
path
```

A path to verify.

### Returns

T if the path is slow.

nil if the path is not slow, or on error.

### Example

```lisp
Command: (dos_ispathslow "C:\\Program Files\\AutoCAD
 2010\\")

nil

Command: (dos_ispathslow "Z:\\RemoteUsers\\Data\\")

T
```

---

## dos_ispathunc

Determines if the string is a valid UNC (universal naming convention) for a server and share path.

### Syntax

```lisp
(dos_ispathunc path)
```

### Parameters

```lisp
path
```

The path to be validated.

### Returns

T if the path is a UNC path.

nil if the path is not a UNC path, or on error.

### Example

```lisp
Command: (dos_ispathunc "C:\\Program Files\\AutoCAD 2006\\")

nil

Command: (dos_ispathroot "\\\\Server\\Shared Folder")

T
```

---

## dos_ispathurl

Tests a given string to determine if it conforms to a valid URL format.

### Syntax

```lisp
(dos_ispathurl path)
```

### Parameters

```lisp
path
```

The string to be validated.

### Returns

T if the path conforms to a valid URL format.

nil if the path does not conforms to a valid URL format, or on error.

### Example

```lisp
Command: (dos_ispathurl "C:\\Program Files\\AutoCAD 2006\\")

nil

Command: (dos_ispathurl "http://www.mcneel.com")

T
```

---

## dos_localpath

Returns the local path that is currently mapped to given UNC path.

### Syntax

```lisp
(dos_localpath path)
```

### Parameters

```lisp
path
```

A string containing a qualified UNC path.

### Returns

A string containing a qualified, local path if successful.

nil on error.

### Example

```lisp
Command: (setq a "z:\\drawing.dwg")

"z:\\drawing.dwg"

Command: (setq b (dos_uncpath a))

"\\\\lulu\\archive\\drawing.dwg"

Command: (dos_localpath b)

"Z:\\drawing.dwg"
```

---

## dos_longpath

Converts a short path name to a long path name.

### Syntax

```lisp
(dos_longpath path)
```

### Parameters

```lisp
path
```

A string containing a qualified, long path.

### Returns

A string containing a qualified, long path if successful.

nil on error.

### Example

```lisp
Command: (setq x (dos_shortpath "C:\\Program Files\\AutoCAD 2006\\"))

"C:\\PROGRA~1\\AUTOCA~1\\"

Command: (dos_longpath x)

"C:\\Program Files\\AutoCAD 2006\\"
```

---

## dos_makepath

Creates a single path, composed of a drive letter, directory path, file name, and file extension.

### Syntax

```lisp
(dos_makepath drive directory filename extension)
```

### Parameters

```lisp
drive
```

The letter (A, B, etc.) corresponding to the desired drive and an optional trailing colon (:). The function inserts the colon automatically in the composite path name if it is missing. If drive is an empty string (""), no drive letter and colon appear in the returned path.

```lisp
directory
```

The path of directories, not including the drive designator or the actual file name. The trailing slash is optional. Either forward slashes (/) or double-backslashes (\\) or both may be used in a single directory argument. If a trailing slash (/ or \\) is not specified, it is inserted automatically. If directory is a empty string (""), no slash is inserted in the returned path.

```lisp
filename
```

The base file name without any extensions. If filename is an empty string (""), no file name is inserted in the returned path.

```lisp
extension
```

The file name extension, with or without a leading period (.). The function inserts the period automatically if it does not appear in extension. If extension is an empty string (""), no period is inserted in the returned path.

### Returns

A fully qualified path if successful.

nil on error.

### Example

```lisp
Command: (dos_makepath "C:" "\\Program Files\\AutoCAD 2006" "acad" "exe")

"C:\\Program Files\\AutoCAD 2006\\acad.exe"

Command: (dos_makepath "C:" "\\Program Files\\AutoCAD 2006" "" "")

"C:\\Program Files\\AutoCAD 2006\\"
```

---

## dos_path

Returns a list describing the current search path for executable programs as specified by the PATH environment variable.

### Syntax

```lisp
(dos_path)
```

### Parameters

n/a

### Returns

A list containing each directory found in the PATH environment variable if successful.

nil on error.

### Example

```lisp
Command: (dos_path)

("C:\\WINDOWS\\system32" "C:\\WINDOWS" "C:\\WINDOWS\\System32\\Wbem" "C:\\Program Files\\Microsoft SDK\\Bin\\." "C:\\Program Files\\Microsoft SDK\\Bin\\WinNT\\." "C:\\Program Files\\Common Files\\Autodesk Shared\\" "C:\\Program Files\\Rational\\common" "C:\\Program Files\\Microsoft Visual Studio 8\\" "C:\\Program Files\\Microsoft Visual Studio 8\\VC\\bin")
```

---

## dos_pathbackslash

Adds or removes a backslash to the end of a path string.

### Syntax

```lisp
(dos_pathbackslash path [T])
```

### Parameters

```lisp
path
```

A path to manipulate.

```lisp
T
```

If specified, the backslash will be removed if necessary. Otherwise, a backslash will be added if necessary.

### Returns

The modified path string if successful.

nil on error.

### Example

```lisp
Command: (dos_pathbackslash "C:\\Program Files\\AutoCAD 2006")

"C:\\Program Files\\AutoCAD 2006\\"

Command: (dos_pathbackslash "C:\\Program Files\\AutoCAD 2006\\" T)

"C:\\Program Files\\AutoCAD 2006"
```

---

## dos_pathextension

Adds, replaces, or removes the file extension to the end of a path string.

### Syntax

```lisp
(dos_pathextension path [extension])
```

### Parameters

```lisp
path
```

A path to manipulate.

```lisp
extension
```

If not specified, the file extension will be removed. Otherwise, the specified file extension will replace the existing one. If a file extension does not exist, one will be added.

### Returns

The modified path string if successful.

nil on error.

### Example

```lisp
Command: (dos_pathextension "C:\\Program Files\\AutoCAD 2006\\acad.exe")

"C:\\Program Files\\AutoCAD 2006\\acad"

Command: (dos_pathextension "C:\\Program Files\\AutoCAD 2006\\acad" ".exe")

"C:\\Program Files\\AutoCAD 2006\\acad.exe"

Command: (dos_pathextension "C:\\Program Files\\AutoCAD 2006\\acad.exe" ".xyz")

"C:\\Program Files\\AutoCAD 2006\\acad.xyz"
```

---

## dos_pathquotes

Adds or removes a surrounding double-quote characters to a path string.

### Syntax

```lisp
(dos_pathquotes path [T])
```

### Parameters

```lisp
path
```

A path to manipulate.

T

If specified, the surrounding double-quotes will be removed if necessary.
 Otherwise, a the surrounding double-quotes will be added if necessary.

### Returns

The modified path string if successful.

nil on error.

### Example

```lisp
Command: (dos_pathquotes "C:\\Program Files\\AutoCAD
 2006\\")

"\"C:\\Program Files\\AutoCAD 2006\\\""

Command: (dos_pathquotes "\"C:\\Program Files\\AutoCAD
 2006\\\"" T)

"C:\\Program Files\\AutoCAD 2006\\"
```

---

## dos_relativepath

Creates a relative path from one file or folder to another. The paths do not have to be fully-qualified, but they must have a common prefix, or the function will fail and return nil.

For example, let the starting point, path_from, be "C:\\One\\Two\\Three", and the ending point, path_to, be "C:\\One\\Four\\Five". The dos_relativepath function will return the relative path from path_from to path_to as: "..\\..\\Four\\Five".  Note, you will get the same result if you set path_from to "\\One\\Two\\Three" and path_to to "\\One\\Four\\Five". On the other hand, "C:\\One\\Two\\Three" and "A:\\One\\Four\\Five" do not share a common prefix, and the function will fail.  Also note that "\\" is not considered a prefix and is ignored. If you set path_from to "\\Two\\Three", and path_to to "\\Four\\Five", the function will fail.

### Syntax

```lisp
(dos_relativepath path_from path_to)
```

### Parameters

```lisp
path_from
```

A string that contains the path that defines the start of the relative path.

```lisp
path_to
```

A string that contains the path that defines the endpoint of the relative path.

### Returns

A string containing a relative path or filename if successful.

nil on error.

### Example

```lisp
Command: (setq x (dos_relativepath "C:\\Program Files\\AutoCAD 2006" "C:\\Drawings\\Xrefs"))

"..\\..\\Drawings\\Xrefs"
```

---

## dos_shortpath

Converts a long path name to a short path name.

### Syntax

```lisp
(dos_shortpath path)
```

### Parameters

```lisp
path
```

A string containing a qualified, long path.

### Returns

A string containing a qualified, short path if successful.

nil on error.

### Example

```lisp
Command: (setq x (dos_shortpath "C:\\Program Files\\AutoCAD 2006\\"))

"C:\\PROGRA~1\\AUTOCA~1\\"

Command: (dos_longpath x)

"C:\\Program Files\\AutoCAD 2006\\"
```

---

## dos_splitpath

Breaks a full path name into its four components. The function returns a list containing the four components.

### Syntax

```lisp
(dos_splitpath path)
```

### Parameters

```lisp
path
```

A string containing a qualified path.

### Returns

A list containing the following elements:

drive

The drive letter followed by a colon (:) if a drive is specified in path.

directory

The path of subdirectories, if any, including the trailing backslashes. Forward slashes (/), double-backslashes (\\), or both may be present in path.

filename

The base file name without any extension.

extension

The file name extension, if any, including the leading period.

nil on error.

### Examples

```lisp
Command: (dos_splitpath "C:\\Program Files\\AutoCAD 2006\\acad.exe")
```

```lisp
("C:" "\\Program Files\\AutoCAD 2006\\" "acad" ".exe")
```

```lisp
Command: (dos_splitpath "C:\\Program Files\\AutoCAD 2006\\")
```

```lisp
("C:" "\\Program Files\\AutoCAD 2006\\" "" "")
```

---

## dos_uncpath

Converts a drive-based path or filename for a resource to a Universal Naming Convention (UNC) path or filename.

### Syntax

```lisp
(dos_uncpath path)
```

### Parameters

```lisp
path
```

A string containing a qualified path or filename.

### Returns

A string containing a UNC path or filename if successful.

nil on error.

### Examples

```lisp
Command: (dos_uncpath "P:\\Drawings\\")
```

```lisp
"\\\\cadserver\\projects\\drawings\\"
```

```lisp
Command: (dos_uncpath "P:\\Drawing1.dwg")
```

```lisp
"\\\\cadserver\\projects\\drawings\\drawing1.dwg"
```

---

