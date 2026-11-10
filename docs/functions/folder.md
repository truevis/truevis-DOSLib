# DOSLib: Folder functions

[Back to index](README.md)

## dos_chdir

Changes the current directory to the specified directory. This function can change the current directory on any drive; it cannot be used to change the current drive. Use dos_drive to change the current drive.

### Syntax

```lisp
(dos_chdir path)
```

### Parameters

```lisp
path
```

A string containing a existing path.

### Returns

A string containing a qualified path to the current directory if successful.

nil on error.

### Example

```lisp
Command: (dos_chdir "\\Program Files\\AutoCAD 2006\\Sample\\")
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\Sample\\"
```

```lisp

```

```lisp
Command: (dos_chdir "..\\Support\\")
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\Support\\"
```

---

## dos_deltree

Deletes a directory and all of its subdirectories.

### Syntax

```lisp
(dos_deltree path)
```

### Parameters

```lisp
path
```

A string containing a existing path.

### Returns

A string containing the specified directory if successful.

nil on error.

### Example

```lisp
Command: (dos_deltree "C:\\Temp\\")
```

```lisp
"C:\\Temp\\"
```

---

## dos_dirattrib

Returns directory attributes, or sets directory attributes to the value described by bits.

### Syntax

```lisp
(dos_dirattrib [pathspec [bits]])
```

### Parameters

```lisp
pathspec
```

The desired directory or directories. pathspec can contain wildcard characters ("*" and "?"). If pathspec is not supplied, it is assumed to be *.*.

```lisp
bits
```

A bit-coded integer identifying the desired directory attributes to set. Specify more than one directory attribute by adding the following bit values:

0

Normal

1

Read-only

2

Hidden

4

System

8

Archive

### Returns

An association list containing the directory names and the attribute bits if successful.

nil on error.

### Example

```lisp
Command: (dos_dirattrib "C:\\Program Files\\AutoCAD 2006\\*.*")
```

```lisp
(("Data Links" . 0) ("Drv" . 0) ("en-US" . 0) ("Express" . 0) ("Fonts" . 0) ("Help" . 0) ("Plot Styles" . 0) ("Plotters" . 0) ("Sample" . 0) ("Support" . 0) ("Template" . 0) ("Textures" . 0) ("UserDataCache" . 2) ("WebDepot" . 0) ("WebServices" . 0))
```

```lisp

```

```lisp
Command: (dos_dirattrib "C:\\Program Files\\AutoCAD 2006\\Sample\\" 1)
```

```lisp
(("Sample" . 1))
```

---

## dos_dirp

Check for the existence of a directory.

### Syntax

```lisp
(dos_dirp path)
```

### Parameters

```lisp
path
```

A string containing a existing path.

### Returns

T if the directory exists.

nil if the directory does not exist, or on error.

### Example

```lisp
Command: (dos_dirp "C:\\Program Files\\AutoCAD 2006\\")
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_dirp "C:\\Program Files\\AutoCAD 2005\\")
```

```lisp
nil
```

---

## dos_dirsize

Returns the total size, the number of subdirectories, and the number
 of files in the specified directory.

### Syntax

```lisp
(dos_dirsize path [T])
```

### Parameters

```lisp
path
```

A string containing a existing path.

```lisp
T
```

Recurse into subdirectories.

### Returns

A list containing the total size in bytes, the number of subdirectories,
 and the number of files if successful. Note, the size is returned as a
 real number.

nil on error.

### Example

```lisp
Command: ( dos_dirsize
 "C:\\Program Files\\AutoCAD 2007\\")
```

```lisp
(1.78669e+008 0 533)
```

```lisp

```

```lisp
Command: (dos_dirsize "C:\\Program Files\\AutoCAD
 2007\\" T)
```

```lisp
(3.86812e+008 81 1620)
```

---

## dos_dirtree

Returns a list of directories and any subdirectories found in the specified directory.

