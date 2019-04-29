# File daqadcreceiver.pro
# File created : 01 Jan 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ

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
INCLUDEPATH += $$(PWD)/../../../implglibc

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
    $$(PWD)/../../../include/additional/libio/iolibio.h

# LIBS += -lMCclass
SOURCES += \
    $$(PWD)/../../../src/lib/additional_functions_for_library.c               \
    $$(PWD)/../../../implglibc/auth_des.c               \
    $$(PWD)/../../../implglibc/authdes_prot.c           \
    $$(PWD)/../../../implglibc/auth_none.c              \
    $$(PWD)/../../../implglibc/auth_unix.c              \
    $$(PWD)/../../../implglibc/authuxprot.c             \
    $$(PWD)/../../../implglibc/bindrsvprt.c             \
    $$(PWD)/../../../implglibc/clnt_gen.c               \
    $$(PWD)/../../../implglibc/clnt_perr.c              \
    $$(PWD)/../../../implglibc/clnt_raw.c               \
    $$(PWD)/../../../implglibc/clnt_simp.c              \
    $$(PWD)/../../../implglibc/clnt_tcp.c               \
    $$(PWD)/../../../implglibc/clnt_udp.c               \
    $$(PWD)/../../../implglibc/clnt_unix.c              \
    $$(PWD)/../../../implglibc/create_xid.c             \
    $$(PWD)/../../../implglibc/des_crypt.c              \
    $$(PWD)/../../../implglibc/des_impl.c               \
    $$(PWD)/../../../implglibc/des_soft.c               \
    $$(PWD)/../../../implglibc/get_myaddr.c             \
    $$(PWD)/../../../implglibc/getrpcbyname.c           \
    $$(PWD)/../../../implglibc/getrpcbyname_r.c         \
    $$(PWD)/../../../implglibc/getrpcbynumber.c         \
    $$(PWD)/../../../implglibc/getrpcbynumber_r.c       \
    $$(PWD)/../../../implglibc/getrpcent.c              \
    $$(PWD)/../../../implglibc/getrpcent_r.c            \
    $$(PWD)/../../../implglibc/getrpcport.c             \
    $$(PWD)/../../../implglibc/key_call.c               \
    $$(PWD)/../../../implglibc/key_prot.c               \
    $$(PWD)/../../../implglibc/netname.c                \
    $$(PWD)/../../../implglibc/openchild.c              \
    $$(PWD)/../../../implglibc/pmap_clnt.c              \
    $$(PWD)/../../../implglibc/pmap_prot2.c             \
    $$(PWD)/../../../implglibc/pmap_prot.c              \
    $$(PWD)/../../../implglibc/pmap_rmt.c               \
    $$(PWD)/../../../implglibc/pm_getmaps.c             \
    $$(PWD)/../../../implglibc/pm_getport.c             \
    $$(PWD)/../../../implglibc/publickey.c              \
    $$(PWD)/../../../implglibc/rpc_clntout.c            \
    $$(PWD)/../../../implglibc/rpc_cmsg.c               \
    $$(PWD)/../../../implglibc/rpc_common.c             \
    $$(PWD)/../../../implglibc/rpc_cout.c               \
    $$(PWD)/../../../implglibc/rpc_dtable.c             \
    $$(PWD)/../../../implglibc/rpcgen.c                 \
    $$(PWD)/../../../implglibc/rpc_gethostbyname.c      \
    $$(PWD)/../../../implglibc/rpc_hout.c               \
    $$(PWD)/../../../implglibc/rpc_main.c               \
    $$(PWD)/../../../implglibc/rpc_parse.c              \
    $$(PWD)/../../../implglibc/rpc_prot.c               \
    $$(PWD)/../../../implglibc/rpc_sample.c             \
    $$(PWD)/../../../implglibc/rpc_scan.c               \
    $$(PWD)/../../../implglibc/rpc_svcout.c             \
    $$(PWD)/../../../implglibc/rpc_tblout.c             \
    $$(PWD)/../../../implglibc/rpc_thread.c             \
    $$(PWD)/../../../implglibc/rpc_util.c               \
    $$(PWD)/../../../implglibc/rtime.c                  \
    $$(PWD)/../../../implglibc/svc_auth.c               \
    $$(PWD)/../../../implglibc/svcauth_des.c            \
    $$(PWD)/../../../implglibc/svc_authux.c             \
    $$(PWD)/../../../implglibc/svc.c                    \
    $$(PWD)/../../../implglibc/svc_raw.c                \
    $$(PWD)/../../../implglibc/svc_run.c                \
    $$(PWD)/../../../implglibc/svc_simple.c             \
    $$(PWD)/../../../implglibc/svc_tcp.c                \
    $$(PWD)/../../../implglibc/svc_udp.c                \
    $$(PWD)/../../../implglibc/svc_unix.c               \
    $$(PWD)/../../../implglibc/test-rpcent.c            \
    $$(PWD)/../../../implglibc/thrsvc.c                 \
    $$(PWD)/../../../implglibc/tst-getmyaddr.c          \
    $$(PWD)/../../../implglibc/tst-svc_register.c       \
    $$(PWD)/../../../implglibc/tst-udp-error.c          \
    $$(PWD)/../../../implglibc/tst-udp-garbage.c        \
    $$(PWD)/../../../implglibc/tst-udp-nonblocking.c    \
    $$(PWD)/../../../implglibc/tst-udp-timeout.c        \
    $$(PWD)/../../../implglibc/tst-xdrmem2.c            \
    $$(PWD)/../../../implglibc/tst-xdrmem.c             \
    $$(PWD)/../../../implglibc/xcrypt.c                 \
    $$(PWD)/../../../implglibc/xdr_array.c              \
    $$(PWD)/../../../implglibc/xdr.c                    \
    $$(PWD)/../../../implglibc/xdr_float.c              \
    $$(PWD)/../../../implglibc/xdr_intXX_t.c            \
    $$(PWD)/../../../implglibc/xdr_mem.c                \
    $$(PWD)/../../../implglibc/xdr_rec.c                \
    $$(PWD)/../../../implglibc/xdr_ref.c                \
    $$(PWD)/../../../implglibc/xdr_sizeof.c             \
    $$(PWD)/../../../implglibc/xdr_stdio.c
