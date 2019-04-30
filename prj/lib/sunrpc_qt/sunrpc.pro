# File daqadcreceiver.pro
# File created : 01 Jan 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ

DEFINES += TESTS
DEFINES += __FLOAT_WORD_ORDER=_LITTLE_ENDIAN

message("!!! sunrpc.pro:")

TEMPLATE = lib
include(../../common/common_qt/sys_common.pri)

QT -= core
QT -= gui

QMAKE_CXXFLAGS += -include first_include_for_gcc.h
QMAKE_CFLAGS += -include first_include_for_gcc.h
QMAKE_CXXFLAGS_WARN_ON += -Wno-attributes

#QMAKE_CFLAGS_WARN_ON += -Wno-self-assign
#QMAKE_CFLAGS_WARN_ON += -Wno-tautological-pointer-compare
#QMAKE_CFLAGS_WARN_ON += -Wno-absolute-value
#QMAKE_CFLAGS_WARN_ON += -Wno-null-pointer-arithmetic
#QMAKE_CFLAGS_WARN_ON += -Wno-implicit-function-declaration
#QMAKE_CFLAGS_WARN_ON += -Wno-sometimes-uninitialized
#QMAKE_CFLAGS_WARN_ON += -Wno-unused-variable
QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CFLAGS_WARN_ON += -Wno-unused-function
QMAKE_CFLAGS_WARN_ON += -Wno-deprecated-declarations
QMAKE_CFLAGS_WARN_ON += -Wno-int-conversion
QMAKE_CFLAGS_WARN_ON += -Wno-sign-compare
QMAKE_CFLAGS_WARN_ON += -Wno-incompatible-pointer-types


#QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS += -std=c++14
CONFIG += c++14

DEFINES += MULTITHREADED
DEFINES += LINUX
DEFINES += API_VERSION_TO_USE=26

INCLUDEPATH += $${PWD}/../../../include
INCLUDEPATH += $${PWD}/../../../include/additional
INCLUDEPATH += $$(PWD)/../../../include/glibc
INCLUDEPATH += $$(PWD)/../../../src/glibc

android {
    DEFINES += __GNU_LIBRARY__
    INCLUDEPATH += $${PWD}/../../../include/android
    INCLUDEPATH += $${PWD}/../../../include/android/openldap_include
}

HEADERS += \
    $$(PWD)/../../../include/first_include_for_gcc.h \
    $$(PWD)/../../../include/additional/libintl.h  \
    $$(PWD)/../../../include/additional/shlib-compat.h   \
    $$(PWD)/../../../include/additional/libc-lock.h  \
    $$(PWD)/../../../include/additional/libio/iolibio.h \
    $$(PWD)/../../../include/additional/errqueue.h \
    $$(PWD)/../../../include/additional/kernel-features.h \
    $$(PWD)/../../../include/additional/inet/net-internal.h \
    $$(PWD)/../../../include/version.h \
    $$(PWD)/../../../include/additional/.private/private_declarations.h \

# LIBS += -lMCclass
SOURCES += \
    $$(PWD)/../../../src/lib/additional_functions_for_library.c               \
    $$(PWD)/../../../src/glibc/sunrpc/auth_none.c              \
    $$(PWD)/../../../src/glibc/sunrpc/auth_unix.c              \
    $$(PWD)/../../../src/glibc/sunrpc/authuxprot.c             \
    $$(PWD)/../../../src/glibc/sunrpc/bindrsvprt.c             \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_gen.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_perr.c              \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_raw.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_simp.c              \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_tcp.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_udp.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_unix.c              \
    $$(PWD)/../../../src/glibc/sunrpc/get_myaddr.c             \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcport.c             \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_clnt.c              \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_prot2.c             \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_prot.c              \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_rmt.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_clntout.c            \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_cmsg.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_common.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_cout.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_dtable.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpcgen.c                 \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_hout.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_parse.c              \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_prot.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_sample.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_scan.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_svcout.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_tblout.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_thread.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_util.c               \
    $$(PWD)/../../../src/glibc/sunrpc/svc_auth.c               \
    $$(PWD)/../../../src/glibc/sunrpc/svc_authux.c             \
    $$(PWD)/../../../src/glibc/sunrpc/svc.c                    \
    $$(PWD)/../../../src/glibc/sunrpc/svc_raw.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_run.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_simple.c             \
    $$(PWD)/../../../src/glibc/sunrpc/svc_tcp.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_udp.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_unix.c               \
    $$(PWD)/../../../src/glibc/sunrpc/xcrypt.c                 \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_array.c              \
    $$(PWD)/../../../src/glibc/sunrpc/xdr.c                    \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_float.c              \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_intXX_t.c            \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_mem.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_rec.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_ref.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_sizeof.c             \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_stdio.c



