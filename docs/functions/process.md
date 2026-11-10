# DOSLib: Process functions

[Back to index](README.md)

## dos_command

Runs an internal command. Internal commands are those commands native to the operating system's command interpreter (e.g. COMMAND.COM or CMD.EXE).

### Syntax

```lisp
(dos_command command [show])
```

### Parameters

```lisp
command
```

The command to run, including arguments.

```lisp
show
```

How the newly opened window is to be shown. The default value is Normal (0).

0

Normal. Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

1

Not Active. Displays a window in its most recent size and position. This value is similar option 0, except the window is not active.

2

Minimized. Activates the window and displays it as a minimized window.

3

Minimized Not Active. Displays the window as a minimized window. This value is similar to option 2, except the window is not activated.

4

Maximized. Activates the window and displays it as a maximized window.

### Returns

Returns command if successful.

nil on error.

### Example

```lisp
Command: (dos_command "copy *.dwg c:\temp")

"CMD.EXE /C copy *.dwg c:\temp"
```

---

## dos_execute

Executes an external program. The PATH environment variable is used to find the program to be executed.

### Syntax

```lisp
(dos_execute command [show])
```

### Parameters

```lisp
command
```

The command to run, including arguments.

```lisp
show
```

How the newly opened window is to be shown. The default value is Normal (0).

0

Normal. Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

1

Not Active. Displays a window in its most recent size and position. This value is similar option 0, except the window is not active.

2

Minimized. Activates the window and displays it as a minimized window.

3

Minimized Not Active. Displays the window as a minimized window. This value is similar to option 2, except the window is not activated.

4

Maximized. Activates the window and displays it as a maximized window.

### Returns

Returns command if successful.

nil on error.

### Example

```lisp
Command: (dos_execute "Notepad.exe")

"Notepad.exe"
```

---

## dos_exewait

Executes an external program, then waits for termination before returning control to the calling application.

### Syntax

```lisp
(dos_exewait command [show])
```

### Parameters

```lisp
command
```

The command to run, including arguments.

```lisp
show
```

How the newly opened window is to be shown. The default value is Normal (0).

0

Normal. Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

1

Not Active. Displays a window in its most recent size and position. This value is similar option 0, except the window is not active.

2

Minimized. Activates the window and displays it as a minimized window.

3

Minimized Not Active. Displays the window as a minimized window. This value is similar to option 2, except the window is not activated.

4

Maximized. Activates the window and displays it as a maximized window.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_exewait "Notepad.exe")

Running external process, please wait...

T
```

---

## dos_processes

Returns a list of processes, or tasks, running on the system.

### Syntax

```lisp
(dos_processes [T])
```

### Parameters

```lisp
T
```

 If specified, a fully qualified path to the running process is returned. Otherwise, just the filename is returned.

### Returns

A list of running processes if successful.

nil on error.

### Example

```lisp
Command: (dos_processes)

("smss.exe" "csrss.exe" "winlogon.exe" "services.exe" "lsass.exe" "Ati2evxx.exe" "svchost.exe" "svchost.exe" "svchost.exe" "S24EvMon.exe" "svchost.exe" "svchost.exe" "ccSetMgr.exe" "SPBBCSvc.exe" "ccEvtMgr.exe" "spoolsv.exe" "DefWatch.exe" "mdm.exe" "RegSrvc.exe" "ZCfgSvc.exe" "Ati2evxx.exe" "svchost.exe" "Rtvscan.exe" "1XConfig.exe" "wdfmgr.exe" "ccApp.exe" "VPTray.exe" "type32.exe" "point32.exe" "ctfmon.exe" "alg.exe" "svchost.exe" "explorer.exe" "devenv.exe" "RoboHTML.exe" "notepad.exe" "mspdbsrv.exe" "hh.exe" "dexplore.exe" "acad.exe" "AdskCleanup.0001" "AdskScSrv.exe" "wmiprvse.exe" "WSCommCntr1.exe")
```

---

## dos_shellexe

Opens or prints a specified file. The file can be an executable file or a document file.

### Syntax

```lisp
(dos_shellexe file parameters [operation [show]])
```

### Parameters

```lisp
file
```

A file to open or print or the folder to open or explore. The function can open an executable file or a document file. The function can print a document file.

```lisp
parameters
```

The parameters to be passed to the application, like a document. If file specifies a document file, parameters should be nil.

```lisp
operation
```

0

Open the executable or document.

1

Print the document.

2

Explore the specified folder.

```lisp
show
```

How the newly opened window is to be shown. The default value is Normal (0).

0

Normal. Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

1

Not Active. Displays a window in its most recent size and position. This value is similar option 0, except the window is not active.

2

Minimized. Activates the window and displays it as a minimized window.

3

Minimized Not Active. Displays the window as a minimized window. This value is similar to option 2, except the window is not activated.

4

Maximized. Activates the window and displays it as a maximized window.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_shellexe "notepad.exe" "readme.txt")

T

(dos_shellexe "www.mcneel.com" nil)

T

(dos_shellexe "c:\\drawings\\" nil 2)

T
```

---

