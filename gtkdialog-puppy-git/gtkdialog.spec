# $Id: gtkdialog.spec.in,v 1.2 2004/11/22 06:36:20 pipas Exp pipas $
#
# Copyright (c) 2003 Pere Laszlo pipas@linux.pte.hu
#
%define name gtkdialog
%define version 0.8.4
%define release 1
%define manifest %{_builddir}/%{name}-%{version}-%{release}.manifest

Name: %{name}
Version: %{version}
Release: %{release}
License: GPL GNU
Group: Application/Misc
Packager: Pere Laszlo pipas@linux.pte.hu
Source: %{name}-%{version}.tar.gz
URL: ftp://linux.pte.hu/pub/gtkdialog/%{name}-%{version}.tar.gz
BuildRoot: /var/tmp/%{name}-%{version}

Summary: GUI creation tool for shells and arbitrary interpreters. 

%description
The gtkdialog is uses an XML like simple language as a GUI description
language to produce dialog boxes. The program can be used with shells
and arbitrary interpreters. Example programs included for BASH and AWK.

%prep
%setup -q

%build
%configure
make

rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT
%makeinstall


%{?__os_install_post}
%define __os_install_post %{nil}

# build the file list automagically into %{manifest}

cd $RPM_BUILD_ROOT
rm -f %{manifest}
find . -type d \
        | sed '1,2d;s,^\.,\%attr(-\,root\,root) \%dir ,' >> %{manifest}
find . -type f \
        | sed 's,^\.,\%attr(-\,root\,root) ,' >> %{manifest}
find . -type l \
        | sed 's,^\.,\%attr(-\,root\,root) ,' >> %{manifest}

%clean
rm -f %{manifest}
rm -rf $RPM_BUILD_ROOT

%files -f %{manifest}
%defattr(-,root,root)
%doc README TODO examples

%changelog
* Thu Nov 25 2004 Laszlo Pere <pipas@linux.pte.hu> 0.59.0
- New version numbers: this is the unstable version (59 is odd).
- It is possible now to preset radiobuttons with the <default> tag.
- The syntax of --program option is changed. See --help.

* Wed Nov 24 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.12
- Environment variable name after the --program option now optional,
the default is: MAIN_WINDOW
- The -geometry option is working as it should be (see "man X")
- Menu can have a command witf type (eg. <command type="insert">)
- The tree widget is much more better now

* Sun Nov 21 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.11
- A new widget: <gvim>, which is not working correctly.
- A new widget: <tree>, barely functional.

* Sat Nov 20 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.10
- New widget: menubar with menu and menuitems inside.
- The label widget can get text from an input file.
- The program will not print the default named widgets from now.
- Better error messages for unknown tags.
- New action: <action copy>FROM, TO</action>
- List widgets have a variable called XXX_ALL.
- Icon search path is: 
-   (1) the working directory, 
-   (2) /usr/share/icons/Bluecurve/16x16/stock/, 
-   (3) Anywhere if the locate finds it 

* Fri Nov 19 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.9
- stringman.c: A bug with the multi-column tables fixed.
- The button now can contain label beside a pixmap.

* Fri Jun 4 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.5
- Texinfo documentation (mostly empty :-)
- Bash completion scripts as examples.

* Thu Apr 22 2004 Laszlo Pere <pipas@linux.pte.hu> 0.58.6
- The <edit> widget can accept <output file> attribute.
- There is a new action for saving a widget's content into file.  See gtk_edit for example.
- The sizes of widgets are corrected. Some widgets can grow---list, table, edit, frame, etc.---but some can't---buttons, entries, etc.
- The entry widgets can take actions which called when a key pressed after the entry is updated.

