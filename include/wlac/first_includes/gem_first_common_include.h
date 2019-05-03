/*
 *	File: <gem_first_common_include.h> For WINDOWS MFC
 *
 *	Created on: Dec 26, 2015
 *	Author    : Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This is the include file that is included by all gem related headers
 *
 */
#ifndef __gem_first_common_include_h__
#define __gem_first_common_include_h__


#include <first_includes/common_definations_wul.h>

#ifndef UNDEFINED_API_NOT_NEEDED
#endif  // #ifndef UNDEFINED_API_NOT_NEEDED

#define __USE_POSIX199309

#ifndef GEM_API_FAR
#ifdef ___GEM_LIB_CREATION___
#define GEM_API_FAR		EXPORT_TO_LIB_API
#define GEM_VAR_FAR		extern EXPORT_TO_LIB_VAR
#elif defined(__USING_GEM_SOURCES__)  // #ifdef ___GEM_LIB_CREATION___
#define GEM_API_FAR
#define GEM_VAR_FAR		extern
#else   // #ifdef ___GEM_LIB_CREATION___
#define GEM_API_FAR		IMPORT_FROM_LIB_API
#define GEM_VAR_FAR		IMPORT_FROM_LIB_VAR
#endif  // #ifdef ___GEM_LIB_CREATION___
#endif  // #ifndef GEM_API_FAR

#define	_SINGLE_THREAD_	1980

#ifndef __GNUC__
#define	__GNUC__		1
#define __GLIBC__		2
#define	__GLIBC_MINOR__	15
#endif  // #ifndef __GNUC__

#ifndef __linux__
#define __linux__	1
#endif

#include <sys/timeb.h>
#ifndef timeb
//#define timeb _timeb
#endif

#include <stdio.h>
#include <io.h>
#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif
#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif
#ifndef STDERR_FILENO
#define STDERR_FILENO 2
#endif

/// Code can be written to link this library automatically to application

#include <process.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _SOURCE_FILE_
#define _SOURCE_FILE_	\
	(  strrchr(__FILE__,'/') ? (strrchr(__FILE__,'/')+1) : \
		(strrchr(__FILE__,'\\') ? (strrchr(__FILE__,'\\')+1) : __FILE__) )
#endif

#ifdef exit
#undef exit
#endif

//#define exit(__code)	exit2(__code)
#define exit(__code)	do{printf("fl:\"%s\", ln:%d, fnc:%s\n",_SOURCE_FILE_,__LINE__,__FUNCTION__); ExitProcess((__code));}while(0)

#endif  /* #ifndef __gem_first_common_include_h__ */
