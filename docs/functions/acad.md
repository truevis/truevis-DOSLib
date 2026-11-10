# DOSLib: Acad functions

[Back to index](README.md)

## dos_acadmem

Returns AutoCAD memory statistics

### Syntax

```lisp
(dos_acadmem)
```

### Parameters

n/a

### Returns

A list containing AutoCAD memory statistics if successful. The list elements are as follows:

		WorkingSetSize

		Current
		 working set size, in bytes.

		PeakWorkingSetSize

		Peak
		 working set size, in bytes.

		PageFaultCount

		Number
		 of page faults.

		PagefileUsage

		Current
		 space allocated for the pagefile, in bytes. Those pages may or
		 may not be in memory.

		PeakPagefileUsage

		Peak
		 space allocated for the pagefile, in bytes.

		QuotaPagedPoolUsage

		Current
		 paged pool usage, in bytes.

		QuotaPeakPagedPoolUsage

		Peak
		 paged pool usage, in bytes.

		QuotaNonPagedPoolUsage

		Current
		 nonpaged pool usage, in bytes.

		QuotaPeakNonPagedPoolUsage

		Peak
		 nonpaged pool usage, in bytes.

nil on error.

### Example

```lisp
Command: (dos_acadmem)

(16003072 73891840 43562 57044992 58130432 469140 481864 46140 49708)
```

---

## dos_acadname

Returns the product name of the running AutoCAD. Useful in determine whether or not you are running a "vertical" version of AutoCAD.

### Syntax

```lisp
(dos_acadname)
```

### Parameters

n/a

### Returns

The AutoCAD product name.

nil on error.

### Example

```lisp
Command: (dos_acadname)

"AutoCAD 2010"
```

---

## dos_acitorgb

Converts an AutoCAD Color Index (ACI) value to a Red-Green-Blue (RGB)
 color value.

### Syntax

```lisp
(dos_acitorgb aci-value)
```

### Parameters

```lisp
aci-value
```

An integer between 1 and 255 that represents an ACI color value.

### Returns

A list of three integers representing an RGB color value if successful.

nil on error.z

### Example

```lisp
Command: (dos_acitorgb 1)

(255 0 0)

Command: (dos_acitorgb 128)

(0 76 57)
```

---

## dos_arxlist

Returns a list of loaded ARX applications.

### Syntax

```lisp
(dos_arxlist [T])
```

### Parameters

```lisp
T
```

If specified, fully qualified paths are returned. Otherwise, just the filenames are returned.

### Returns

A list of string identifying the loaded ARX applications if successful.

nil on error.

### Example

```lisp
Command: (dos_arxlist)

("acapp.arx" "acdblclkedit.arx" "acdblclkeditpe.arx" "acdim.arx" "acdwgrecovery.arx" "acdxnotify.arx" "aceplotx.arx" "acetlodr.arx" "acetutil.arx" "achapi16.dbx" "achlnkui.arx" "acidropmgr.arx" "aclayerp.arx" "acmgd.dll" "acobjclassimp.arx" "acocschemautil.arx" "acopm.arx" "acopmext.arx" "acpexctl.arx" "acpi.arx" "acpltstamp.arx" "acprevinput.arx" "acsign.arx" "acsmdwgmine.arx" "acsmnav.arx" "acsmpublishutils.arx" "acspacetrans.arx" "acstd.arx" "actaskbar.arx" "actp.arx" "doslib16.arx" "fscreen.arx" "movebak.arx" "oleaprot.arx" "vl.arx" "whohas.arx" "wscommcntraccon.arx")
```

---

## dos_cleardbmod

Clears the DBMOD, or drawing modification status, system variable. Warning, after clearing this variable, will not be prompted to save the drawing when closing it or closing AutoCAD.

### Syntax

```lisp
(dos_cleardbmod [T])
```

### Parameters

```lisp
T
```

If specified, the DBMOD system variable for all open drawings will be cleared. Otherwise, just the DBMOD system variable from the current drawing will be cleared.

### Returns

nil if successful.

### Example

```lisp
Command: (dos_cleardbmod)

nil
```

---

## dos_closeall

Closes all open AutoCAD drawing files.

### Syntax

```lisp
(dos_closeall)
```

### Parameters

n/a

### Returns

n/a

### Example

