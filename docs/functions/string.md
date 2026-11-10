# DOSLib: String functions

[Back to index](README.md)

## dos_strcase

Converts all the characters in this string to uppercase or lowercase characters.

### Syntax

```lisp
(dos_strcase string [T])
```

### Parameters

```lisp
string
```

A string.

```lisp
T
```

If specified as T, all alphabetic characters in string are converted to lowercase. Otherwise, characters are converted to uppercase.

### Returns

The converted string if successful.

nil on error.

### Example

```lisp
Command: (dos_strcase "AutoCAD 2006")

"AUTOCAD 2006"

Command: (dos_strcase "AutoCAD 2006" T)

"autocad 2006"
```

---

## dos_strcat

Returns a string that is the concatenation of multiple strings.

### Syntax

```lisp
(dos_strcat [string [string] ... ])
```

### Parameters

```lisp
string
```

A string.

### Returns

A concatenated string if successful. If string supplied, a zero-length string is returned.

nil on error.

### Example

```lisp
Command: (dos_strcat "Hockey " "is " "the " "best.")

"Hockey is the best."
```

---

## dos_strchar

Returns or sets the character at a given position.

### Syntax

```lisp
(dos_strchar string index [char])
```

### Parameters

```lisp
string
```

A string.

```lisp
index
```

A zero-based index of the character in the string. The index parameter must be greater than or equal to 0 and less than the value returned by dos_strlength.

```lisp
char
```

The character to set at the index position.

### Returns

The character at the specified position if char is not specified.

The modified string if char is specified.

nil on error.

### Example

```lisp
Command: (dos_strchar "AutoCAD 2006" 11)

"6"

Command: (dos_strchar "AutoCAD 2006" 11 "7")

"AutoCAD 2007"
```

---

## dos_strcmplogical

Compares two strings logically, or naturally. Digits in the strings are considered as numerical content rather than text. This test is not

 case-sensitive. Note, Windows Explorer sorts files using this method.

### Syntax

```lisp
(dos_strcmplogical string1 string2)
```

### Parameters

```lisp
string1
```

The first string.

```lisp
string2
```

The second string.

### Returns

Zero if the strings are identical, < 0 if string1 is less than string2, or > 0 if string1 object is greater than string2.

nil on error.

### Example

```lisp
Command: (dos_strcmplogical "Layer2" "Layer3")

-1

Command: (dos_strcmplogical "Layer2" "Layer20")

-1

Command: (dos_strcmplogical "Layer3" "Layer20")

-1

Command: (dos_strcmplogical "Layer30" "Layer20")

1
```

---

## dos_strcompare

Compares two strings (case sensitive or case insensitive).

### Syntax

```lisp
(dos_strcompare string1 string2 [T])
```

### Parameters

```lisp
string1
```

The first string.

```lisp
string2
```

The second string.

```lisp
T
```

If specified as T, a case insensitive comparison is performed. Otherwise, a case sensitive comparison is performed.

### Returns

Zero if the strings are identical, < 0 if string1 is less than string2, or > 0 if string1 object is greater than string2.

nil on error.

### Example

```lisp
Command: (dos_strcompare "AutoCAD" "AUTOCAD")

1

Command: (dos_strcompare "AutoCAD" "AUTOCAD" T)

0
```

---

## dos_strcull

Culls, or removes, duplicate strings from a list of strings.

### Syntax

```lisp
(dos_strcull list [T])
```

### Parameters

```lisp
list
```

A list of strings.

```lisp
T
```

If specified as T, a case insensitive comparison is performed. Otherwise, a case sensitive comparison is performed..

### Returns

A culled list if successful.

nil on error.

### Example

```lisp
Command: (dos_strcull '("autocad" "AutoCAD"
 "AUTOCAD" "autocad"))

("autocad" "AutoCAD" "AUTOCAD")

Command: (dos_strcull '("autocad" "AutoCAD"
 "AUTOCAD" "autocad") T)

("autocad")
```

