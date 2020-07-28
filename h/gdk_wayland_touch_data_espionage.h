/* This file is part of gtk3-espionage
 *
 * Copyright (C) 2009 Carlos Garnacho <carlosg@gnome.org>
 * Copyright © 2020 gtk3-espionage/scripts/code.py

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

#ifndef GDK_WAYLAND_TOUCH_DATA_ESPIONAGE_H
#define GDK_WAYLAND_TOUCH_DATA_ESPIONAGE_H

typedef struct _GdkWaylandTouchData GdkWaylandTouchData;

// Version ID 0
// Valid for GTK v3.22.0 - v3.24.21
struct _GdkWaylandTouchData_v3_22_0
{
  uint32_t id;
  gdouble x;
  gdouble y;
  GdkWindow *window;
  uint32_t touch_down_serial;
  guint initial_touch : 1;
};

// For internal use only
int gdk_wayland_touch_data_espionage_get_version_id() {
  static int version_id = -1;
  
  if (version_id == -1) {
    if (gtk_get_major_version() != 3) {
      g_error("gtk3-espionage only supports GTK3");
      g_abort();
    }
  
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
        break;
  
      default:
        g_warning(
          "gtk3-espionage was not compiled with support for GTK v%d.%d.%d, program may crash",
          gtk_get_major_version(),
          gtk_get_minor_version(),
          gtk_get_micro_version());
    }
  
    {
      version_id = 0;
    }
  }
  
  return version_id;
}

// GdkWaylandTouchData::id

uint32_t gdk_wayland_touch_data_espionage_get_id(GdkWaylandTouchData * self) {
  return ((struct _GdkWaylandTouchData_v3_22_0*)self)->id;
}

void gdk_wayland_touch_data_espionage_set_id(GdkWaylandTouchData * self, uint32_t id) {
  ((struct _GdkWaylandTouchData_v3_22_0*)self)->id = id;
}

// GdkWaylandTouchData::x

gdouble * gdk_wayland_touch_data_espionage_get_x_ptr(GdkWaylandTouchData * self) {
  return (gdouble *)&((struct _GdkWaylandTouchData_v3_22_0*)self)->x;
}

// GdkWaylandTouchData::y

gdouble * gdk_wayland_touch_data_espionage_get_y_ptr(GdkWaylandTouchData * self) {
  return (gdouble *)&((struct _GdkWaylandTouchData_v3_22_0*)self)->y;
}

// GdkWaylandTouchData::window

GdkWindow * gdk_wayland_touch_data_espionage_get_window(GdkWaylandTouchData * self) {
  return ((struct _GdkWaylandTouchData_v3_22_0*)self)->window;
}

void gdk_wayland_touch_data_espionage_set_window(GdkWaylandTouchData * self, GdkWindow * window) {
  ((struct _GdkWaylandTouchData_v3_22_0*)self)->window = window;
}

// GdkWaylandTouchData::touch_down_serial

uint32_t gdk_wayland_touch_data_espionage_get_touch_down_serial(GdkWaylandTouchData * self) {
  return ((struct _GdkWaylandTouchData_v3_22_0*)self)->touch_down_serial;
}

void gdk_wayland_touch_data_espionage_set_touch_down_serial(GdkWaylandTouchData * self, uint32_t touch_down_serial) {
  ((struct _GdkWaylandTouchData_v3_22_0*)self)->touch_down_serial = touch_down_serial;
}

// GdkWaylandTouchData::initial_touch

guint gdk_wayland_touch_data_espionage_get_initial_touch(GdkWaylandTouchData * self) {
  return ((struct _GdkWaylandTouchData_v3_22_0*)self)->initial_touch;
}

void gdk_wayland_touch_data_espionage_set_initial_touch(GdkWaylandTouchData * self, guint initial_touch) {
  ((struct _GdkWaylandTouchData_v3_22_0*)self)->initial_touch = initial_touch;
}

#endif // GDK_WAYLAND_TOUCH_DATA_ESPIONAGE_H
