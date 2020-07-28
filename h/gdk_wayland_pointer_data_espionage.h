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

#ifndef GDK_WAYLAND_POINTER_DATA_ESPIONAGE_H
#define GDK_WAYLAND_POINTER_DATA_ESPIONAGE_H

typedef struct _GdkWaylandPointerData GdkWaylandPointerData;

// Version ID 0
// Valid for GTK v3.22.0 - v3.24.21
struct _GdkWaylandPointerData_v3_22_0
{
  GdkWindow *focus;
  double surface_x;
  double surface_y;;
  GdkModifierType button_modifiers;
  uint32_t time;
  uint32_t enter_serial;
  uint32_t press_serial;
  GdkWindow *grab_window;
  uint32_t grab_time;
  struct wl_surface *pointer_surface;
  GdkCursor *cursor;
  guint cursor_timeout_id;
  guint cursor_image_index;
  guint cursor_image_delay;
  guint current_output_scale;
  GSList *pointer_surface_outputs;
  struct _GdkWaylandPointerFrameData_v3_22_0 frame;
};

// For internal use only
int gdk_wayland_pointer_data_espionage_get_version_id() {
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

// GdkWaylandPointerData::focus

GdkWindow * gdk_wayland_pointer_data_espionage_get_focus(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->focus;
}

void gdk_wayland_pointer_data_espionage_set_focus(GdkWaylandPointerData * self, GdkWindow * focus) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->focus = focus;
}

// GdkWaylandPointerData::surface_x

double gdk_wayland_pointer_data_espionage_get_surface_x(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_x;
}

void gdk_wayland_pointer_data_espionage_set_surface_x(GdkWaylandPointerData * self, double surface_x) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_x = surface_x;
}

// GdkWaylandPointerData::surface_y

double gdk_wayland_pointer_data_espionage_get_surface_y(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_y;
}

void gdk_wayland_pointer_data_espionage_set_surface_y(GdkWaylandPointerData * self, double surface_y) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_y = surface_y;
}

// GdkWaylandPointerData::button_modifiers

GdkModifierType * gdk_wayland_pointer_data_espionage_get_button_modifiers_ptr(GdkWaylandPointerData * self) {
  return (GdkModifierType *)&((struct _GdkWaylandPointerData_v3_22_0*)self)->button_modifiers;
}

// GdkWaylandPointerData::time

uint32_t gdk_wayland_pointer_data_espionage_get_time(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->time;
}

void gdk_wayland_pointer_data_espionage_set_time(GdkWaylandPointerData * self, uint32_t time) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->time = time;
}

// GdkWaylandPointerData::enter_serial

uint32_t gdk_wayland_pointer_data_espionage_get_enter_serial(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->enter_serial;
}

void gdk_wayland_pointer_data_espionage_set_enter_serial(GdkWaylandPointerData * self, uint32_t enter_serial) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->enter_serial = enter_serial;
}

// GdkWaylandPointerData::press_serial

uint32_t gdk_wayland_pointer_data_espionage_get_press_serial(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->press_serial;
}

void gdk_wayland_pointer_data_espionage_set_press_serial(GdkWaylandPointerData * self, uint32_t press_serial) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->press_serial = press_serial;
}

// GdkWaylandPointerData::grab_window

GdkWindow * gdk_wayland_pointer_data_espionage_get_grab_window(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_window;
}

void gdk_wayland_pointer_data_espionage_set_grab_window(GdkWaylandPointerData * self, GdkWindow * grab_window) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_window = grab_window;
}

// GdkWaylandPointerData::grab_time

uint32_t gdk_wayland_pointer_data_espionage_get_grab_time(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_time;
}

void gdk_wayland_pointer_data_espionage_set_grab_time(GdkWaylandPointerData * self, uint32_t grab_time) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_time = grab_time;
}

// GdkWaylandPointerData::pointer_surface

struct wl_surface * gdk_wayland_pointer_data_espionage_get_pointer_surface(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface;
}

void gdk_wayland_pointer_data_espionage_set_pointer_surface(GdkWaylandPointerData * self, struct wl_surface * pointer_surface) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface = pointer_surface;
}

// GdkWaylandPointerData::cursor

GdkCursor * gdk_wayland_pointer_data_espionage_get_cursor(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor;
}

void gdk_wayland_pointer_data_espionage_set_cursor(GdkWaylandPointerData * self, GdkCursor * cursor) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor = cursor;
}

// GdkWaylandPointerData::cursor_timeout_id

guint gdk_wayland_pointer_data_espionage_get_cursor_timeout_id(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_timeout_id;
}

void gdk_wayland_pointer_data_espionage_set_cursor_timeout_id(GdkWaylandPointerData * self, guint cursor_timeout_id) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_timeout_id = cursor_timeout_id;
}

// GdkWaylandPointerData::cursor_image_index

guint gdk_wayland_pointer_data_espionage_get_cursor_image_index(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_index;
}

void gdk_wayland_pointer_data_espionage_set_cursor_image_index(GdkWaylandPointerData * self, guint cursor_image_index) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_index = cursor_image_index;
}

// GdkWaylandPointerData::cursor_image_delay

guint gdk_wayland_pointer_data_espionage_get_cursor_image_delay(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_delay;
}

void gdk_wayland_pointer_data_espionage_set_cursor_image_delay(GdkWaylandPointerData * self, guint cursor_image_delay) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_delay = cursor_image_delay;
}

// GdkWaylandPointerData::current_output_scale

guint gdk_wayland_pointer_data_espionage_get_current_output_scale(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->current_output_scale;
}

void gdk_wayland_pointer_data_espionage_set_current_output_scale(GdkWaylandPointerData * self, guint current_output_scale) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->current_output_scale = current_output_scale;
}

// GdkWaylandPointerData::pointer_surface_outputs

GSList * gdk_wayland_pointer_data_espionage_get_pointer_surface_outputs(GdkWaylandPointerData * self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface_outputs;
}

void gdk_wayland_pointer_data_espionage_set_pointer_surface_outputs(GdkWaylandPointerData * self, GSList * pointer_surface_outputs) {
  ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface_outputs = pointer_surface_outputs;
}

// GdkWaylandPointerData::frame

GdkWaylandPointerFrameData * gdk_wayland_pointer_data_espionage_get_frame_ptr(GdkWaylandPointerData * self) {
  return (GdkWaylandPointerFrameData *)&((struct _GdkWaylandPointerData_v3_22_0*)self)->frame;
}

#endif // GDK_WAYLAND_POINTER_DATA_ESPIONAGE_H