---

## dos_strdelete

Deletes characters from a string.

### Syntax

```lisp
(dos_strdelete string index count)
```

### Parameters

```lisp
string
```

A string.

```lisp
index
```

The zero-based index of the first character to delete.

```lisp
count
```

The number of characters to be removed. If index is longer than the length of string, the remainder of string will be removed.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "Hockey is the best.")

"Hockey is the best."

Command: (dos_strdelete str 6 8)

"Hockeybest."
```

---

## dos_strexcluding

Extracts a substring that contains only the characters not in a set.

### Syntax

```lisp
(dos_strexcluding string charset)
```

### Parameters

```lisp
string
```

A string.

```lisp
charset
```

A string interpreted as a set of characters.

### Returns

A substring that contains characters in string that are not in charset, beginning with the first character in string and ending with the first character found in string that is also in charset (that is, starting with the first character in string and up to but excluding the first character in string that is found charset). It returns the entire string if no character in charset is found in string.

nil on error.

### Example

```lisp
Command: (dos_strexcluding "1.0,1.0,1.0" ";,-:")

"1.0"
```

---

## dos_strfind

Finds a character or substring inside a larger string.

### Syntax

```lisp
(dos_strfind string substring [index])
```

### Parameters

```lisp
string
```

A string.

```lisp
substring
```

A substring to search for.

```lisp
index
```

The zero-based index of the character in string to begin the search with, or 0 to start from the beginning. The character at index is excluded from the search if index is not equal to 0. The default value of index is 0.

### Returns

The zero-based index of the first character in string that matches the requested substring or characters; -1 if the substring or character is not found.

nil on error.

### Example

```lisp
Command: (dos_strfind "AutoCAD 2006" "C")

4

Command: (dos_strfind "The stars are aligned." "e" 5)

12
```

---

## dos_strfindoneof

Finds the first matching character from a set.

### Syntax

```lisp
(dos_strfindoneof string charset)
```

### Parameters

```lisp
string
```

A string.

```lisp
substring
```

A string interpreted as a set of characters.

### Returns

The zero-based index of the first character in string that is also in substring; –1 if there is no match.

nil on error.

### Example

```lisp
Command: (dos_strfindoneof "abcdefg" "xd")

