#ifndef BC_CONFIG_H
#define BC_CONFIG_H

#ifdef _WIN32
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#ifndef _CRT_NONSTDC_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS 1
#endif
#endif

/* Build-time constants used by bc/dc. */
#define BC_COPYRIGHT "Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2018, 2024 Free Software Foundation, Inc."
#define DC_COPYRIGHT "Copyright 1994, 1997, 1998, 2000, 2001, 2003-2006, 2008, 2010, 2012-2018, 2022, 2024 Free Software Foundation, Inc."
#define DC_VERSION "1.5.2"

#define ENABLE_DC_BANG_SHELL 1

/* Header/function probes from configure for this checked-in build config. */
#define HAVE_ERRNO_H 1
#define HAVE_FSTAT 1
#define HAVE_INTTYPES_H 1
#define HAVE_ISGRAPH 1
#define HAVE_LIMITS_H 1
#define HAVE_SETVBUF 1
#define HAVE_STDARG_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRTOL 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_VPRINTF 1
#define HAVE_WCHAR_H 1

#define PACKAGE "bc"
#define PACKAGE_BUGREPORT "bug-bc@gnu.org"
#define PACKAGE_NAME "bc"
#define PACKAGE_STRING "bc 1.08.2"
#define PACKAGE_TARNAME "bc"
#define PACKAGE_URL ""
#define PACKAGE_VERSION "1.08.2"
#define VERSION "1.08.2"

#define STDC_HEADERS 1
#define YYTEXT_POINTER 1

/* Compiler feature probe. */
#if defined(__GNUC__) || defined(__clang__)
#define HAVE___ATTRIBUTE__ 1
#endif

/* Windows CRT compatibility for POSIX names used by the codebase. */
#ifdef _WIN32
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#define isatty _isatty
#define fileno _fileno
#define read _read
#define write _write
#define stat _stat64
#define fstat _fstat64
#define strdup _strdup
#define srandom(seed) srand((unsigned int)(seed))
#define random() ((long) rand())
#endif

#endif /* BC_CONFIG_H */
