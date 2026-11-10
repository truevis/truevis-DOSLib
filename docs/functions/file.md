# DOSLib: File functions

[Back to index](README.md)

## dos_attrib

Returns file attributes, or sets file attributes to the value described by bits.

### Syntax

```lisp
(dos_attrib [filespec [bits]])
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is not supplied, it is assumed to be *.*.

```lisp
bits
```

A bit-coded integer identifying the desired file attributes to set. Specify more than one file attribute by adding the following bit values:

0 (bit 0)

Normal

1 (bit 1)

Read-only

2 (bit 2)

Hidden

4 (bit 3)

System

8 (bit 4)

Archive

### Returns

An association list containing the filenames and the attribute bits if successful.

nil on error.

### Example

```lisp
Command: (dos_attrib "C:\\Program Files\\AutoCAD 2006\\acad.exe")

(("acad.exe" . 8))

Command: (dos_attrib "C:\\Program Files\\AutoCAD 2006\\acad.exe" 1)

(("acad.exe" . 1))
```

---

## dos_copy

Copies a single file or multiple files. The function can be used to copy files from one directory to another, or from one drive to another.

### Syntax

```lisp
(dos_copy source destination)
```

### Parameters

```lisp
source
```

The source file or files. source can contain wildcard characters ("*" and "?").

```lisp
destination
```

The destination path or file.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_copy "C:\\Drawings\\test1.dwg" "C:\\Drawings\\test2.dwg")

T

Command: (dos_copy "C:\\Drawings\\test1.dwg" "C:\\Temp\\")

T

Command: (dos_copy "C:\\Drawings\\*.dwg" "C:\\Temp\\")

T
```

---

## dos_delete

Deletes existing files.

### Syntax

```lisp
(dos_delete filespec)
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?").

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_delete "C:\\Temp\\test1.dwg")

T

Command: (dos_delete "C:\\Temp\\*.dwg")

T
```

---

## dos_dir

Returns a list of files in a directory. The function is very similar the command prompt's DIR command.

### Syntax

```lisp
(dos_dir [filespec [format]])
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is not specified, all files (*.*) in the current directory are returned.

```lisp
format
```

The format of the filenames returned. The default value is 0. The allowable values are as follows:

0

None.

1

Sorted alphabetically, ascending.

2

Sorted alphabetically, descending.

3

Sorted by date, ascending.

4

Sorted by date, descending.

5

Sorted by size, ascending.

6

Sorted by size, descending.

### Returns

A list of filenames if successful.

nil on error.

### Example

```lisp
Command: (dos_dir)

("Blocks and Tables - Imperial.3dm" "Blocks and Tables - Imperial.bak" "Blocks and Tables - Imperial.dwg" "Blocks and Tables - Metric.3dm" "Blocks and Tables - Metric.dwg" "Blocks and Tables.dwf" "colorwh.dwg" "db_samp.3dm" "db_samp.dwg" "db_samples.mdb" "Hotel Model.dwg" "Hummer Elevation.dwg" "Lineweights.dwg" "Plot Screening and Fill Patterns.dwg" "Stadium North Elevation.dwg" "Tablet.dwg" "Taisei Detail Plan.dwg" "Taisei Door Window Sheet.dwg" "Taisei Interior Elv.dwg")

Command: (dos_dir "t*.dwg" 1)

("Tablet.dwg" "Taisei Detail Plan.dwg" "Taisei Door Window Sheet.dwg" "Taisei Interior Elv.dwg")

Command: (dos_dir "t*.dwg" 3)

("Tablet.dwg" "Taisei Detail Plan.dwg" "Taisei Door Window Sheet.dwg" "Taisei Interior Elv.dwg")

Command: (dos_dir "t*.dwg" 5)