3
```

---

## dos_strformat

Formats string similar to the sprintf C-Runtime library function.

### Syntax

```lisp
(dos_strformat format arg1 arg2 ...)
```

### Parameters

```lisp
format
```

A string that contains the text to be formatted. It can optionally contain embedded format tags that are substituted by the values specified in subsequent

 argument(s) and formatted as requested.
 The number of arguments following the format parameters should at least be as much as the number of format tags.

The format tags follow this prototype:

```lisp
%[flags][width][.precision][length]specifier
```

Where specifier is the most significant one and defines the type and the interpretation of the value of the corresponding argument:

		Specifier

		Output

		Example

		c

		Character

		a

		d or i

		Signed
		 decimal integer

		392

		e

		Scientific
		 notation (/exponent) using e character

		3.9265e+2

		E

		Scientific
		 notation (exponent) using E character

		3.9265E+2

		f

		Decimal
		 floating point

		392.65

		g

		Use
		 the shorter of % e or %
		 f

		392.65

		G

		Use
		 the shorter of % E or %
		 f

		392.65

		o

		Signed
		 octal

		610

		s

		String
		 of characters

		sample

		u

		Unsigned
		 decimal integer

		7235

		x

		Unsigned
		 hexadecimal integer

		7fa

		X

		Unsigned
		 hexadecimal integer (capital letters)

		7FA

		n

		Nothing
		 printed. The argument must be a pointer to a signed integer, where
		 the number of characters written so far is stored.

		%

		A
		 % followed by another % character will write % to the string.

The tag can also contain flags, width, .precision and modifiers sub-specifiers, which are optional and follow these specifications:

		Flag

		Description

		-

		Left-justify
		 within the given field width; Right justification is the default
		 (see width sub-specifier).

		+

		Forces
		 to proceed the result with a plus or minus sign (+ or -) even
		 for positive numbers. By default, only negative numbers are preceded
		 with a - sign.

		(space)

		If
		 no sign is going to be written, a blank space is inserted before
		 the value.

		#

		Used
		 with o, x or X specifiers the value is
		 proceeded with 0, 0x or 0X respectively for values different than
		 zero.

		Used with e, E and f, it forces the written output to contain
		 a decimal point even if no digits would follow. By default, if
		 no digits follow, no decimal point is written.

		Used with g or G the result is the same as with e or E but trailing
		 zeros are not removed.

		0

		Left-pads
		 the number with zeroes (0) instead of spaces, where padding is
		 specified (see width sub-specifier).

		Width

		Description

		number

		Minimum
		 number of characters to be printed. If the value to be printed
		 is shorter than this number, the result is padded with blank spaces.
		 The value is not truncated even if the result is larger.

		*

		The
		 width is not specified in the format string, but as an additional
		 integer value argument proceeded the argument that has to be formatted.

		Precision

		Description

		number

		For
		 integer specifiers (d, i, o, u, x, X): precision specifies the
		 minimum number of digits to be written. If the value to be written
		 is shorter than this number, the result is padded with leading
		 zeros. The value is not truncated even if the result is longer.
		 A precision of 0 means that no character is written for the value
		 0.

		For e, E and f specifiers: this is the number of digits to be
		 printed after de decimal point.

		For g and G specifiers: This is the maximum number of significant
		 digits to be printed.

		For s: this is the maximum number of characters to be printed.
		 By default all characters are printed until the ending null character
		 is encountered.

		For c type: it has no effect.

		When no precision is specified, the default is 1. If the period
		 is specified without an explicit value for precision, 0 is assumed.

		*

		The
		 precision is not specified in the format string, but as an additional
		 integer value argument preceding the argument that has to be formatted.

		Length

		Description

		h

		The
		 argument is interpreted as a short integer or unsigned short integer
		 (only applies to integer specifiers: i, d, o, u, x and X).

		l

		The
		 argument is interpreted as a long int or unsigned long int for
		 integer specifiers (i, d, o, u, x and X), and as a wide character
		 or wide character string for specifiers c and s.

		L

		The
		 argument is interpreted as a long double (only applies to floating
		 point specifiers: e, E, f, g and G).

```lisp
substring
```

Depending on the format string, the function may expect a sequence of additional arguments, each containing one value to be inserted instead

 of each %-tag specified in the format parameter, if any. There should be the same number of these arguments as the number of %-tags that expect

 a value.

### Returns

The formatted string if successful.

nil on error.

### Example

```lisp
(defun c:test (/ ch string count fp) (setq ch "h") (setq string "computer") (setq count -9234) (setq fp 251.7366) ; Display integers (princ (dos_strformat "Integer formats:\n Decimal: %d Justified: %.6d Unsigned: %u\n" count count count ) ) ; Display decimals (princ (dos_strformat "Decimal %d as:\n Hex: %Xh C hex: 0x%x Octal: %o\n" count count count count ) ) ; Display characters (princ (dos_strformat "Characters in field:\n%10c%5hc%5c%5lc\n" ch ch ch ch ) ) ; Display strings (princ (dos_strformat "Strings in field:\n%25s\n%25.4hs\n %s%25.3ls\n" string string string string ) ) ; Display real numbers (princ (dos_strformat "Real numbers:\n %f %.2f %e %E\n" fp fp fp fp ) ) (princ) ) Integer formats: Decimal: -9234 Justified: -009234 Unsigned: 4294958062 Decimal -9234 as: Hex: FFFFDBEEh C hex: 0xffffdbee Octal: 37777755756 Characters in field: h h h h Strings in field: computer c computer com Real numbers: 251.736600 251.74 2.517366e+002 2.517366E+002
```

---

## dos_strformatcurrency

Formats a number as a currency string.

Currency string is formatted based on the currency settings identified in the Regional and Language Options found in Control Panel unless one of the overrides is specified.

### Syntax

```lisp
(dos_strformatcurrency number [num_digits [leading_zero [decimal_sep [thousands_sep [currency_sym]]]]])
```

### Parameters

```lisp
number
```

A number as a currency string.

```lisp
num_digits
```

Number of fractional digits for the monetary format. Value must be number between 0 and 9.

```lisp
leading_zero
```

Specifier for leading zeros in decimal fields. Value must be either 0 or 1.

```lisp
decimal_sep
```

Character(s) used as the monetary decimal separator. Maximum number of characters is 4.

```lisp
thousands_sep
```

Character(s) used as the monetary thousands separator. Maximum number of characters is 4.

```lisp
currency_sym
```

String used as the monetary symbol. Maximum number of characters is 6.

### Returns

The formatted currency string if successful.

nil on error.

### Example

```lisp
Command: (dos_strformatcurrency 1234.56)

