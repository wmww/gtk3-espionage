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

GObject gdk_window_extract_parent_instance(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->parent_instance;
}

GdkWindowImpl * gdk_window_extract_impl(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->impl;
}

GdkWindow * gdk_window_extract_parent(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->parent;
}

GdkWindow * gdk_window_extract_transient_for(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->transient_for;
}

GdkVisual * gdk_window_extract_visual(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->visual;
}

gpointer gdk_window_extract_user_data(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->user_data;
}

gint gdk_window_extract_x(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->x;
}

gint gdk_window_extract_y(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->y;
}

GdkEventMask gdk_window_extract_event_mask(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->event_mask;
}

guint8 gdk_window_extract_window_type(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->window_type;
}

guint8 gdk_window_extract_depth(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->depth;
}

guint8 gdk_window_extract_resize_count(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->resize_count;
}

gint8 gdk_window_extract_toplevel_window_type(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->toplevel_window_type;
}

GList * gdk_window_extract_filters(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->filters;
}

GList * gdk_window_extract_children(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->children;
}

GList gdk_window_extract_children_list_node(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->children_list_node;
}

GList * gdk_window_extract_native_children(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->native_children;
}

cairo_pattern_t * gdk_window_extract_background(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->background;
}

cairo_surface_t * gdk_window_extract_current_paint_surface(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface;
}

cairo_region_t * gdk_window_extract_current_paint_region(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.region;
}

cairo_region_t * gdk_window_extract_current_paint_flushed_region(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.flushed_region;
}

cairo_region_t * gdk_window_extract_current_paint_need_blend_region(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.need_blend_region;
}

gboolean gdk_window_extract_current_paint_surface_needs_composite(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface_needs_composite;
}

gboolean gdk_window_extract_current_paint_use_gl(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.use_gl;
}

GdkGLContext * gdk_window_extract_gl_paint_context(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->gl_paint_context;
}

cairo_region_t * gdk_window_extract_update_area(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_area;
}

guint gdk_window_extract_update_freeze_count(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_freeze_count;
}

cairo_region_t * gdk_window_extract_active_update_area(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->active_update_area;
}

cairo_region_t ** gdk_window_extract_old_updated_area(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->old_updated_area;
}

GdkWindowState gdk_window_extract_old_state(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->old_state;
}

GdkWindowState gdk_window_extract_state(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->state;
}

guint gdk_window_extract_synthesized_crossing_event_id(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->synthesized_crossing_event_id;
}

guint8 gdk_window_extract_alpha(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->alpha;
}

guint8 gdk_window_extract_fullscreen_mode(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->fullscreen_mode;
}

guint gdk_window_extract_input_only(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->input_only;
}

guint gdk_window_extract_pass_through(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->pass_through;
}

guint gdk_window_extract_modal_hint(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->modal_hint;
}

guint gdk_window_extract_composited(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->composited;
}

guint gdk_window_extract_has_alpha_background(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->has_alpha_background;
}

guint gdk_window_extract_destroyed(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->destroyed;
}

guint gdk_window_extract_accept_focus(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->accept_focus;
}

guint gdk_window_extract_focus_on_map(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->focus_on_map;
}

guint gdk_window_extract_shaped(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shaped;
}

guint gdk_window_extract_support_multidevice(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->support_multidevice;
}

guint gdk_window_extract_effective_visibility(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->effective_visibility;
}

guint gdk_window_extract_visibility(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->visibility;
}

guint gdk_window_extract_native_visibility(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->native_visibility;
}

guint gdk_window_extract_viewable(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->viewable;
}

guint gdk_window_extract_applied_shape(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->applied_shape;
}

guint gdk_window_extract_in_update(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->in_update;
}

guint gdk_window_extract_geometry_dirty(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->geometry_dirty;
}

guint gdk_window_extract_event_compression(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->event_compression;
}

guint gdk_window_extract_frame_clock_events_paused(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->frame_clock_events_paused;
}

GdkWindow * gdk_window_extract_impl_window(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->impl_window;
}

guint gdk_window_extract_update_and_descendants_freeze_count(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_and_descendants_freeze_count;
}

gint gdk_window_extract_abs_x(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->abs_x;
}

gint gdk_window_extract_abs_y(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->abs_y;
}

gint gdk_window_extract_width(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->width;
}

gint gdk_window_extract_height(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->height;
}

gint gdk_window_extract_shadow_top(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_top;
}

gint gdk_window_extract_shadow_left(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_left;
}

gint gdk_window_extract_shadow_right(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_right;
}

gint gdk_window_extract_shadow_bottom(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_bottom;
}

guint gdk_window_extract_num_offscreen_children(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->num_offscreen_children;
}

cairo_region_t * gdk_window_extract_clip_region(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->clip_region;
}

GdkCursor * gdk_window_extract_cursor(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->cursor;
}

GHashTable * gdk_window_extract_device_cursor(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_cursor;
}

cairo_region_t * gdk_window_extract_shape(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shape;
}

cairo_region_t * gdk_window_extract_input_shape(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->input_shape;
}

GList * gdk_window_extract_devices_inside(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->devices_inside;
}

GHashTable * gdk_window_extract_device_events(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_events;
}

GHashTable * gdk_window_extract_source_event_masks(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->source_event_masks;
}

gulong gdk_window_extract_device_added_handler_id(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_added_handler_id;
}

gulong gdk_window_extract_device_changed_handler_id(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_changed_handler_id;
}

GdkFrameClock * gdk_window_extract_frame_clock(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->frame_clock;
}

GdkWindowInvalidateHandlerFunc gdk_window_extract_invalidate_handler(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->invalidate_handler;
}

GdkDrawingContext * gdk_window_extract_drawing_context(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->drawing_context;
}

cairo_region_t * gdk_window_extract_opaque_region(GdkWindow* self) {
  return ((struct _GdkWindow_v3_24_11*)self)->opaque_region;
}

#endif // GDK_WINDOW_ESPIONAGE_H
