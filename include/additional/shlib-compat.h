
#include ".private/private_declarations.h"

//#define RPC_THREAD_VARIABLE(_typeName)  ( *__rpc_thread_specific_variable_##_typeName() )

#ifndef SUNRPC_ADDITIONAL_SHLIB_COMPAT_H
#define SUNRPC_ADDITIONAL_SHLIB_COMPAT_H

#include <sys/types.h>
#include <ifaddrs.h>

//#define libc_freeres_fn (...) void __libc_freeres_fn(void* buf)

#ifdef __cplusplus
extern "C" {
#endif

void** __rpc_thread_specific_variable(const char* a_name);

#ifndef RPC_THREAD_VARIABLE
//#define RPC_THREAD_VARIABLE(_typeName)  ( (struct _typeName*)(*__rpc_thread_specific_variable(#_typeName)) )

//#define RPC_THREAD_VARIABLE(_typeName)  ( (*__rpc_thread_specific_variable(#_typeName)) )

#define RPC_THREAD_VARIABLE_RAW(_typeName)  ( (struct _typeName**)__rpc_thread_specific_variable(#_typeName) )
#define RPC_THREAD_VARIABLE(_typeName)  ( *RPC_THREAD_VARIABLE_RAW(_typeName)  )

#endif

#if !defined(__cplusplus) && !defined(bool) && !defined(bool_defined)
#define bool_defined
typedef char bool;
#endif

int ffsl(long int i);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef SUNRPC_ADDITIONAL_SHLIB_COMPAT_H
