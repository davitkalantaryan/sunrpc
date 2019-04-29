//

#ifndef  FIRST_INCLUDE_FOR_GCC
#define  FIRST_INCLUDE_FOR_GCC

#define _BSD_SOURCE

#ifdef __cplusplus
#include <memory>
#endif

#include <stdint.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <netdb.h>


#ifndef __u_char_defined
//typedef uint8_t __u_char;
//typedef uint16_t __u_short;
//typedef uint32_t __u_int;
//typedef unsigned long __u_long;
typedef int64_t quad_t;
typedef int64_t u_quad_t;
//typedef int __fsid_t;
#define __u_char_defined
#endif
#ifndef __daddr_t_defined
//typedef long __daddr_t;
//typedef long __caddr_t ;
#define __daddr_t_defined
#endif

#if !defined(bool_t) && !defined(bool_t_defined)
//typedef int bool_t;
//#define bool_t_defined
#endif

#ifndef __THROW
#define __THROW
#endif

#ifndef libc_hidden_proto
//#define libc_hidden_proto(_symbol)  __attribute__((visibility("hidden"))) _symbol
#define libc_hidden_proto(_symbol)
#endif
#ifndef attribute_hidden
#define attribute_hidden
#endif

#include "rpc/auth.h"
#include "rpc/xdr.h"
#include "rpc/auth_des.h"

#ifndef libc_hidden_nolink_sunrpc
#define libc_hidden_nolink_sunrpc(...)
#endif
#ifndef __libc_lock_define_initialized
#define __libc_lock_define_initialized(...)
#endif
#ifndef __libc_once_define
#define __libc_once_define(...)
#endif

#ifndef __libc_once
#define __libc_once(...)
#endif

#ifndef libc_hidden_def
#define libc_hidden_def(...)
#endif

#ifndef _
#define _(_str) _str
#endif

#ifndef N_
#define N_(_str) _str
#endif

#ifndef IPPORT_RESERVED
# define IPPORT_RESERVED     1024
#endif

#define __libc_lock_lock(...)
#define __libc_lock_unlock(...)


#define __gettimeofday gettimeofday
#define __getpid    getpid
#define __fxprintf fprintf
#define __bind  bind
#define __gethostname  gethostname
#define __geteuid  geteuid
#define __getegid  getegid
#define __getgroups getgroups
#define __asprintf  asprintf
#define __alloca  alloca
#define __strerror_r  strerror_r
#define __close  close

#ifdef __cplusplus
extern "C"{
#endif

bool_t xdr_authdes_cred (XDR *xdrs, struct authdes_cred *cred);
bool_t xdr_authdes_verf (register XDR *xdrs, register struct authdes_verf *verf);
int __libc_rpc_gethostbyname(const char* a_hostname, struct sockaddr_in* a_pSin);
int __getprotobyname_r(const char *a_name,struct protoent *a_result_buf, char *a_buf,size_t a_buflen, struct protoent **a_pResult);

#ifdef __cplusplus
}
#endif


#endif  // #ifndef  FIRST_INCLUDE_FOR_GCC

