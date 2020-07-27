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

// GdkWaylandTabletData::wp_tablet

struct zwp_tablet_v2 * gdk_wayland_tablet_data_espionage_get_wp_tablet(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->wp_tablet;
}

void gdk_wayland_tablet_data_espionage_set_wp_tablet(GdkWaylandTabletData * self, struct zwp_tablet_v2 * wp_tablet) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->wp_tablet = wp_tablet;
}

// GdkWaylandTabletData::name

gchar * gdk_wayland_tablet_data_espionage_get_name(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->name;
}

void gdk_wayland_tablet_data_espionage_set_name(GdkWaylandTabletData * self, gchar * name) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->name = name;
}

// GdkWaylandTabletData::path

gchar * gdk_wayland_tablet_data_espionage_get_path(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->path;
}

void gdk_wayland_tablet_data_espionage_set_path(GdkWaylandTabletData * self, gchar * path) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->path = path;
}

// GdkWaylandTabletData::vid

uint32_t gdk_wayland_tablet_data_espionage_get_vid(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->vid;
}

void gdk_wayland_tablet_data_espionage_set_vid(GdkWaylandTabletData * self, uint32_t vid) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->vid = vid;
}

// GdkWaylandTabletData::pid

uint32_t gdk_wayland_tablet_data_espionage_get_pid(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pid;
}

void gdk_wayland_tablet_data_espionage_set_pid(GdkWaylandTabletData * self, uint32_t pid) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->pid = pid;
}

// GdkWaylandTabletData::master

GdkDevice * gdk_wayland_tablet_data_espionage_get_master(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->master;
}

void gdk_wayland_tablet_data_espionage_set_master(GdkWaylandTabletData * self, GdkDevice * master) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->master = master;
}

// GdkWaylandTabletData::stylus_device

GdkDevice * gdk_wayland_tablet_data_espionage_get_stylus_device(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->stylus_device;
}

void gdk_wayland_tablet_data_espionage_set_stylus_device(GdkWaylandTabletData * self, GdkDevice * stylus_device) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->stylus_device = stylus_device;
}

// GdkWaylandTabletData::eraser_device

GdkDevice * gdk_wayland_tablet_data_espionage_get_eraser_device(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->eraser_device;
}

void gdk_wayland_tablet_data_espionage_set_eraser_device(GdkWaylandTabletData * self, GdkDevice * eraser_device) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->eraser_device = eraser_device;
}

// GdkWaylandTabletData::current_device

GdkDevice * gdk_wayland_tablet_data_espionage_get_current_device(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_device;
}

void gdk_wayland_tablet_data_espionage_set_current_device(GdkWaylandTabletData * self, GdkDevice * current_device) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_device = current_device;
}

// GdkWaylandTabletData::seat

GdkSeat * gdk_wayland_tablet_data_espionage_get_seat(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->seat;
}

void gdk_wayland_tablet_data_espionage_set_seat(GdkWaylandTabletData * self, GdkSeat * seat) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->seat = seat;
}

// GdkWaylandTabletData::pointer_info

GdkWaylandPointerData * gdk_wayland_tablet_data_espionage_get_pointer_info_ptr(GdkWaylandTabletData * self) {
  return (GdkWaylandPointerData *)&((struct _GdkWaylandTabletData_v3_22_0*)self)->pointer_info;
}

// GdkWaylandTabletData::pads

GList * gdk_wayland_tablet_data_espionage_get_pads(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->pads;
}

void gdk_wayland_tablet_data_espionage_set_pads(GdkWaylandTabletData * self, GList * pads) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->pads = pads;
}

// GdkWaylandTabletData::current_tool

GdkWaylandTabletToolData * gdk_wayland_tablet_data_espionage_get_current_tool(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_tool;
}

void gdk_wayland_tablet_data_espionage_set_current_tool(GdkWaylandTabletData * self, GdkWaylandTabletToolData * current_tool) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->current_tool = current_tool;
}

// GdkWaylandTabletData::axis_indices

gint* * gdk_wayland_tablet_data_espionage_get_axis_indices_ptr(GdkWaylandTabletData * self) {
  return (gint* *)&((struct _GdkWaylandTabletData_v3_22_0*)self)->axis_indices;
}

// GdkWaylandTabletData::axes

gdouble * gdk_wayland_tablet_data_espionage_get_axes(GdkWaylandTabletData * self) {
  return ((struct _GdkWaylandTabletData_v3_22_0*)self)->axes;
}

void gdk_wayland_tablet_data_espionage_set_axes(GdkWaylandTabletData * self, gdouble * axes) {
  ((struct _GdkWaylandTabletData_v3_22_0*)self)->axes = axes;
}

#endif // GDK_WAYLAND_TABLET_DATA_ESPIONAGE_H
