# DOSLib: System functions

[Back to index](README.md)

## dos_nicinfo

Returns detailed information on the system's network adapters.

### Syntax

```lisp
(dos_nicinfo)
```

### Parameters

n/a

### Returns

A list containing one or more sublists describing the details of each
 network adapter if successful. The information returned in each sublist
 is as follows:

		Element

		Description

		0

		The
		 adapter's unique name.

		1

		The
		 adapter's friendly name.

		2

		The
		 adapter's description, or manufacturer/make/model.

		3

		The
		 adapter's MAC address.

		4

		The
		 adapter type (e.g. Ethernet, Token Ring, etc.).

		5

		The adapter's IP address.

		6

		The adapter's subnet mask.

		7

		The adapter's gateway address.

		8

		The adapter's address type, either
		 DHCP or Fixed.

nil on error.

### Example

```lisp
Command: (dos_nicinfo)
```

```lisp
(("{914DECA6-4DDC-4FEE-92DC-B36EA7BE2DAD}" "Wireless
 Network Connection 2" "Microsoft Virtual WiFi Miniport Adapter"
 "00:24:2C:49:D5:F1" "UNKNOWN" "0.0.0.0"
 "0.0.0.0" "0.0.0.0" "DHCP") ("{C12C38A5-8225-422E-8D46-F6FF46902FD0}"
 "Local Area Connection 2" "TAP-Win32 Adapter V9" "00:FF:C1:2C:38:A5"
 "ETHERNET" "0.0.0.0" "0.0.0.0" "0.0.0.0"
 "DHCP") ("{FA0586CA-CC81-4C08-9226-4C77D6203C4C}"
 "Wireless Network Connection" "Dell Wireless 1397 WLAN
 Mini-Card" "00:24:2C:49:D5:F1" "UNKNOWN" "192.168.1.110"
 "255.255.255.0" "192.168.1.1" "DHCP") ("{6C2A5A61-CA16-4DDC-AEE7-41ABB3326CF3}"
 "Local Area Connection" "Intel(R) 82567LM Gigabit Network
 Connection" "00:21:70:F9:0D:4E" "ETHERNET" "0.0.0.0"
 "0.0.0.0" "10.67.30.1" "DHCP"))
```

---

## dos_adminp

Determines whether the current user has administrator rights. This is done by confirming membership in the local Administrators group.

### Syntax

```lisp
(dos_adminp)
```

### Parameters

n/a

### Returns

T if the current user is member of the local Administrators group.

nil if not a member of the local Administrators group, or on error.

### Example

```lisp
Command: (dos_adminp)
```

```lisp
T
```

```lisp

```

---

## dos_beep
Plays a Windows waveform audio file. The waveform sound for each sound type is identified by an entry in the SOUNDS section of the registry. If the system cannot play the specified alert sound, dos_beep plays the system default sound. If the function cannot play the default sound, dos_beep produces a standard beep by using the computer speaker.

### Syntax

```lisp
(dos_beep [type])
```

### Parameters

```lisp
type
```

The waveform type. The default type is a standard beep (0). The allowable values are as follows:

0

Standard Beep

1

System Asterisk

2

System Exclamation

3

System Hand

4

System Question

5

System Default

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_beep)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_beep 1)
```

```lisp
T
```

```lisp

```

---

## dos_capslock

Toggles the state of the <Caps Lock> key.

### Syntax

```lisp
(dos_capslock [T])
```

### Parameters

```lisp
T
```

 If specified, the <Caps Lock> is turned on. Otherwise, it is turned off.

### Returns

T if <Caps Lock> is turned on.

nil if <Caps Lock> is turned off.

### Example

```lisp
Command: (dos_capslock t)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_capslock)
```

```lisp
nil
```

```lisp

