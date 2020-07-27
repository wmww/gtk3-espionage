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

#ifndef GDK_WAYLAND_POINTER_FRAME_DATA_ESPIONAGE_H
#define GDK_WAYLAND_POINTER_FRAME_DATA_ESPIONAGE_H

typedef struct _GdkWaylandPointerFrameData GdkWaylandPointerFrameData;

// Valid for GTK v3.22.0 - v3.24.21
struct _GdkWaylandPointerFrameData_v3_22_0
{
  GdkEvent *event;
  gdouble delta_x;
  gdouble delta_y;;
  int32_t discrete_x;
  int32_t discrete_y;;
  gint8 is_scroll_stop;
  enum wl_pointer_axis_source source;
};

GdkEvent * gdk_wayland_pointer_frame_data_extract_event(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->event;
}

gdouble gdk_wayland_pointer_frame_data_extract_delta_x(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->delta_x;
}

gdouble gdk_wayland_pointer_frame_data_extract_delta_y(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->delta_y;
}

int32_t gdk_wayland_pointer_frame_data_extract_discrete_x(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->discrete_x;
}

int32_t gdk_wayland_pointer_frame_data_extract_discrete_y(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->discrete_y;
}

gint8 gdk_wayland_pointer_frame_data_extract_is_scroll_stop(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->is_scroll_stop;
}

enum wl_pointer_axis_source gdk_wayland_pointer_frame_data_extract_source(GdkWaylandPointerFrameData* self) {
  return ((struct _GdkWaylandPointerFrameData_v3_22_0*)self)->source;
}

#endif // GDK_WAYLAND_POINTER_FRAME_DATA_ESPIONAGE_H
