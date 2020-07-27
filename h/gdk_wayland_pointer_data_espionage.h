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

GdkWindow * gdk_wayland_pointer_data_extract_focus(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->focus;
}

double gdk_wayland_pointer_data_extract_surface_x(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_x;
}

double gdk_wayland_pointer_data_extract_surface_y(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->surface_y;
}

GdkModifierType gdk_wayland_pointer_data_extract_button_modifiers(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->button_modifiers;
}

uint32_t gdk_wayland_pointer_data_extract_time(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->time;
}

uint32_t gdk_wayland_pointer_data_extract_enter_serial(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->enter_serial;
}

uint32_t gdk_wayland_pointer_data_extract_press_serial(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->press_serial;
}

GdkWindow * gdk_wayland_pointer_data_extract_grab_window(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_window;
}

uint32_t gdk_wayland_pointer_data_extract_grab_time(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->grab_time;
}

struct wl_surface * gdk_wayland_pointer_data_extract_pointer_surface(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface;
}

GdkCursor * gdk_wayland_pointer_data_extract_cursor(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor;
}

guint gdk_wayland_pointer_data_extract_cursor_timeout_id(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_timeout_id;
}

guint gdk_wayland_pointer_data_extract_cursor_image_index(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_index;
}

guint gdk_wayland_pointer_data_extract_cursor_image_delay(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->cursor_image_delay;
}

guint gdk_wayland_pointer_data_extract_current_output_scale(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->current_output_scale;
}

GSList * gdk_wayland_pointer_data_extract_pointer_surface_outputs(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->pointer_surface_outputs;
}

GdkWaylandPointerFrameData gdk_wayland_pointer_data_extract_frame(GdkWaylandPointerData* self) {
  return ((struct _GdkWaylandPointerData_v3_22_0*)self)->frame;
}

#endif // GDK_WAYLAND_POINTER_DATA_ESPIONAGE_H