```

---

## dos_cdate

Returns a formatted string containing the current date and/or time.

### Syntax

```lisp
(dos_cdate format)
```

### Parameters

```lisp
format
```

 A string containing one or more formatting codes. Other characters
 in the formatting string are copied unchanged to the returned string.
 The formatting codes are as follows:

		%a

		Abbreviated
		 weekday name

		%A

		Full
		 weekday name

		%b

		Abbreviated
		 month name

		%B

		Full
		 month name

		%c

		Date
		 and time representation appropriate for locale

		%d

		Day
		 of month as decimal number (01 – 31)

		%H

		Hour
		 in 24-hour format (00 – 23)

		%I

		Hour
		 in 12-hour format (01 – 12)

		%j

		Day
		 of year as decimal number (001 – 366)

		%m

		Month
		 as decimal number (01 – 12)

		%M

		Minute
		 as decimal number (00 – 59)

		%p

		Current
		 locale’s A.M./P.M. indicator for 12-hour clock

		%S

		Second
		 as decimal number (00 – 59)

		%U

		Week
		 of year as decimal number, with Sunday as first day of week (00
		 – 53)

		%w

		Weekday
		 as decimal number (0 – 6; Sunday is 0)

		%W

		Week
		 of year as decimal number, with Monday as first day of week (00
		 – 53)

		%x

		Date
		 representation for current locale

		%X

		Time
		 representation for current locale

		%y

		Year
		 without century, as decimal number (00 – 99)

		%Y

		Year
		 with century, as decimal number

		%z
		 or %Z

		Time-zone
		 name or abbreviation; no characters if time zone is unknown

		%%

		Percent
		 sign

The # flag may prefix any formatting
 code. In that case, the meaning of the format code is changed as follows:

		%#a,
		 %#A, %#b, %#B, %#p, %#X, %#z, %#Z, %#%

		#
		 flag is ignored.

		%#c

		Long
		 date and time representation, appropriate for current locale.
		 For example: “Tuesday, March 14, 1995, 12:41:29”.

		%#x

		Long
		 date representation, appropriate to current locale. For example:
		 “Tuesday, March 14, 1995”.

		%#d,
		 %#H, %#I, %#j, %#m, %#M, %#S, %#U, %#w, %#W, %#y, %#Y

		Remove
		 leading zeros (if any).

### Returns

A string identifying the current date and/or time if successful.

nil on error.

### Example

```lisp
Command: (dos_cdate "%m/%d/%y")
```

```lisp
"01/09/02"
```

```lisp

```

```lisp
Command: (dos_cdate "%A, %B %d, %Y")
```

```lisp
"Wednesday, January 09, 2002"
```

```lisp

