# DOSLib: Config functions

[Back to index](README.md)

## dos_getini

Returns a string from the specified section in the Windows-style initialization (.INI) file. The initialization file must have the following form:

```lisp
[section]
```

```lisp
entry=string
```

```lisp
...
```

### Syntax

```lisp
(dos_getini section entry filename [default])
```

### Parameters

```lisp
section
```

The section containing the entry.

```lisp
entry
```

The entry whose associated string is to be returned.

```lisp
filename
```

The filename of the initialization file.

```lisp
default
```

A default return value. If entry is not found in the initialization file, default is returned.

Note, parameters are not case sensitive, so section and entry may be in any combination of uppercase and lowercase characters.

### Returns

If section is nil, a list of section names is returned.

If entry is nil, a list of entries for the specified section is returned.

If entry is not found, default is returned.

Otherwise, a string associated with entry is returned.

nil on error.

### Examples

```lisp
Command: (dos_getini nil
nil "C:\\Windows\\win.ini")
```

```lisp
("AeDebug" "Clock" "Colors" "Compatibility" "Console" "Cursors" "DeskTop" "Devices" "Embedding" "Extensions" "Fonts" "FontSubstitutes" "GRE_Initialize" "Intl" "IOProcs" "MCI Extensions" "ModuleCompatibility" "MSCharMap" "Net_Files" "NWCS" "Ports" "PrinterPorts" "Sounds" "TrueType" "Twain" "Windows Help" "Winlogon" "Network" "Windows" "fonts" "extensions" "mci extensions" "files" "Mail" "MCI Extensions.BAK" "MSUCE" "SciCalc" "WS_FTP" "CKSN")
```

```lisp
Command: (dos_getini "Mail" nil "C:\\Windows\\win.ini")
```

```lisp
("MAPI" "CMC" "CMCDLLNAME" "CMCDLLNAME32" "MAPIX" "MAPIXVER" "OLEMessaging")
```

```lisp
Command: (dos_getini "Mail" "CMCDLLNAME32" "C:\\Windows\\win.ini")
```

```lisp
"mapi32.dll"
```

---

## dos_regaddkey

Adds a new key to the Windows Registry. This function creates all the keys in the specified path, if necessary.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regaddkey hive key)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key to add.

### Returns

T if successful.

nil on error.

### Examples

```lisp
(dos_regaddkey "HKEY_CURRENT_USER" "Software\\MyCompany\\MyProduct")
```

```lisp
T
```

---

## dos_regdel

Note, this function is deprecated. User either dos_regdelkey or dos_regdelval.

Removes a value from a key or an existing subkey from a key in the Windows Registry. This function will also remove any subkeys.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regdel key [name])
```

### Parameters

```lisp
key
```

The registry key. If a name is not specified, then key and any subkeys will be removed.

```lisp
name
```

The name of the value to remove.

### Returns

T if successful.

nil on error.

### Examples

```lisp
Command: (dos_regdel "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem")
```

```lisp
T
```

```lisp
Command: (dos_regdel "HKEY_CURRENT_USER\\Software\\MyApp")
```

```lisp
T
```

---

## dos_regdelkey

Removes an existing subkey from a key in the Windows Registry. This function will also remove any subkeys.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regaddkey hive key subkey)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
subkey
```

The subkey to remove.

### Returns

T if successful.

nil on error.

### Examples

```lisp
Command: (dos_regdelkey "HKEY_CURRENT_USER" "Software\\MyCompany" "MyProduct")
```

```lisp
T
```

---

## dos_regdelval

Removes a value from a key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regdelval hive key name)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to remove.

### Returns

T if successful.

nil on error.

### Examples

```lisp
(dos_regdelval "HKEY_CURRENT_USER" "Software\\MyCompany\\MyProduct" "Name")
```

```lisp
T
```

---

## dos_regenumkeys

Enumerates the subkeys in a specified key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regenumkey hive key)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key to enumerate.

### Returns

A list of subkeys if successful.

nil on error.

### Examples

```lisp
(dos_regenumkeys "HKEY_CURRENT_USER" "")
```

```lisp
("AppEvents" "Console" "Control Panel" "Environment" "Identities" "Keyboard Layout" "Network" "Printers" "Software" "SYSTEM" "UNICODE Program Groups" "Windows 3.1 Migration Status" "SessionInformation" "Volatile Environment")
```

