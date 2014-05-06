#ifndef __HIREDIS_FMACRO_H
#define __HIREDIS_FMACRO_H


#ifdef _WIN32

#define snprintf _snprintf
#define strerror_r(e, s, n) strerror_s(s, n, e)
#ifndef va_copy
#define va_copy(d,s) ((d) = (s))
#endif

#else

#if !defined(_BSD_SOURCE)
#define _BSD_SOURCE
#endif

#if defined(__sun__)
#define _POSIX_C_SOURCE 200112L
#elif defined(__linux__)
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE
#endif

#if __APPLE__ && __MACH__
#define _OSX
#endif

#if defined(linux) || defined(__linux)
#define _LINUX
#endif

#endif

#endif
