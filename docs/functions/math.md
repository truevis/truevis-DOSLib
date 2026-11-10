# DOSLib: Math functions

[Back to index](README.md)

## dos_abs

Returns the absolute value of a number, or the numerical value of a number without regard to its sign.

### Syntax

```lisp
(dos_abs number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The absolute value if successful.

nil on error.

### Example

```lisp
Command: (dos_abs 3.14)

3.14

Command: (dos_abs -3.14)

3.14
```

---

## dos_acos

Calculates the arccosine (inverse cosine) of a number. The inverse cosine can be defined as:

### Syntax

```lisp
(dos_acos number)
```

### Parameters

```lisp
number
```

The number, which should be in the range [-1, 1].

### Returns

The arccosine of the number, in the range [0, π] radians, if successful.

nil on error.

### Example

```lisp
Command: (dos_acos 0.0)

1.5708

Command: (dos_acos 1.0)

0
```

---

## dos_acosh

Calculate the inverse hyperbolic cosine. The inverse hyperbolic cosine can be defined as:

### Syntax

```lisp
(dos_acosh number)
```

### Parameters

```lisp
number
```

The number, which should be >= 1.0.

### Returns

The inverse hyperbolic cosine of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_acosh 1)

0

Command: (dos_acosh 10)

2.99322
```

---

## dos_anglebetween

Returns the angle between two 2D or two 3D vectors.

### Syntax

```lisp
(dos_anglebetween vector0 vector1)
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

### Returns

The angle in radians, if successful.

nil on error.

### Example

```lisp
Command: (dos_anglebetween '(1 0) '(0.70710 0.70710))

0.785398

Command: (dos_anglebetween '(1 0 0) '(0 0 1))