```lisp
Command: (dos_regenumkeys "HKEY_CURRENT_USER" "Software\\Autodesk")
```

```lisp
("ACPROJECT" "AutoCAD" "Autodesk Digital Signatures" "DWFWriter" "Express Viewer" "FTPConnect" "ObjectARX AppWizard" "ObjectDBX")
```

```lisp
Command: (dos_regenumkeys "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD")
```

```lisp
("R16.2" "R17.0")
```

---

## dos_regenumnames

Enumerates the value names in a specified key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regenumnames hive key)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key to enumerate.

### Returns

A list of value names if successful.

nil on error.

### Examples

```lisp
Command: (dos_regenumnames "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD\\R16.2")
```

```lisp
("CurVer")
```

```lisp
Command: (dos_regenumnames "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD\\R16.2\\ACAD-4001:409")
```

```lisp
("LocalRootFolder" "RoamableRootFolder" "" "NFWFile" "LaunchNFW" "AutoMigrate")
```

---

## dos_regget

Note, this function is deprecated. User either dos_reggetint or dos_reggetstr.

Retrieves a string value or a list of value names from the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regget key [name])
```

### Parameters

```lisp
key
```

The registry key. If a name is not specified, a list containing the names of all values found in key are returned.

```lisp
name
```

The name of the value to query.

### Returns

If a name is not specified, then a list of value names is returned.

If a name is specified, then the value is returned.

nil on error.

### Examples

```lisp
Command: (dos_regget "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem1")
```

```lisp
"True"
```

```lisp
Command: (dos_regget "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem2")
```

```lisp
"False"
```

```lisp
Command: (dos_regget "HKEY_CURRENT_USER\\Software\\MyApp")
```

```lisp
("MyItem1" "MyItem2" "MyItem3")
```

---

## dos_reggetint

Retrieves an integer value, or REG_DWORD, from the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_reggetint hive key name)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to query.

### Returns

The integer value if successful.

nil on error.

### Examples

```lisp
Command: (dos_reggetint "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD\\R16.2\\ACAD-4001:409" "AutoMigrate")
```

```lisp
2
```

---

## dos_reggetstr

Retrieves a string value, or REG_SZ, from the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_reggetstr hive key name)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to query.

### Returns

The string value if successful.

nil on error.

### Examples

```lisp
Command: (dos_reggetstr "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD\\R16.2" "CurVer")
```

```lisp
"ACAD-4001:409"
```

---

## dos_reggettype

Returns the data type of a value in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regenumkey hive key name)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to query.

### Returns

An integer identifying the data type if successful. Possible values include:

0

REG_NONE

No value type

1

REG_SZ

Unicode null terminated string

2

REG_EXPAND_SZ

Unicode nul terminated string (with environment variable references)

3

REG_BINARY

Free form binary

4

REG_DWORD

32-bit number

4

REG_DWORD_LITTLE_ENDIAN

32-bit number (same as REG_DWORD)

5

REG_DWORD_BIG_ENDIAN

32-bit number

6

REG_LINK

Symbolic Link (unicode)

7

REG_MULTI_SZ

Multiple Unicode strings

8

REG_RESOURCE_LIST

Resource list in the resource map

9

REG_FULL_RESOURCE_DESCRIPTOR

Resource list in the hardware description

10

REG_RESOURCE_REQUIREMENTS_LIST

Reserved

11

REG_QWORD

64-bit number

11

REG_QWORD_LITTLE_ENDIAN

64-bit number (same as REG_QWORD)

nil on error.

### Examples

```lisp
(dos_reggettype "HKEY_CURRENT_USER" "Software\\Autodesk\\AutoCAD\\R16.2" "CurVer")
```

```lisp
1
```

---

## dos_regkey

Note, this function is deprecated. Use either dos_regenumkeys or dos_regenumnames.

Enumerates the subkeys in a specified key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regkey key)
```

### Parameters

```lisp
key
```

The registry key to enumerate.

### Returns

A list of subkeys if successful.

nil on error.

### Examples

```lisp
Command: (dos_regkey "HKEY_CURRENT_USER\\")
```