```lisp
Command: (dos_closeall)
```

---

## dos_cmdline

Returns text from AutoCAD's command-line or history window.

### Syntax

```lisp
(dos_cmdline [T])
```

### Parameters

```lisp
T
```

If specified, text from AutoCAD's history window will be returned. Otherwise, text from AutoCAD's command-line window will be returned.

### Returns

A string of text from either the command-line window or the history windows if successful.

nil on error.

### Example

```lisp
Command: (dos_cmdline)

"Command: (dos_cmdline)"

Command: (dos_cmdline t)

"Regenerating model.DOSLib Version 6.0.0 (Jan 30 2002)Copyright © 1992-2002, Robert McNeel & AssociatesAutoCAD Express Tools Copyright © 2000 Autodesk, Inc.AutoCAD menu utilities loaded.Command: (dos_cmdline)\"Command: (dos_cmdline)\"Command: (dos_cmdline t)"
```

---

## dos_curvearea

Returns the area bound by a closed curve entity.

### Syntax

```lisp
(dos_curvearea entity)
```

### Parameters

```lisp
entity
```

The entity name of a closed curve object.

### Returns

The area of the closed curve if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_curvearea (car (entsel "\nSelect a closed curve:")))

6.43372
```

---

## dos_custominfo

Returns or modifies AutoCAD's custom drawing summary information, or DWGPROPS.  Note, this function just manipulates the custom information fields. If you want to manipulate summary fields, use dos_summaryinfo.

### Syntax

```lisp
(dos_custominfo)
```

```lisp
(dos_custominfo nil)
```

```lisp
(dos_custominfo field_name [field_value])
```

### Parameters

```lisp
nil
```

Clears all custom drawing summary information.

```lisp
field_name
```

The name of the custom field to retrieve.

```lisp
field_value
```

The new string value, if specified.

Note, if no argument is specified, all of the custom drawing summary information is returned in an association list. Also, to delete a field, specified a field value of either "" or nil.

### Returns

If no arguments are specified, then all of the custom  drawing summary information is returned in an association list.

If nil is specified, then all of the drawing custom summary information is cleared and T is returned if successful.

If a valid field name is specified, then the field value is returned if successful.

If a valid field name and a field value is specified, then T returned if successful.

nil on error.

### Example

```lisp
Command: (dos_custominfo)

nil

Command: (dos_custominfo "Field1" "Value1")

T

Command: (dos_custominfo "Field2" "Value2")

T

Command: (dos_custominfo)

(("Field1" . "Value1") ("Field2" . "Value2"))

Command: (dos_custominfo "Field2" "Value10")

T

Command: (dos_custominfo)

(("Field1" . "Value1") ("Field2" . "Value10"))

Command: (dos_custominfo "Field2" "")

T

Command: (dos_custominfo)

(("Field1" . "Value1"))
```

---

## dos_dwgpreview

Displays a list of drawings and their thumbnail preview images. The function is useful for selecting drawings to open or blocks to insert.

### Syntax

```lisp
(dos_dwgpreview title path [T])
```

```lisp
(dos_dwgpreview title path-list [T])
```

### Parameters

```lisp
title
```

A string containing the dialog box title.

```lisp
path
```

A string identifying an existing directory. If nil is specified, the current directory is used.

```lisp
path-list
```

A list containing fully qualified drawing file path strings.

```lisp
T
```

Toggles the background color of the preview image from the default color of black to white.

### Returns

A qualified path to the selected file.

nil on cancel or on error.

### Examples

```lisp
Command: (dos_dwgpreview "Preview a drawing"
 "C:\\Program Files\\AutoCAD 2010\\Sample")
```

```lisp
"C:\\Program Files\\AutoCAD 2010\\Sample\\A-01.dwg"
```

---

## dos_dwgver

Returns the version of an AutoCAD drawing file.

### Syntax

```lisp
(dos_dwgver filename)
```

### Parameters

```lisp
filename
```

The source filename.

### Returns

A string identifying the drawing file version if successful.

nil on error.

### Example

```lisp
Command: (dos_dwgver "c:\\Program Files\\AutoCAD 2010\\drawing1.dwg")