("Taisei Door Window Sheet.dwg" "Taisei Interior Elv.dwg" "Taisei Detail Plan.dwg" "Tablet.dwg")
```

---

## dos_dos2unix

Converts a DOS-type text file to a Unix-type text file. DOS and Unix systems use different methods to identify end-of-line information in text files. DOS, including all versions of Windows, use a carriage return/linefeed pair (CR/LF), while Unix only uses the LF character.

### Syntax

```lisp
(dos_dos2unix source destination)
```

### Parameters

```lisp
source
```

The source filename.

```lisp
destination
```

The destination file name.

### Returns

A qualified path to destination if successful.

nil on error.

### Example

```lisp
Command: (dos_dos2unix "readme.dos" "readme.unix")

"C:\\temp\\readme.unix"
```

---

## dos_emptyrecycle

Empties the Windows recycle bin.

### Syntax

```lisp
(dos_emptyrecycle)
```

### Parameters

n/a

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_emptyrecycle)

T
```

---

## dos_encrypt

Encrypts or unencrypts a file with a specified password.

WARNING: Once a file has been encrypted, it cannot be unencrypted without calling this function and specifying the same password argument. Use this function carefully.

The function generates a series of "mutated" number from the password you specify using a simple (but non-reversible) one-step cellular automation process. This process is similar to the one that drives John Conway's Life, which was described in the October 1970 issue of Scientific American. These mutated numbers are then XORed through the specified file.

### Syntax

```lisp
(dos_encrypt filename password)
```

### Parameters

```lisp
filename
```

The source filename.

```lisp
password
```

An encrypt/unencrypt password

### Returns

A qualified path to the encrypted or unencrypted file if successful.

nil on error.

### Example

```lisp
Command: (dos_encrypt "C:\\Program Files\\Autocad 2006\\Sample\\colorwh.dwg" "password")

"C:\\Program Files\\Autocad 2006\\Sample\\colorwh.dwg"
```

---

## dos_file

Returns detailed information on a file.

### Syntax

```lisp
(dos_file filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

A list describing the file's details if successful. The information returned is as follows:

		Element

		Description

		0

		The filename.

		1

		The
		 file size in bytes.

		2

		The
		 file date and time in AutoCAD calendar date format.

		3

		A bit-coded integer identifying
		 the file's attributes. The bit values are as follows:

				0
				 (bit 0)

				Normal

				1
				 (bit 1)

				Read-only

				2
				 (bit 2)

				Hidden

				4
				 (bit 3)

				System

				8
				 (bit 4)

				Archive

nil on error.

### Example

```lisp
Command: (dos_file "C:\\Program Files\\AutoCAD 2007\\acad.exe")

("acad.exe" 9.48746e+006 2.00603e+007 8)
```

---

## dos_filecrc

Calculates the Cyclic Redundancy Check, or CRC, of a file. A file CRC can be useful in detecting whether or not a file has changed.

### Syntax

```lisp
(dos_filecrc filename [T])
```

### Parameters

```lisp
filename
```

The source filename.

```lisp
T
```

If specified, a 64-bit CRC is returned. Otherwise, a 32-bit CRC is returned.

### Returns

A 32- bit or 64-bit CRC, represented as a string, if successful.

nil if filename does not exist, or on error.

### Example

```lisp
Command: (dos_filecrc "C:\\Users\\Dale\\Desktop\\Drawing1.dwg")

"664C1CC4"

Command: (dos_filecrc "C:\\Users\\Dale\\Desktop\\Drawing1.dwg"
 T)

"9EDBD808460C988F"
```

---

## dos_filedate

Returns a list containing filenames and AutoCAD calendar dates. Use rtos and substr or dos_strleft to extract elements from the AutoCAD calendar date.

### Syntax

```lisp
(dos_filedate filespec)
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is not supplied, it is assumed to be *.*.

### Returns

An association list containing filenames and their corresponding dates in AutoCAD calendar date format if successful.

nil on error.

### Example

```lisp
Command: (dos_filedate "C:\\Program Files\\Autocad 2006\\Support\\*.dwg")

(("chroma.dwg" . 2.00301e+007) ("direct.dwg" . 2.00301e+007) ("overhead.dwg" . 2.00301e+007) ("rm_sdb.dwg" . 2.00301e+007) ("sh_spot.dwg" . 2.00301e+007))
```

