/* This file is part of gtk3-espionage
 *
 * Copyright © 2010 Intel Corporation
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

#ifndef GDK_WINDOW_IMPL_WAYLAND_CLASS_ESPIONAGE_H
#define GDK_WINDOW_IMPL_WAYLAND_CLASS_ESPIONAGE_H

typedef struct _GdkWindowImplWaylandClass GdkWindowImplWaylandClass;

// Valid for GTK v3.22.0 - v3.24.21
struct _GdkWindowImplWaylandClass_v3_22_0
{
  struct _GdkWindowImplClass_v3_22_0 parent_class;
};

GdkWindowImplClass gdk_window_impl_wayland_class_extract_parent_class(GdkWindowImplWaylandClass* self) {
  return ((struct _GdkWindowImplWaylandClass_v3_22_0*)self)->parent_class;
}

#endif // GDK_WINDOW_IMPL_WAYLAND_CLASS_ESPIONAGE_H