"AutoCAD 2010"
```

---

## dos_extractpreview

Extracts the thumbnail image from the active document to a bitmap file.

### Syntax

```lisp
(dos_extractpreview filename)
```

### Parameters

```lisp
filename
```

The name of the bitmap file to create. The allowable file types are as follows:

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

### Returns

A string identifying the created bitmap file if successful.

nil on error.

### Example

```lisp
Command: (dos_extractpreview "C:\\test.bmp")

"C:\\test.bmp"
```

---

## dos_hatcharea

Returns the area of a hatch object.

### Syntax

```lisp
(dos_hatcharea entity)
```

### Parameters

```lisp
entity
```

The entity name of a hatch object.

### Returns

The area of the hatch if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_hatcharea (car (entsel "\nSelect a hatch:")))

346.43372
```

---

## dos_hideobjects

Hides one or more AutoCAD entities. Hidden entities can be shown, or unhidden by using dos_showobjects or by closing and reopening the document..

### Syntax

```lisp
(dos_hideobjects entity-name)
```

```lisp
(dos_hideobjects selection-set)
```

### Parameters

```lisp
entity-name
```

The name of an entity to hide.

```lisp
selection-set
```

A selection set of entities to hide.

### Returns

The number of entities hidden if successful.

nil on error.

### Example

```lisp
Command: (dos_hideobjects ss)

3
```

---

## dos_hlstorgb

Converts a Hue-Luminance-Saturation (HLS) color value to Red-Green-Blue (RGB) format.

### Syntax

```lisp
(dos_hlstorgb hue luminance saturation)
```

### Parameters

```lisp
hue
```

The hue component of an HLS color value.

```lisp
luminance
```

The luminance component of an HLS color value.

```lisp
saturation
```

The saturation component of an HLS color value.

### Returns

A list containing the red-green-blue values if successful.

nil on error.

### Example

```lisp
Command: (dos_hlstorgb 160 120 240)

(0 0 255)
```

---

## dos_imagelist

Returns a list to all raster images in the active document.

### Syntax

```lisp
(dos_imagelist)
```

### Parameters

n/a

### Returns

A list of string identifying the raster images in the active document if successful.

nil on error.

### Example

```lisp
Command: (dos_imagelist)

("C:\\Users\\dale\\Pictures\\image1.jpg" "C:\\Users\\dale\\Pictures\\image2.jpg")
```

---

## dos_isbreak

Queries AutoCAD's console break handler to verify that the escape key has been pressed. Used in conjunction with the vl-catch-all-apply

 function, dos_isbreak is useful in breaking out of tight loops.

### Syntax

```lisp
(dos_isbreak)
```

### Parameters

n/a

### Returns

A list of drawing file names if successful.

nil if not successful or on error.

### Example

```lisp
(defun c:breaktest (/ msg cnt err) (setq msg "User break!" cnt -1 err (vl-catch-all-apply 'dos_isbreak) ) (while (/= err T) (if (> 10000000000 (setq cnt (1+ cnt))) (setq err (vl-catch-all-apply 'dos_isbreak)) (setq msg "Maximum count reached." err T ) ) (princ cnt) ) (if (vl-catch-all-error-p err) (princ (vl-catch-all-error-msg err)) (princ (strcat "\nTerminated loop: " msg)) ) (princ) )
```

---

## dos_isinsidecurve

Verifies that a point lies inside of a closed, planar curve entity.

### Syntax

```lisp
(dos_isinsidecurve curve point)
```

### Parameters

```lisp
curve
```

The entity name of a closed, planar curve object.

```lisp
point
```

The point to test.

### Returns

T if successful.

nil if not successful or on error.

### Example

```lisp
Command: (setq ent (car (entsel "\nSelect closed curve:")))

<Entity name: 7ef8d048>

Command: (setq pt (getpoint "\nPick a test point:"))

(31.6951 25.9553 0.0)

Command: (dos_isinsidecurve ent pt)

T
```

---

## dos_istextscr

Verifies that the AutoCAD text screen is open or visible.  If the text screen is not open, or if it is minimized, then the function will return nil.

### Syntax

```lisp
(dos_istextscr )
```

### Parameters

n/a

### Returns

T if the text screen is open.

nil if the text screen is not open.

### Example

```lisp
Command: (dos_istextscr)

nil

Command: (textscr)

Command: (dos_istextscr)

T
```

---

## dos_isvlide

Verifies that the Visual LISP IDE (editor) is open.

### Syntax

