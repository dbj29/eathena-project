#ifndef __BASESTRFORMAT_H__
#define __BASESTRFORMAT_H__


#include "basetypes.h"

NAMESPACE_BEGIN(basics)

///////////////////////////////////////////////////////////////////////////////
// predeclaration
///////////////////////////////////////////////////////////////////////////////
template <class T> class stringoperator;
template <class T> class string;


/*------------------------------------------------------------------------------

  Author:    Andy Rushton
  Copyright: (c) Andy Rushton, 2004
  License:   BSD License, see ../docs/license.html

  Provides an sprintf-like function acting on STL strings rather than char* so
  that there is no possibility of overflowing the string buffer. The 'd' stands
  for "dynamic" in that the string is a dynamic string whereas a char* buffer
  would be static (in size that is, not static in C terms).

int dprintf (std::string&, const char* format, ...);

   Like sprintf(), formats the message by appending to the std::string (using the +=
   operator) according to the formatting codes in the format string. The return int
   is the number of characters generated by this call, i.e. the increase in the
   length of the std::string.

int vdprintf (std::string& formatted, const char* format, va_list args);

   As above, but using a pre-initialised va_args argument list. Useful for nesting
   printf calls within variable argument functions.

std::string dprintf (const char* format, ...);

   Similar to dprintf() above, except the result is formatted into a new std::string
   which is returned by the function. Very useful for inline calls within a textio
   expression.
   e.g.    fout << "Total: " << dprintf("%6i",t) << newline;

std::string dvprintf (const char* format, va_list);

   As above, but using a pre-initialised va_args argument list. Useful for nesting
   sformat calls within variable argument functions.


The result supports the following "C" format codes:

   % [ flags ] [ width ] [ . precision ] [ modifier ] [ conversion ]

 flags:
   -    - left justified
   +    - print sign for +ve numbers
   ' '  - leading space where + sign would be
   0    - leading zeros to width of field
   #    - alternate format

 width:
   a numeric argument specifying the field width - default = 0
   * means take the next va_arg as the field width - if negative then left justify

 precision:
   a numeric argument the meaning of which depends on the conversion -
   - %s - max characters from a string - default = strlen()
   - %e, %f - decimal places to be displayed - default = 6
   - %g - significant digits to be displayed - default = 6
   - all integer conversions - minimum digits to display - default = 0
   * means take the next va_arg as the field width - if negative then left justify

 modifier:
   h    - short or unsigned short
   l    - long or unsigned long
   L    - long double
   
 conversions:
   d, i - short/int/long as decimal
   u    - short/int/long as unsigned decimal
   o    - short/int/long as unsigned octal - # adds leading 0
   x, X - short/int/long as unsigned hexadecimal - # adds leading 0x
   c    - char
   s    - char*
   f    - double/long double as fixed point
   e, E - double/long double as floating point
   g, G - double/long double as fixed point/floating point depending on value
   p    - void* as unsigned hexadecimal
   %    - literal %
   n    - int* as recipient of length of formatted string so far

------------------------------------------------------------------------------*/
template<typename T> ssize_t dsprintf(stringoperator<T>& formatted, const T* format, ...);
template<typename T> ssize_t dvsprintf(stringoperator<T>& formatted, const T* format, va_list args);

template<typename T> string<T> dprintf(const T* format, ...);
template<typename T> string<T> dvprintf(const T* format, va_list);


NAMESPACE_END(basics)


#endif//__BASESTRFORMAT_H__
