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