```lisp
(dos_isvlide)
```

### Parameters

n/a

### Returns

T if the IDE is open.

nil if the IDE is not open.

### Example

```lisp
Command: (dos_isvlide)

nil

Command: VLIDE

Command: (dos_isvlide)

T
```

---

## dos_layerlistbox

Displays a list of AutoCAD layers in a sizeable Windows dialog box.

### Syntax

```lisp
(dos_layerlistbox title prompt [bits])
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
bits
```

A bit-coded integer identifying the desired file attributes to set.
 Specify more than one file attribute by adding the following bit values:

		0

		Show
		 all layers (default).

		1

		Hide
		 on layers.

		2

		Hide
		 off layers.

		4

		Hide
		 thawed layers.

		8

		Hide
		 frozen layers.

		16

		Hide
		 unlocked layers.

		32

		Hide
		 locked layers.

		64

		Hide
		 standard layers.

		128

		Hide
		 xref layers.

		256

		Allow
		 multiple selection.

### Returns

The layer selected from the list if successful.

If the "allow multiple selection" bit is set, a list of layers selected from the list if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_layerlistbox "AutoCAD Layers" "Select
 one or more layers" 256)

("TB_BORDER" "TB_CORNERS" "TB_INFORMATION")
```

---

## dos_linetypebox

Displays AutoCAD's linetype selection dialog box.

### Syntax

```lisp
( dos_linetypebox [default [ T]])
```

### Parameters

```lisp
default
```

The name of the default linetype.

```lisp
T
```

If specified, the " ByBlock" and " ByLayer" linetypes

 will be displayed.

### Returns

The linetype selected from the list if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_linetypebox "Continuous")

"HIDDEN"
```

---

## dos_lisplist

Returns a list of loaded AutoLISP/Visual LISP files.

### Syntax

```lisp
(dos_lisplist [T])
```

### Parameters

```lisp
T
```

If specified, fully qualified paths are returned. Otherwise, just the filenames are returned.

### Returns

A list of string identifying the loaded LISP files if successful.

nil on error.

### Example

```lisp
Command: (dos_lisplist)

("acetutil.fas" "acetauto.LSP" "acettest.fas" "dwfout.lsp" "acad2000.FAS" "acad2000doc.FAS" "acad.mnl" "acetmain.mnl")
```

---

## dos_massprops

Returns the mass properties of a 3-D solid entity.

### Syntax

(dos_massprops entity)

### Parameters

entity

 The entity name of a 3-D solid object.

### Returns

A list of strings describing the file's details if successful. The information returned is as follows:

		volume

		The
		 volume of the solid.

		centroid

		A
		 list containing the centroid of the solid.

		momInertia

		A
		 list containing the X, Y, and Z moments of inertia of the solid.

		prodInertia

		A
		 list containing the X, Y, and Z products of inertia of the solid.

		prinMoments

		A
		 list containing the X, Y, and Z principal moments of the solid.

		prinAxes

		A
		 list containing the X, Y, and Z principal axes of the solid.

		radiiGyration

		A
		 list containing the X, Y, and Z radii of gyration of the solid.

		extents

		A
		 list containing the extents (bounding box) of the solid.

nil if not successful or on error.

### Example

```lisp
Command: (dos_massprops (car (entsel "\nSelect a solid:")))

(29.7069 (8.38222 3.97879 2.0) (640.888 2273.47 2597.49) (990.758 236.395 498.02) (51.7765 67.3905 39.9486) ((1.0 0.0 0.0) (0.0 1.0 0.0) (0.0 0.0 1.0)) (4.64475 8.74815 9.35079) ((6.70725 2.87031 0.0) (10.0572 5.08728 4.0)))
```

---

## dos_olelist

Returns a list to all linked OLE objects.

### Syntax

```lisp
(dos_olelist [space])
```

### Parameters

```lisp
space
```

If specified, the work space to query, where 0 = both, 1 = model space, and 2 = paper space. Otherwise, both model space and paper space are queried.

### Returns

A list of string identifying the OLE objects in the specified space if successful.

nil on error.

### Example

```lisp
Command: (dos_olelist)

("C:\\Users\\dale\\Documents\\Book1.xls")
```

---

## dos_plinecentroid

Returns the centroid of a  closed, planar polyline entity.

### Syntax