```

```lisp
Command: (dos_cdate "Today is %A, day %d of %B in
 the year %Y.")
```

```lisp
"Today is Wednesday, day 09 of January in the year
 2002."
```

```lisp

```

---

## dos_clipboard

Returns or sets a string of text in the Windows clipboard.

### Syntax

```lisp
(dos_clipboard [string])
```

### Parameters

```lisp
string
```

A string of text to set in the Windows clipboard.

### Returns

The string if successful.

nil on error.

### Example

```lisp
Command: (dos_clipboard "Hello World!")
```

```lisp
"Hello World!"
```

```lisp

```

```lisp
Command: (dos_clipboard)
```

```lisp
"Hello World!"
```

```lisp

```

---

## dos_cmdargs

Retrieves the command-line arguments, or switches, used to launch AutoCAD. Command line switches are parameters that you add to the ACAD.EXE command line which enable AutoCAD to perform additional operations when it starts. For example, AutoCAD can start with an alternative configuration, run a script, load a template drawing and even open a drawing with a saved view. The standard AutoCAD switches are as follows:

/b - Open a drawing and runs a Script. Drawing name is optional.

Syntax:  path ["drawing file"] /b "script"

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /b "C:\Scripts\MyScript"

/c - Specifies the hardware configuration file to use.

Syntax:  path /c "Configuration File"

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /c "C:\MyConfigs\MyConfig"

/nologo - Starts AutoCAD without the splash screen.

Syntax:  path  /nologo

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /nologo

/p - Starts AutoCAD with the specified Profile name. If the Profile does not exist, AutoCAD uses the current Profile.

Syntax:  path  /b profile

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /p "C:\Profiles\MyProfile"

/r - Resets all AutoCAD default settings, printers and system pointing device.

Syntax:  path /r

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /r

/s - Designates additional Support Paths.

Syntax:  path /s "Support Paths"

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /s "C:\Blocks;C:\Lisp;C:\VBA"

/t - Creates a new drawing based on a Template or Prototype drawing. Drawing name is optional.

Syntax:  path  ["drawing file"] /t "Template File"

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" /t "C:\MyTemplates\MyTemplate"

/v -  Opens a drawing with a predefined view.

Syntax:  path  ["drawing file"] /v "View Name"

Example:  "C:\Program Files\AutoCAD 2007\acad.exe" "MyDrawing" /v "MyView"

### Syntax

```lisp
(dos_cmdargs)
```

### Parameters

n/a

### Returns

A list containing the command-line arguments if successful.

nil on error.

### Example

```lisp
Command: (dos_cmdargs)
```

```lisp
("C:\\Program Files\\AutoCAD 2007\\acad.exe" "/b" "C:\\Scripts\\MyScript")
```

---

## dos_computer

Returns or sets the computer name of the current system. The name is established at system startup, when it is initialized from the Windows Registry. Changes to the computer name take effect the next time the system is started.

### Syntax

```lisp
(dos_computer [name])
```

### Parameters

```lisp
name
```

The computer name.

### Returns

A string identifying the computer name if successful.

nil on error.

### Example

```lisp
Command: (dos_computer)
```

```lisp
"ELVIS"
```

```lisp

```

```lisp
Command: (dos_computer "SPEEDO")
```

```lisp
"SPEEDO"
```

```lisp

```

---

## dos_date

Returns the current system date or changes the current system date to
 one specified.

### Syntax

```lisp
(dos_date [date])
```

### Parameters

```lisp
date
```

A list of numbers specifying the year (1970–3000), month (1–12), and
 day (1–31).

### Returns

A list of numbers identifying the current year, month, and day if successful.

nil on error.

### Example

```lisp
Command: (dos_date)
```

```lisp
(2006 7 14)
```

```lisp

```

```lisp
Command: (dos_date '(2007 7 14))
```

```lisp
(2007 7 14)
```

```lisp

```

---

## dos_guidgen

Creates a GUID, a unique 128-bit integer.

### Syntax

```lisp
(dos_guidgen)
```

### Parameters

n/a

### Returns

A string identifying a GUID if successful.

nil on error.

### Example

```lisp
Command: (dos_guidgen)
```

```lisp
"947823AD-9F0B-4171-85B9-81C73F46E801"
```

```lisp

```

---

## dos_hostname

Returns a systems local DNS hostname.

### Syntax

```lisp
(dos_hostname)
```

### Parameters

n/a

### Returns

A strings containing the local hostname if successful.

nil on error.

### Example

```lisp
Command: (dos_hostname)
```

```lisp
"ELVIS"
```

```lisp

```

---

## dos_htmlhelp

Starts HTML Help (HH.exe) and passes additional data that indicates the nature of the help requested by the application.

### Syntax

```lisp
(dos_htmlhelp filename [index/topic])
```

### Parameters

```lisp
filename
```

An HTML Help filename.

```lisp
index/topic
```

Either an index number into the help file, or a topic string in the help file (depending on how the help file was designed).

### Returns

nil successful or on error.

### Example

```lisp
Command: (dos_htmlhelp "C:\\Program Files\\AutoCAD 2006\\help\\readme.chm")
```

```lisp
nil
```

```lisp

```

---

## dos_ipaddress

Returns a list of local IP addresses.

### Syntax

```lisp
(dos_ipaddress)
```

### Parameters

n/a

### Returns

A list of strings containing the local ip addresses and subnet mask if successful.

nil on error.

### Example

```lisp
Command: (dos_ipaddress)
```

```lisp
("204.177.179.67" "255.255.255.0")
```

```lisp

```

---

## dos_isacad64

Determines if the version of AutoCAD that DOSLib is currently running in is a 64-bit version of AutoCAD.

### Syntax

```lisp
(dos_isacad64)
```

### Parameters

n/a

### Returns

T if AutoCAD is a 64-bit version.

nil otherwise.

### Example

```lisp
Command: (dos_isacad64)
```

```lisp
nil
```

---

## dos_ispoweruser

Determines whether the current user has power user rights. This is done by confirming membership in the local power users group.

### Syntax

```lisp
(dos_ispoweruser)
```

### Parameters

n/a

### Returns

T if the current user is member of the local power users group.

nil if not a member of the local power users group, or on error.

### Example

```lisp
Command: (dos_ispoweruser)
```

```lisp
T
```

---

## dos_iswin64

Determines if AutoCAD is running on a 64-bit version of Windows, such as Windows XP x64 or Windows Vista x64. This function does not determine if you are running a 64-bit version of AutoCAD.

### Syntax

```lisp
(dos_iswin64)
```

### Parameters

n/a

### Returns

T if Windows is a 64-bit version.

nil otherwise.

### Example

```lisp
Command: (dos_iswin64)
```

```lisp

T
```

---

## dos_macaddress

Returns the system's media access control (MAC) addresses.

### Syntax

```lisp
(dos_macaddress)
```

### Parameters

n/a

### Returns

A strings containing the local MAC address if successful.

nil on error.

### Example

```lisp
Command: (dos_macaddress)
```

```lisp
"00:00:86:4A:CF:7F"
```

```lisp

```

---

## dos_mem

Returns a list containing information about current available memory. The function returns information about both physical and virtual memory. Use the rtos function to convert the return values to strings.

### Syntax

```lisp
(dos_mem)
```

### Parameters

n/a

### Returns

A list of numbers describing the current state of memory if successful. The return values are as follows:

Memory Load

The percent of memory in use (integer).

Total Physical

Total bytes of physical memory.

Available Physical

Available bytes of free physical memory.

Total Page File

Total bytes of the paging file.

Available Page File

Available bytes in the paging file.

Total Virtual

Total user bytes of address space.

Available Virtual

Available, free user bytes of address space.

nil on error.

### Example

```lisp
Command: (dos_mem)
```

```lisp
(27 5.3633e+008 3.90562e+008 1.30926e+009 1.18208e+009 2.14735e+009 2.06644e+009)
```

```lisp

```

---

## dos_numlock

Toggles the state of the <Num Lock> key.

### Syntax

```lisp
(dos_numlock [T])
```

### Parameters

```lisp
T
```

 If specified, the <Num Lock> is turned on. Otherwise, it is turned off.

### Returns

T if <Num Lock> is turned on.

nil if <Num Lock> is turned off.

### Example

```lisp
Command: (dos_numlock t)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_numlock)
```

```lisp
nil
```

```lisp

```

---

## dos_pause

Pauses the execution of a function or expression for a specified number of seconds.

### Syntax

```lisp
(dos_pause duration)
```

### Parameters

```lisp
duration
```

The duration time in seconds.

### Returns

nil if successful on error.

### Example

```lisp
Command: (dos_pause 3)
```

```lisp
nil
```

```lisp

```

```lisp

```

---

## dos_printscrn

Screen capture utility.

### Syntax

```lisp
(dos_printscrn filename
 [mode [prompt]])
```

### Parameters

```lisp
filename
```

The name of the bitmap file to create, or nil
 to copy the screen capture to the Windows Clipboard. The allowable file
 types are as follows:

		BMP

		Windows
		 Bitmap

		JPG

		JFIF
		 Compliant

		GIF

		Compuserve
		 Graphics Interchange

		TIF

		Tagged
		 Image File Format

		PNG

		Portable
		 Network Graphics

```lisp

```

```lisp
mode
```

The screen capture mode. The allowable file types are as follows:

		0
		 (Default)

		Capture
		 the primary display.

		1

		Capture
		 the AutoCAD main window.

		2

		Capture
		 the AutoCAD document window.

		3

		Capture
		 the foreground-most window.

		4

		Capture
		 a user-defined region.

```lisp

```

```lisp
prompt
```

A string to be displayed to prompt the user when in user-defined region
 capture mode.

### Returns

A string identifying the created bitmap file if successful.

nil on error.

### Example

```lisp
Command: (dos_printscrn "C:\\test.bmp")
```

```lisp
"C:\\test.bmp"
```

---

## dos_scrolllock

Toggles the state of the <Scroll Lock> key.

### Syntax

```lisp
(dos_scrolllock [T])
```

### Parameters

```lisp
T
```

If specified, the <Scroll Lock> is turned on. Otherwise, it is turned off.

### Returns

T if <Scroll Lock> is turned on.

nil if <Scroll Lock> is turned off.

### Example

```lisp
Command: (dos_scrolllock t)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_scrolllock)
```

```lisp
nil
```

```lisp

