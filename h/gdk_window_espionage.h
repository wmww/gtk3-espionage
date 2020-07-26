/* This file is part of gtk3-espionage
 *
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
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

#ifndef GDK_WINDOW_ESPIONAGE_H
#define GDK_WINDOW_ESPIONAGE_H

typedef struct _GdkWindow GdkWindow;

// Valid for GTK v3.22.0 - v3.22.18
struct _GdkWindow_v3_22_0
{
  GObject parent_instance;
  GdkWindowImpl *impl;
  GdkWindow *parent;
  GdkWindow *transient_for;
  GdkVisual *visual;
  gpointer user_data;
  gint x;
  gint y;
  GdkEventMask event_mask;
  guint8 window_type;
  guint8 depth;
  guint8 resize_count;
  gint8 toplevel_window_type;
  GList *filters;
  GList *children;
  GList children_list_node;
  GList *native_children;
  cairo_pattern_t *background;
  struct {
    cairo_surface_t *surface;
    cairo_region_t *region;
    cairo_region_t *flushed_region;
    cairo_region_t *need_blend_region;
    gboolean surface_needs_composite;
    gboolean use_gl;
  } current_paint;
  GdkGLContext *gl_paint_context;
  cairo_region_t *update_area;
  guint update_freeze_count;
  cairo_region_t *active_update_area;
  cairo_region_t * old_updated_area[2];
  GdkWindowState old_state;
  GdkWindowState state;
  guint8 alpha;
  guint8 fullscreen_mode;
  guint input_only : 1;
  guint pass_through : 1;
  guint modal_hint : 1;
  guint composited : 1;
  guint has_alpha_background : 1;
  guint destroyed : 2;
  guint accept_focus : 1;
  guint focus_on_map : 1;
  guint shaped : 1;
  guint support_multidevice : 1;
  guint synthesize_crossing_event_queued : 1;
  guint effective_visibility : 2;
  guint visibility : 2;
  guint native_visibility : 2;
  guint viewable : 1;
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;
  GdkWindow *impl_window;
  guint update_and_descendants_freeze_count;
  gint abs_x;
  gint abs_y;;
  gint width;
  gint height;;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;
  guint num_offscreen_children;
  cairo_region_t *clip_region;
  GdkCursor *cursor;
  GHashTable *device_cursor;
  cairo_region_t *shape;
  cairo_region_t *input_shape;
  GList *devices_inside;
  GHashTable *device_events;
  GHashTable *source_event_masks;
  gulong device_added_handler_id;
  gulong device_changed_handler_id;
  GdkFrameClock *frame_clock;
  GdkWindowInvalidateHandlerFunc invalidate_handler;
  GdkDrawingContext *drawing_context;
};

// Valid for GTK v3.22.19 - v3.24.10
struct _GdkWindow_v3_22_19
{
  GObject parent_instance;
  GdkWindowImpl *impl;
  GdkWindow *parent;
  GdkWindow *transient_for;
  GdkVisual *visual;
  gpointer user_data;
  gint x;
  gint y;
  GdkEventMask event_mask;
  guint8 window_type;
  guint8 depth;
  guint8 resize_count;
  gint8 toplevel_window_type;
  GList *filters;
  GList *children;
  GList children_list_node;
  GList *native_children;
  cairo_pattern_t *background;
  struct {
    cairo_surface_t *surface;
    cairo_region_t *region;
    cairo_region_t *flushed_region;
    cairo_region_t *need_blend_region;
    gboolean surface_needs_composite;
    gboolean use_gl;
  } current_paint;
  GdkGLContext *gl_paint_context;
  cairo_region_t *update_area;
  guint update_freeze_count;
  cairo_region_t *active_update_area;
  cairo_region_t * old_updated_area[2];
  GdkWindowState old_state;
  GdkWindowState state;
  guint8 alpha;
  guint8 fullscreen_mode;
  guint input_only : 1;
  guint pass_through : 1;
  guint modal_hint : 1;
  guint composited : 1;
  guint has_alpha_background : 1;
  guint destroyed : 2;
  guint accept_focus : 1;
  guint focus_on_map : 1;
  guint shaped : 1;
  guint support_multidevice : 1;
  guint synthesize_crossing_event_queued : 1;
  guint effective_visibility : 2;
  guint visibility : 2;
  guint native_visibility : 2;
  guint viewable : 1;
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;
  GdkWindow *impl_window;
  guint update_and_descendants_freeze_count;
  gint abs_x;
  gint abs_y;;
  gint width;
  gint height;;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;
  guint num_offscreen_children;
  cairo_region_t *clip_region;
  GdkCursor *cursor;
  GHashTable *device_cursor;
  cairo_region_t *shape;
  cairo_region_t *input_shape;
  GList *devices_inside;
  GHashTable *device_events;
  GHashTable *source_event_masks;
  gulong device_added_handler_id;
  gulong device_changed_handler_id;
  GdkFrameClock *frame_clock;
  GdkWindowInvalidateHandlerFunc invalidate_handler;
  GdkDrawingContext *drawing_context;
  cairo_region_t *opaque_region;
};

// Valid for GTK v3.24.11 - v3.24.21
struct _GdkWindow_v3_24_11
{
  GObject parent_instance;
  GdkWindowImpl *impl;
  GdkWindow *parent;
  GdkWindow *transient_for;
  GdkVisual *visual;
  gpointer user_data;
  gint x;
  gint y;
  GdkEventMask event_mask;
  guint8 window_type;
  guint8 depth;
  guint8 resize_count;
  gint8 toplevel_window_type;
  GList *filters;
  GList *children;
  GList children_list_node;
  GList *native_children;
  cairo_pattern_t *background;
  struct {
    cairo_surface_t *surface;
    cairo_region_t *region;
    cairo_region_t *flushed_region;
    cairo_region_t *need_blend_region;
    gboolean surface_needs_composite;
    gboolean use_gl;
  } current_paint;
  GdkGLContext *gl_paint_context;
  cairo_region_t *update_area;
  guint update_freeze_count;
  cairo_region_t *active_update_area;
  cairo_region_t * old_updated_area[2];
  GdkWindowState old_state;
  GdkWindowState state;
  guint synthesized_crossing_event_id;
  guint8 alpha;
  guint8 fullscreen_mode;
  guint input_only : 1;
  guint pass_through : 1;
  guint modal_hint : 1;
  guint composited : 1;
  guint has_alpha_background : 1;
  guint destroyed : 2;
  guint accept_focus : 1;
  guint focus_on_map : 1;
  guint shaped : 1;
  guint support_multidevice : 1;
  guint effective_visibility : 2;
  guint visibility : 2;
  guint native_visibility : 2;
  guint viewable : 1;
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;
  GdkWindow *impl_window;
  guint update_and_descendants_freeze_count;
  gint abs_x;
  gint abs_y;;
  gint width;
  gint height;;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;
  guint num_offscreen_children;
  cairo_region_t *clip_region;
  GdkCursor *cursor;
  GHashTable *device_cursor;
  cairo_region_t *shape;
  cairo_region_t *input_shape;
  GList *devices_inside;
  GHashTable *device_events;
  GHashTable *source_event_masks;
  gulong device_added_handler_id;
  gulong device_changed_handler_id;
  GdkFrameClock *frame_clock;
  GdkWindowInvalidateHandlerFunc invalidate_handler;
  GdkDrawingContext *drawing_context;
  cairo_region_t *opaque_region;
};

#endif // GDK_WINDOW_ESPIONAGE_H
