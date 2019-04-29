
#ifndef SUNRPC_ADDITIONAL_SHLIB_COMPAT_H
#define SUNRPC_ADDITIONAL_SHLIB_COMPAT_H

void** __rpc_thread_specific_variable(const char* a_name);

#ifndef RPC_THREAD_VARIABLE
//#define RPC_THREAD_VARIABLE(_typeName)  ( (struct _typeName*)(*__rpc_thread_specific_variable(#_typeName)) )
#define RPC_THREAD_VARIABLE(_typeName)  ( (*__rpc_thread_specific_variable(#_typeName)) )
#endif

#endif  // #ifndef SUNRPC_ADDITIONAL_SHLIB_COMPAT_H
