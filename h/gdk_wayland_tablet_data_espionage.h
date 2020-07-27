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

#ifndef GDK_WAYLAND_TABLET_DATA_ESPIONAGE_H
#define GDK_WAYLAND_TABLET_DATA_ESPIONAGE_H

typedef struct _GdkWaylandTabletData GdkWaylandTabletData;

// Valid for GTK v3.22.0 - v3.24.21
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

struct zwp_tablet_v2 * gdk_wayland_tablet_data_extract_wp_tablet(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->wp_tablet;
}

gchar * gdk_wayland_tablet_data_extract_name(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->name;
}

gchar * gdk_wayland_tablet_data_extract_path(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->path;
}

uint32_t gdk_wayland_tablet_data_extract_vid(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->vid;
}

uint32_t gdk_wayland_tablet_data_extract_pid(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pid;
}

GdkDevice * gdk_wayland_tablet_data_extract_master(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->master;
}

GdkDevice * gdk_wayland_tablet_data_extract_stylus_device(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->stylus_device;
}

GdkDevice * gdk_wayland_tablet_data_extract_eraser_device(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->eraser_device;
}

GdkDevice * gdk_wayland_tablet_data_extract_current_device(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_device;
}

GdkSeat * gdk_wayland_tablet_data_extract_seat(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->seat;
}

GdkWaylandPointerData gdk_wayland_tablet_data_extract_pointer_info(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pointer_info;
}

GList * gdk_wayland_tablet_data_extract_pads(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pads;
}

GdkWaylandTabletToolData * gdk_wayland_tablet_data_extract_current_tool(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_tool;
}

gint* gdk_wayland_tablet_data_extract_axis_indices(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->axis_indices;
}

gdouble * gdk_wayland_tablet_data_extract_axes(GdkWaylandTabletData* self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->axes;
}

#endif // GDK_WAYLAND_TABLET_DATA_ESPIONAGE_H
