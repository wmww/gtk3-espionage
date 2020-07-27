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