```

---

## dos_sortlist

Sorts a list of strings, reals or integers. Sorting of string is case-sensitive.

### Syntax

```lisp
(dos_sortlist list)
```

### Parameters

```lisp
list
```

A list of string, real or integer values.

### Returns

A sorted list if successful.

nil on error.

### Example

```lisp
Command: (dos_sortlist '(4 3 6 5 1 2 7 9 8))
```

```lisp
(1 2 3 4 5 6 7 8 9)
```

```lisp

```

```lisp
Command: (dos_sortlist (dos_dir "*.dwg"))
```

```lisp
("1st floor architectural.dwg" "1st floor
 electrical.dwg" "1st floor lighting.dwg" "1st floor
 plan.dwg" "1st floor.dwg" "Campus.dwg" "City
 base map.dwg" "City map.dwg" "City skyway map.dwg"
 "Colorwh.dwg" "Db_samp.dwg" "EXPO98 base.dwg"
 "EXPO98 maps.dwg" "Elevation.dwg" "Expo Headquarters
 model.dwg" "Lineweights.dwg" "MKMPlan.dwg" "Oceanarium.dwg"
 "Opera.dwg" "Plot Screening and Fill Patterns.dwg"
 "R300-20.dwg" "Single cavity mold.dwg" "Tablet
 2000.dwg" "Truck model.dwg" "TrueType.dwg" "Watch.dwg"
 "Wilhome.dwg")
```

```lisp

```

---

## dos_speaker

Plays a sound out of the PC speaker.

Note, dos_speaker does not work
 on all systems.

A long time ago, all PC computers shared a common 8254 programmable
 interval timer chip for the generation of primitive sounds. The dos_speaker function was written
 specifically to emit a beep on that piece of hardware.

Since then, sound cards have become standard equipment on almost all
 PC computers. As sound cards became more common, manufacturers began to
 remove the old timer chip from computers. The chips were also excluded
 from the design of server computers. The result is that dos_speaker
 did not work on all computers without the chip. This was okay because
 most developers had moved on to calling the dos_beep
 function that uses whatever is the default sound device instead of the
 8254 chip.

### Syntax

```lisp
(dos_speaker frequency
 duration)
```

### Parameters

```lisp
frequency
```

The frequency of the sound, in hertz. This parameter must be in the
 range 37 through 32,767.

```lisp
duration
```

The duration of the sound, in milliseconds.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_speaker 1500 5)
```

```lisp
nil
```

```lisp

```

---

## dos_tickcount

Returns the number of milliseconds since the device booted, excluding
 any time that the system was suspended. The system "tick count"
 starts at zero on boot and then counts up from there. Because AutoLISP
 does not use "unsigned long" integers, the value is returned
 as a double-precision floating point number.

This function is useful for benchmarking time consuming tasks. Just
 obtain the tick count immediately before and after the time consuming
 task. Then, subtract the two values to determine the elapsed time in milliseconds.

### Syntax

```lisp
(dos_tickcount)
```

### Parameters

n/a

### Returns

The number of milliseconds as a real, or
 double-precision floating point, number.

### Example

```lisp
Command: (rtos (dos_tickcount) 2 0)
```

```lisp
"12263784"
```

---

## dos_time

Returns the current system time or changes the current system time to
 one specified.

### Syntax

```lisp
(dos_time [time])
```

### Parameters

```lisp
time
```

A list of numbers specifying the new hour and minutes in 24-hour format.
 Optionally, the seconds and milliseconds can be specified.

### Returns

A list of numbers identifying the current hour, minutes, seconds, and
 milliseconds in 24-hour format if successful.

nil on error.

### Example

```lisp
Command: (dos_time)
```

```lisp
(15 8 15 242)
```

```lisp

```

```lisp
Command: (dos_time '(16 0 0))
```

```lisp
(16 0 0 10)
```

```lisp

```

---

## dos_username

Returns user name of the current thread. This is the name of the user currently logged onto the system.

### Syntax

```lisp
(dos_username)
```

### Parameters

n/a

### Returns

A string identifying the current user if successful.

nil on error.

### Example

```lisp
Command: (dos_username)
```

```lisp
"dale"
```

```lisp

```

---

## dos_ver

Returns the operating system version.

### Syntax

```lisp
(dos_ver)
```

### Parameters

n/a

### Returns

A string containing the operating version if successful.

nil on error.

### Example

```lisp
Command: (dos_ver)
```

```lisp
"Microsoft Windows XP Professional Service Pack 2 (Build 2600)"
```

---

## dos_wav

Plays a Windows waveform audio file.

### Syntax

```lisp
(dos_wav filename)
```

### Parameters

```lisp
filename
```

A waveform (.WAV) filename.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_wav "c:\\windows\\media\\ding.wav")
```

```lisp
T
```

---

## dos_winhelp

Starts Windows Help (Winhelp.exe) and passes additional data that indicates
 the nature of the help requested by the application.

### Syntax

```lisp
(dos_winhelp filename
 [index/topic])
```

### Parameters

```lisp
filename
```

A Windows Help filename.

```lisp
index/topic
```

Either an index number into the help file, or a topic string in the
 help file (depending on how the help file was designed).

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_winhelp "c:\\Program Files\\AutoCAD
 2002\\Help\\readme.hlp")
```

```lisp
T
```

```lisp

```

```lisp

```

```lisp

```

```lisp

```

---



