#ifndef ERRNO_H
#define ERRNO_H

#include "sys/cdefs.h"

__HEADER_START

extern int errno;

#define EDOM	(-1)
#define ERANGE	(-2)
#define EILSEQ	(-3)

__HEADER_END

#endif