---

## dos_fileex

Returns extended information on a file.

### Syntax

```lisp
(dos_fileex filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

A list describing the file's details if successful. The information returned is as follows:

		Element

		Description

		0

		The file
		 path.

		1

		The file
		 name including extension.

		2

		The file
		 size in bytes.

		3

		The time
		 the specified file was created.

		4

		The
		 time the file was last changed and saved.

		5

		The
		 time that the file was last accessed.

		6

		A
		 bit-coded integer identifying the file's attributes. The bit values
		 are as follows:

				0
				 (bit 0)

				Normal
				 (has no other attributes).

				1
				 (bit 1)

				Read-only

				2
				 (bit 2)

				Hidden

				4
				 (bit 3)

				System

				8
				 (bit 4)

				Archive

				16
				 (bit 5)

				Compressed

				32
				 (bit 6)

				Temporary

nil on error.

### Example

```lisp
Command: (dos_fileex "acad.exe")

("C:\\program files\\autocad 2010\\" "acad.exe" 1.57155e+007 2.00908e+007 2.00908e+007 2.00911e+007 8)
```

---

## dos_fileinfo

Returns a file's version information. This is information about a file that you see if you right-click on a file, in Windows Explorer, and pick

 Properties and then pick Details.

### Syntax

```lisp
(dos_fileinfo filename)
```

### Parameters

```lisp
filename
```

The filename of either an executable (EXE) or a dynamic link library (DLL) file.

### Returns

A list describing the file's version information if successful. Note, a developer is not required to fill in all fields. Thus, some items in

 the list may be empty strings.

The information returned is as follows:

		Element

		Description

		0

		File Version
		 (List)

		1

		Product
		 Version (List)

		2

		Comments

		3

		Company
		 Name

		4

		File Description

		5

		File Version

		6

		Internal
		 Name

		7

		Legal Copyright

		8

		Legal Trademarks

		9

		Original
		 Filename

		10

		Private
		 Build

		11

		Product
		 Name

		12

		Product
		 Version

		13

		Special
		 Build

nil on error.

### Example

```lisp
Command: (dos_fileinfo "acad.exe")

