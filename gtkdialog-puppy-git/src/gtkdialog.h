/*
 * gtkdialog.h:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GTKDIALOG_H
#define GTKDIALOG_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <gtk/gtk.h>
#include "variables.h"
#include "automaton.h"

#define PRG_UNKNOWN 0
#define PRG_MEMORY  1
#define PRG_STDIN   2
#define PRG_FILE    3

#define GTKD_FUNCTION_SIGNALS_BLOCK (function_signals_block++)
#define GTKD_FUNCTION_SIGNALS_UNBLOCK (function_signals_block--)
#define GTKD_FUNCTION_SIGNALS_RESET (function_signals_block = FALSE)

#ifndef GTKDIALOG_NO_EXTERN
extern gint function_signals_block;

extern gint project_space_expand;
extern gint project_space_fill;

extern GtkWidget *lastradiowidget;

extern GList *accel_groups;

extern GList *widget_hide_list, *widget_show_list;

extern gint window_id;
#endif

void reset_program_source(void);
//Redundant: gint set_program_source(gchar *name);
gint get_program_from_variable(gchar *name);
void set_program_name(gchar *name);
gchar *get_program_name(void);
void load_styles_file(gchar *filename);

#endif
