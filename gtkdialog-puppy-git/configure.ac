# Process this file with autoconf to produce a configure script.
AC_INIT([gtkdialog], [0.8.5], [thunorsif@hotmail.com], [gtkdialog],
	[http://code.google.com/p/gtkdialog/])
AM_INIT_AUTOMAKE
#AM_CONFIG_HEADER([config.h]) Obsolete.
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

# Setting config.h macros.
AC_PATH_PROG(svnv, svnversion)
if test "x$svnv" != "x" && test `$svnv -n` != "exported"; then
	AC_DEFINE_UNQUOTED(BUILD_DETAILS, ["r`svnversion -n`"], [Build details])
else
	AC_DEFINE_UNQUOTED(BUILD_DETAILS, ["release"], [Build details])
fi
# Don't uncomment this as there's a limit on the number of file
# descriptors -- see /proc/sys/fs/inotify/max_user_instances
#AC_CHECK_HEADER([sys/inotify.h], [AC_DEFINE([HAVE_SYS_INOTIFY_H], 1,
#	[Define to 1 if you have the <sys/inotify.h> header file.])])

# Checks for programs.
AC_ISC_POSIX
#AM_PROG_CC_STDC Obsolete.
AC_PROG_CC
AC_HEADER_STDC
AM_PROG_LEX
AC_PROG_YACC
AC_SUBST(YACC)

# *** gtk3: Support automatically checking for the correct libraries.
AC_ARG_ENABLE([gtk3], AS_HELP_STRING([--enable-gtk3],
	[Enable support for GTK+ 3 (GTK+ 2 is currently the default if both available)]))

AC_ARG_WITH([gtkapi],
	[AS_HELP_STRING([--with-gtkapi],
		[Choose GTK+ api version (2.0 or 3.0) (default is auto)])],
	[],
	[with_gtkapi=auto])

AS_IF([test "x$with_gtkapi" = "x3.0"], [enable_gtk3=yes],
	[test "x$with_gtkapi" = "xauto"],
		[PKG_CHECK_EXISTS([gtk+-2.0],,
			[PKG_CHECK_EXISTS([gtk+-3.0],
				[enable_gtk3=yes])
			])
		])

# Checks for libraries.
pkg_modules="gthread-2.0"
PKG_CHECK_MODULES(GTHREAD, [$pkg_modules])
AC_SUBST(GTHREAD_CFLAGS)
AC_SUBST(GTHREAD_LIBS)

AS_IF([test "x$enable_gtk3" = "xyes"], [
	pkg_modules="gtk+-3.0 >= 3.0.0"
	PKG_CHECK_MODULES(GTK, \
		[$pkg_modules], \
		AC_SUBST(HAVE_GTK, 3),\
		AC_SUBST(HAVE_GTK, 0))
	AC_SUBST(GTK_CFLAGS)
	AC_SUBST(GTK_LIBS)

	AC_SUBST(HAVE_GLADE_LIB, 0)

	PKG_CHECK_MODULES([VTE],
		[vte-2.91 >= 0.30.0],
		AC_SUBST(HAVE_VTE, 1),
		[PKG_CHECK_MODULES([VTE],
			[vte-2.90 >= 0.30.0],
			AC_SUBST(HAVE_VTE, 1),
			AC_SUBST(HAVE_VTE, 0))]
)
	AC_SUBST(VTE_CFLAGS)
	AC_SUBST(VTE_LIBS)
],
[
	pkg_modules="gtk+-2.0 >= 2.0.0"
	PKG_CHECK_MODULES(GTK, \
		[$pkg_modules], \
		AC_SUBST(HAVE_GTK, 2),\
		AC_SUBST(HAVE_GTK, 0))
	AC_SUBST(GTK_CFLAGS)
	AC_SUBST(GTK_LIBS)

	glade_lib="libglade-2.0"
	PKG_CHECK_MODULES([GLADE_LIB], \
		[$glade_lib], \
		AC_SUBST(HAVE_GLADE_LIB, 1),\
		AC_SUBST(HAVE_GLADE_LIB, 0))
	AC_SUBST(GLADE_LIB_CFLAGS)
	AC_SUBST(GLADE_LIB_LIBS)

	vte_lib="vte >= 0.23.5"
	PKG_CHECK_MODULES([VTE], \
		[$vte_lib], \
		AC_SUBST(HAVE_VTE, 1),\
		AC_SUBST(HAVE_VTE, 0))
	AC_SUBST(VTE_CFLAGS)
	AC_SUBST(VTE_LIBS)
])

# Checks for header files.
AC_CHECK_HEADERS([locale.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

#AC_CONFIG_FILES([])
AC_OUTPUT(
	Makefile
	gtkdialog.spec
	src/Makefile
	doc/Makefile
	data/Makefile
	data/icons/Makefile
	data/icons/hicolor/Makefile
	data/icons/hicolor/32x32/Makefile
	data/icons/hicolor/32x32/apps/Makefile
)
