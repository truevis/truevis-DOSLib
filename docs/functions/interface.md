# DOSLib: Interface functions

[Back to index](README.md)

## dos_checklist

Displays a sizeable Windows dialog box with a check-style list box.
 Useful when trying to toggle the state of objects or settings.

### Syntax

```lisp
(dos_checklist title
 prompt assoc-list
 [T])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
assoc-list
```

An association list of string values and their associated state, either
 1 for on or 0 for off.

```lisp
T
```

If specified, the dialog will display an Add... button allowing the
 user to add new items to the list.

### Returns

The association list with the state values updated to reflect the changed
 made by the user if successful.

nil on cancel or on error.

### Example

```lisp
Command: (setq layer_list '(("Layer1" . 0) ("Layer2"
 . 0) ("Layer3" . 0)))
```

```lisp
(("Layer1" . 0) ("Layer2" . 0) ("Layer3"
 . 0))
```

```lisp

```

```lisp
Command: (dos_checklist "Display Layers" "Layers
 to turn on/off" layer_list)
```

```lisp

```

```lisp
(("Layer1" . 1) ("Layer2" . 0) ("Layer3"
 . 1))
```

```lisp

```

```lisp

```

---

## dos_combolist

Displays a sizeable Windows dialog box with a combo-style list box.
 Useful when needing to select an item from a list or enter a string value.

### Syntax

```lisp
(dos_combolist title
 prompt list
 [default])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list
```

A list of string values.

```lisp
default
```

A string containing a default string value.

### Returns

The item entered into the edit field or selected from the list if successful.

nil on cancel or on error.

### Examples

```lisp
Command: (dos_combolist "Set Current Layer" "Select
 a layer" '("Layer1" "Layer2" "Layer3"))
```

```lisp
"MyLayer"
```

---

## dos_duallist

Displays a sizeable Windows dialog box with a include/exclude list boxes.
 Items can be moved between the list boxes by either dragging or by using
 the move left/right buttons.

### Syntax

```lisp
(dos_duallist title
 prompt list1
 list2 [list1_prompt list2_prompt])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list1
```

The first list of string values.

```lisp
list2
```

The second list of string values.

```lisp
list1_prompt
```

A prompt for the first list box.

```lisp
list2_prompt
```

A prompt for the second list box.

### Returns

A list of two lists: each containing the results of each list box, if
 successful.

nil on cancel or on error.

### Example

```lisp
Command: (setq list1 (list "Layer1" "Layer2"
 "Layer3"))
```

```lisp
("Layer1" "Layer2" "Layer3")
```

```lisp

```

```lisp
Command: (setq list2 (list "Layer5" "Layer5"
 "Layer6"))
```

```lisp
("Layer5" "Layer5" "Layer6")
```

```lisp

```

```lisp
Command: (dos_duallist "Layers" "Drag or
 move the layers" list1 list2 "List1" "List2")
```

```lisp
(("Layer2" "Layer5") ("Layer1"
 "Layer5" "Layer6" "Layer3"))
```

```lisp

```

```lisp

```

---

## dos_editbox

Displays a sizeable Windows dialog box with a multi-line edit control.
 Useful for editing paragraphs of text. Text can also be imported into
 the dialog box from external files.

### Syntax

```lisp
(dos_editbox title
 prompt [default])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
default
```

A default string value. Lines can be separated with a newline, or '\n',
 character.

### Returns

A string value if successful. Lines will be separated with a newline,
 or '\n', character. Use the dos_strtokens
 function to convert the return value into a list of strings.

nil on cancel or on error.

### Example

```lisp
Command: (dos_editbox "Editor" "Enter some
 text" "Hockey\nis\nthe\nbest!")
```

```lisp
"I really think \nHockey\nis\nthe\nbest!"
```

---

## dos_editlist

Displays a sizeable Windows dialog box with an editable list box. Items
 can be added or removed from the list, and the order of the list can be
 changed.

### Syntax

```lisp
(dos_editlist title
 prompt list)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list
```

A list of string values.

### Returns

A list of string items selected from the list if successful. Note, if
 the list is empty, a list containing a single nil
 symbol is returned.

nil on cancel or on error.

### Example

```lisp
Command: (dos_editlist "Edit Items" "Add,
 remove, or edit items" '("Item1" "Item2" "Item3"))
```

```lisp
("Item1" "Item2" "Item3"
 "NewItem4")
```

```lisp

```

```lisp

```

---

## dos_getcancel

