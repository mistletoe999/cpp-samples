// Defs.h contains the definitions of two macros: MAX2 and MAX3

#ifndef DEFS_H_
#define DEFS_H_

// MAX2 Macro: Gets the maximum of two numbers
#define MAX2(x, y) (x > y ? x : y)

// MAX3 Macro: Gets the maximum of three numbers
#define MAX3(x, y, z) (x > y? MAX2(x, z) : MAX2(y, z))

#endif // _DEFS_H_