```lisp
("AppEvents" "Console" "Control Panel" "Environment" "Identities" "Keyboard Layout" "Network" "Printers" "Software" "SYSTEM" "UNICODE Program Groups" "Windows 3.1 Migration Status" "SessionInformation" "Volatile Environment")
```

```lisp
Command: (dos_regkey "HKEY_CURRENT_USER\\Software\\Autodesk")
```

```lisp
("ACPROJECT" "AutoCAD" "Autodesk Digital Signatures" "FTPConnect")
```

---

## dos_regset

Note, this function is deprecated. Use either dos_regsetint or dos_regsetstr.

Sets a string value or adds a key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regset key [name [value]])
```

### Parameters

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to modify.

```lisp
value
```

The value to set

### Returns

If a name was not specified, then the key that was created.

If a value was not specified, then the value name that was created.

Otherwise the value that was set is returned if successful.

nil on error.

### Examples

```lisp
Command: (dos_regset "HKEY_CURRENT_USER\\Software\\MyApp")
```

```lisp
"HKEY_CURRENT_USER\\Software\\MyApp"
```

```lisp
Command: (dos_regset "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem1")
```

```lisp
"MyItem1"
```

```lisp
Command: (dos_regset "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem1" "True")
```

```lisp
"True"
```

```lisp
Command: (dos_regset "HKEY_CURRENT_USER\\Software\\MyApp" "MyItem1" "False")
```

```lisp
"False"
```

---

## dos_regsetint

Sets an integer value, or REG_DWORD, to a key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regsetint hive key name int-value)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to modify.

```lisp
int-value
```

The value to set

### Returns

T if successful.

nil on error.

### Examples

```lisp
Command: (dos_regsetint "HKEY_CURRENT_USER" "Software\\MyCompany\\MyProduct" "Number" 4)
```

```lisp
4
```

---

## dos_regsetstr

Sets a string value, or REG_SZ, to a key in the Windows Registry.

WARNING: Using registry functions incorrectly can cause serious problems that may require you to reinstall your operating system. Use the registry functions carefully.

### Syntax

```lisp
(dos_regsetstr hive key name str-value)
```

### Parameters

```lisp
hive
```

The registry hive. Valid values include:

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

HKEY_CURRENT_CONFIG

HKEY_CLASSES_ROOT

HKEY_PERFORMANCE_DATA

HKEY_DYN_DATA

```lisp
key
```

The registry key.

```lisp
name
```

The name of the value to modify.

```lisp
str-value
```

The value to set

### Returns

T if successful.

nil on error.

### Examples

```lisp
Command: (dos_regsetstr "HKEY_CURRENT_USER" "Software\\MyCompany\\MyProduct" "Name" "Value")
```

```lisp
"Value"
```

---

## dos_setini

Copies a string into the specified section of the Windows-style initialization (.INI) file. An initialization file must have the following form:

```lisp
[section]
```

```lisp
entry=string
```

```lisp
...
```

### Syntax

```lisp
(dos_setini section entry string filename)
```

### Parameters

```lisp
section
```

The section to which the string will be copied. If section does not exist, it is created.

```lisp
entry
```

The name of the entry to be associated with string. If entry does not exist in the specified section, it is created. If entry is nil, the entire section, including all entries within the section, is deleted.

```lisp
string
```

The string to be written to the file. If this parameter is nil, the entry pointed to by entry is deleted.

```lisp
filename
```

The name of the initialization file. If filename does not exist, the function creates the file. The specified directory must already exist.

Note, parameters are not case sensitive, so section and entry may be in any combination of uppercase and lowercase characters.  Also, to improve performance, Windows keeps a cached version of the most recently accessed initialization file. If filename is specified and the other arguments are nil, Windows flushes the cache. This function always returns nil after flushing the cache, regardless of whether the flush succeeds or fails.

### Returns

A qualified path name to filename if successful.

nil on error.

### Examples

```lisp
Command: (dos_setini "section1" "entry1" "string1" "filename.ini")
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\filename.ini"
```

```lisp
Command: (dos_setini "section1" "entry2" "string2" "filename.ini")
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\filename.ini"
```

```lisp
Command: (dos_setini "section2" "entry1" "string1" "filename.ini")
```

```lisp
"C:\\Program Files\\AutoCAD 2006\\filename.ini"
```

---

