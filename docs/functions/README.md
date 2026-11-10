# DOSLib function reference

Reference for all 316 dos_* functions in DOSLib, converted from the original DOSLib.chm help file. Each function lists its syntax, parameters, return value, and an example.

## Loading DOSLib in AutoLISP

DOSLib is an ObjectARX module, so AutoCAD must load the .arx before the dos_* functions exist.

**1. Load the module.** Use the file that matches your AutoCAD release:

- AutoCAD 2027: DOSLib26x64.arx
- AutoCAD 2026: DOSLib25x64.arx

Put the file on the AutoCAD support path, then load it:

```lisp
(arxload "DOSLib26x64.arx")
```

**2. Choose the file by version.** ACADVER starts with the release number, so the name can be built at run time:

```lisp
(defun dos-load (/ acadv fname) (setq acadv (substr (getvar "ACADVER") 1 2)) ; "26" for AutoCAD 2027 (setq fname (strcat "DOSLib" acadv "x64.arx")) (if (findfile fname) (arxload fname nil) (princ (strcat "\n" fname " not found on the support path."))) (princ))
```

**3. Call the functions.** Once loaded, call any dos_* function from your own code:

```lisp
(defun c:pickfile (/ fname) (dos-load) (setq fname (dos_getfiled "Select a file" "C:\\" "PTS files (*.pts)|*.pts|All files (*.*)|*.*||")) (if fname (princ (strcat "\nChosen: " fname))) (princ))
```

**4. Check what is loaded.** dos_arxlist returns the loaded ARX module names. Check for DOSLib before calling its functions:

```lisp
(member (strcase "DOSLib26x64.arx" T) (mapcar '(lambda (s) (strcase s T)) (dos_arxlist)))   ; non-nil when loaded
```

The ptsimport.lsp command in the truevis PTS import project uses this same pattern in its DOSLibLoader function.

## Categories

- [Acad](acad.md) - 40 functions
- [Config](config.md) - 16 functions
- [Doslib](doslib.md) - 4 functions
- [Drive](drive.md) - 9 functions
- [File](file.md) - 32 functions
- [Folder](folder.md) - 16 functions
- [Interface](interface.md) - 28 functions
- [Math](math.md) - 79 functions
- [Path](path.md) - 21 functions
- [Printer](printer.md) - 4 functions
- [Process](process.md) - 5 functions
- [String](string.md) - 32 functions
- [System](system.md) - 30 functions

## Notes

- Functions return nil on error, as described on each page.
- Some help pages were written for older AutoCAD and BricsCAD releases. The behavior of functions tied to specific AutoCAD versions may differ on 2026 and 2027.
- These pages come from the original DOSLib help. The DOSLib trademark belongs to Robert McNeel & Associates. This fork is not endorsed by them.