"$1,234.56"

Command: (dos_strformatcurrency 1234.56 0)

"$1,235"

Command: (dos_strformatcurrency 0.56 2 0)

"$.56"
```

---

## dos_strformatdate

Returns a formatted string containing a specified date and/or time.

### Syntax

```lisp
(dos_strformatdate format date/time)
```

### Parameters

```lisp
format
```

 A string containing one or more formatting codes. Other characters in the formatting string are copied unchanged to the returned string.

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

The # flag may prefix any formatting code. In that case, the meaning of the format code is changed as follows:

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

```lisp
date/time
```

A list of numbers specifying the year (1970–3000), month (1–12), and day (1–31). Optionally, the list can contain the hour (0-23), minute (0-59),

 and second (0-59).

### Returns

A string identifying the date and/or time if successful.

nil on error.

### Example

```lisp
Command: (dos_strformatdate "%m/%d/%y" (dos_date))

"11/06/09"

Command: (dos_strformatdate "%A, %B %d, %Y" (dos_getdate
 "Date"))

"Wednesday, November 11, 2009"
```

---

## dos_strformatnumber

Formats a number as a number string.

Number string is formatted based on the number settings identified in the Regional and Language Options found in Control Panel unless one of the overrides is specified.

### Syntax

```lisp
(dos_strformatnumber number [num_digits [leading_zero [decimal_sep [thousands_sep]]]])
```

### Parameters

```lisp
number
```

A number as a currency string.

```lisp
num_digits
```

Number of fractional digits for the monetary format. Value must be number between 0 and 9.

```lisp
leading_zero
```

Specifier for leading zeros in decimal fields. Value must be either 0 or 1.

```lisp
decimal_sep
```

Character(s) used as the monetary decimal separator. Maximum number of characters is 4.

```lisp
thousands_sep
```

Character(s) used as the monetary thousands separator. Maximum number of characters is 4.

### Returns

The formatted number string if successful.

nil on error.

### Example

```lisp
Command: (dos_strformatnumber 1234.56)

"1,234.56"

Command: (dos_strformatnumber 1234.56 0)

"1,235"

Command: (dos_strformatnumber 0.56 2 0)

".56"
```

---

## dos_strincluding

Extracts a substring that contains only the characters in a set.

### Syntax

```lisp
(dos_strincluding string charset)
```

### Parameters

```lisp
string
```

A string.

```lisp
char_set
```

A string interpreted as a set of characters.

### Returns

A substring that contains characters string that are in charset, beginning with the first character in string and ending when a character is found in string that is not in charset. dos_strincluding returns an empty substring if the first character in string is not in the specified set.

nil on error.

### Example

```lisp
Command: (dos_strincluding "cabbage" "abc")