1.5708
```

---

## dos_asin

Calculates the arcsine (inverse sine) of a number. The inverse sine can be defined as:

### Syntax

```lisp
(dos_asin number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The arcsine of the number in the range [–π/2, π/2] radians, if successful.

nil on error.

### Example

```lisp
Command: (dos_asin 0.0)

0

Command: (dos_asin 1.0)

1.5708
```

---

## dos_asinh

Calculate the inverse hyperbolic sine. The inverse hyperbolic sine can be defined as:

### Syntax

```lisp
(dos_asinh number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The inverse hyperbolic sine of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_asinh -2.5)

-1.64723

Command: (dos_asinh 10)

2.99822
```

---

## dos_atan

Calculates the arctangent (inverse tangent) of a number. The inverse tangent can be defined as:

### Syntax

```lisp
(dos_atan number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The arctangent of the number in the range [–π/2, π/2] radians, if successful.

nil on error.

### Example

```lisp
Command: (dos_atan 0.0)

0

Command: (dos_atan 1.0)

0.785398
```

---

## dos_atan2

Calculates the arctangent (inverse tangent) of y/x.

### Syntax

```lisp
(dos_atan2 y x)
```

### Parameters

```lisp
y
```

The y value.

```lisp
x
```

The x value.

### Returns

The arctangent of y/x (if x equals 0, dos_atan2 returns π/2 if y is positive, -π/2 if y is negative, or 0 if y is 0) if successful.

nil on error.

### Example

```lisp
Command: (dos_atan2 0.5 5.0)

0.0996687
```

---

## dos_atanh

Calculate the inverse hyperbolic tangent. The inverse hyperbolic tangent can be defined as:

### Syntax

```lisp
(dos_atanh number)
```

### Parameters

```lisp
number
```

The number, which must be between -1.0 and 1.0 (excluding -1.0 and 1.0).

### Returns

The inverse hyperbolic tangent of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_atanh 0.76159416)

1.0

Command: (dos_atanh -0.1)

-0.100335
```

---

## dos_cbrt

Calculates the cube root.

### Syntax

```lisp
(dos_cbrt number)
```

### Parameters

```lisp
number
```

The nonnegative number.

### Returns

The cube root, if successful.

nil on error.

### Example

```lisp
Command: (dos_cbrt 25)

2.92402

Command: (dos_cbrt 45)

3.55689
```

---

## dos_ceil

Calculates the ceiling of a number.

### Syntax

```lisp
(dos_ceil number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The value representing the smallest integer that is greater than or equal to the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_ceil -1.6)

-1

Command: (dos_ceil -1.5)

-1

Command: (dos_ceil -1.4)

-1

Command: (dos_ceil 1.4)

2

Command: (dos_ceil 1.5)

2

Command: (dos_ceil 1.6)

2
```

---

## dos_chgsign

Reverses the sign of a number.

### Syntax

```lisp
(dos_chgsign number)
```

### Parameters

```lisp
number
```

The number to be changed.

### Returns

The number with its sign reversed, if successful.

nil on error.

### Example

```lisp
Command: (dos_chgsign 3.14)

-3.14

Command: (dos_chgsign -3.14)

3.14
```

---

## dos_clamp

Clamps, or limits, a number to an interval.

### Syntax

```lisp
(dos_clamp number min max)
```

### Parameters

```lisp
number
```

The number.

```lisp
min
```

The minimum interval value, or lower limit.

```lisp
max
```

The maximum interval value, or upper limit.

### Returns

The number clamped to lie between min and max, making min <= number <= max, if successful.

nil on error.

### Example

```lisp
Command: (dos_clamp 3 0 10)

3

Command: (dos_clamp 11 0 10)

10
```

---

## dos_copysign

Returns a number with the sign of another number.

### Syntax

```lisp
(dos_copysign first second)
```

### Parameters

```lisp
first
```

The number whose sign is to be adjusted.

```lisp
second
```

The number whose sign is to be used.

### Returns

first with its sign changed to match the sign of second,

 if successful.

nil on error.

### Example

```lisp
Command: (dos_copysign 3.14 -1)

-3.14

Command: (dos_copysign -3.14 -1)

-3.14

Command: (dos_copysign -3.14 1)

3.14
```

---

## dos_cos

Calculates the cosine of a number. The cosine can be defined as:

### Syntax

```lisp
(dos_cos angle)
```

### Parameters

```lisp
angle
```

The angle in radians.

### Returns

The cosine, if successful.

nil on error.

### Example

```lisp
Command: (dos_cos 1.047)

0.500171

Command: (dos_cos (/ (* 60 (dos_pi)) 180))

0.5

Command: (dos_cos (dos_dtr 60))

0.5
```

---

## dos_cosh

Calculate the hyperbolic cosine of a number. The hyperbolic cosine can be defined as:

### Syntax

```lisp
(dos_cosh number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The hyperbolic cosine, if successful.

nil on error.

### Example

```lisp
Command: (dos_cosh 4)

27.3082

Command: (dos_cosh (dos_exp 1))

7.61013
```

---

## dos_crossproduct

Calculates the cross product of two 2D or two 3D vectors.

### Syntax

```lisp
(dos_crossproduct vector0 vector1)
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

### Returns

The resulting vector, if successful.

nil on error.

### Example

```lisp
Command: (dos_crossproduct '(1 0) '(0.70710 0.70710))

(0 0 0.7071)

Command: (dos_crossproduct '(1 0 0) '(0 0 1))

(0 -1 0)
```

---

## dos_cullnumbers

Culls, or removes, duplicate values from a list of numbers.

### Syntax

```lisp
(dos_cullnumbers list [tolerance])
```

### Parameters

```lisp
list
```

A list of real or integer values.

```lisp
tolerance
```

The culling tolerance. If omitted, a tolerance of 1.0e-12 is used.

### Returns

A culled list if successful.

nil on error.

### Example

```lisp
Command: (dos_cullnumbers '(3 8 4 8 2 3 9 5 8))

(3 8 4 2 9 5)
```

---

## dos_difference

Subtracts numbers, including lists of numbers, and returns the difference.

### Syntax

```lisp
(dos_difference number0 ...)
```

```lisp
(dos_difference list0 ...)
```

### Parameters

```lisp
number0
 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The difference, if successful.

nil on error.

### Example

```lisp
Command: (dos_difference 10)

-10

Command: (dos_difference 10 3 5 8)

-6

Command: (dos_difference '(10 3 5 8))

2

Command: (dos_difference '(10 3) '(2 7))

(8 -4)
```

---

## dos_div

Computes the quotient and the remainder of two integers.

### Syntax

```lisp
(dos_div numerator denominator)
```

### Parameters

```lisp
numerator
```

The numerator.

```lisp
denominator
```

The denominator.

### Returns

A list comprising the quotient and the remainder, if successful.

nil on error.

### Example

```lisp
Command: (dos_div 876 13)

(67 5)
```

---

## dos_dotproduct

Calculates the dot product of two 2D or two 3D vectors.

### Syntax

```lisp
(dos_dotproduct vector0 vector1)
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

### Returns

The dot product, if successful.

nil on error.

### Example

```lisp
Command: (dos_dotproduct '(1 0) '(0.70710 0.70710))

0.7071

Command: (dos_dotproduct '(1 0 0) '(0 0 1))

0
```

---

## dos_dtr

Converts an angle from degrees to radians.

### Syntax

```lisp
(dos_dtr degrees)
```

```lisp
(dos_dtr degrees [minutes [seconds [direction]]])
```

### Parameters

```lisp
degrees
```

The degrees in either decimal or DMS.

```lisp
minutes
```

The minutes.

```lisp
seconds
```

The seconds.

```lisp
direction
```

The direction. Specify T for north or east (default), and nil

 for south and west.

### Returns

The angle in radians, if successful.

nil on error.

### Example

```lisp
Command: (dos_dtr 45)

0.785398

Command: (dos_dtr 90)

1.5708

Command: (dos_dtr 47 6 13)

0.822113
```

---

## dos_e

Returns e (mathematical constant), or the Euler's number, which is 2.71828182845904523536.

### Syntax

```lisp
(dos_e)
```

### Parameters

n/a

### Returns

2.71828182845904523536.

### Example

```lisp
Command: (dos_e)

2.71828

Command: (dos_log (dos_e))

1
```

---

## dos_equal

Compares two numbers or two lists of numbers, approximately, by subtracting the two variables being compared and testing whether their difference

 is less than a value chosen at the limits of significance.

### Syntax

```lisp
(dos_equal number0 number1 [tolerance])
```

```lisp
(dos_equal list0 list1 [tolerance[)
```

### Parameters

```lisp
number0
```

The first number to compare.

```lisp
number1
```

The second number to compare.

```lisp
list0
```

The first numeric list to compare.

```lisp
list1
```

The second numeric list to compare.

```lisp
tolerance
```

The tolerance to compare against. Of omitted, the LUPREC system variable is used to calculate the tolerance (e.g. if LUPREC = 4,

 then tolerance = 0.0001).

### Returns

T if the two number are equal within tolerance, if successful.

nil on error.

### Example

```lisp
Command: (dos_equal 3.14 3.14159)

nil

Command: (dos_equal 3.14 3.14159 0.01)

T

Command: (dos_equal '(1 3) '(1 3))

T
```

---

## dos_exp

Returns e raised to the power of number. The constant e equals

 2.71828182845904523536, the base of the natural logarithm.

### Syntax

```lisp
(dos_exp number)
```

### Parameters

```lisp
number
```

The exponent applied to the base e.

### Returns

Returns e raised the power, if successful.

nil on error.

### Example

```lisp
Command: (dos_exp 1)

2.71828

Command: (dos_exp 2)

7.38906
```

---

## dos_fact

Returns the factorial of a number. The factorial of a number is equal to 1*2*3*...* number.

### Syntax

```lisp
(dos_fact number)
```

### Parameters

```lisp
number
```

The nonnegative number you want the factorial of. If number is not an integer, it is truncated.

### Returns

The factorial, if successful.

nil on error.

### Example

```lisp
Command: (dos_fact 5)

120

Command: (dos_fact 1.9)

1

Command: (dos_fact 0)

1

Command: (dos_fact -1)

nil

Command: (dos_fact 1)

1
```

---

## dos_floor

Calculates the floor of a number. The function returns a value representing the largest integer that is less than or equal to the number.

### Syntax

```lisp
(dos_floor number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The value representing the largest integer that is less than or equal to the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_floor -1.6)

-2

Command: (dos_floor -1.5)

-2

Command: (dos_floor -1.4)

-2

Command: (dos_floor 1.4)

1

Command: (dos_floor 1.5)

1

Command: (dos_floor 1.6)

1
```

---

## dos_fmod

Calculates the floating-point remainder of x / y.

### Syntax

```lisp
(dos_fmod numerator denominator)
```

### Parameters

```lisp
numerator
```

The numerator.

```lisp
denominator
```

The denominator.

### Returns

The floating point remainder, if successful.

nil on error.

### Example

```lisp
Command: (dos_fmod 5.3 2)

1.3

Command: (dos_fmod 18.5 4.2)

1.7
```

---

## dos_gcd

Computes the greatest common divisor of two integers.

### Syntax

```lisp
(dos_gcd first second)
```

### Parameters

```lisp
first
```

The first number.

```lisp
second
```

The second number.

### Returns

The greatest common divisor, if successful.

nil on error.

### Example

```lisp
Command: (dos_gcd 81 57)

3

Command: (dos_gcd 12 20)

4
```

---

## dos_hypot

Calculates the hypotenuse. The function calculates the length of the hypotenuse of a right triangle, given the length of the two sides x and

 y (in other words, the square root of x2 + y2).

### Syntax

```lisp
(dos_hypot x y)
```

### Parameters

```lisp
x
```

The value of x.

```lisp
y
```

The value of y.

### Returns

The length of the hypotenuse, if successful.

nil on error.

### Example

```lisp
Command: (dos_hypot 3 4)

5
```

---

## dos_interp

Performs an interpolation between two numbers.

### Syntax

```lisp
(dos_interp min max t [mode])
```

### Parameters

```lisp
min
```

The minimum value in the range.

```lisp
max
```

The maximum value in the range.

```lisp
t
```

The normalized value ( ranging between 0 and 1) between min and max. Values of outside this

 range result in extrapolation.

```lisp
mode
```

The interpolation method to use.

		Method

		Description

		0 (default)

		Linear

		1

		Cosine

		2

		Smooth step

		3

		Acceleration

		4

		Deceleration

### Returns

The result of the interpolation if successful.

nil on error.

### Example

---

## dos_lcm

Computes the least common multiple of two integers. The least common multiple is the smallest positive integer that is a multiple of both integers.

### Syntax

```lisp
(dos_lcm first second)
```

### Parameters

```lisp
first
```

The first number.

```lisp
second
```

The second number.

### Returns

The least common multiple, if successful.

nil on error.

### Example

```lisp
Command: (dos_lcm 5 2)

10

Command: (dos_lcm 24 36)

72
```

---

## dos_length

Calculates the length of a 2D or 3D vector.

### Syntax

```lisp
(dos_length vector)
```

### Parameters

```lisp
vector
```

The vector.

### Returns

The length, if successful.

nil on error.

### Example

```lisp
Command: (dos_length '(3 2))

3.60555

Command: (dos_length '(3 2 2))

4.12311
```

---

## dos_log

Calculates the natural logarithm of a number. Natural logarithms are based on the constant e (2.71828182845904523536).

 Note, this function is the inverse of the dos_exp function.

### Syntax

```lisp
(dos_log number)
```

### Parameters

```lisp
number
```

The positive number for which you want the natural logarithm.

### Returns

The natural logarithm of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_log 86)

4.45435

Command: (dos_log 2.7182818)

1.0

Command: (dos_log (dos_exp 3))

3
```

---

## dos_log10

Calculates the common (decadic) logarithm (base-10) of a number.

### Syntax

```lisp
(dos_log10 number)
```

### Parameters

```lisp
number
```

The positive real number for which you want the base-10 logarithm.

### Returns

The base-10 logarithm of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_log10 86)

1.9345

Command: (dos_log10 10)

1

Command: (dos_log10 1e5)

5
```

---

## dos_log2

Calculates the binary logarithm (base-2) of a number.

### Syntax

```lisp
(dos_log2 number)
```

### Parameters

```lisp
number
```

The positive real number for which you want the base-2 logarithm.

### Returns

The base-2 logarithm of the number, if successful.

nil on error.

### Example

```lisp
Command: (dos_log2 1)

0

Command: (dos_log2 2)

1

Command: (dos_log2 3)

1.58496

Command: (dos_log2 4)

2
```

---

## dos_max

Returns the maximum number from a list or series of numbers.

### Syntax

```lisp
(dos_max numbers)
```

```lisp
(dos_max number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0 ...
```

A series of numbers.

### Returns

The maximum number from the list, if successful.

nil on error.

### Example

```lisp
Command: (dos_max '(1 2 3 4 5 6 7 8 9))

9

Command: (dos_max 1 2 3 4 5 6 7 8 9)

9
```

---

## dos_mean

Returns the mean, or average, of a list or series of numbers.

### Syntax

```lisp
(dos_mean number0 ...)
```

```lisp
(dos_mean list0 ...)
```

### Parameters

```lisp
number0
 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The mean value, if successful.

nil on error.

### Example

```lisp
Command: (dos_mean 1 2 3 4 5 6 7 8 9)

5

Command: (dos_mean '(1 2 3 4 5 6 7 8 9))

5

Command: (dos_mean '(1 2) '(3 6) '(1 7))

(1.66667 5)
```

---

## dos_median

Returns the median, or middle, of a list or series of numbers.

### Syntax

```lisp
(dos_median numbers)
```

```lisp
(dos_median number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0 ...
```

A series of numbers.

### Returns

The median value, if successful.

nil on error.

### Example

```lisp
Command: (dos_median '(1 2 3 4 5 6 7 8 9))

5

Command: (dos_median 1 2 3 4 5 6 7 8 9)

5
```

---

## dos_min

Returns the minimum number from a list or series of numbers.

### Syntax

```lisp
(dos_min numbers)
```

```lisp
(dos_min number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0
 ...
```

A series of numbers.

### Returns

The minimum number from the list, if successful.

nil on error.

### Example

```lisp
Command: (dos_min '(1 2 3 4 5 6 7 8 9))

1

Command: (dos_min 1 2 3 4 5 6 7 8 9)

1
```

---

## dos_mode

Returns the mode (the value that occurs most often) of a list or series of numbers.

### Syntax

```lisp
(dos_mode numbers)
```

```lisp
(dos_mode number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0
 ...
```

A series of numbers.

### Returns

A list containing the modes, if successful.

nil on error.

### Example

```lisp
Command: (dos_mode '(1 1 2 2 2 3 4 4 5 6 7 7 8 9))

(2)

Command: (dos_mode 1 1 2 2 2 3 4 4 5 6 7 7 8 9)

(2)
```

---

## dos_modf

Splits a floating-point value into integer and fractional parts.

### Syntax

```lisp
(dos_modf number)
```

### Parameters

```lisp
number
```

The number.

### Returns

A list containing the integer and fractional parts, if successful.

nil on error.

### Example

```lisp
Command: (dos_modf (dos_e))

(2.0 0.718282)

Command: (dos_modf (dos_pi))

(3.0 0.141593)

Command: (dos_modf -14.87654321)

(-14.0 -0.876543)
```

---

## dos_moment

Calculates the moments of a distribution: Mean, Average Deviation, Standard Deviation, Variance, Skewness, and Kurtosis.

### Syntax

```lisp
(dos_moment numbers)
```

```lisp
(dos_moment number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0
 ...
```

A series of numbers.

### Returns

A list containing the Mean, Average Deviation, Standard Deviation, Variance, Skewness, and Kurtosis, if successful. Note, if Variance = 0, Skewness

 and Kurtosis will be nil.

nil on error.

### Example

```lisp
Command: (dos_moment '(1 3 2 5 6 2 4 6 8 9 6 5 7 2 3 5
 4))

(4.58824 1.84775 2.26547 5.13235 0.210593 -1.04927)

Command: (dos_moment 1 3 2 5 6 2 4 6 8 9 6 5 7 2 3 5 4)

(4.58824 1.84775 2.26547 5.13235 0.210593 -1.04927)
```

---

## dos_negate
Negates a list or series of numbers. Note, a negated vector has the same magnitude as before, but its direction is now opposite.

### Syntax

```lisp
(dos_negate number0 ...)
```

```lisp
(dos_negate list0 ...)
```

### Parameters

```lisp
number0
 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The negated numbers, if successful.

nil on error.

### Example

```lisp
Command: (dos_negate '(1 1 2 2 2 3 4 4 5 6 7 7 8 9))

(-1 -1 -2 -2 -2 -3 -4 -4 -5 -6 -7 -7 -8 -9)

Command: (dos_negate 1 1 2 2 2 3 4 4 5 6 7 7 8 9)

(-1 -1 -2 -2 -2 -3 -4 -4 -5 -6 -7 -7 -8 -9)

Command: (dos_negate '(3 2))

(-3 -2)
```

---

## dos_normalize

Converts a parameter, or value, to a normalized parameter; one that ranges between 0.0 and 1.0.

### Syntax

```lisp
(dos_normalize number minimum maximum)
```

### Parameters

```lisp
number
```

The number to normalize that is within the specified range.

```lisp
minimum
```

The minimum number in the range.

```lisp
maximum
```

The maximum number in the range.

### Returns

The normalized value, if successful.

nil on error.

### Example

```lisp
Command: (dos_normalize 39 0 255)

0.152941

Command: (dos_parameterize 0.152941 0 255)

39.0
```

---

## dos_orthogonalp

Determines if two 2D or two 3D vectors are non-zero and mutually perpendicular.

### Syntax

```lisp
(dos_orthogonalp x-axis y-axis)
```

```lisp
(dos_orthogonalp x-axis y-axis z-axis)
```

### Parameters

```lisp
x-axis
```

The x-axis vector.

```lisp
y-axis
```

The y-axis vector.

```lisp
z-axis
```

The z-axis vector.

### Returns

T if orthogonal.

nil if not orthogonal, or on error.

### Example

```lisp
Command: (dos_orthogonalp '(1 0) '(0.70710 0.70710))

nil

Command: (dos_orthogonalp '(1 0 0) '(0 1 0) '(0 0 1))

T
```

---

## dos_orthonormalp

Determines if two 2D or two 3D vectors are orthogonal and of unit length.

### Syntax

```lisp
(dos_orthonormalp x-axis y-axis)
```

```lisp
(dos_orthonormalp x-axis y-axis z-axis)
```

### Parameters

```lisp
x-axis
```

The x-axis vector.

```lisp
y-axis
```

The y-axis vector.

```lisp
z-axis
```

The z-axis vector.

### Returns

T if orthonormal.

nil if not orthonormal, or on error.

### Example

```lisp
Command: (dos_orthonormalp '(1 0) '(0 1))

T

Command: (dos_orthonormalp '(3 0) '(0 2))

nil
```

---

## dos_parallelp

Determines if two 2D or two 3D vectors are parallel.

### Syntax

```lisp
(dos_parallelp vector0 vector1 [angle_tol])
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

```lisp
angle_tol
```

An optional angle tolerance in radians. If omitted, an angle tolerance of PI/180.0 is used.

### Returns

1 if the vectors are parallel.

0 if the vectors are not parallel.

-1 if the vectors are anti-parallel.

nil on error.

### Example

```lisp
Command: (dos_parallelp '(1 1) '(2 2))

1

Command: (dos_parallelp '(1 1) '(2 3))

0
```

---

## dos_parameterize

Converts a normalized parameter, or value, to a parameter; one in the specified range.

### Syntax

```lisp
(dos_parameterize number minimum maximum)
```

### Parameters

```lisp
number
```

The normalized value, one that ranges between 0.0 and 1.0.

```lisp
minimum
```

The minimum number in the range.

```lisp
maximum
```

The maximum number in the range.

### Returns

The parameter, if successful.

nil on error.

### Example

```lisp
Command: (dos_normalize 39 0 255)

0.152941

Command: (dos_parameterize 0.152941 0 255)

39.0
```

---

## dos_perpendicularp

Determines if two 2D or two 3D vectors are perpendicular.

### Syntax

```lisp
(dos_perpendicularp vector0 vector1 [angle_tol])
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

```lisp
angle_tol
```

An optional angle tolerance in radians. If omitted, an angle tolerance of PI/180.0 is used.

### Returns

T if the vectors are perpendicular.

nil if the vectors are not perpendicular, or on error.

### Example

```lisp
Command: (dos_perpendicularp '(1 0) '(0 1))

T

Command: (dos_perpendicularp '(1 0) '(0.707 1))

nil
```

---

## dos_perpendicularto

Returns a perpendicular vector. The resulting vector is not unitized.

### Syntax

```lisp
(dos_perpendicularto vector)
```

### Parameters

```lisp
vector
```

The vector.

### Returns

The perpendicular if successful.

nil on error.

### Example

```lisp
Command: (dos_perpendicularto '(1 0))

(0 1)

Command: (dos_perpendicularto '(3 2 1))

(-2 3 0)
```

---

## dos_phi

Returns Phi, the golden ratio. Phi is defined as:

### Syntax

```lisp
(dos_phi)
```

### Parameters

n/a

### Returns

1.61803

### Example

```lisp
Command: (dos_phi)

1.61803
```

---

## dos_pi

Returns PI, a mathematical constant whose value is the ratio of any circle's circumference to its diameter in Euclidean space, which is 3.14159265358979323846.

### Syntax

```lisp
(dos_pi)
```

### Parameters

n/a

### Returns

3.14159265358979323846.

### Example

```lisp
Command: (dos_pi)

3.14159
```

---

## dos_pow

Calculates x raised to the power of y.

### Syntax

```lisp
(dos_pow number power)
```

### Parameters

```lisp
number
```

The base number.

```lisp
power
```

The exponent to which the base number is raised.

### Returns

The base number raised to a power, if successful.

nil on error.

### Example

```lisp
Command: (dos_pow 5 2)

25

Command: (dos_pow 98.6 3.2)

2.40108e+006

Command: (dos_pow 4 (/ 5.0 4.0))

5.65685
```

---

## dos_product

Multiplies numbers, including lists of numbers, and returns the product.

### Syntax

```lisp
(dos_product number0 ...)
```

```lisp
(dos_product list0 ...)
```

### Parameters

```lisp
number0
 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The product, if successful.

nil on error.

### Example

```lisp
Command: (dos_product 50 2 5)

500

Command: (dos_product '(50 2 5))

500

Command: (dos_product '(50 25) '(2 5))

(100 125)
```

---

## dos_quadratic

Find solutions of a quadratic equation. A quadratic equation is a polynomial equation of the second degree. The general form is

where x represents a variable, and a, b, and c, constants, with a ≠ 0. (If a = 0, the equation becomes

 a linear equation.)

### Syntax

```lisp
(dos_quadratic a b c)
```

### Parameters

```lisp
a
```

The a coefficient.

```lisp
b
```

The b coefficient.

```lisp
c
```

The c coefficient.

### Returns

The list containing the results of the calculation, where:

		Element

		Description

		0

		0: successful - two distinct real roots (r0 < r1)

		1: successful - one real root (r0 = r1)

		2: successful - two complex conjugate roots (r0 +/- (r1)*sqrt(-1))

		-1: failure - a = 0, b != 0 (r0 = r1 = -c/b)

		-2: failure - a = 0, b  = 0 c != 0 (r0 = r1 = 0.0)

		-3: failure - a = 0, b  = 0 c  = 0 (r0 = r1 = 0.0)

		1

		r0 (root)

		2

		r1 (root)

nil on error.

### Example

```lisp
Command: (dos_quadratic 1 -3 -4)

(0 -1 4)
```

---

## dos_quotient

Divides numbers, including lists of numbers, and returns the quotient.

### Syntax

```lisp
(dos_quotient number0 ...)
```

```lisp
(dos_quotient list0 ...)
```

### Parameters

```lisp
number0
 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The quotient, if successful.

nil on error.

### Example

```lisp
Command: (dos_quotient 50 2 5)

5

Command: (dos_quotient '(50 2 5))

5

Command: (dos_quotient '(50 25) '(2 5))

(25 5)
```

---

## dos_random

Returns a pseudo random number.

### Syntax

```lisp
(dos_random)
```

### Parameters

n/a

### Returns

An integer pseudo random number if successful.

nil on error.

### Example

```lisp
Command: (dos_random)

4748

Command: (dos_random)

13395

Command: (rem (dos_random) 100) 'in
 the range 0-99

37

Command: (+ (rem (dos_random) 100) 1) 'in
 the range 1-100

69

Command: (+ (rem (dos_random) 30) 1985) 'in
 the range 1985-2014

2003
```

---

## dos_range

Returns the range (the difference between the lowest and highest values)
 of a list or series of numbers.

### Syntax

```lisp
(dos_range numbers)
```

```lisp
(dos_range number0 ...)
```

### Parameters

```lisp
numbers
```

The list of numbers.

```lisp
number0 ...
```

A series of numbers.

### Returns

The range, if successful.

nil on error.

### Example

```lisp
Command: (dos_range '(1 1 2 2 2 3 4 4 5 6 7 7 8 9))

8

Command: (dos_range 1 1 2 2 2 3 4 4 5 6 7 7 8 9)

8
```

---

## dos_righthandp

Determines if two 2D or two 3D vectors are orthonormal and right handed.

### Syntax

```lisp
(dos_righthandp x-axis y-axis)
```

```lisp
(dos_righthandp x-axis y-axis z-axis)
```

### Parameters

```lisp
x-axis
```

The x-axis vector.

```lisp
y-axis
```

The y-axis vector.

```lisp
z-axis
```

The z-axis vector.

### Returns

T if right handed.

nil if not right handed, or on error.

### Example

```lisp
Command: (dos_righthandp '(1 0) '(0 1))

T

Command: (dos_righthandp '(0 1) '(1 0))

nil
```

---

## dos_round

Rounds a decimal number to an integer.

There are many different ways to round floating point values to integers.
 DOSLib provide a couple basic ones in dos_ceil and dos_floor. This function provides several

 other useful methods for rounding numbers.

Note, there are two general categories of rounding algorithm: those that are symmetric about zero and those that are biased in some way.

### Syntax

```lisp
(dos_round number [mode])
```

### Parameters

```lisp
number
```

The number to round.

```lisp
mode
```

The rounding method

		Method

		Description

		0

		Symmetric
		 round up. Bias is away from zero.

		1

		Symmetric
		 round down. Bias is towards zero.

		2

		Common
		 round half up. Bias is to positive infinity.

		3

		Common
		 round half down. Bias is to negative infinity.

		4

		Symmetric
		 round half up. Bias is away from zero.

		5

		Symmetric
		 round half down. Bias is towards zero.

		6 (Default)

		Round half
		 even (Banker's rounding). No bias.

		7

		Round alternate.
		 No bias for sequential calls.

		8

		Symmetric
		 round alternate. No bias for sequential calls.

		9

		Random
		 round. Bias toward the random number generator.

### Returns

The rounded number if successful.

nil on error.

### Example

---

## dos_rtd

Converts an angle from radians to degrees.

### Syntax

```lisp
(dos_rtd radians)
```

### Parameters

```lisp
radians
```

The angle in radians.

### Returns

The angle in degrees, if successful.

nil on error.

### Example

```lisp
Command: (dos_rtd 0.785398)

45.0

Command: (dos_rtd 1.5708)

90.0002
```

---

## dos_scale

Scales a list of numbers. The list can represent 2D and 3D points and vectors.

### Syntax

```lisp
(dos_scale list scale)
```

### Parameters

```lisp
list
```

The list of numbers.

```lisp
scale
```

The scale factor.

### Returns

The scaled list, if successful.

nil on error.

### Example

```lisp
Command: (dos_scale '(1 2 3) 5)

(5 10 15)
```

---

## dos_sign

Returns a value indicating the sign of a number, or an expression based on the sign of a value.

### Syntax

```lisp
(dos_sign number [expr0 expr1 expr2])
```

### Parameters

```lisp
number
```

The number.

```lisp
expr0
```

The first expression.

```lisp
expr1
```

The second expression.

```lisp
expr2
```

The third expression.

### Returns

If optional expressions are not specified, then -1 if number is less than zero, 0 if number

 is equal to zero, and 1 if number is greater than zero, if successful.

If optional expressions are specified, then expr0 if number is less than zero,

 expr1 if number is equal to zero, and expr2 if

 number is greater than zero, if successful.

nil on error.

### Example

```lisp
Command: (dos_sign -3.14)

-1

Command: (dos_sign 0.0)

0

Command: (dos_sign 3.14)

1

Command: (dos_sign 3.14 "Less Than" '(2 3) 5.67)

5.67
```

---

## dos_sin

Calculates the sine of a number. The sine can be defined as:

### Syntax

```lisp
(dos_sin angle)
```

### Parameters

```lisp
angle
```

The angle in radians.

### Returns

The sine, if successful.

nil on error.

### Example

```lisp
Command: (dos_sin (dos_pi))

0

Command: (dos_sin (/ (dos_pi) 2))

1

Command: (dos_sin (dos_dtr 30))

0.5
```

---

## dos_sinh

Calculate the hyperbolic sine of a number. The hyperbolic sine can be defined as:

### Syntax

```lisp
(dos_sinh number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The hyperbolic sine, if successful.

nil on error.

### Example

```lisp
Command: (dos_sinh 1)

1.1752

Command: (dos_sinh -1)

-1.1752
```

---

## dos_sortnumbers

Sorts a list of numbers.

### Syntax

```lisp
(dos_sortnumbers list [ascending])
```

### Parameters

```lisp
list
```

A list of real or integer values.

```lisp
ascending
```

Sort the list in either ascending (T)
 or descending (nil) order. If omitted, the list is sorted in ascending order.

### Returns

A sorted list if successful.

nil on error.

### Example

```lisp
Command: (dos_sortnumbers '(4 3 6 5 1 2 7 9 8))

(1 2 3 4 5 6 7 8 9)

Command: (dos_sortnumbers '(4 3 6 5 1 2 7 9 8) nil)

(9 8 7 6 5 4 3 2 1)
```

---

## dos_sqrt

Calculates the square root.

### Syntax

```lisp
(dos_sqrt number)
```

### Parameters

```lisp
number
```

The nonnegative number.

### Returns

The square root, if successful.

nil on error.

### Example

```lisp
Command: (dos_sqrt 16)

4

Command: (dos_sqrt -2)

nil

Command: (dos_sqrt (dos_abs -2))

1.41421
```

---

## dos_sum

Adds numbers, including lists of numbers, and returns the sum.

### Syntax

```lisp
(dos_sum number0 ...)
```

```lisp
(dos_sum list0 ...)
```

### Parameters

```lisp
number0 ...
```

A series of numbers.

```lisp
list0
```

The series of numeric lists.

### Returns

The sum, if successful.

nil on error.

### Example

```lisp
Command: (dos_sum 1 1 2 2 2 3 4 4 5 6 7 7 8 9)

61

Command: (dos_sum '(1 1 2 2 2 3 4 4 5 6 7 7 8 9))

61

Command: (dos_sum '(3 2 1) '(2 4 -3))

(5 6 -2)
```

---

## dos_tan

Calculates the tangent of a number. The tangent can be defined as:

### Syntax

```lisp
(dos_tan angle)
```

### Parameters

```lisp
angle
```

The angle in radians.

### Returns

The tangent, if successful.

nil on error.

### Example

```lisp
Command: (dos_tan 0.785)

0.999204

Command: (dos_tan (dos_dtr 45))

1.0
```

---

## dos_tanh

Calculate the hyperbolic tangent of a number. The hyperbolic tangent can be defined as:

### Syntax

```lisp
(dos_tanh number)
```

### Parameters

```lisp
number
```

The number.

### Returns

The hyperbolic tangent, if successful.

nil on error.

### Example

```lisp
Command: (dos_tanh -2)

-0.964028

Command: (dos_tanh 0)

0

Command: (dos_tanh 0.5)

0.462117
```

---

## dos_tinyp

Determines if a 2D or 3D vector is very short.

### Syntax

```lisp
(dos_tinyp vector [tiny_tol])
```

### Parameters

```lisp
vector
```

The vector.

```lisp
tiny_tol
```

The tolerance used to determine if the vector is tiny. If omitted, a tolerance of 1.0e-12 is used.

### Returns

T if the vector is tiny.

nil if the vector is not tiny, or on error.

### Example

```lisp
Command: (dos_tinyp '(1 0 0))

nil

Command: (dos_tinyp '(0 0 0))

T
```

---

## dos_tripleproduct

Calculates the triple product of three 3D vectors.

### Syntax

```lisp
(dos_tripleproduct vector0 vector1 vector2)
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

```lisp
vector2
```

The third vector.

### Returns

The triple dot product, if successful.

nil on error.

### Example

```lisp
Command: (dos_tripleproduct '(1 0 0) '(0 1 0) '(0 0 1))

1
```

---

## dos_trunc

Truncates a number to a specified number of decimal places.

### Syntax

```lisp
(dos_pow number [precision])
```

### Parameters

```lisp
number
```

The number.

```lisp
precision
```

The precision of the truncation. The default value precision is 0 (zero).

### Returns

The truncated number, if successful.

nil on error.

### Example

```lisp
Command: (dos_trunc (dos_pi))

3

Command: (dos_trunc (dos_pi) 1)

3.1

Command: (dos_trunc (dos_pi) 2)

3.14

Command: (dos_trunc (dos_pi) 3)

3.141
```

---

## dos_unitize

Unitizes, or normalized, a 2D or 3D vector. A unitized vector maintains its direction but its length becomes 1. The

 resulting vector is often called a unit vector.

### Syntax

```lisp
(dos_unitize vector)
```

### Parameters

```lisp
vector
```

The vector.

### Returns

The unitized vector, if successful.

nil on error.

### Example

```lisp
Command: (dos_unitize '(2 1))

(0.894427 0.447214)

Command: (dos_unitize '(2 1 -3))

(0.534522 0.267261 -0.801784)
```

---

## dos_unitp

Determines if a 2D or 3D vector is a unit vector.

### Syntax

```lisp
(dos_unitp vector)
```

### Parameters

```lisp
vector
```

The vector.

### Returns

T if the vector is a unit vector.

nil if the vector is not a unit vector, or on error.

### Example

```lisp
Command: (dos_unitp (dos_unitize '(2 1)))

T

Command: (dos_unitp '(2 1))

nil
```

---

## dos_vector

Creates a vector from two 2D or two 3D points.

### Syntax

```lisp
(dos_vector point0 point1)
```

### Parameters

```lisp
point0
```

The first point.

```lisp
point1
```

The second point.

### Returns

The vector, if successful.

nil on error.

### Example

```lisp
Command: (dos_vector '(3 2) '(1 1))

(2 1)

Command: (dos_vector '(3 2 2) '(1 1 5))

(2 1 -3)
```

---

## dos_wedgeproduct

Calculates the wedge product, or the signed area of the parallelogram, of two 2D vectors

### Syntax

```lisp
(dos_wedgeproduct vector0 vector1)
```

### Parameters

```lisp
vector0
```

The first vector.

```lisp
vector1
```

The second vector.

### Returns

The wedge product, if successful.

nil on error.

### Example

```lisp
Command: (dos_wedgeproduct '(5 0) '(3 2))

10
```

---

## dos_zerop

Determines if a 2D or 3D vector is a zero, or null, vector.

### Syntax

```lisp
(dos_zerop vector)
```

### Parameters

```lisp
vector
```

The vector.

### Returns

T if the vector is a zero vector.

nil if the vector is not a zero vector, or on error.

### Example

```lisp
Command: (dos_zerop '(0 0 0))

T

Command: (dos_zerop '(0 0 0.00001))

nil
```

---