### Syntax

```lisp
(dos_dirtree [path])
```

### Parameters

```lisp
path
```

A string containing a existing path. If not specified, the current directory is used.

### Returns

A list of subdirectories if successful.

nil on error.

### Example

```lisp
Command: (dos_dirtree "C:\\Program Files\\AutoCAD 2006\\Support\\")
```

```lisp
("C:\\Program Files\\AutoCAD 2006\\Support\\" "C:\\Program Files\\AutoCAD 2006\\Support\\Color\\")
```

```lisp

```

---

## dos_getdir

Displays a Windows "Browse for folder" dialog box. The dos_getdir
 function is also capable of creating directories.

### Syntax

```lisp
(dos_getdir [title
 [path [message
 [T]]]])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
path
```

A string identifying an existing directory. If nil is specified, the
 current directory is used.

```lisp
message
```

A string containing an optional message.

```lisp
T
```

Display a "Make New Folder" button.

### Returns

A qualified path to the directory selected by the user if successful.

nil on cancel or on error.

### Example

```lisp
Command: (dos_getdir "Browse for folder" "C:\\Program
 Files\\AutoCAD 2010\\" "Select a folder to use" T)
```

```lisp
"C:\\Program Files\\AutoCAD 2010\\Support\\"
```

---

## dos_mkdir

Creates a new directory. The dos_mkdir function creates all the directories in the specified path, beginning with the root.

### Syntax

```lisp
(dos_mkdir path)
```

### Parameters

```lisp
path
```

A string containing a existing path.

### Returns

A qualified path to the newly created directory if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_mkdir "c:\\temp\\")
```

```lisp
"c:\\temp\\"
```

```lisp

```

```lisp
Command: (dos_mkdir "c:\\temp\\autocad\\drawings\\project")
```

```lisp
"c:\\temp\\autocad\\drawings\\project"
```

```lisp

```

---

## dos_pwdir

Returns the path to the current directory for the current drive, or the specified drive.

### Syntax

```lisp
(dos_pwdir [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:).

### Returns

The path to the current directory for specified drive if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_pwdir)
```

```lisp
"c:\\temp\\"
```

```lisp

```

```lisp
Command: (dos_pwdir "D:")
```

```lisp
"d:\\projects\\drawings\\"
```

---

## dos_rendir

Renames a directory.

### Syntax

```lisp
(dos_rendir old_path new_path)
```

### Parameters

```lisp
old_path
```

A string containing a existing path.

```lisp
new_path
```

A string containing a non-existing path.

### Returns

A qualified path containing the new directory name if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_rmdir "c:\\temp\\" "c:\\mydrawings")
```

```lisp
"c:\\mydrawings"
```

---

## dos_rmdir

Removes an empty directory.

### Syntax

```lisp
(dos_rmdir path)
```

### Parameters

```lisp
path
```

A string containing a existing path. The specified directory must be empty, and it must not be either the current directory or the root directory.

### Returns