"cabba"
```

---

## dos_strinsert

Inserts a single character or a substring at the given index within the string.

### Syntax

```lisp
(dos_strinsert string index chars)
```

### Parameters

```lisp
string
```

A string.

```lisp
index
```

The zero-based index of the character before which the insertion will take place. If index is zero, the insertion will occur before the entire string. If index is higher than the length of string, the function will concatenate chars to the present string

```lisp
chars
```

The characters to inserted.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "HockeyBest.")

"HockeyBest."

Command: (dos_strinsert str 6 " is the ")

"Hockey is the Best."
```

---

## dos_strischar

Tests a character for satisfaction of a condition or conditions described by bits.

### Syntax

```lisp
(dos_strischar [char [bits]])
```

### Parameters

```lisp
char
```

The character to test.

```lisp
bits
```

A bit-coded integer identifying the desired condition. Specify more than one condition by adding the following bit values:

1

Alphanumeric. Character within the ranges A – Z, a – z, or 0 – 9.

2

Alphabetic. Character within the ranges A – Z or a – z.

4

Decimal digit. Character is a decimal digit (0 – 9).

8

 Printable. Character is a printable character, including the space character (0x20 – 0x7E).

16

Punctuation. Any printable character that is not a space character or an alphanumeric character

32

White-space. Character is a white-space character (0x09 – 0x0D or 0x20).

64

Lowercase. Character is a lowercase character (a – z).

128

Uppercase. Character is an uppercase character (A – Z).

256

ASCII. Character is an ASCII character (in the range 0x00 – 0x7F).

512

Control. Character is a control character (0x00 – 0x1F or 0x7F).

### Returns

T if successful.

nil if not successful, or on error.

### Example

```lisp
Command: (dos_strischar "D" 2)

T

Command: (dos_strischar "D" 4)

nil

Command: (dos_strischar "D" 129)

T
```

---

## dos_strleft

Extracts the left part of a string (like the Basic LEFT$ function).

### Syntax

```lisp
(dos_strleft string count)
```

### Parameters

```lisp
string
```

A string.

```lisp
count
```

The number of characters to extract from string. If count exceeds the length of string, then the entire string is extracted.

### Returns

A string that contains a copy of the specified range of characters if successful.

nil on error.

### Example

```lisp
Command: (dos_strleft "AutoCAD 2006" 7)

"AutoCAD"
```

---

## dos_strlength

Returns the number of characters in a string.

### Syntax

```lisp
(dos_strlength string)
```

### Parameters

```lisp
string
```

A string.

### Returns

An integer specifying the length of the string.

nil on error.

### Example

```lisp
Command: (dos_strlength "AutoCAD 2006")

12
```

---

## dos_strmatch

Matches a string against a wildcard string.

### Syntax

```lisp
(dos_strmatch string wildcard [T])
```

### Parameters

```lisp
string
```

A string.

```lisp
wildcard
```

A string containing wildcard characters (* and ?).

```lisp
T
```

If specified, then a case-insensitive comparison is performed. Otherwise, a case-sensitive comparison is performed.

### Returns

T if string matches wildcard.

nil on error.

### Example

```lisp
Command: (dos_strmatch "MyLayerName" "My*")

T

Command: (dos_strmatch "MyDrawing.dwg" "My*.*")

T
```

---

## dos_strmid

Extracts the middle part of a string (like the Basic MID$ function).

### Syntax

```lisp
(dos_strmid string index [count])
```

### Parameters

```lisp
string
```

A string.

```lisp
index
```

The zero-based index of the first character in string that is to be included in the extracted substring.

```lisp
count
```

The number of characters to extract from string. If this parameter is not supplied, then the remainder of string is extracted.

### Returns

A string that contains a copy of the specified range of characters if successful.

nil on error.

### Example

```lisp
Command: (dos_strmid "AutoCAD 2006" 8)

"2006"

Command: (dos_strmid "AutoCAD 2006" 4 3)

"CAD"
```

---

## dos_strregexp

