# DOSLib: Printer functions

[Back to index](README.md)

## dos_getprn

Returns the current, or default, Windows printer.

### Syntax

```lisp
(dos_getprn)
```

### Parameters

n/a

### Returns

A string identifying the current Windows printer if successful.

nil on error.

### Example

```lisp
Command: (dos_getprn)
```

```lisp
"HP LaserJet 8100 Series PCL"
```

```lisp

```

---

## dos_printers

Returns the list of installed Windows printers. These printers were installed through the Windows Control Panel.

### Syntax

```lisp
(dos_printers)
```

### Parameters

n/a

### Returns

A list strings identifying the installed Windows printers if successful

nil on error.

### Example

```lisp
Command: (dos_printers)
```

```lisp
("HP LaserJet 8100 Series PCL 6" "hp LaserJet 1300 PCL 6" "HP DeskJet 935C" "HP Color LaserJet 4500")
```

---

## dos_setprn

Sets the current, or default, Windows printer. The printer name must be a name returned by dos_printers.

### Syntax

```lisp
(dos_setprn printername)
```

### Parameters

```lisp
printername
```

The name of an existing printer, as returned by dos_printers.

### Returns

A string identifying the current Windows printer if successful.

nil on error.

### Example

```lisp
Command: (dos_setprn (cadr (dos_printers)))
```

```lisp
"hp LaserJet 1300 PCL 6"
```

---

## dos_spool

Spools, or prints, a disk file to a Windows printer. The spool file must be in a "raw" printer format.

### Syntax

```lisp
(dos_spool filename printername)
```

### Parameters

```lisp
filename
```

The source filename. filename must contain either text or printer information.

```lisp
printername
```

The name of an existing printer, as returned by either dos_getprn or dos_printers.

### Returns

A qualified path to the spooled file if successful.

nil on error.

### Example

```lisp
Command: (dos_spool "readme.txt" (dos_getprn))
```

```lisp
"C:\\temp\\readme.txt"
```

---


