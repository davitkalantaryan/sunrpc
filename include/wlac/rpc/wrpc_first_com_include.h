/*
 *	File: <wrpc_first_com_include.h> For WINDOWS MFC
 *
 *	Created on: Dec 29, 2015
 *	Author    : Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This is the include file that is included by all gem related headers
 *
 */
#ifndef __wrpc_first_com_include_h__
#define __wrpc_first_com_include_h__

#include <first_includes/common_definations_wul.h>

#if !defined(___WRPC_LIB_CREATION___) && !defined(__USING_WRPC_SOURCES__) && !defined(WRPC_LIB_NOT_INCLUDE) && defined(WRPC_LIB_INCLUDE)
#ifdef _MSC_VER
///#pragma comment(lib, "win_xdr_rpc.lib")
#endif
#endif  // #if !defined(___WRPC_LIB_CREATION___) && !defined(__USING_WRPC_SOURCES__) && !defined(WRPC_LIB_NOT_INCLUDE)

#ifndef WRPC_API_FAR
#ifdef ___WRPC_LIB_CREATION___
#define WRPC_API_FAR		EXPORT_TO_LIB_API
#define WRPC_VAR_FAR		extern EXPORT_TO_LIB_VAR
#elif defined(__USING_WRPC_SOURCES__)  // #ifdef ___WRPC_LIB_CREATION___
#define WRPC_API_FAR
#define WRPC_VAR_FAR
#else   // #ifdef ___WRPC_LIB_CREATION___
#define WRPC_API_FAR		IMPORT_FROM_LIB_API
#define WRPC_VAR_FAR		IMPORT_FROM_LIB_VAR
#endif  // #ifdef ___WRPC_LIB_CREATION___
#endif  // #ifndef WRPC_API_FAR

#ifndef __GNUC__
#define	__GNUC__		1
#define __GLIBC__		2
#define	__GLIBC_MINOR__	15
#endif  // #ifndef __GNUC__

// these 2 definations will be deleted
#ifndef LINKAGE_HDR
#define LINKAGE_HDR	WRPC_API_FAR
#endif
#ifndef LINKAGE_SRC
#define LINKAGE_SRC	WRPC_API_FAR
#endif


#endif  // #ifndef __wrpc_first_com_include_h__