Displays a modeless dialog box that consists of a message and a cancel
 button. Because the dialog box is modeless, you can use it when performing
 long processes that can be interrupted by the user. The function is called
 once with arguments to initialize the dialog box. It is called with no
 arguments to check the open status of the dialog box. It can be called
 with a T argument to close the
 dialog box.

### Syntax

```lisp
(dos_getcancel title
 message)
```

```lisp
(dos_getcancel T)
```

```lisp
(dos_getcancel)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
message
```

A string containing a message.

```lisp
T
```

Closes the dialog box.

### Returns

Returns nil when initializing
 and closing the dialog box.

When checking the open status, it return T
 if the dialog box is open, otherwise, nil
 is returned.

### Example

```lisp
Command: (setq x 0)
```

```lisp
0
```

```lisp

```

```lisp
Command: (dos_getcancel "Testing" "Testing,
 please wait...")
```

```lisp
nil
```

```lisp

```

```lisp
Command: (while (and (dos_getcancel) (< x 10000)) (setq
 x (1+ x)))
```

```lisp
10000
```

```lisp

```

```lisp
Command: (if (= x 10000) (dos_getcancel t))
```

```lisp
nil
```

```lisp

```

```lisp

```

---

## dos_getcolor
Displays a Windows common color selection dialog box. This is useful
 for selecting Red-Green-Blue (RGB) color values.

### Syntax

```lisp
(dos_getcolor title
 [default])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
default
```

An integer between 1 and 255 that represents an ACI color value, or
 a list of three integers that represent an RGB color value.

### Returns

A list of three integers that represent an RGB color value if successful.

nil on error.

### Examples

```lisp
Command: (dos_getcolor "Select a color" 1)
```

```lisp
(255 0 0)
```

```lisp

```

```lisp

```

---

## dos_getdate

Displays a date selection dialog box.

### Syntax

```lisp
(dos_getdate title
 [date])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
date
```

A list of numbers specifying the year (1970–3000), month (1–12), and
 day (1–31) to select. Of omitted, the current date is selected.

### Returns

A list of numbers identifying the selected year, month, and day if successful.

nil on cancel or on error

### Example

Command: (dos_getdate "Select Date")

(2009 11 2)

---

## dos_getint

Windows Dialog box equivalent to LISP getint
 function. ADSRX limits integers to 16-bit signed numbers with values ranging
 from +32767 to -32,768.

### Syntax

