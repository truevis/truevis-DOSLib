# DOSLib: Drive functions

[Back to index](README.md)

## dos_chkdsk

Returns drive space statistics for the current drive or for the specified drive. Use the rtos function to convert the return values to strings if necessary.

### Syntax

```lisp
(dos_chkdsk [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

### Returns

A list of three real numbers indicating the total disk space, used disk space, and free disk space in bytes if successful.

nil on error.

### Example

```lisp
Command: (dos_chkdsk)

(1.94292e+010 1.23667e+010 7.06254e+009)

Command: (rtos (cadr (dos_chkdsk)) 2 0)

"12366708736"

Command: (dos_chkdsk "Z:")

(5.03223e+010 4.86313e+010 1.69095e+009)
```

---

## dos_drive

Returns the current drive or changes the current drive to the one specified.

### Syntax

```lisp
(dos_drive [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

### Returns

A string identifying the current or new drive if successful.

nil on error.

### Example

```lisp
Command: (dos_drive)

"C:"

Command: (dos_drive "D:")

"D:"
```

---

## dos_drivep

Checks for the existence of a drive.

### Syntax

```lisp
(dos_drivep drive)
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:).

### Returns

T if the specified drive exists.

nil on error.

### Example

```lisp
Command: (dos_drivep "D:")

T

Command: (dos_drivep "Z:")

nil
```

---

## dos_drives

Returns a list of available drives.

### Syntax

```lisp
(dos_drives)
```

### Parameters

n/a

### Returns

A list of available local and network drives if successful.

nil on error.

### Example

```lisp
Command: (dos_drives)

("A:" "C:" "D:" "E:" "F:")
```

---

## dos_drivetype

Returns the type of the specified drive; either removable, fixed, CD-ROM, RAM disk, or a network drive.

### Syntax

```lisp
(dos_drivetype [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

### Returns

A string describing the drive type if successful.

nil on error.

### Example

```lisp
Command: (dos_drivetype)

"FIXED"

Command: (dos_drivetype "F:")

"CDROM"

Command: (dos_drivetype "Z:")

"REMOTE"
```

---

## dos_filesys

Returns the file system of the specified drive; either FAT, FAT32, NTFS, HPFS, CDFS, or a network drive.

### Syntax

```lisp
(dos_filesys [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

### Returns

A string identifying the file system if successful.

nil on error.

### Example

```lisp
Command: (dos_filesys)

"NTFS"

Command: (dos_drive "F:")

"CDFS"
```

---

## dos_format

Displays a Windows Format dialog box allowing the user for prepare a disk or diskette for use.

### Syntax

```lisp
(dos_format drive)
```

### Parameters

```lisp
drive
```

The drive name (for example, A:, B:).

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_format "A:")

T
```

---

## dos_label

Returns or changes the volume label of a specified disk.

### Syntax

```lisp
(dos_label [drive [label]])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

```lisp
label
```

The volume label. If not specified, the volume label is returned.

### Return

A string identifying the volume label if successful.

nil on error.

### Examples

```lisp
Command: (dos_label)
```

```lisp
"DRIVE-C"
```

```lisp
Command: (dos_label "D:" "drive-d")
```

```lisp
"DRIVE-D"
```

---

## dos_serialno

Returns the serial number of a specified disk.

### Syntax

```lisp
(dos_serialno [drive])
```

### Parameters

```lisp
drive
```

The drive name (for example, C:, D:). If not specified, the current drive is used.

### Return

A string identifying the serial number if successful.

nil on error.

### Examples

```lisp
Command: (dos_serialno)
```

```lisp
"4216120B"
```

```lisp
Command: (dos_serialno "D:")
```

```lisp
"FCF9CE6C"
```

---

