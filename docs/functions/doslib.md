# DOSLib: Doslib functions

[Back to index](README.md)

## dos_about

Displays DOSLib's version number and copyright information.

### Syntax

```lisp
(dos_about)
```

### Parameters

n/a

### Returns

nil if successful or on error.

### Example

```lisp
Command: (dos_about)
```

```lisp
nil
```

---

## dos_demandload

Returns or sets the demand-loading method used by DOSLib.

### Syntax

```lisp
(dos_demandload [val])
```

### Parameters

```lisp
val
```

If T is specified, DOSLib will load on AutoCAD startup. If nil is specified, DOSLib will load on command invocation. If no argument is specified, the current demand load state is returned.

### Returns

T if demand-loading at startup.

nil if command invocation, or on error.

### Example

```lisp
Command: (dos_demandload T)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_demandload)
```

```lisp
T
```

```lisp

```

---

## dos_help

Displays the DOSLib HTML help file

### Syntax

```lisp
(dos_help [function])
```

### Parameters

```lisp
function
```

The name of the function to display help on. If omitted, the table of contents will be displayed.

### Returns

nil on success or on error.

### Example

```lisp
Command: (dos_help)
```

```lisp
nil
```

```lisp

```

```lisp
Command: (dos_help "dos_dir")
```

```lisp
nil
```

---

## dos_version

Returns the DOSLib version number.

### Syntax

```lisp
(dos_version)
```

### Parameters

n/a

### Returns

A list containing the DOSLib major version number, minor version number,
 and service release if successful.

nil on error.

### Example

```lisp
Command: (dos_version)
```

```lisp
(8 4 0)
```

---