OTHER_FILES += \
    $$(PWD)/../../../src/lib/additional_functions_for_library.c               \
    $$(PWD)/../../../src/glibc/sunrpc/auth_des.c               \
    $$(PWD)/../../../src/glibc/sunrpc/authdes_prot.c           \
    $$(PWD)/../../../src/glibc/sunrpc/auth_none.c              \
    $$(PWD)/../../../src/glibc/sunrpc/auth_unix.c              \
    $$(PWD)/../../../src/glibc/sunrpc/authuxprot.c             \
    $$(PWD)/../../../src/glibc/sunrpc/bindrsvprt.c             \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_gen.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_perr.c              \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_raw.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_simp.c              \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_tcp.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_udp.c               \
    $$(PWD)/../../../src/glibc/sunrpc/clnt_unix.c              \
    $$(PWD)/../../../src/glibc/sunrpc/create_xid.c             \
    $$(PWD)/../../../src/glibc/sunrpc/des_crypt.c              \
    $$(PWD)/../../../src/glibc/sunrpc/des_impl.c               \
    $$(PWD)/../../../src/glibc/sunrpc/des_soft.c               \
    $$(PWD)/../../../src/glibc/sunrpc/get_myaddr.c             \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcbyname.c           \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcbyname_r.c         \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcbynumber.c         \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcbynumber_r.c       \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcent.c              \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcent_r.c            \
    $$(PWD)/../../../src/glibc/sunrpc/getrpcport.c             \
    $$(PWD)/../../../src/glibc/sunrpc/key_call.c               \
    $$(PWD)/../../../src/glibc/sunrpc/key_prot.c               \
    $$(PWD)/../../../src/glibc/sunrpc/netname.c                \
    $$(PWD)/../../../src/glibc/sunrpc/openchild.c              \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_clnt.c              \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_prot2.c             \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_prot.c              \
    $$(PWD)/../../../src/glibc/sunrpc/pmap_rmt.c               \
    $$(PWD)/../../../src/glibc/sunrpc/pm_getmaps.c             \
    $$(PWD)/../../../src/glibc/sunrpc/pm_getport.c             \
    $$(PWD)/../../../src/glibc/sunrpc/publickey.c              \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_clntout.c            \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_cmsg.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_common.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_cout.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_dtable.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpcgen.c                 \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_gethostbyname.c      \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_hout.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_main.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_parse.c              \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_prot.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_sample.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_scan.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_svcout.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_tblout.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_thread.c             \
    $$(PWD)/../../../src/glibc/sunrpc/rpc_util.c               \
    $$(PWD)/../../../src/glibc/sunrpc/rtime.c                  \
    $$(PWD)/../../../src/glibc/sunrpc/svc_auth.c               \
    $$(PWD)/../../../src/glibc/sunrpc/svcauth_des.c            \
    $$(PWD)/../../../src/glibc/sunrpc/svc_authux.c             \
    $$(PWD)/../../../src/glibc/sunrpc/svc.c                    \
    $$(PWD)/../../../src/glibc/sunrpc/svc_raw.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_run.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_simple.c             \
    $$(PWD)/../../../src/glibc/sunrpc/svc_tcp.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_udp.c                \
    $$(PWD)/../../../src/glibc/sunrpc/svc_unix.c               \
    $$(PWD)/../../../src/glibc/sunrpc/test-rpcent.c            \
    $$(PWD)/../../../src/glibc/sunrpc/thrsvc.c                 \
    $$(PWD)/../../../src/glibc/sunrpc/tst-getmyaddr.c          \
    $$(PWD)/../../../src/glibc/sunrpc/tst-svc_register.c       \
    $$(PWD)/../../../src/glibc/sunrpc/tst-udp-error.c          \
    $$(PWD)/../../../src/glibc/sunrpc/tst-udp-garbage.c        \
    $$(PWD)/../../../src/glibc/sunrpc/tst-udp-nonblocking.c    \
    $$(PWD)/../../../src/glibc/sunrpc/tst-udp-timeout.c        \
    $$(PWD)/../../../src/glibc/sunrpc/tst-xdrmem2.c            \
    $$(PWD)/../../../src/glibc/sunrpc/tst-xdrmem.c             \
    $$(PWD)/../../../src/glibc/sunrpc/xcrypt.c                 \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_array.c              \
    $$(PWD)/../../../src/glibc/sunrpc/xdr.c                    \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_float.c              \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_intXX_t.c            \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_mem.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_rec.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_ref.c                \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_sizeof.c             \
    $$(PWD)/../../../src/glibc/sunrpc/xdr_stdio.c
