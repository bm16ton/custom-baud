#
# We do this becouse this way we can use multiple parsers in a single binary
# program.
#
AM_LFLAGS=-P$$(basename $@ lexer.c) -olex.yy.c
AM_YFLAGS=-d -p $$(basename $@ parser.c)
BUILT_SOURCES = \
	gtkdialog_parser.h 

bin_PROGRAMS = gtkdialog 
gtkdialog_SOURCES = \
	gtkdialog.c gtkdialog.h \
	macros.h \
	printing.c printing.h \
	variables.c variables.h \
	gtkdialog_parser.y gtkdialog_lexer.l \
	stack.c stack.h \
	automaton.c automaton.h \
	attributes.c attributes.h \
	signals.c signals.h \
	stringman.c stringman.h \
	widgets.c widgets.h \
	actions.c actions.h \
	tag_attributes.c tag_attributes.h \
	glade_support.c glade_support.h \
	scrolling.c scrolling.h \
	widget_button.c widget_button.h \
	widget_checkbox.c widget_checkbox.h \
	widget_chooser.c widget_chooser.h \
	widget_colorbutton.c widget_colorbutton.h \
	widget_combobox.c widget_combobox.h \
	widget_comboboxtext.c widget_comboboxtext.h \
	widget_edit.c widget_edit.h \
	widget_entry.c widget_entry.h \
	widget_eventbox.c widget_eventbox.h \
	widget_expander.c widget_expander.h \
	widget_fontbutton.c widget_fontbutton.h \
	widget_frame.c widget_frame.h \
	widget_hbox.c widget_hbox.h \
	widget_hscale.c widget_hscale.h \
	widget_hseparator.c widget_hseparator.h \
	widget_list.c widget_list.h \
	widget_menubar.c widget_menubar.h \
	widget_menuitem.c widget_menuitem.h \
	widget_notebook.c widget_notebook.h \
	widget_pixmap.c widget_pixmap.h \
	widget_progressbar.c widget_progressbar.h \
	widget_radiobutton.c widget_radiobutton.h \
	widget_spinbutton.c widget_spinbutton.h \
	widget_statusbar.c widget_statusbar.h \
	widget_table.c widget_table.h \
	widget_terminal.c widget_terminal.h \
	widget_text.c widget_text.h \
	widget_timer.c widget_timer.h \
	widget_tree.c widget_tree.h \
	widget_vbox.c widget_vbox.h \
	widget_window.c widget_window.h

AM_CFLAGS = \
	$(GTK_CFLAGS) -DHAVE_GTK=$(HAVE_GTK) \
	$(GTHREAD_CFLAGS) \
	$(GLADE_LIB_CFLAGS) -DHAVE_GLADE_LIB=$(HAVE_GLADE_LIB) \
	$(VTE_CFLAGS) -DHAVE_VTE=$(HAVE_VTE)

LIBS = \
	$(GTK_LIBS) \
	$(GTHREAD_LIBS) \
	$(GLADE_LIB_LIBS) \
	$(VTE_LIBS) \
	@LIBS@

