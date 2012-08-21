AC_INIT([lightdm-remote-session-freerdp], [0.1])

AM_INIT_AUTOMAKE([1.11 -Wno-portability])
AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_CC_C_O

###########################
# Local Install
###########################

with_localinstall="no"
AC_ARG_ENABLE(localinstall, AS_HELP_STRING([--enable-localinstall],
                                           [install all files locally (for distcheck)]),
              with_localinstall=$enableval,
              with_localinstall=no)

###########################
# PAM Module dir
###########################

if test "x$with_localinstall" = "xyes"; then
	PAMMODULEDIR="${libdir}/security/"
else
	PAMMODULEDIR="/lib/security"
fi
AC_SUBST(PAMMODULEDIR)


AC_CONFIG_FILES([
  Makefile
])
AC_OUTPUT