Parses a string using a regular expression. A regular expression provides a concise and flexible means for "matching" (specifying and

 recognizing) strings of text, such as particular characters, words, or patterns of characters.

### Syntax

```lisp
(dos_strregexp regexp input [ignore_case [value [replace_all]]])
```

### Parameters

```lisp
regexp
```

The regular expression. The metacharacters understood by this function are::

		Metacharacter

		Description

		.

		Matches
		 any single character.

		[ ]

		Indicates
		 a character class. Matches any character inside the brackets (for
		 example, [abc] matches "a", "b", and "c").

		^

		If this
		 metacharacter occurs at the start of a character class, it negates
		 the character class. A negated character class matches any character
		 except those inside the brackets (for example, [^abc] matches
		 all characters except "a", "b", and "c").

		If ^ is at the beginning of the regular expression, it matches
		 the beginning of the input (for example, ^[abc] will only match
		 input that begins with "a", "b", or "c").

		-

		In a character
		 class, indicates a range of characters (for example, [0-9] matches
		 any of the digits "0" through "9").

		?

		Indicates
		 that the preceding expression is optional: it matches once or
		 not at all (for example, [0-9][0-9]? matches "2" and
		 "12").

		+

		Indicates
		 that the preceding expression matches one or more times (for example,
		 [0-9]+ matches "1", "13", "666",
		 and so on).

		*

		Indicates
		 that the preceding expression matches zero or more times.

		??, +?,
		 *?

		Non-greedy
		 versions of ?, +, and *. These match as little as possible, unlike
		 the greedy versions which match as much as possible. Example:
		 given the input "<abc><def>", <.*?>
		 matches "<abc>" while <.*> matches "<abc><def>".

		( )

		Grouping
		 operator. Example: (\d+,)*\d+ matches a list of numbers separated
		 by commas (such as "1" or "1,23,456").

		{ }

		Indicates
		 a match group.

		\

		Escape
		 character: interpret the next character literally (for example,
		 [0-9]+ matches one or more digits, but [0-9]\+ matches a digit
		 followed by a plus character). Also used for abbreviations (such
		 as \a for any alphanumeric character; see table below).

		If \ is followed by a number n, it matches the nth match group
		 (starting from 0). Example: <{.*?}>.*?</\0> matches
		 "<head>Contents</head>".

		Note, with string literals, two backslashes must be used: "\\+",
		 "\\a", "<{.*?}>.*?</\\0>".

		$

		At the
		 end of a regular expression, this character matches the end of
		 the input. Example: [0-9]$ matches a digit at the end of the input.

		|

		Alternation
		 operator: separates two expressions, exactly one of which matches
		 (for example, T|the matches "The" or "the").

		!

		Negation
		 operator: the expression following ! does not match the input.
		 Example: a!b matches "a" not followed by "b".

