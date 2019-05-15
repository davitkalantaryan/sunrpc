# File daqadcreceiver.pro
# File created : 01 Jan 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ

DEFINES += TESTS
DEFINES += __FLOAT_WORD_ORDER=_LITTLE_ENDIAN

message("!!! sunrpc.pro:")

TEMPLATE = lib
#include(../../common/common_qt/sys_common.pri)

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

INCLUDEPATH += ../../../include/wlac

android {
    DEFINES += __GNU_LIBRARY__
}

HEADERS += \
    ../../../include/wlac/first_include_for_gcc.h


android|win32 {

# LIBS += -lMCclass
SOURCES += \
    ../../../src/lib/additional_functions_for_library.c        \
    ../../../src/wlac/xdr_rpc/auth_none.c                      \
    ../../../src/wlac/xdr_rpc/auth_unix_used_on_static.c       \
    ../../../src/wlac/xdr_rpc/authuxprot.c                     \
    ../../../src/wlac/xdr_rpc/clnt_gen.c                       \
    ../../../src/wlac/xdr_rpc/clnt_perr.c                      \
    ../../../src/wlac/xdr_rpc/clnt_raw.c                       \
    ../../../src/wlac/xdr_rpc/clnt_simp.c                      \
    ../../../src/wlac/xdr_rpc/clnt_tcp.c                       \
    ../../../src/wlac/xdr_rpc/clnt_udp.c                       \
    ../../../src/wlac/xdr_rpc/get_myaddr.c                     \
    ../../../src/wlac/xdr_rpc/getrpcport.c                     \
    ../../../src/wlac/xdr_rpc/pm_getmaps.c                     \
    ../../../src/wlac/xdr_rpc/pm_getport.c                     \
    ../../../src/wlac/xdr_rpc/pmap_clnt.c                      \
    ../../../src/wlac/xdr_rpc/pmap_prot.c                      \
    ../../../src/wlac/xdr_rpc/pmap_prot2.c                     \
    ../../../src/wlac/xdr_rpc/rpc_cmsg1.c                      \
    ../../../src/wlac/xdr_rpc/rpc_common.c                     \
    ../../../src/wlac/xdr_rpc/rpc_dtable.c                     \
    ../../../src/wlac/xdr_rpc/rpc_prot.c                       \
    ../../../src/wlac/xdr_rpc/svc.c                            \
    ../../../src/wlac/xdr_rpc/svc_auth.c                       \
    ../../../src/wlac/xdr_rpc/svc_authux.c                     \
    ../../../src/wlac/xdr_rpc/svc_raw.c                        \
    ../../../src/wlac/xdr_rpc/svc_run.c                        \
    ../../../src/wlac/xdr_rpc/svc_simple.c                     \
    ../../../src/wlac/xdr_rpc/svc_tcp.c                        \
    ../../../src/wlac/xdr_rpc/svc_udp.c                        \
    ../../../src/wlac/xdr_rpc/xdr.c                            \
    ../../../src/wlac/xdr_rpc/xdr_array.c                      \
    ../../../src/wlac/xdr_rpc/xdr_float.c                      \
    ../../../src/wlac/xdr_rpc/xdr_mem.c                        \
    ../../../src/wlac/xdr_rpc/xdr_rec.c                        \
    ../../../src/wlac/xdr_rpc/xdr_ref.c                        \
    ../../../src/wlac/xdr_rpc/xdr_stdio.c

}