A qualified path to the removed directory if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_rmdir "c:\\temp\\)
```

```lisp
"c:\\temp\\"
```

---

## dos_specialdir

Retrieves the path of a special directory. Note, many of the items are either operating system or Windows shell specific.

### Syntax

```lisp
(dos_specialdir item)
```

### Parameters

```lisp
item
```

An integer specifying a special directory. Valid values are as follows:

0

Windows desktop

1

Internet Explorer (icon on desktop)

2

Start Menu\Programs

3

My Computer\Control Panel

4

My Computer\Printers

5

My Documents

6

 <user name>\Favorites

7

Start Menu\Programs\Startup

8

<user name>\Recent

9

<user name>\SendTo

10

<desktop>\Recycle Bin

11

<user name>\Start Menu

12

Logical "My Documents" desktop icon

13

"My Music" folder

14

"My Videos" folder

15

<user name>\Desktop

16

UNUSED

17

My Computer

18

Network Neighborhood (My Network Places)

19

<user name>\nethood

20

Windows\fonts

21

Templates

22

All Users\Start Menu

23

All Users\Start Menu\Programs

24

All Users\Startup

25

All Users\Desktop

26

<user name>\Application Data

27

<user name>\PrintHood

28

<user name>\Local Settings\Application Data (non roaming)

29

Non localized startup

30

 Non localized common startup

31

Non localized favorites

32

Internet cache

33

Internet cookies

34

 Internet history

35

All Users\Application Data

36

Windows directory

37

System directory

38

C:\Program Files

39

C:\Program Files\My Pictures

40

User profile

41

x86 system directory on RISC

42

x86 C:\Program Files on RISC

43

C:\Program Files\Common

44

x86 Program Files\Common on RISC

45

All Users\Templates

46

All Users\Documents

47

All Users\Start Menu\Programs\Administrative Tools

48

<user name>\Start Menu\Programs\Administrative Tools

49

Network and Dial-up Connections

50

UNUSED

51

UNUSED

52

UNUSED

53

All Users\My Music

54

All Users\My Pictures

55

All Users\My Pictures

56

All Users\My Pictures

57

Localized Resource Directory

58

Links to All Users OEM specific apps

59

USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning

60

UNUSED

61

Computers Near Me (computered from Workgroup membership)

### Returns

A string containing the path of the special directory if successful.

nil if not successful on error.

### Example

```lisp
Command: (dos_specialdir 0)
```

```lisp
"C:\\Documents and Settings\\dale\\Desktop\\"
```

```lisp

```

```lisp
Command: (dos_specialdir 5)
```

```lisp
"C:\\Documents and Settings\\dale\\My Documents\\"
```

---

## dos_subdir

Returns a list of subdirectories found in the specified directory. This function is the only path-related function whose return values do not contain trailing double-backslashes (\\).

### Syntax

```lisp
(dos_subdir [path [T]])
```

### Parameters

```lisp
path
```

A string containing a existing path. If not specified, the current directory is used.

```lisp
T
```

Return the current directory and parent directory markers "." and "..".  The default is not to return these markers.

### Returns

A list of subdirectories if successful.

nil on error.

### Example

```lisp
(dos_subdir)
```

```lisp
("Data Links" "Drv" "en-US" "Express" "Fonts" "Help" "Plot Styles" "Plotters" "Sample" "Support" "Template" "Textures" "UserDataCache" "WebDepot" "WebServices")
```

---

## dos_sysdir

Returns the path of the Windows system directory. The system directory contains such files as Windows libraries, drivers, and font files.

### Syntax

```lisp
(dos_sysdir)
```

### Parameters

n/a

### Returns

A string containing the path of the system directory if successful.

nil on error.

### Example

```lisp
Command: (dos_sysdir)
```

```lisp
"C:\\WINDOWS\\system32\\"
```

---

## dos_tempdir

Retrieves the path of the directory designated for temporary files.

### Syntax

```lisp
(dos_tempdir)
```

### Parameters

n/a

### Returns

A string containing the path of the temporary directory if successful.

nil on error.

### Example

```lisp
Command: (dos_tempdir)
```

```lisp
"C:\\DOCUME~1\\dale\\LOCALS~1\\Temp\\"
```

```lisp

```

```lisp
Command: (dos_longpath (dos_tempdir))
```

```lisp
"C:\\Documents and Settings\\dale\\Local Settings\\Temp\\"
```

---

## dos_windir

Retrieves the path of the Windows directory. The Windows directory contains such files as Windows-based applications, initialization files, and Help files.

### Syntax

```lisp
(dos_windir)
```

### Parameters

n/a

### Returns

A string containing the path of Windows directory if successful.

nil on error.

### Example

```lisp
Command: (dos_windir)
```

```lisp
"C:\\WINDOWS\\"
```

---