A regular expression can also contain abbreviations, or shortcuts, such as \d instead of [0-9].  The predefined character traits classes

 provide the following abbreviations are:

		Abbreviation

		Description

		\a

		Any alphanumeric
		 character: ([a-zA-Z0-9])

		\b

		White space
		 (blank): ([ \\t])

		\c

		Any alphabetic
		 character: ([a-zA-Z])

		\d

		Any decimal
		 digit: ([0-9])

		\h

		Any hexadecimal
		 digit: ([0-9a-fA-F])

		\n

		Newline:
		 (\r|(\r?\n))

		\q

		A quoted
		 string: (\"[^\"]*\")|(\'[^\']*\')

		\w

		A simple
		 word: ([a-zA-Z]+)

		\z

		An integer:
		 ([0-9]+)

Examples of regular expressions are as follows:

		String
		 to find

		Regular
		 expression

		A date
		 in yyyy-mm-dd format that is between 1900-01-01 and 2099-12-31

		((19)|(20))\d\d((0[1-9])|(1[012]))((0[1-9])|([12][0-9])|(3[01]))

		Parts of
		 a line before and after a person's name

		^.*Dale.*$

		A string
		 field that contains only alphabetic characters

		[A-Za-z]*

```lisp
input
```

The input string to parse using the regular expression.

```lisp
ignore_case
```

Specify T to ignore character case when parsing, or nil (default)

 to respect character case.

```lisp
value
```

The string to replace matches with.

```lisp
replace_all
```

Specify T (default) to replace all matches or nil to replace

 the first match.

### Returns

The modified string if successful.

nil on error.

### Examples

Parse time in h:mm or hh:mm format.

```lisp
Command: (dos_strregexp "[0-9]?[0-9]:[0-9][0-9]"
 "1:57")
```

```lisp
(0 "1:57")
```

Parse time in h:mm or hh:mm format, and indicate matching groups.

```lisp
Command: (dos_strregexp "{[0-9]?[0-9]}:{[0-9][0-9]}"
 "1:57")
```

```lisp
(0 "1:57" (0 "1") (2 "57"))
```

Parses a seven digit phone number using abbreviations.

```lisp
Command: (dos_strregexp "\\d\\d\\d-\\d\\d\\d\\d"
 "My phone number is (206) 555-1212.")
```

```lisp
(25 "555-1212")
```

Parses a seven digit phone number using abbreviations.

```lisp
Command: (dos_strregexp "\\d+-\\d+" "My
 phone number is (206) 555-1212.")
```

```lisp
(25 "555-1212")
```

Another matching group example.

```lisp
Command: (dos_strregexp "product: {.*?};" "product:
 Bowling ball; price: $199;")
```

```lisp
(0 "product: Bowling ball;" (9 "Bowling ball"))
```

---

## dos_strremove

Removes indicated characters from a string.

### Syntax

```lisp
(dos_strremove string char)
```

### Parameters

```lisp
string
```

A string.

```lisp
char
```

The character to remove.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (dos_strremove "AutoCAD 2006" "A")

"utoCD 2006"
```

---

## dos_strreplace

Replaces indicated characters with other characters in a string.

### Syntax

```lisp
(dos_strreplace string oldchars newchars [T])
```

### Parameters

```lisp
string
```

A string.

```lisp
oldchars
```

The character to be replaced by newchars.

```lisp
newchars
```

The character replacing oldchars.

```lisp
T
```

If specified as T, a case insensitive replacement is performed. Otherwise, a case sensitive replacement is performed.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "Everybody likes ice hockey.")

"Everybody likes ice hockey."

Command: (dos_strreplace str "hockey" "golf")

"Everybody likes ice golf."
```

---

## dos_strreverse

Reverses the characters in this string.

### Syntax

```lisp
(dos_strreverse string)
```

### Parameters

```lisp
string
```

A string.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (dos_strreverse "AutoCAD 2006")

"6002 DACotuA"
```

---

## dos_strreversefind

Finds a character inside a larger string; starts from the end.

### Syntax

```lisp
(dos_strreversefind string char)
```

### Parameters

```lisp
string
```

A string.

```lisp
substring
```

A character to search for.

### Returns

The zero-based index of the last character in string that matches the requested character, –1 if the character is not found.

nil on error.

### Example

```lisp
Command: (dos_strreversefind "abcabc" "b")

4
```

---

## dos_strright

Extracts the right part of a string (like the Basic RIGHT$ function).

### Syntax

```lisp
(dos_strright string count)
```

### Parameters

```lisp
string
```

A string.

```lisp
count
```

The number of characters to extract from string. If count exceeds the length of string, then the entire string is extracted.

### Returns

A string that contains a copy of the specified range of characters if successful.

nil on error.

### Example

```lisp
Command: (dos_strright "AutoCAD 2010" 4)

"2010"
```

---

## dos_strsort

Sorts a list of strings.

### Syntax

```lisp
(dos_strsort strings [mode [ascending]])
```

### Parameters

```lisp
strings
```

A list of strings.

```lisp
mode
```

The sorting mode, where:

		Mode

		Description

		-1
		Logical sorting. Digits in the strings are considered as numerical
		 content rather than text. Note, this method is not case-sensitive.

		0 (default)
		Case insensitive sorting.

		1
		Case sensitive sorting.

```lisp
ascending
```

Sort the list in either ascending (T)
 or descending (nil) order. If omitted, the list is sorted in ascending order.

### Returns

A sorted list of strings if successful.

nil on error.

### Example

```lisp
Command: (setq x '("1A" "2A" "3A"
 "10C" "10B" "10A" "11B" "11D"))

