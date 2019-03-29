# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file LICENSE or http://www.opensource.org/licenses/mit-license.php.

LIBS+= -lcurl
AM_LDFLAGS = $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
AM_CXXFLAGS = $(HARDENED_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)

TCPPDC_CONFIG_INCLUDES=-I$(builddir)/config
TCPPDC_INCLUDES=-I$(builddir) -I$(builddir)/obj

bin_PROGRAMS = tcppdc
noinst_PROGRAMS =
TESTS =

.PHONY: FORCE
# tcppdc binary #
tcppdc_SOURCES = \
  main.cpp \
  bignumber.h

tcppdc_CPPFLAGS = $(AM_CPPFLAGS) $(TCPPDC_INCLUDES)
tcppdc_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
tcppdc_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)
tcppdc_LDADD = -lgmp -lgmpxx

if TARGET_WINDOWS
tcppdc_SOURCES += tcppdc-res.rc
endif

clean-local:

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@


%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<