```lisp
( dos_plinecentroid entity)
```

### Parameters

```lisp
entity
```

The entity name of a closed, planar curve object.

### Returns

The centroid if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_plinecentroid (car (entsel "\nSelect a closed curve:")))

(35.8886 26.6375 0.0)
```

---

## dos_plinewinding

Determines whether a closed polyline winds clockwise or counterclockwise.
 Note that the test does not determine whether the polyline is self-intersecting.

### Syntax

```lisp
(dos_plinewinding entity)
```

### Parameters

```lisp
entity
```

The entity name of a closed polyline.

### Returns

> 0 If the polyline winds to the left.

< 0 If the polyline winds to the right.

0 If unable to determine the winding.

nil on error.

### Example

```lisp
Command: (dos_plinewinding (car (entsel "\nSelect
 a closed polyline:")))

-1
```

---

## dos_progbar

Manipulates the AutoCAD Status Bar Progress Meter. This function is called once to initialize the progress meter. Then, it is called any number of times to move the progress meter in an absolute or relative manner. Finally, it is called with no arguments to reset the status bar.

### Syntax

```lisp
(dos_progbar message maxvalue)
```

```lisp
(dos_progbar abs/-rel)
```

```lisp
(dos_progbar)
```

### Parameters

```lisp
message
```

A string containing a message.

```lisp
maxvalue
```

An integer representing the maximum range value (between 0 and maxvalue) of the progress bar.

```lisp
abs/-rel
```

An absolute position to move the progress meter, or a relative position (denoted with a negative sign) to move the progress meter.

### Returns

T if successful

nil if not successful or on error.

### Examples

```lisp
Command: (dos_progbar "Wait..." 10)
```

```lisp
T
```

```lisp
Command: (dos_progbar -1)
```

```lisp
T
```

```lisp
Command: (dos_progbar)
```

```lisp
nil
```

---

## dos_proxyclean

Removes all of the of proxy objects from the current drawing. This is done by iterating through the entire drawing, and swapping all proxy entities for anonymous blocks. The blocks contain the equivalent geometry of the proxy entities.

### Syntax

```lisp
(dos_proxyclean)
```

### Parameters

n/a

### Returns

The number of proxies that were cleaned.

nil on error.

### Example

```lisp
Command: (dos_proxyclean)

2
```

---

## dos_proxycount

Returns the number of proxy objects in the current drawing.

### Syntax

```lisp
(dos_proxycount)
```

### Parameters

n/a

### Returns

The number of proxies in the drawing.

nil on error.

### Example

```lisp
Command: (dos_proxycount)

2
```

---

## dos_purgexdata

Removes all extended entity data (xdata) that is attached to an entity regardless of the APPNAME.

### Syntax

```lisp
(dos_purgexdata entity)
```

### Parameters

```lisp
entity
```

The name of the entity to modify.

### Returns

T if successful.

nil on error.

### Example

```lisp
Command: (dos_purgexdata (car (entsel "\nSelect object:")))

T
```

---

## dos_rgbtoaci

Converts a Red-Green-Blue (RGB) color value to the closest AutoCAD Color Index (ACI) value.

### Syntax

```lisp
(dos_rgbtoaci red green blue)
```

```lisp
(dos_rgbtoaci rgb)
```

### Parameters

```lisp
red
```

The red component of an RGB color value.

```lisp
green
```

The green component of an RGB color value.

```lisp
blue
```

The blue component of an RGB color value.

```lisp
rgb
```

An RGB color value.

### Returns

An ACI color value if successful.

nil on error.

### Example

```lisp
Command: (dos_rgbtoaci 0 0 255)

5

Command: (dos_rgbtoaci 16711680)

5
```

---

## dos_rgbtogray

Converts a Red-Green-Blue (RGB) color value to an RGB grayscale value.

### Syntax

```lisp
(dos_rgbtogray red green blue)
```

```lisp
(dos_rgbtogray rgb)
```

### Parameters

```lisp
red
```

The red component of an RGB color value.

```lisp
green
```

The green component of an RGB color value.

```lisp
blue
```

The blue component of an RGB color value.

```lisp
rgb
```

An RGB color value.

### Returns

A list containing the grayscale red-green-blue values if successful.

nil on error.

### Example

```lisp
Command: (dos_rgbtogray 255 0 255)

(104 104 104)
```

---

## dos_rgbtohls

Converts a Red-Green-Blue (RGB) color value to Hue-Luminance-Saturation (HLS) format.

### Syntax

```lisp
(dos_rgbtohls red green blue)
```

```lisp
(dos_rgbtohls rgb)
```

### Parameters

```lisp
red
```

The red component of an RGB color value.

```lisp
green
```

The green component of an RGB color value.

```lisp
blue
```

The blue component of an RGB color value.

```lisp
rgb
```

An RGB color value.

### Returns

A list containing the hue-luminance-saturation values if successful.

nil on error.

### Example

```lisp
Command: (dos_rgbtohls 0 0 255)

(160 120 240)

Command: (dos_rgbtohls 16711680)

(160 120 240)
```

---

## dos_saveall

Saves all open AutoCAD drawing files.

### Syntax

```lisp
(dos_saveall)
```

### Parameters

n/a

### Returns

nil if successful or on error.

### Example

```lisp
Command: (dos_saveall)
```

---

## dos_show

Controls the display of the AutoCAD window.

### Syntax

```lisp
(dos_show method)
```

### Parameters

```lisp
method
```

The display method. The allowable values are as follows:

0

Maximize Window

1

Minimize Window

2

Restore Window

### Returns

nil if successful on error.

### Example

```lisp
Command: (dos_show 0)

nil
```

---

## dos_showobjects

Shows, or unhides, one or more hidden AutoCAD entities. You can hide entities by using dos_hideobjects.

### Syntax

```lisp
(dos_showobjects entity-name)
```

```lisp
(dos_showobjects selection-set)
```

```lisp
(dos_showobjects)
```

### Parameters

```lisp
entity-name
```

The name of an entity to show.

```lisp
selection-set
```

A selection set of entities to show.

Note, if no argument is specified, all hidden entities will be shown.

### Returns

The number of entities shown if successful.

nil on error.

### Example

```lisp
Command: (dos_showobjects ss)

3
```

---

## dos_slblist

Lists the names of the slides in an AutoCAD slide library file (.SLB).

### Syntax

```lisp
(dos_slblist filename [sort])
```

### Parameters

```lisp
filename
```

The slide library filename.

```lisp
sort
```

If not specified, the slide names will be returned in the order found in the slide library. If T, then

 the names will be sorted in ascending order. If nil, the names will be sorted in descending order.

### Returns

A list of strings identifying the names of the slides in the slide library if successful.

nil on error.

### Example

```lisp
Command: (dos_slblist acad.slb)

("ZIGZAG" "WEDGEPIC" "WEDGE" "VPORT-4R" "VPORT-4L" "VPORT-4" "VPORT-3V" "VPORT-3R" "VPORT-3L" "VPORT-3H" "VPORT-3B" "VPORT-3A" "VPORT-2V" "VPORT-2H" "VPORT-1" "VP-UR" "VP-UL" "VP-U" "VP-RIGHT" "VP-PLAN" "VP-LR" "VP-LO" "VP-LL" "VP-LEFT" "U-WORLD" "U-TOP" "U-RIGHT" "U-PREV" "U-LEFT" "U-FRONT" "U-CVIEW" "U-BOTTOM" "U-BACK" "TRIANG" "TRANS" "TORUS" "TORPIC" "SWAMP" "STEEL" "STARS" "SQUARE" "SPHERPIC" "SPHERE" "SOLID" "SACNCR" "PYRAMID" "PT100" "PT99" "PT98" "PT97" "PT96" "PT68" "PT67" "PT66" "PT65" "PT64" "PT36" "PT35" "PT34" "PT33" "PT32" "PT4" "PT3" "PT2" "PT1" "PT0" "PM-QUAD" "PM-CUBIC" "PM-BEZR" "PLASTI" "PLAST" "PL-QUAD" "PL-CUBIC" "NET3" "NET" "MUDST" "MESH" "MEDIT_WA" "MEDIT_OT" "MEDIT_OC" "MEDIT_MT" "MEDIT_MC" "MEDIT_DV" "MEDIT_CT" "MEDIT_CS" "MEDIT_CJ" "MEDIT_CC" "MEDIT_CA" "MEDIT_AV" "LINE" "INSUL" "HOUND" "HONEY" "HEX" "H-OUTER" "H-NORMAL" "H-IGNORE" "GRATE" "GRASS" "GDTU" "GDTT" "GDTS" "GDTR" "GDTP" "GDTN" "GDTM" "GDTL" "GDTK" "GDTJ" "GDTI" "GDTH" "GDTG" "GDTF" "GDTE" "GDTD" "GDTC" "GDTB" "GDTA" "FLEX" "ESCHER" "EARTH" "DOTS" "DOME" "DOLMIT" "DISH" "DDVP3D" "DASH" "CYLPIC" "CROSS" "CORK" "CONEPIC" "CONE" "CLAY" "CHROMA" "BRSTONE" "BRICK" "BRASS" "BOXPIC" "BOX3D" "BOX" "AR-SAND" "AR-RSHKE" "AR-RROOF" "AR-PARQ1" "AR-HBONE" "AR-CONC" "AR-BRSTD" "AR-BRELM" "AR-B88" "AR-B816C" "AR-B816" "ANSI38" "ANSI37" "ANSI36" "ANSI35" "ANSI34" "ANSI33" "ANSI32" "ANSI31" "ANGLE" "AILOGO" "15W100" "14W100" "13W100" "12W100" "11W100" "10W100" "09W100" "08W100" "07W100" "06W100" "05W100" "04W100" "03W100" "02W100" "%%BLANK" "GLASS" "WOOD" "GROUND")
```

---

## dos_summaryinfo

Returns or modifies AutoCAD's drawing summary information, or DWGPROPS.  Note, this function just manipulates the summary information fields. If you want to manipulate

 custom fields, use dos_custominfo.

### Syntax

```lisp
(dos_summaryinfo)
```

```lisp
(dos_summaryinfo nil)
```

```lisp
(dos_summaryinfo field_id [field_value])
```

### Parameters

```lisp
nil
```

Clears all drawing summary information.

```lisp
field_id
```

The identifier of the field to retrieve. The possible field identifiers are as follows:

		0

		Title

		1

		Subject

		2

		Author

		3

		Keywords

		4

		Comments

		5

		Last
		 Saved By

		6

		Revision
		 Number

		7

		Hyperlink
		 Base

```lisp
field_value
```

The new string value, if specified.

Note, if no argument is specified, all of the drawing summary information is returned in an association list. Also, to clear a field, specified

 a field value of either "" or nil.

### Returns

If no arguments are specified, then all of the drawing summary information is returned in an association list.

If nil is specified, then all of the drawing summary information is cleared and T

 is returned if successful.

If a valid field identifier is specified, then the field value is returned if successful.

If a valid field identifier and a field value is specified, then T returned if successful.

nil on error.

### Example

```lisp
Command: (dos_summaryinfo)

((0 . "3rd Floor Plumbing") (1 . "McNeel Project") (2 . "Dale Fugier") (3 . "McNeel, Plumbing") (4 . "In progress") (5 . "Dale") (6 . "") (7 . "www.mcneel.com"))

Command: (dos_summaryinfo 0)

"3rd Floor Plumbing"

Command: (dos_summaryinfo 0 "2nd Floor Plumbing")

T

Command: (dos_summaryinfo 2 "")

T

Command: (dos_summaryinfo)

((0 . "2nd Floor Plumbing") (1 . "McNeel Project") (2 . "") (3 . "McNeel, Plumbing") (4 . "In progress") (5 . "Dale") (6 . "") (7 . "www.mcneel.com"))
```

---

## dos_xreflist

Returns a list of externally referenced drawing files.

### Syntax

```lisp
(dos_xreflist [filename])
```

### Parameters

```lisp
filename
```

An AutoCAD drawing filename. If not specified, the externally referenced drawing files within the current drawing are returned.

### Returns

A list of drawing file names if successful.

nil if not successful or on error.

### Example

```lisp
Command: (dos_xreflist)

("C:\\Program Files\\AutoCAD 2010\\Drawing1.dwg" "C:\\Program Files\\AutoCAD 2010\\Drawing2.dwg")

Command: (dos_xreflist "C:\\Program Files\\AutoCAD
 2010\\Sample\\1st floor.dwg")

("1st floor plan.dwg" "1st floor architectural.dwg" "1st floor electrical.dwg" "1st floor lighting.dwg")
```

---