("1A" "2A" "3A" "10C" "10B" "10A" "11B" "11D")

Command: (dos_strsort x)

("10A" "10B" "10C" "11B" "11D" "1A" "2A" "3A")

Command: (dos_strsort x 0 nil)

("3A" "2A" "1A" "11D" "11B" "10C" "10B" "10A")

Command: (dos_strsort x -1)

("1A" "2A" "3A" "10A" "10B" "10C" "11B" "11D")

Command: (dos_strsort x -1 nil)

("11D" "11B" "10C" "10B" "10A" "3A" "2A" "1A")
```

---

## dos_strtokens

Converts a string of tokens into a list.

### Syntax

```lisp
(dos_strtokens string tokens [T])
```

### Parameters

```lisp
string
```

A string.

```lisp
tokens
```

 A string interpreted as a set of delimiter characters.

```lisp
T
```

If specified, the result is compatible with the strtok C/C++ run-time library function.

### Returns

A list of strings, if successful.

nil on error.

### Example

```lisp
Command: (dos_strtokens "Hockey is the best." " ")

("Hockey" "is" "the" "best.")

Command: (dos_strtokens "A string\tof ,,tokens\nand some more tokens" " ,\t\n" t)

("A" "string" "of" "tokens" "and" "some" "more" "tokens")

Command: (dos_strtokens "0,0,,0,0" ",")

("0" "0" "" "0" "0")

Command: (dos_strtokens "0,0,,0,0" "," t)

("0" "0" "0" "0")
```

---

## dos_strtrim
Trims leading and trailing characters from a string.

### Syntax

```lisp
(dos_strtrim string [chars])
```

### Parameters

```lisp
string
```

A string.

```lisp
chars
```

A string containing the target characters to be trimmed. If chars is not specified, this function removes leading and trailing newline, space, and tab characters from string.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "  Hockey is the best  ")

"  Hockey is the best  "

Command: (dos_strtrim str)

"Hockey is the best"
```

---

## dos_strtrimleft

Trims leading characters from a string.

### Syntax

```lisp
(dos_strtrimleft string [chars])
```

### Parameters

```lisp
string
```

A string.

```lisp
chars
```

A string containing the target characters to be trimmed. All trailing occurrences of characters in chars will be trimmed from string.

 If chars is not specified, this function removes leading newline, space,

 and tab characters from string.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "****Hockey is the best")

"****Hockey is the best"

Command: (dos_strtrimleft str "*")

"Hockey is the best"

Command: (setq str "\t\tHockey is the best")

"\t\tHockey is the best"

Command: (dos_strtrimleft str)

"Hockey is the best"
```

---

## dos_strtrimright

Trims trailing characters from a string.

### Syntax

```lisp
(dos_strtrimright string [chars])
```

### Parameters

```lisp
string
```

A string.

```lisp
chars
```

A string containing the target characters to be trimmed. All trailing occurrences of characters in chars will be trimmed from string.

 If chars is not specified, this function removes trailing newline, space,

 and tab characters from string.

### Returns

The modified string if successful.

nil on error.

### Example

```lisp
Command: (setq str "Hockey is the best!!!!")

"Hockey is the best!!!!"

Command: (dos_strtrimright str "!")

"Hockey is the best"

Command: (setq str "Hockey is the best ")

"Hockey is the best "

Command: (dos_strtrimright str)

"Hockey is the best"
```

---

