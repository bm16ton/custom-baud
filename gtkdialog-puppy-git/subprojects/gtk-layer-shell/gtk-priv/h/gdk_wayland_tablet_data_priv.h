/* AUTOGENERATED, DO NOT EDIT DIRECTLY
 * See gtk-priv/README.md for more information
 *
 * This file is part of gtk-layer-shell
 *
 * Copyright (C) 2009 Carlos Garnacho <carlosg@gnome.org>
 * Copyright © 2022 gtk-priv/scripts/code.py
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef GDK_WAYLAND_TABLET_DATA_PRIV_H
#define GDK_WAYLAND_TABLET_DATA_PRIV_H

#include "common.h"

typedef struct _GdkWaylandTabletData GdkWaylandTabletData;

// Version ID 0
// Valid for GTK v3.22.0 - v3.24.35 (unreleased)
struct _GdkWaylandTabletData_v3_22_0
{
  struct zwp_tablet_v2 *wp_tablet;
  gchar *name;
  gchar *path;
  uint32_t vid;
  uint32_t pid;
  GdkDevice *master;
  GdkDevice *stylus_device;
  GdkDevice *eraser_device;
  GdkDevice *current_device;
  GdkSeat *seat;
  struct _GdkWaylandPointerData_v3_22_0 pointer_info;
  GList *pads;
  GdkWaylandTabletToolData *current_tool;
  gint axis_indices[GDK_AXIS_LAST];
  gdouble *axes;
};

// For internal use only
int gdk_wayland_tablet_data_priv_get_version_id() {
  static int version_id = -1;
  
  if (version_id == -1) {
    gtk_priv_assert_gtk_version_valid();
    int combo = gtk_get_minor_version() * 1000 + gtk_get_micro_version();
  
    switch (combo) {
      case 22000:
      case 22001:
      case 22002:
      case 22003:
      case 22004:
      case 22005:
      case 22006:
      case 22007:
      case 22008:
      case 22009:
      case 22010:
      case 22011:
      case 22012:
      case 22013:
      case 22014:
      case 22015:
      case 22016:
      case 22017:
      case 22018:
      case 22019:
      case 22020:
      case 22021:
      case 22022:
      case 22023:
      case 22024:
      case 22025:
      case 22026:
      case 22027:
      case 22028:
      case 22029:
      case 22030:
      case 23000:
      case 23001:
      case 23002:
      case 23003:
      case 24000:
      case 24001:
      case 24002:
      case 24003:
      case 24004:
      case 24005:
      case 24006:
      case 24007:
      case 24008:
      case 24009:
      case 24010:
      case 24011:
      case 24012:
      case 24013:
      case 24014:
      case 24015:
      case 24016:
      case 24017:
      case 24018:
      case 24020:
      case 24021:
      case 24022:
      case 24023:
      case 24024:
      case 24025:
      case 24026:
      case 24027:
      case 24028:
      case 24029:
      case 24030:
      case 24031:
      case 24032:
      case 24033:
      case 24034:
        break;
  
      default:
        gtk_priv_warn_gtk_version_may_be_unsupported();
    }
  
    {
      version_id = 0;
    }
  }
  
  return version_id;
}

// GdkWaylandTabletData::wp_tablet

struct zwp_tablet_v2 * gdk_wayland_tablet_data_priv_get_wp_tablet(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->wp_tablet;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_wp_tablet(GdkWaylandTabletData * self, struct zwp_tablet_v2 * wp_tablet) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->wp_tablet = wp_tablet; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::name

gchar * gdk_wayland_tablet_data_priv_get_name(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->name;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_name(GdkWaylandTabletData * self, gchar * name) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->name = name; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::path

gchar * gdk_wayland_tablet_data_priv_get_path(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->path;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_path(GdkWaylandTabletData * self, gchar * path) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->path = path; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::vid

uint32_t gdk_wayland_tablet_data_priv_get_vid(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->vid;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_vid(GdkWaylandTabletData * self, uint32_t vid) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->vid = vid; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::pid

uint32_t gdk_wayland_tablet_data_priv_get_pid(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pid;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_pid(GdkWaylandTabletData * self, uint32_t pid) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->pid = pid; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::master

GdkDevice * gdk_wayland_tablet_data_priv_get_master(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->master;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_master(GdkWaylandTabletData * self, GdkDevice * master) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->master = master; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::stylus_device

GdkDevice * gdk_wayland_tablet_data_priv_get_stylus_device(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->stylus_device;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_stylus_device(GdkWaylandTabletData * self, GdkDevice * stylus_device) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->stylus_device = stylus_device; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::eraser_device

GdkDevice * gdk_wayland_tablet_data_priv_get_eraser_device(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->eraser_device;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_eraser_device(GdkWaylandTabletData * self, GdkDevice * eraser_device) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->eraser_device = eraser_device; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::current_device

GdkDevice * gdk_wayland_tablet_data_priv_get_current_device(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_device;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_current_device(GdkWaylandTabletData * self, GdkDevice * current_device) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_device = current_device; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::seat

GdkSeat * gdk_wayland_tablet_data_priv_get_seat(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->seat;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_seat(GdkWaylandTabletData * self, GdkSeat * seat) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->seat = seat; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::pointer_info

GdkWaylandPointerData * gdk_wayland_tablet_data_priv_get_pointer_info_ptr(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return (GdkWaylandPointerData *)&((struct _GdkWaylandTabletData_v3_22_0*)self)->pointer_info;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::pads

GList * gdk_wayland_tablet_data_priv_get_pads(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pads;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_pads(GdkWaylandTabletData * self, GList * pads) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->pads = pads; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::current_tool

GdkWaylandTabletToolData * gdk_wayland_tablet_data_priv_get_current_tool(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_tool;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_current_tool(GdkWaylandTabletData * self, GdkWaylandTabletToolData * current_tool) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_tool = current_tool; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::axis_indices

gint* * gdk_wayland_tablet_data_priv_get_axis_indices_ptr(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return (gint* *)&((struct _GdkWaylandTabletData_v3_22_0*)self)->axis_indices;
    default: g_error("Invalid version ID"); g_abort();
  }
}

// GdkWaylandTabletData::axes

gdouble * gdk_wayland_tablet_data_priv_get_axes(GdkWaylandTabletData * self) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: return ((struct _GdkWaylandTabletData_v3_22_0*)self)->axes;
    default: g_error("Invalid version ID"); g_abort();
  }
}

void gdk_wayland_tablet_data_priv_set_axes(GdkWaylandTabletData * self, gdouble * axes) {
  switch (gdk_wayland_tablet_data_priv_get_version_id()) {
    case 0: ((struct _GdkWaylandTabletData_v3_22_0*)self)->axes = axes; break;
    default: g_error("Invalid version ID"); g_abort();
  }
}

#endif // GDK_WAYLAND_TABLET_DATA_PRIV_H