((24 0 215 0) (18 0 215 0) "" "Autodesk, Inc." "AutoCAD Application" "R18.0.215.0.0" "AutoCAD" "Copyright (c) 1982-2009 by Autodesk, Inc." "" "ACAD.EXE" "" "AutoCAD" "R18.0.215.0.0" "")
```

---

## dos_fileowner

Returns the current owner of a file. Note, the specified file must exist on an NTFS formatted drive.

### Syntax

```lisp
(dos_fileowner filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

The current owner of the file, if successful.

nil if filename does not exist, or on error.

### Example

```lisp
Command: (dos_fileowner "z:\\drawing.dwg")

"BUILTIN\\Administrators"

Command: (dos_fileowner "c:\\users\\dale\\desktop\\drawing.dwg")

"MCNEEL\\dale"
```

---

## dos_filep

Tests for the existence of a file.

### Syntax

```lisp
(dos_filep filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

T if filename exists.

nil if filename does not exist, or on error.

### Example

```lisp
Command: (dos_filep "C:\\Program Files\\Autocad 2006\\acad.exe")

T

Command: (dos_filep "C:\\Program Files\\Autocad 2006\\drawing1.dwg")

nil
```

---

## dos_filesize

Returns a list containing filenames and sizes in bytes.

### Syntax

```lisp
(dos_filesize filespec)
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is not supplied, it is assumed to be *.*.

### Returns

An association list containing filenames and their corresponding sizes in bytes if successful. Note, file sizes are returned as real numbers.

nil on error.

### Example

```lisp
Command: (dos_filesize "C:\\Program Files\\Autocad 2006\\Support\\*.dwg")

(("chroma.dwg" . 42419.0) ("direct.dwg" . 34704.0) ("overhead.dwg" . 34991.0) ("rm_sdb.dwg" . 35183.0) ("sh_spot.dwg" . 35248.0))
```

---

## dos_find

Recursively searches for instances of a file or files. The function is very similar the command prompt's DIR /S command.

### Syntax

```lisp
(dos_find [filespec [format]])
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is not specified, all files (*.*) in the current directory and in all subdirectories are returned.

```lisp
format
```

The format of the filenames returned. The default value is 0. The allowable values are as follows:

0

None.

1

Sorted alphabetically, ascending.

2

Sorted alphabetically, descending.

3

Sorted by date, ascending.

4

Sorted by date, descending.

5

Sorted by size, ascending.

6

Sorted by size, descending.

### Returns

A list of fully qualified filenames if successful.

nil on error.

### Example

```lisp
Command: (dos_find "C:\\Program Files\\Autocad 2006\\b*.dwg")

("C:\\Program Files\\Autocad 2006\\Express\\brkline.dwg" "C:\\Program Files\\Autocad 2006\\Help\\Tutorials\\createTransmittal\\Brush Roller.dwg" "C:\\Program Files\\Autocad 2006\\Help\\Tutorials\\PlaceView\\Building Elevations.dwg" "C:\\Program Files\\Autocad 2006\\Help\\Tutorials\\sheetListTable\\Base Plate.dwg" "C:\\Program Files\\Autocad 2006\\Sample\\DesignCenter\\Basic Electronics.dwg" "C:\\Program Files\\Autocad 2006\\Sample\\Sheet Sets\\Architectural\\Res\\Building Section.dwg" "C:\\Program Files\\Autocad 2006\\Sample\\Blocks and Tables - Imperial.dwg" "C:\\Program Files\\Autocad 2006\\Sample\\Blocks and Tables - Metric.dwg")
```

---

## dos_getfiled

Displays a resizing Windows common file open dialog box that allows for single file selection.

### Syntax

```lisp
(dos_getfiled title path filter)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
path
```

A string identifying an existing directory.

```lisp
filter
```

A filename filter string. The filter string consists of two components:
 a description (for example, "Text Files"), and a filter pattern (for example, "*.TXT"). Multiple filter patterns can be specified

 for a single item by separating the filter-pattern strings with a semicolon (for example, "*.TXT;*.DOC;*.BAK"). The components must be separated

 by a pipe character ("|"). The filename filter string can consist of one or more filter strings, each separated by a pipe character ("|").

 The entire string must be terminated with two pipe characters ("||").

### Returns

A qualified path to the selected file.

nil on cancel or on error.

### Example

```lisp
Command: (dos_getfiled "Select a file" "C:\\Program
 Files\\Autocad 2010\\" "Drawing files (*.dwg)|*.dwg|All files
 (*.*)|*.*||")

"C:\\Program Files\\AutoCAD 2010\\Sample\\A-01.dwg"
```

---

## dos_getfilem

Displays a resizing Windows common file open dialog box that allows for multiple file selection.

### Syntax

```lisp
(dos_getfilem title path filter)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
path
```

A string identifying an existing directory.

```lisp
filter
```

A filename filter string. The filter string consists of two components:
 a description (for example, "Text Files"), and a filter pattern (for example, "*.TXT"). Multiple filter patterns can be specified

 for a single item by separating the filter-pattern strings with a semicolon (for example, "*.TXT;*.DOC;*.BAK"). The components must be separated

 by a pipe character ("|"). The filename filter string can consist of one or more filter strings, each separated by a pipe character ("|").

 The entire string must be terminated with two pipe characters ("||").

### Returns

A list of filenames if successful. The first element of the list is a qualified path to the selected directory.

nil on cancel or on error.

### Example

```lisp
Command: (dos_getfilem "Select a file" "C:\\Program
 Files\\Autocad 2010\\" "Drawing files (*.dwg)|*.dwg|All files
 (*.*)|*.*||")

("C:\\Program Files\\AutoCAD 2010\\Sample\\" "A-01.dwg" "A-02.dwg" "A-03.dwg" "A-04.dwg" "A-05.dwg")
```

---

## dos_getfilenav

Displays an AutoCAD-style file selection dialog box.

### Syntax

```lisp
(dos_getfilenav title default ext flags)
```

### Parameters

```lisp
title
```

A string specifying the dialog box label.

```lisp
default
```

A default file name to use; can be a null string ("").

```lisp
ext
```

The default file name extension. If ext is passed as a null string (""), it defaults to * (all file types).

```lisp
flags
```

An integer value (a bit-coded field) that controls the behavior of the dialog box. To set more than one condition at a time, add the values together.

		1
		 (bit 0)

		Indicates
		 a request to create a new file.

		If
		 bit 0 is not set (open) and bit 2 is not set, only the default
		 extension (or none) is accepted.  If no extension is entered,
		 the default extension is used.  If the user enters any extension
		 other than the default, an "Invalid file name" message
		 box is displayed and the user is required to try again or cancel.
		  If bit 0 is set (create) and bit 2 is not set, the default
		 extension is added if it is not entered as part of the file name.
		  Note If an extension other than the default is entered,
		 the default extension is still appended and the file name will
		 have multiple extensions.  For example, if the user enters
		 test.dwg and the default
		 extension is .txt, then
		 the file name returned will be test.dwg.txt.
		  If the default extension is used, another copy of the extension
		 is not appended.  For example, if the default extension is
		 .txt and the user enters
		 test.txt, then test.txt is returned.  If
		 bit 0 is not set (open) and bit 2 is set, any extension (or none)
		 is accepted. If no extension is entered, the default is not used;
		 the file name is used as is. If bit 0 is set (create) and bit
		 2 is set, then any file name is accepted (with or without an extension)
		 as entered

		2
		 (bit 1)

		Not
		 used

		Bit
		 1 is unused and reserved.

		4
		 (bit 2)

		Enables
		 the user to enter an arbitrary file name extension

		Controls
		 the use of file name extensions.  If bit 2 is set, any extension
		 (or none) may be used. If bit 2 is not set, this function  accepts
		 only the extension specified in the ext argument and appends this
		 extension to the file name if the user doesn't enter it in the
		 File edit box. (See the discussion of bit 0 for information on
		 the results of various combinations of bit 0 and bit 2 settings.)

		8
		 (bit 3)

		Performs
		 a library search for the file name entered

		If
		 this bit is set and bit 0 is not set, this function performs a
		 library search for the file name entered.  If it finds the
		 file and its directory in the library search path, it strips the
		 path name and returns only the name of the file. (It doesn't strip
		 the path name if it finds a file of the same name but in a different
		 directory.)  If bit 3 is not set, this function returns the
		 entire file name, including the path name.  Set bit 3 if
		 you are using the dialog box to open an existing file whose name
		 you want to save in the drawing (or other database) and which
		 you will search for later by calling (FindFile).

		16
		 (bit 4)

		Interprets
		 the second argument to this function as a path or directory name,
		 and not a file name

		If
		 this bit is set (or if the default argument ends with a path delimiter,
		 such as "/acad/support/"), the path is interpreted as
		 a path name only, and this function assumes that there is no default
		 file name.  It displays the path in the Directory text line,
		 leaves the File edit box blank, and disables the Default button.

		32
		 (bit 5)

		Inhibits
		 display of the alert box, which warns that a file exists when
		 a new file of the same name is opened

		If
		 this bit is set and bit 0 is set (which means the file exists),
		 the alert box to warn the user that the file exists is not displayed,
		 even though the file exists.

		64
		 (bit 6)

		Do
		 not transfer remote file when user specifies a URL

		If
		 this bit is set and the user types a URL, no transfer takes place
		 and the URL is returned as is.

		128
		 (bit 7)

		Do
		 not allow URLs at all

		If
		 this bit is set and the user types a URL, an error status and
		 no filename are returned to the caller. Note This bit overrides
		 the "No transfer" bit (bit 6).

		256
		 (bit 8)

		Force
		 the initial directory to be the one specified

		If
		 this bit is set, the initial directory is forced to be the second
		 argument. If it is not set, the initial directory is retrieved
		 from the Windows registry and is the last directory browsed when
		 this dialog was last used.  If this is the first time used
		 and this bit is not set, the initial directory is the current
		 directory.

		512
		 (bit 9)

		Do
		 not enable FTP sites

		If
		 this bit is set, the FTP sites item is not present and cannot
		 be browsed.

		1024
		 (bit 10)

		Do
		 not enable shell namespace extension items

		If
		 this bit is set, no shell namespace extension items are visible
		 or can be browsed. No shell namespace extension buttons are present
		 in the places list.

		2048
		 (bit 11)

		Navigation-only
		 folders; allow selection of a folder only

		If
		 this bit is set, the dialog displays only folders and allows the
		 selection of a folder only.

		4096
		 (bit 12)

		Allow
		 multiple selection

		If
		 this bit is set, the dialog allows the selection of multiple files
		 (not honored with bit 11).

### Returns

If flag bits 11 (2048) and 12 (4096) are not specified, then the qualified path to the selected file is returned. This is similar to dos_getfiled.

If flag bit 11 (2048) is specified, then the qualified path to the selected folder is returned. This is similar to dos_getdir.

If flag bit 12 (4096) is specified, then a list of selected filenames is returned. This is similar to dos_getfilem.

 Note, the first element of the list is the qualified path to the selected folder.

nil on cancel or on error.

### Examples

```lisp
Command: (dos_getfilenav "Select Lisp Files"
 "C:\\Program Files\\AutoCAD 2007\\Support\\" "lsp"
 8)
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\Support\\3d.lsp"
```

```lisp
Command: (dos_getfilenav "Select Lisp Files"
 "C:\\Program Files\\AutoCAD 2007\\Support\\" "lsp"
 4104)
```

```lisp
("C:\\Program Files\\AutoCAD 2007\\Support\\" "3darray.lsp" "3d.lsp")
```

---

## dos_mergefiles

Merges, or combines, two or more files into a single file.

### Syntax

```lisp
(dos_mergefiles source [destination])
```

### Parameters

```lisp
source
```

A list of filenames to merge into a single file..

```lisp
destination
```

The name of the destination file to create. if omitted, the source files will be merged into the file identified by the first element of the source

 list.

### Returns

The name of the destination file if successful.

nil on error.

### Example

```lisp
Command: (setq z '("one.txt" "two.txt"
 "three.txt"))

("one.txt" "two.txt" "three.txt")

Command: (dos_mergefiles z)

"one.txt"

Command: (dos_mergefiles z "four.txt")

"four.txt"
```

---

## dos_move

Moves a single file or multiple files. The function can be used to move files from one directory to another, or from one drive to another.

### Syntax

```lisp
(dos_move source destination)
```

### Parameters

```lisp
source
```

The source file or files. source can contain wildcard characters ("*" and "?").

```lisp
destination
```

The destination path or file.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_move "C:\\Program Files\\AutoCAD 2006\\drawing1.dwg" "C:\\Temp\\")

T

Command: (dos_move "C:\\Program Files\\AutoCAD 2006\\drawing1.dwg" "C:\\Temp\\drawing1.bak")

T
```

---

## dos_openp

Returns the open status of a file. This function has use in network environments. DOSLib determines whether a file is already open by attempting to open the file for exclusive-sharing access. If a sharing violation occurs during the attempt, the file is already open and T is returned. If the attempt causes a different error, such as access denied or file not found, then DOSLib will not be able to tell whether the file is already open, and nil is returned.

### Syntax

```lisp
(dos_openp filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

T if filename is open.

nil if the file is closed, or on error.

### Example

```lisp
Command: (dos_openp "C:\\Program Files\\Autocad 2006\\Sample\\colorwh.dwg")

T
```

---

## dos_readdelimitedfile

Reads a delimited text file from disk. A delimited file is a specially formatted text file which stores spreadsheet or database-style information

 in a very simple format, with one row/record on each line, and each column/ field within that row/record separated by a delimiter character.

Each row that is read from the file is split into a specified number of columns based on the specified delimiter character. The columnar data

 is then converted to the appropriate data type, either numbers or strings, and added to a list that will eventually be returned. Empty or missing

 columns will be represented as empty elements (nil)
 in the list.

A list containing one or more lists will be returned. The number of elements in each list will correspond to the maximum number of columns

 found in the file.

ANSI, UTF-8 and Unicode encoded text files are supported.

### Syntax

```lisp
(dos_readdelimitedfile [filename [delimiter [ignore_empty [trim_spaces]]])
```

### Parameters

```lisp
filename
```

The name of an existing delimited text file to read.

```lisp
delimiter
```

The file's delimiter character. If omitted, a comma character will be used.

```lisp
ignore_empty
```

If omitted or nil, then if an empty row in the file is encountered, a nil

 element for each column will be added to the list. If T, then empty lines will be ignored.

```lisp
trim_spaces
```

If omitted or nil, then leading and trailing spaces for string elements in the will not be trimmed.  If

 T, then leading and trailing spaces will be trimmed.

### Returns

A list containing one or more lists if successful.

nil on error.

### Example

```lisp
Command: (dos_readdelimitedfile "users.csv")

(("Ted" 1 2.3 3) ("Bill" 2 5 6.7) ("Larry" 7.1 8 9))
```

---

## dos_readtextfile

Reads a text file from disk and returns the text as a list of strings.
 ANSI, UTF-8 and Unicode encoded text files are supported.

### Syntax

```lisp
(dos_readtextfile [filename [ignore_empty [trim_spaces]])
```

### Parameters

```lisp
filename
```

The name of an existing text file to read.

```lisp
ignore_empty
```

If omitted or nil, then if an empty line in the file is encountered, a nil

 element will be added to the list. If T, then empty lines will be ignored.

```lisp
trim_spaces
```

If omitted or nil, then leading and trailing spaces, for each line in the file, will not be trimmed. If

 T, then leading and trailing spaces will be trimmed.

### Returns

A list containing one or more lists if successful.

nil on error.

### Example

```lisp
Command: (dos_readtextfile "test.txt")

("The quick brown fox" "jumped over the lazy dog.")
```

---

## dos_recent

Adds to or clears the Windows recently used document list.

### Syntax

```lisp
(dos_recent [filename])
```

### Parameters

```lisp
filename
```

The source filename. If no argument is specified, the recently used document list will be cleared.

### Returns

nil if successful or on error.

### Example

```lisp
Command: (dos_recent "C:\\Program Files\\Autocad 2006\\drawing1.dwg")

nil
```

---

## dos_recycle

Sends existing files to the Windows Recycle Bin.

### Syntax

```lisp
(dos_recycle filespec)
```

### Parameters

```lisp
filespec
```

The desired file or files. filespec can contain wildcard characters ("*" and "?").

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_recycle "C:\\Temp\\test1.dwg")

T

Command: (dos_recycle "C:\\Temp\\*.dwg")

T
```

---

## dos_rename

Renames an existing file. You cannot use this function to rename multiple files. Use dos_move instead.

### Syntax

```lisp
(dos_rename old-filename new-filename)
```

### Parameters

```lisp
old-filename
```

The old filename.

```lisp
new-filename
```

The new filename. new-filename must not be the same name as an existing file.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_rename "drawing1.dwg" "drawing1.bak")

T

Command: (dos_rename "C:\\Program Files\\Autocad 2006\\drawing1.dwg" "C:\\Program Files\\Autocad 2006\\drawing1.bak")

T
```

---

## dos_search

Searches for a file in a specified path. The function searches for a matching file in the directories specified the path argument. If path is nil, the following directories are searched, in the order listed:

The directory from which the application loaded

The current directory

The Windows system directory

The Windows directory

Any directories listed by the PATH environment variable

### Syntax

```lisp
(dos_search filename [path])
```

### Parameters

```lisp
filespec
```

The source filename.

```lisp
path
```

A formatted path to search (e.g. "C:\Windows;C:\Windows\System;...").

### Returns

A qualified path to filename if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_search "kernel32.dll")

"C:\\WINNT\\System32\\kernel32.dll"

Command: (dos_search "3d.lsp" (getvar "acadprefix"))

"C:\\Program Files\\AutoCAD 2006\\support\\3d.lsp"
```

---

## dos_tempfile

Creates a name for a temporary file. The file name is the concatenation of specified path the prefix string "~ac", a hexadecimal string formed from a specified integer, and the .tmp extension.

### Syntax

```lisp
(dos_tempfile)
```

### Parameters

n/a

### Returns

A string containing the path of a temporary file if successful.

nil on error.

### Example

```lisp
Command: (dos_tempfile)

"C:\\Documents and Settings\\dale\\Local Settings\\Temp\\~acA04B.tmp"

Command: (dos_tempfile)

"C:\\Documents and Settings\\dale\\Local Settings\\Temp\\~acA3BC.tmp"

Command: (dos_tempfile)

"C:\\Documents and Settings\\dale\\Local Settings\\Temp\\~acA679.tmp"
```

---

## dos_touch

Sets the date and time at which files were last written to the current date and time or, optionally, a specified date.

### Syntax

```lisp
(dos_touch filespec [date [time]])
```

### Parameters

```lisp
filename
```

The desired file or files. filespec can contain wildcard characters ("*" and "?"). If filespec is supplied, it is assumed to be *.*.

```lisp
date
```

A list of numbers specifying the new year, month, and day. For details, see dos_date. If omitted, the current date is used.

```lisp
time
```

A list of numbers specifying the new hour and minutes in 24-hour format. Optionally, the seconds and milliseconds can be specified. For details, see dos_time. If omitted, the current time is used.

### Returns

A list of file that were modified if successful.

nil on error.

### Example

```lisp
Command: (dos_touch "C:\\Program Files\\Autocad 2006\\*.dwg")

("Drawing2.dwg" "Drawing1.dwg")
```

---

## dos_unix2dos

Converts a Unix-type text file to a DOS-type text file. DOS and Unix systems use different methods to identify end-of-line information in text files. DOS, including all versions of Windows, use a carriage return/linefeed pair (CR/LF), while Unix only uses the LF character.

### Syntax

```lisp
(dos_unix2dos source destination)
```

### Parameters

```lisp
source
```

The source filename.

```lisp
destination
```

The destination file name.

### Returns

A qualified path to destination if successful.

nil on error.

### Example

```lisp
Command: (dos_unix2dos "readme.unix" "readme.dos")

"C:\\temp\\readme.dos"
```

---

## dos_writetextfile

Writes a list of strings to a text file. ANSI, UTF-8 and Unicode encoded text files are supported.

### Syntax

```lisp
(dos_writetextfile [filename strings [append [encoding]])
```

### Parameters

```lisp
filename
```

The name of the text file to write

```lisp
strings
```

The array of strings to write.

```lisp
append
```

If omitted or nil, the file will be overwritten if it already exists. If T,

 then the will be appended to if it already exists.

```lisp
encoding
```

The text file encoding, where: 0 = ANSI Encoding (default), 1 = UTF-8 Encoding, and 2 = Unicode Encoding.

### Returns

The number of lines written to the text file if successful.

nil on error.

### Example

```lisp
Command: (setq strings (list "The quick brown fox"
 "jumped over the lazy dog."))

("The quick brown fox" "jumped over the lazy dog.")

Command: (dos_writetextfile "test.txt" strings)

2
```

---

