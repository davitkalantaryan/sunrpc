//

#ifndef  FIRST_INCLUDE_FOR_GCC
#define  FIRST_INCLUDE_FOR_GCC

#include <strings.h>

#define REGISTER
#define bool_t  int
#define IMPORT_FROM_LIB_API
#define __THROW

#ifndef bcopy
#define bcopy(_src,_dest,_size) memcpy((_dest),(_src),(_size))
#endif

#ifndef bcmp
#define bcmp(_s1,_s2,_n)    memcmp((_s1),(_s2),(_n))
#endif

#if !defined(caddr_t) && !defined(caddr_t_defined)
#define caddr_t_defined
typedef char* caddr_t;
#endif

#ifndef _
#define _(_str) _str
#endif

#ifdef __cplusplus
extern "C" {
#endif

int ffs2(int a_arg);

#ifdef __cplusplus
}
#endif

#if 0

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

#ifndef __set_errno
#define __set_errno(_errnoM) do{errno = (_errnoM);}while(0)
#endif

#ifndef libc_sunrpc_symbol
#define libc_sunrpc_symbol(...)
#endif

#ifndef text_set_element
#define text_set_element(...)
#endif

#ifndef libnss_files_hidden_proto
#define libnss_files_hidden_proto(...)
#endif

#ifndef __libc_tsd_define
#define __libc_tsd_define(...)
#endif

#ifndef attribute_tls_model_ie
#define attribute_tls_model_ie
#endif


#define __libc_lock_lock(...)
#define __libc_lock_unlock(...)

//#define svc_xports_s  SVCXPRT*


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
#define __socket    socket
#define __connect  connect
#define __glibc_unlikely(_cond)   (_cond)
#define __poll  poll
#define __read  read
#define __write  write
#define __setsockopt    setsockopt
#define __recvmsg    recvmsg
#define __sendmsg   sendmsg
#define __sendto   sendto
#define __recvfrom  recvfrom
#define __gethostbyname2_r  gethostbyname2_r
#define __getdtablesize()   (2048)
#define __strdup    strdup
#define __nanosleep  nanosleep
#define __getsockname   getsockname

#ifdef TESTS
#define REPORT_BUGS_TO  "davit.kalantaryan@desy.de"
#endif

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

#endif // #if 0

#endif  // #ifndef  FIRST_INCLUDE_FOR_GCC

