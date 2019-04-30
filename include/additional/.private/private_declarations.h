

#ifdef _typeName

    extern void** __rpc_thread_specific_variable(const char* a_name);

    static inline struct _typeName** __rpc_thread_specific_variable_##_typeName(void) { \
        struct _typeName** ppReturn = (struct _typeName**)__rpc_thread_specific_variable(#_typeName); \
        return ppReturn; \
    }


#endif
