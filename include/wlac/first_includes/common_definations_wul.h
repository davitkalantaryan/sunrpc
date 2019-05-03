/*
 *	File: <common_definations_wul.h> 
 *
 *	Created on: Dec 23, 2015
 *	Author    : Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *
 */
#ifndef __common_definations_wul_h__
#define __common_definations_wul_h__

#ifdef _WIN64
#ifndef WIN32
#define WIN32
#endif
#endif

#ifdef WIN32
#define PATH_CHAR	'\\'
#else
#define PATH_CHAR	'/'
#endif

#ifdef _MSC_VER

#define IMPORT_FROM_LIB_API		_declspec(dllimport)
#define IMPORT_FROM_LIB_VAR		extern _declspec(dllimport)
#define EXPORT_TO_LIB_API		_declspec(dllexport)
#define EXPORT_TO_LIB_VAR		_declspec(dllexport)
#define	NOT_IMPLEMENTED_API

#elif defined(__GNUC__)  // #ifdef _MSC_VER

#else  // #ifdef _MSC_VER

#endif // #ifdef _MSC_VER

#ifndef __BEGIN_C_DECLS
#ifdef __cplusplus
#define __BEGIN_C_DECLS	extern "C" {
#else  /* #ifdef __cplusplus */
#define __BEGIN_C_DECLS
#endif	/* #ifdef __cplusplus */
#endif  /* #ifndef __BEGIN_C_DECLS */

#ifndef __END_C_DECLS
#ifdef __cplusplus
#define	__END_C_DECLS		}
#else  /* #ifdef __cplusplus */
#define	__END_C_DECLS
#endif	/* #ifdef __cplusplus */
#endif  /* #ifndef __END_C_DECLS */


#ifdef _MSC_VER
//#define _DEPRICATED_TEXT_(_text_)	__declspec(deprecated(_text_))
#define _DEPRICATED_TEXT_(_text_)
#define _DEPRICATED_	_DEPRICATED_TEXT_("")
#else  // #ifdef _MSC_VER
#define	_DEPRICATED_	__attribute__((deprecated))
#endif  // #ifdef _MSC_VER

#if 0
#ifdef _MSC_VER
#if(_MSC_VER >= 1400)
//#define		_CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
#endif  // #if(_MSC_VER >= 1400)
#ifndef WARNING_
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : Warning Msg: "
//#pragma message(__LOC__"Need to do 3D collision testing")
#define WARNING_(_TEXT_)	message(__LOC__ (_TEXT_))
#endif	//#ifndef WARNING_
//#pragma WARNING("Need to do 3D collision testing")
#else/* #ifdef _MSC_VER */
#define __GENERATOR__(hash,text) hash warning text
//#define WARNING(x) Generator(#,x)
#endif
#endif

#endif  /* #ifndef __common_definations_wul_h__ */