```lisp
(dos_getint title
 prompt [flags
 [default [max
 [min]]]])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing a prompt.

```lisp
flags
```

An optional bit-coded integer identifying the desired validation. Specify
 more than one validation by adding the following bit values:

		0

		No
		 additional validation.

		1

		Do
		 not allow a null, or empty, value.

		2

		Do
		 not allow a zero value.

		4

		Do
		 not allow a negative value.

```lisp
default
```

An optional default value.

```lisp
max
```

An optional maximum allowable value.

```lisp
min
```

An optional minimum allowable value.

### Returns

An integer, if successful.

nil on cancel or on error

### Example

```lisp
Command: (dos_getint "Copies" "Enter number
 of copies")
```

```lisp
2
```

```lisp

```

```lisp

```

---

## dos_getpassword

Windows Dialog box equivalent to LISP getstring
 function. The Dialog box displays a password-style edit control.

### Syntax

```lisp
(dos_getpassword title
 message [default
 [length]])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
message
```

A string containing a message.

```lisp
default
```

A default string value.

```lisp
length
```

A maximum character length limit.

### Returns

A string value, if successful.

nil on cancel or on error

### Example

```lisp
Command: (dos_getpassword "Password" "Enter
 your password")
```

```lisp
"password"
```

```lisp

```

```lisp

```

---

## dos_getprogress

Displays a modeless dialog box that consists of a message, a progress
 bar, and an optional cancel button. Because the dialog box is modeless,
 you can use it when performing long processes that can be interrupted
 by the user. The function is called once with arguments to initialize
 the dialog box. Then, it is called any number of times to move the progress
 bar in an absolute or relative manner. It is called with no arguments
 to check the open status of the dialog box. It can be called with a T argument to close the dialog box.

### Syntax

```lisp
(dos_getprogress title
 message maxvalue
 [T])
```

```lisp
(dos_getprogress abs/-rel)
```

```lisp
(dos_getprogress T)
```

```lisp
(dos_getprogress)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
message
```

A string containing a message.

```lisp
maxvalue
```

An integer representing the maximum range value (between 0 and maxvalue)
 of the progress bar.

```lisp
abs/-rel
```

An absolute position to move the progress meter, or a relative position
 (denoted with a negative sign) to move the progress meter.

```lisp
T
```

If specified during the creation of the dialog box, an optional Cancel
 button is displayed. Otherwise, T
 closes the dialog box.

### Returns

Returns nil when initializing,
 incrementing, and closing the dialog box.

When checking the open status, it return T
 if the dialog box is open, otherwise, nil
 is returned

### Example

```lisp
Command: (setq x 0 y 1000)
```

```lisp
1000
```

```lisp

```

```lisp
Command: (dos_getprogress "Testing" "Testing,
 please wait..." y)
```

```lisp
nil
```

```lisp

```

```lisp
Command: (while (< x y) (dos_getprogress -1) (setq x
 (1+ x)))
```

```lisp
1000
```

```lisp

```

```lisp
Command: (dos_getprogress t)
```

```lisp
nil
```

---

## dos_getreal

Windows Dialog box equivalent to LISP getreal
 function. Real numbers are double-precision floating-point values, providing
 at least 14 significant digits of precision. Values can be expressed in
 scientific notation, which has an optional e or E followed by the exponent
 of the number (for example, 0.0000041 is the same as 4.1e-6).

### Syntax

```lisp
(dos_getreal title
 prompt [flags
 [default [max
 [min]]]])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing a prompt.

```lisp
flags
```

An optional bit-coded integer identifying the desired validation. Specify
 more than one validation by adding the following bit values:

		0

		No
		 additional validation.

		1

		Do
		 not allow a null, or empty, value.

		2

		Do
		 not allow a zero value.

		4

		Do
		 not allow a negative value.

```lisp
default
```

An optional default value.

```lisp
max
```

An optional maximum allowable value.

```lisp
min
```

An optional minimum allowable value.

### Returns

A real number, if successful.

nil on cancel or on error

### Example

```lisp
Command: (dos_getreal "Distance" "Enter
 a distance")
```

```lisp
23.4
```

```lisp

```

```lisp

```

---

## dos_getsecret

Retrieves a password string from the AutoCAD command line.

### Syntax

```lisp
(dos_getsecret prompt [T])
```

### Parameters

```lisp
prompt
```

A string containing a prompt.

```lisp
T
```

The string can contain blanks and the user must terminate it by pressing <Enter>. Otherwise, entering either a space or <Enter> terminates the string.

### Returns

A string value, if successful.

nil on cancel or on error

### Example

```lisp
Command: (dos_getsecret "Password: ")
```

```lisp
"MySecretPassword"
```

---

## dos_getstring

Windows Dialog box equivalent to LISP getstring
 function.

### Syntax

```lisp
(dos_getstring title
 prompt [default
 [length]])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing a prompt.

```lisp
default
```

A default string value.

```lisp
length
```

A maximum character length limit.

### Returns

A string value, if successful.

nil on cancel or on error

### Example

```lisp
Command: (dos_getstring "Text" "Enter some
 text")
```

```lisp
"This is a string of text"
```

```lisp

```

```lisp

```

---

## dos_htmlbox

Displays an HTML web page in a sizable dialog box.

### Syntax

```lisp
(dos_htmlbox title
 address [width
 height])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
address
```

A web address (URL) or a path to an HTML-formatted file.

```lisp
width
```

An optional dialog box width.

```lisp
height
```

An optional dialog box height.

### Returns

nil if successful or on error.

### Example

```lisp
Command: (dos_htmlbox "McNeel" "www.mcneel.com")
```

```lisp
nil
```

```lisp

```

```lisp

```

---

## dos_htmlboxex

Displays an HTML web page in a modeless, sizable dialog box.

### Syntax

```lisp
(dos_htmlboxex title
 address [width
 height])
```

```lisp
(dos_htmlboxex T)
```

```lisp
(dos_htmlboxex )
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
address
```

A web address (URL) or a path to an HTML-formatted file.

```lisp
width
```

An optional dialog box width.

```lisp
height
```

An optional dialog box height.

```lisp
T
```

Closes the dialog box.

### Returns

Returns nil when initializing
 and closing the dialog box.

When checking the open status, it return T
 if the dialog box is open, otherwise, nil
 is returned.

### Example

```lisp
Command: (dos_htmlboxex "McNeel" "www.mcneel.com")
```

```lisp
nil
```

---

## dos_htmldialog

Creates a dialog box that displays HTML. An HTML dialog box can be used
 as an alternative to a DCL dialog box.

### Syntax

```lisp
(dos_htmldialog filename
 [arguments [options
 [modeless]]])
```

### Parameters

```lisp
filename
```

The filename containing the HTML dialog box to display. If a full path
 is not specified, the function will search the AutoCAD search path for
 the file.

```lisp
arguments
```

The argument or arguments to pass to the HTML dialog box. The data
 passed in is converted to a SAFEARRAY, and it is placed in the window
 object's window.dialogArguments
 property.

Note, AutoCAD does not allow ActiveX objects to be passed as parameters
 to ObjectARX-defined LISP functions. So to ensure that HTML dialogs have
 AutoCAD functionality, the AutoCAD object (returned in LISP by the vlax-get-Acad-Object function, is passed to your dialog automatically.
 This object will always
 be the first element of the SAFEARRAY placed in the window object's window.dialogArguments property.

```lisp
options
```

A string specifying the window ornaments for the dialog box. Use one
 or more of the following semicolon-delimited values:

		Value
		Description

		dialogHeight:sHeight

		Sets the height of the dialog window.

		dialogLeft:sXPos

		Sets the left position of the dialog window relative to
		 the upper-left corner of the desktop.

		dialogTop:sYPos

		Sets the top position of the dialog window relative to the
		 upper-left corner of the desktop.

		dialogWidth:sWidth

		Sets the width of the dialog window.

		center:{ yes | no | 1 | 0 | on | off }

		Specifies whether to center the dialog window within the
		 desktop. The default is yes.

		dialogHide:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window is hidden when printing
		 or using print preview. This feature is only available when a
		 dialog box is opened from a trusted application. The default is
		 no.

		edge:{ sunken | raised }

		Specifies the edge style of the dialog window. The default
		 is raised.

		help:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window displays the context-sensitive
		 Help icon. The default is yes.

		resizable:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window has fixed dimensions.
		 The default is no.

		scroll:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window displays scrollbars.
		 The default is yes.

		status:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window displays a status bar.
		 The default is yes for untrusted dialog windows and no for trusted
		 dialog windows.

		unadorned:{ yes | no | 1 | 0 | on | off }

		Specifies whether the dialog window displays the border
		 window chrome. This feature is only available when a dialog box
		 is opened from a trusted application. The default is no.

```lisp
height
```

An optional dialog box height.

```lisp
modeless
```

If omitted or nil , a modal
 dialog will be displayed. A modal dialog box retains the input focus while
 open. The user cannot switch windows until the dialog box is closed.

If T, a modeless dialog box
 will be displayed.

### Returns

If a model dialog is displayed, then if successful, the return value
 of the method will be dependant on the developer's implementation of the
 custom HTML dialog page. In most cases the developer will set the windows.returnValue property before
 closing the dialog box. This property will then be converted from either
 a VARIANT or a SAFEARRAY and returned to LISP. Note, although it is possible
 to create multi-dimensional SAFEARRAY objects, this function will only
 accept a single VARIANT or a 1-dimensional SAFEARRAY as a return value.

If a modeless dialog is displayed, then T
 indicating success.

In both cases, nil is returned
 on error.

### Notes

You can also eliminate scroll bars on dialog boxes by setting the scroll attribute to false in the
 body element for the dialog window, or call the modal dialog box from
 a trusted application.

You can set the default font settings the same way you set Cascading
 Style Sheets (CSS) attributes (for example, "font:3;font-size:4").
 To define multiple font values, use multiple font attributes.

The default unit of measure for dialogHeight
 and dialogWidth in Internet Explorer
 4.0 is the pixel; in Internet Explorer 5 it is the "em". The
 value can be an integer or floating-point number, followed by an absolute
 units designator (cm, mm, in, pt, or pc) or a relative units designator
 (em, ex, or px). For consistent results, specify the dialogHeight
 and dialogWidth in pixels when
 designing modal dialog boxes.

Although a user can manually adjust the height of a dialog box to a
 smaller value - provided the dialog box is resizable - the minimum dialogHeight you can specify is
 100 pixels.

To override center, even though the default for center is yes, you can
 specify either dialogLeft and/or
 dialogTop.

To enable visual styles for your dialog, add the following META tag
 to the <head> section of your HTML file:

```lisp
<META HTTP-EQUIV="MSThemeCompatible" CONTENT="yes">
```

Unlike a modal dialog, where the script code is halted until the dialog
 is dismissed, when a modeless dialog is displayed, the script code will
 continue.

Internet Explorer (IE) 7 is the default rendering mode for embedded
 IE controls (for compatibility reasons). You can use the FEATURE_BROWSER_EMULATION
 registry key to change this if you want. To run in IE11 Standards Mode,
 add the following new value into the registry:

```lisp
[HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE]
```

```lisp
 \Software
```

```lisp
  \Microsoft
```

```lisp
   \Internet
 Explorer
```

```lisp
    \Main
```

```lisp
     \FeatureControl
```

```lisp
      \FEATURE_BROWSER_EMULATION
```

```lisp
Name: "acad.exe"
```

```lisp
Type: REG_DWORD
```

```lisp
Value: 11000 (decimal) or 0x2af8
 (hex)
```

### Example 1

```lisp
Command: (vl-load-com)
```

```lisp
Command: (dos_htmldialog "renamelayer.htm" (getvar
 "clayer") "center:1")
```

```lisp
"Plumbing"
```

```lisp

```

```lisp

```

RenameLayer.htm

```lisp
<HTML id=RenameLayerDialog
 style="width: 22em; height: 12em">
```

```lisp
 <HEAD>
```

```lisp
  <TITLE>Rename
 Layer</TITLE>
```

```lisp
  <SCRIPT LANGUAGE="VBScript">
```

```lisp

```

```lisp
<!--
```

```lisp
Sub OnInitDialog()
```

```lisp
  Dim sArgs
```

```lisp
  sArgs = window.dialogArguments
```

```lisp
  If Not IsNull(sArgs)
 Then
```

```lisp
    txtOldName.value
 = CStr(sArgs(1))
```

```lisp
  End If
```

```lisp
End Sub
```

```lisp

```

```lisp
Sub OnOk()
```

```lisp
  Dim sResult
```

```lisp
  sResult = txtNewName.value
```

```lisp
  window.returnValue
 = sResult
```

```lisp
  window.close
```

```lisp
End Sub
```

```lisp

```

```lisp
Sub OnCancel()
```

```lisp
  window.returnValue
 = ""
```

```lisp
  window.close
```

```lisp
End Sub
```

```lisp
-->
```

```lisp

```

```lisp
</SCRIPT>
```

```lisp
</HEAD>
```

```lisp
 <BODY ONLOAD="OnInitDialog()"
 STYLE="font-family: Arial, sans-serif">
```

```lisp
  <H3>
```

```lisp
   <FONT FACE="Verdana,Arial,Times
 New I2">Enter new layer name</FONT></H3>
```

```lisp
  <P>
```

```lisp
   <TABLE CELLPADDING="1"
 CELLSPACING="2" BORDER="0">
```

```lisp
    <TR>
```

```lisp
     <TD
 VALIGN=CENTER>
```

```lisp
      <P>
```

```lisp
       <FONT
 FACE="Verdana,Arial,Times New I2">Old layer name:</FONT></TD>
```

```lisp
     <TD
 VALIGN=CENTER>
```

```lisp
      <P>
```

```lisp
       <INPUT
 TYPE=TEXT NAME="txtOldName" SIZE="25" MAXLENGTH="256"></TD>
```

```lisp
    </TR>
```

```lisp
    <TR>
```

```lisp
     <TD
 VALIGN=CENTER>
```

```lisp
      <P>
```

```lisp
       <FONT
 FACE="Verdana,Arial,Times New I2">New layer name:</FONT></TD>
```

```lisp
     <TD
 VALIGN=CENTER>
```

```lisp
      <P>
```

```lisp
       <INPUT
 TYPE=TEXT NAME="txtNewName" SIZE="25" MAXLENGTH="256"></TD>
```

```lisp
    </TR>
```

```lisp
    <TR>
```

```lisp
     <TD
 VALIGN=CENTER><DIV ALIGN=RIGHT>
```

```lisp
      <P
 ALIGN=RIGHT>
```

```lisp
       <INPUT
 TYPE=SUBMIT VALUE="OK" ID="cmdOK" CLASS="button"
 ONCLICK="OnOk()" STYLE="width: 5em"></TD>
```

```lisp
     <TD
 VALIGN=CENTER><CENTER>
```

```lisp
      <P
 ALIGN=CENTER>
```

```lisp
       <INPUT
 TYPE=SUBMIT VALUE="Cancel" ID="cmdCancel" CLASS="button"
 ONCLICK="OnCancel()" STYLE="width: 5em"></TD>
```

```lisp
    </TR>
```

```lisp
   </TABLE>
```

```lisp
</P>
```

```lisp
</BODY>
```

```lisp
</HTML>
```

### Example 2

```lisp
Command: (dos_htmldialog "testargs.htm" (list
 1 2 (list "a" "b") (list 3 4.5 6 7.8)))
```

```lisp
nil
```

```lisp

```

```lisp

```

TestArgs.htm

```lisp
<HTML>
```

```lisp
<HEAD>
```

```lisp
<TITLE>DOSLib TestArgs</TITLE>
```

```lisp
</HEAD>
```

```lisp
<BODY>
```

```lisp
<SCRIPT LANGUAGE="VBScript">
```

```lisp
<!--
```

```lisp
Dim args
```

```lisp
args = window.dialogArguments
```

```lisp
Call DumpArguments(args)
```

```lisp
Sub DumpArguments(val)
```

```lisp
  Dim item
```

```lisp
  If IsEmpty(val) Then
```

```lisp
    Call document.writeln("Empty<br>")
```

```lisp
  ElseIf IsNull(val)
 Then
```

```lisp
    Call document.writeln("Null<br>")
```

```lisp
  ElseIf IsArray(val)
 Then
```

```lisp
    document.writeln("*Begin
 Array*<br>")
```

```lisp
    For Each
 item In val
```

```lisp
      Call
 DumpArguments(item)
```

```lisp
    Next
```

```lisp
    document.writeln("*End
 Array*<br>")
```

```lisp
  ElseIf IsObject(val)
 Then
```

```lisp
    Call document.writeln("Object
 = " & TypeName(val) & "<br>")
```

```lisp
  Else
```

```lisp
    Call document.writeln(TypeName(val)
 & " = " & CStr(val) & "<br>")
```

```lisp
  End If
```

```lisp
End Sub
```

```lisp
-->
```

```lisp
</SCRIPT>
```

```lisp
</BODY>
```

```lisp
</HTML>
```

---

## dos_listbox

Displays a sizeable Windows dialog box with a single-selection list
 box.

### Syntax

```lisp
(dos_listbox title
 prompt list
 [default])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list
```

A list of string values.

```lisp
default
```

A string containing a default string value.

### Returns

The item selected from the list if successful.

nil on cancel or on error.

### Example

```lisp
Command: (dos_listbox "Set Current Layer" "Select
 a layer" '("Layer1" "Layer2" "Layer3"))
```

```lisp
"Layer1"
```

---

## dos_msgbox

Creates, displays and operates a Windows message box, or dialog, box.
 The message box contains an application-defined message and title plus
 any combination of predefined icons and push buttons. An optional duration
 allows the message box to be closed automatically.

### Syntax

```lisp
(dos_msgbox text
 title button
 icon [duration])
```

### Parameters

```lisp
text
```

The message to be displayed.

```lisp
title
```

The message box title.

```lisp
button
```

The push button format. The allowable values are as follows:

		0

		Abort,
		 Retry and Ignore

		1

		OK

		2

		OK
		 and Cancel

		3

		Retry
		 and Cancel

		4

		Yes
		 and No

		5

		Yes,
		 No and Cancel

```lisp
icon
```

The icon. The allowable values are as follows:

		0

		Asterisk

		1

		Exclamation

		2

		Hand

		3

		Information

		4

		Question

		5

		Stop

```lisp
duration
```

The duration time in seconds. Note, duration only works with button
 bit values 1, 2, 3 and 5

### Returns

An integer indicating one of the following buttons was pressed:

		0

		Abort

		1

		Cancel

		2

		Ignore

		3

		No

		4

		OK

		5

		Retry

		6

		Yes

nil if not successful or on
 error.

### Example

```lisp
Command: (dos_msgbox "Are you sure?" "Save"
 4 3)
```

```lisp
6
```

```lisp

```

```lisp

```

---

## dos_msgboxchk

Displays a message box that gives the user the option of suppressing
 further occurrences. If the user has already opted to suppress the message
 box, the function does not display a dialog box and instead simply returns
 the default value.

Note  Do not confuse "Do not show this dialog box" with
 "Remember this answer". This function does not provide "Remember
 this answer" functionality. If the user opts to suppress the message
 box again, the function does not preserve which button they clicked. Instead,
 subsequent invocations of this function simply return a developer-provided
 default value.

### Syntax

```lisp
(dos_msgboxchk text
 title button
 icon default
 regkey)
```

### Parameters

```lisp
text
```

The message to be displayed.

```lisp
title
```

The message box title.

```lisp
button
```

The push button format. The allowable values are as follows:

		0

		Abort,
		 Retry and Ignore

		1

		OK

		2

		OK
		 and Cancel

		3

		Retry
		 and Cancel

		4

		Yes
		 and No

		5

		Yes,
		 No and Cancel

```lisp
icon
```

The icon. The allowable values are as follows:

		0

		Asterisk

		1

		Exclamation

		2

		Hand

		3

		Information

		4

		Question

		5

		Stop

```lisp
default
```

The value that the function returns when the user has opted not to have
 the message box displayed again. If the user has not opted to suppress
 the message box, the message box is displayed and the function ignores
 default. Note, default values
 must be either less than -1 or greater than 6.

```lisp
regkey
```

A unique string value to associate with this message box.

### Returns

An integer indicating one of the following buttons was pressed:

		0

		Abort

		1

		Cancel

		2

		Ignore

		3

		No

		4

		OK

		5

		Retry

		6

		Yes

If the user has not opted to suppress the
 message box, the default value is returned.

nil if not successful or on
 error.

### Example

```lisp
Command: (dos_msgboxchk "Are you sure?" "Save"
 4 3 -2 "MyMsgBox")
```

```lisp
6
```

```lisp

```

```lisp

```

```lisp

```

---

## dos_msgboxex

Creates, displays and operates a custom Windows message box, or dialog,
 box. The message box contains an application-defined message and title
 plus user-definable push buttons.

### Syntax

```lisp
(dos_msgboxex text
 title button-list
 icon)
```

### Parameters

```lisp
text
```

The message to be displayed.

```lisp
title
```

The message box title.

```lisp
button-list
```

A list of strings identifying the custom button labels.  For each
 string found in the list, a custom button will be created.  The maximum
 number of buttons allowed is five.  Note, the default button is always
 the first button in the list.

```lisp
icon
```

The icon. The allowable values are as follows:

		0

		Asterisk

		1

		Exclamation

		2

		Hand

		3

		Information

		4

		Question

		5

		Stop

### Returns

An integer indicating the button that was pressed. Note, if the <Esc>
 key is pressed, the index of the last button is returned.

nil if not successful or on
 error.

### Example

```lisp
(setq a "Wouldn't it be nice to have a custom message
 box\n")
```

```lisp
(setq b "function that would accept a list of strings
 that\n")
```

```lisp
(setq c "identify custom button labels?  Thus,
 for instance,\n")
```

```lisp
(setq d "you could present a user with three custom
 buttons.")
```

```lisp
(setq text (strcat a b c d))
```

```lisp
(setq buttons (list "Sometimes" "Never"
 "What?"))
```

```lisp
(dos_msgboxex text "Question of the Day" buttons
 4)
```

```lisp
0
```

---

## dos_multilist

Displays a sizeable Windows dialog box with a multiple-selection list
 box.

### Syntax

```lisp
(dos_multilist title
 prompt list
 [indices])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list
```

A list of string values.

```lisp
indices
```

A zero-based list of indices identifying pre-selected items.

### Returns

A list of string items selected from the list if successful.

nil on cancel or on error.

### Example

```lisp
Command: (dos_multilist "Freeze Layers" "Select
 layers" '("Layer1" "Layer2" "Layer3")
 '(0 2))
```

```lisp
("Layer1" "Layer3")
```

```lisp

```

```lisp

```

---

## dos_orderlist

Displays a sizeable Windows dialog box with an orderable list box. Items
 can be moved by either dragging or by using the top/up/down/bottom buttons.

### Syntax

```lisp
(dos_orderlist title
 prompt list
 [strings])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
list
```

A list of string values.

```lisp
strings
```

If not specified or T, then
 an ordered list of strings is returned. If nil,
 then a list of integers identifying the new sort order is returned

### Returns

A list of string items selected from the list if successful.

nil on cancel or on error.

### Example

```lisp
Command: (setq list1 (list "Layer1" "Layer2"
 "Layer3" "Layer4" "Layer5" "Layer6"))
```

```lisp
("Layer1" "Layer2" "Layer3"
 "Layer4" "Layer5" "Layer6")
```

```lisp

```

```lisp
Command: (dos_orderlist "Layers" "Drag to
 reorder layers" list1)
```

```lisp
("Layer3" "Layer4" "Layer5"
 "Layer6" "Layer1" "Layer2")
```

```lisp

```

```lisp

```

---

## dos_popupmenu

Displays a user-defined, context-style popup menu. The popup menu can
 appear almost anywhere. And, it can be dismissed by either clicking the
 left or right mouse buttons.

### Syntax

```lisp
(dos_popupmenu menu-items
 [item-modes])
```

### Parameters

```lisp
menu-items
```

A list of string representing the menu items. An empty string, or "",
 will create a menu separator item.

```lisp
item-modes
```

A list if numbers identifying the display mode of the corresponding
 menu items. If omitted, all menu items are enabled. Note, although they
 must be specified, display modes are ignored for menu separators. The
 display modes are a follows:

		0

		The
		 menu item is enabled.

		1

		The
		 menu item is disabled.

		2

		The
		 menu item is checked.

		3

		The
		 menu item is disabled and checked.

### Returns

The index value of the menu item that was picked. Note, menu separators
 are not included as part of the returned index value.

nil on cancel or on error.

### Example

```lisp
Command: (setq x '("Line" "" "Circle"
 "Arc"))
```

```lisp
("Line" "" "Circle" "Arc")
```

```lisp

```

```lisp
Command: (setq y '(0 0 1 2))
```

```lisp
(0 0 1 2)
```

```lisp

```

```lisp
Command: (dos_popupmenu x y)
```

```lisp
0
```

```lisp

```

```lisp
Command: (dos_popupmenu x)
```

```lisp
0
```

```lisp

```

```lisp

```

```lisp

```

---

## dos_proplist

Displays a sizeable Windows dialog box with a editable properties list
 box.

### Syntax

```lisp
(dos_proplist title
 prompt assoclist)
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
prompt
```

A string containing the dialog box prompt.

```lisp
assoclist
```

An association list of string descriptions and their values.

### Returns

The association list with the state values updated to reflect the changed
 made by the user if successful.

nil on cancel or on error.

### Example

```lisp
Command: (setq x '(("Title" . "Floorplan")
 ("Project" . "Project A")))
```

```lisp
(("Title" . "Floorplan") ("Project"
 . "Project A"))
```

```lisp

```

```lisp
Command: (dos_proplist "Drawing Properties" "Modify
 Properties" x)
```

```lisp
(("Title" . "Floorplan") ("Project"
 . "Project B"))
```

```lisp

```

```lisp

```

---

## dos_splash

Displays a multi-threaded Windows bitmap splash screen.

### Syntax

```lisp
(dos_splash filename
 duration [T])
```

### Parameters

```lisp
filename
```

The filename of the bitmap to display. The allowable file types are
 as follows:

		BMP

		Windows
		 Bitmap

		JPG

		JFIF
		 Compliant

		GIF

		Compuserve
		 Graphics Interchange

		PNG

		Portable
		 Network Graphics

```lisp

```

```lisp
duration
```

The duration time in seconds.

```lisp
T
```

If specified, the user can dismiss the splash screen by pressing a key
 or clicking the mouse.

### Returns

nil if successful or on error

### Examples

```lisp
Command: (dos_splash "mylogo.bmp" 10)
```

```lisp
nil
```

```lisp

```

---

## dos_traywnd

Displays a popup tray window similar to the MSN Messenger style notification
 window.

### Syntax

```lisp
(dos_traywnd title text
 width height [operation
 [duration]])
```

### Parameters

```lisp
title
```

The title of the popup window.

```lisp
text
```

The popup window text.

```lisp
width
```

The width of the popup window in pixels.

```lisp
height
```

The height of the popup window in pixels.

```lisp
operation
```

The operation to run if the user clicks
 on either the title or the window text.

```lisp
duration
```

The duration time in milliseconds.

### Returns

nil if successful or on error

### Examples

```lisp
Command: (dos_traywnd "DOSLib" "To check
 for updates\nclick here!" 200 100 "www.mcneel.com")
```

```lisp
nil
```

```lisp

```

```lisp

```

---

## dos_waitcursor

Toggles the state of the Windows hourglass cursor.

### Syntax

```lisp
(dos_waitcursor [T])
```

### Parameters

```lisp
T
```

If specified, the hourglass cursor is turned on. Otherwise, it is turned off.

### Returns

T if the hourglass was turned on.

nil if the hourglass is turned off.

### Example

```lisp
Command: (dos_waitcursor t)
```

```lisp
T
```

```lisp

```

```lisp
Command: (dos_waitcursor)
```

```lisp
nil
```

---



