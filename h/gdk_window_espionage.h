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

// GdkWindow::parent_instance

GObject * gdk_window_espionage_get_parent_instance_ptr(GdkWindow * self) {
  return (GObject *)&((struct _GdkWindow_v3_24_11*)self)->parent_instance;
}

// GdkWindow::impl

GdkWindowImpl * gdk_window_espionage_get_impl(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->impl;
}

void gdk_window_espionage_set_impl(GdkWindow * self, GdkWindowImpl * impl) {
  ((struct _GdkWindow_v3_24_11*)self)->impl = impl;
}

// GdkWindow::parent

GdkWindow * gdk_window_espionage_get_parent(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->parent;
}

void gdk_window_espionage_set_parent(GdkWindow * self, GdkWindow * parent) {
  ((struct _GdkWindow_v3_24_11*)self)->parent = parent;
}

// GdkWindow::transient_for

GdkWindow * gdk_window_espionage_get_transient_for(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->transient_for;
}

void gdk_window_espionage_set_transient_for(GdkWindow * self, GdkWindow * transient_for) {
  ((struct _GdkWindow_v3_24_11*)self)->transient_for = transient_for;
}

// GdkWindow::visual

GdkVisual * gdk_window_espionage_get_visual(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->visual;
}

void gdk_window_espionage_set_visual(GdkWindow * self, GdkVisual * visual) {
  ((struct _GdkWindow_v3_24_11*)self)->visual = visual;
}

// GdkWindow::user_data

gpointer gdk_window_espionage_get_user_data(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->user_data;
}

void gdk_window_espionage_set_user_data(GdkWindow * self, gpointer user_data) {
  ((struct _GdkWindow_v3_24_11*)self)->user_data = user_data;
}

// GdkWindow::x

gint gdk_window_espionage_get_x(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->x;
}

void gdk_window_espionage_set_x(GdkWindow * self, gint x) {
  ((struct _GdkWindow_v3_24_11*)self)->x = x;
}

// GdkWindow::y

gint gdk_window_espionage_get_y(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->y;
}

void gdk_window_espionage_set_y(GdkWindow * self, gint y) {
  ((struct _GdkWindow_v3_24_11*)self)->y = y;
}

// GdkWindow::event_mask

GdkEventMask * gdk_window_espionage_get_event_mask_ptr(GdkWindow * self) {
  return (GdkEventMask *)&((struct _GdkWindow_v3_24_11*)self)->event_mask;
}

// GdkWindow::window_type

guint8 * gdk_window_espionage_get_window_type_ptr(GdkWindow * self) {
  return (guint8 *)&((struct _GdkWindow_v3_24_11*)self)->window_type;
}

// GdkWindow::depth

guint8 * gdk_window_espionage_get_depth_ptr(GdkWindow * self) {
  return (guint8 *)&((struct _GdkWindow_v3_24_11*)self)->depth;
}

// GdkWindow::resize_count

guint8 * gdk_window_espionage_get_resize_count_ptr(GdkWindow * self) {
  return (guint8 *)&((struct _GdkWindow_v3_24_11*)self)->resize_count;
}

// GdkWindow::toplevel_window_type

gint8 * gdk_window_espionage_get_toplevel_window_type_ptr(GdkWindow * self) {
  return (gint8 *)&((struct _GdkWindow_v3_24_11*)self)->toplevel_window_type;
}

// GdkWindow::filters

GList * gdk_window_espionage_get_filters(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->filters;
}

void gdk_window_espionage_set_filters(GdkWindow * self, GList * filters) {
  ((struct _GdkWindow_v3_24_11*)self)->filters = filters;
}

// GdkWindow::children

GList * gdk_window_espionage_get_children(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->children;
}

void gdk_window_espionage_set_children(GdkWindow * self, GList * children) {
  ((struct _GdkWindow_v3_24_11*)self)->children = children;
}

// GdkWindow::children_list_node

GList * gdk_window_espionage_get_children_list_node_ptr(GdkWindow * self) {
  return (GList *)&((struct _GdkWindow_v3_24_11*)self)->children_list_node;
}

// GdkWindow::native_children

GList * gdk_window_espionage_get_native_children(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->native_children;
}

void gdk_window_espionage_set_native_children(GdkWindow * self, GList * native_children) {
  ((struct _GdkWindow_v3_24_11*)self)->native_children = native_children;
}

// GdkWindow::background

cairo_pattern_t * gdk_window_espionage_get_background(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->background;
}

void gdk_window_espionage_set_background(GdkWindow * self, cairo_pattern_t * background) {
  ((struct _GdkWindow_v3_24_11*)self)->background = background;
}

// GdkWindow::current_paint.surface

cairo_surface_t * gdk_window_espionage_get_current_paint_surface(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface;
}

void gdk_window_espionage_set_current_paint_surface(GdkWindow * self, cairo_surface_t * current_paint_surface) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface = current_paint_surface;
}

// GdkWindow::current_paint.region

cairo_region_t * gdk_window_espionage_get_current_paint_region(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.region;
}

void gdk_window_espionage_set_current_paint_region(GdkWindow * self, cairo_region_t * current_paint_region) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.region = current_paint_region;
}

// GdkWindow::current_paint.flushed_region

cairo_region_t * gdk_window_espionage_get_current_paint_flushed_region(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.flushed_region;
}

void gdk_window_espionage_set_current_paint_flushed_region(GdkWindow * self, cairo_region_t * current_paint_flushed_region) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.flushed_region = current_paint_flushed_region;
}

// GdkWindow::current_paint.need_blend_region

cairo_region_t * gdk_window_espionage_get_current_paint_need_blend_region(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.need_blend_region;
}

void gdk_window_espionage_set_current_paint_need_blend_region(GdkWindow * self, cairo_region_t * current_paint_need_blend_region) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.need_blend_region = current_paint_need_blend_region;
}

// GdkWindow::current_paint.surface_needs_composite

gboolean gdk_window_espionage_get_current_paint_surface_needs_composite(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface_needs_composite;
}

void gdk_window_espionage_set_current_paint_surface_needs_composite(GdkWindow * self, gboolean current_paint_surface_needs_composite) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.surface_needs_composite = current_paint_surface_needs_composite;
}

// GdkWindow::current_paint.use_gl

gboolean gdk_window_espionage_get_current_paint_use_gl(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->current_paint.use_gl;
}

void gdk_window_espionage_set_current_paint_use_gl(GdkWindow * self, gboolean current_paint_use_gl) {
  ((struct _GdkWindow_v3_24_11*)self)->current_paint.use_gl = current_paint_use_gl;
}

// GdkWindow::gl_paint_context

GdkGLContext * gdk_window_espionage_get_gl_paint_context(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->gl_paint_context;
}

void gdk_window_espionage_set_gl_paint_context(GdkWindow * self, GdkGLContext * gl_paint_context) {
  ((struct _GdkWindow_v3_24_11*)self)->gl_paint_context = gl_paint_context;
}

// GdkWindow::update_area

cairo_region_t * gdk_window_espionage_get_update_area(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_area;
}

void gdk_window_espionage_set_update_area(GdkWindow * self, cairo_region_t * update_area) {
  ((struct _GdkWindow_v3_24_11*)self)->update_area = update_area;
}

// GdkWindow::update_freeze_count

guint gdk_window_espionage_get_update_freeze_count(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_freeze_count;
}

void gdk_window_espionage_set_update_freeze_count(GdkWindow * self, guint update_freeze_count) {
  ((struct _GdkWindow_v3_24_11*)self)->update_freeze_count = update_freeze_count;
}

// GdkWindow::active_update_area

cairo_region_t * gdk_window_espionage_get_active_update_area(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->active_update_area;
}

void gdk_window_espionage_set_active_update_area(GdkWindow * self, cairo_region_t * active_update_area) {
  ((struct _GdkWindow_v3_24_11*)self)->active_update_area = active_update_area;
}

// GdkWindow::old_updated_area

cairo_region_t ** * gdk_window_espionage_get_old_updated_area_ptr(GdkWindow * self) {
  return (cairo_region_t ** *)&((struct _GdkWindow_v3_24_11*)self)->old_updated_area;
}

// GdkWindow::old_state

GdkWindowState * gdk_window_espionage_get_old_state_ptr(GdkWindow * self) {
  return (GdkWindowState *)&((struct _GdkWindow_v3_24_11*)self)->old_state;
}

// GdkWindow::state

GdkWindowState * gdk_window_espionage_get_state_ptr(GdkWindow * self) {
  return (GdkWindowState *)&((struct _GdkWindow_v3_24_11*)self)->state;
}

// GdkWindow::synthesized_crossing_event_id

guint gdk_window_espionage_get_synthesized_crossing_event_id(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->synthesized_crossing_event_id;
}

void gdk_window_espionage_set_synthesized_crossing_event_id(GdkWindow * self, guint synthesized_crossing_event_id) {
  ((struct _GdkWindow_v3_24_11*)self)->synthesized_crossing_event_id = synthesized_crossing_event_id;
}

// GdkWindow::alpha

guint8 * gdk_window_espionage_get_alpha_ptr(GdkWindow * self) {
  return (guint8 *)&((struct _GdkWindow_v3_24_11*)self)->alpha;
}

// GdkWindow::fullscreen_mode

guint8 * gdk_window_espionage_get_fullscreen_mode_ptr(GdkWindow * self) {
  return (guint8 *)&((struct _GdkWindow_v3_24_11*)self)->fullscreen_mode;
}

// GdkWindow::input_only

guint gdk_window_espionage_get_input_only(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->input_only;
}

void gdk_window_espionage_set_input_only(GdkWindow * self, guint input_only) {
  ((struct _GdkWindow_v3_24_11*)self)->input_only = input_only;
}

// GdkWindow::pass_through

guint gdk_window_espionage_get_pass_through(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->pass_through;
}

void gdk_window_espionage_set_pass_through(GdkWindow * self, guint pass_through) {
  ((struct _GdkWindow_v3_24_11*)self)->pass_through = pass_through;
}

// GdkWindow::modal_hint

guint gdk_window_espionage_get_modal_hint(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->modal_hint;
}

void gdk_window_espionage_set_modal_hint(GdkWindow * self, guint modal_hint) {
  ((struct _GdkWindow_v3_24_11*)self)->modal_hint = modal_hint;
}

// GdkWindow::composited

guint gdk_window_espionage_get_composited(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->composited;
}

void gdk_window_espionage_set_composited(GdkWindow * self, guint composited) {
  ((struct _GdkWindow_v3_24_11*)self)->composited = composited;
}

// GdkWindow::has_alpha_background

guint gdk_window_espionage_get_has_alpha_background(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->has_alpha_background;
}

void gdk_window_espionage_set_has_alpha_background(GdkWindow * self, guint has_alpha_background) {
  ((struct _GdkWindow_v3_24_11*)self)->has_alpha_background = has_alpha_background;
}

// GdkWindow::destroyed

guint gdk_window_espionage_get_destroyed(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->destroyed;
}

void gdk_window_espionage_set_destroyed(GdkWindow * self, guint destroyed) {
  ((struct _GdkWindow_v3_24_11*)self)->destroyed = destroyed;
}

// GdkWindow::accept_focus

guint gdk_window_espionage_get_accept_focus(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->accept_focus;
}

void gdk_window_espionage_set_accept_focus(GdkWindow * self, guint accept_focus) {
  ((struct _GdkWindow_v3_24_11*)self)->accept_focus = accept_focus;
}

// GdkWindow::focus_on_map

guint gdk_window_espionage_get_focus_on_map(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->focus_on_map;
}

void gdk_window_espionage_set_focus_on_map(GdkWindow * self, guint focus_on_map) {
  ((struct _GdkWindow_v3_24_11*)self)->focus_on_map = focus_on_map;
}

// GdkWindow::shaped

guint gdk_window_espionage_get_shaped(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shaped;
}

void gdk_window_espionage_set_shaped(GdkWindow * self, guint shaped) {
  ((struct _GdkWindow_v3_24_11*)self)->shaped = shaped;
}

// GdkWindow::support_multidevice

guint gdk_window_espionage_get_support_multidevice(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->support_multidevice;
}

void gdk_window_espionage_set_support_multidevice(GdkWindow * self, guint support_multidevice) {
  ((struct _GdkWindow_v3_24_11*)self)->support_multidevice = support_multidevice;
}

// GdkWindow::effective_visibility

guint gdk_window_espionage_get_effective_visibility(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->effective_visibility;
}

void gdk_window_espionage_set_effective_visibility(GdkWindow * self, guint effective_visibility) {
  ((struct _GdkWindow_v3_24_11*)self)->effective_visibility = effective_visibility;
}

// GdkWindow::visibility

guint gdk_window_espionage_get_visibility(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->visibility;
}

void gdk_window_espionage_set_visibility(GdkWindow * self, guint visibility) {
  ((struct _GdkWindow_v3_24_11*)self)->visibility = visibility;
}

// GdkWindow::native_visibility

guint gdk_window_espionage_get_native_visibility(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->native_visibility;
}

void gdk_window_espionage_set_native_visibility(GdkWindow * self, guint native_visibility) {
  ((struct _GdkWindow_v3_24_11*)self)->native_visibility = native_visibility;
}

// GdkWindow::viewable

guint gdk_window_espionage_get_viewable(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->viewable;
}

void gdk_window_espionage_set_viewable(GdkWindow * self, guint viewable) {
  ((struct _GdkWindow_v3_24_11*)self)->viewable = viewable;
}

// GdkWindow::applied_shape

guint gdk_window_espionage_get_applied_shape(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->applied_shape;
}

void gdk_window_espionage_set_applied_shape(GdkWindow * self, guint applied_shape) {
  ((struct _GdkWindow_v3_24_11*)self)->applied_shape = applied_shape;
}

// GdkWindow::in_update

guint gdk_window_espionage_get_in_update(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->in_update;
}

void gdk_window_espionage_set_in_update(GdkWindow * self, guint in_update) {
  ((struct _GdkWindow_v3_24_11*)self)->in_update = in_update;
}

// GdkWindow::geometry_dirty

guint gdk_window_espionage_get_geometry_dirty(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->geometry_dirty;
}

void gdk_window_espionage_set_geometry_dirty(GdkWindow * self, guint geometry_dirty) {
  ((struct _GdkWindow_v3_24_11*)self)->geometry_dirty = geometry_dirty;
}

// GdkWindow::event_compression

guint gdk_window_espionage_get_event_compression(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->event_compression;
}

void gdk_window_espionage_set_event_compression(GdkWindow * self, guint event_compression) {
  ((struct _GdkWindow_v3_24_11*)self)->event_compression = event_compression;
}

// GdkWindow::frame_clock_events_paused

guint gdk_window_espionage_get_frame_clock_events_paused(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->frame_clock_events_paused;
}

void gdk_window_espionage_set_frame_clock_events_paused(GdkWindow * self, guint frame_clock_events_paused) {
  ((struct _GdkWindow_v3_24_11*)self)->frame_clock_events_paused = frame_clock_events_paused;
}

// GdkWindow::impl_window

GdkWindow * gdk_window_espionage_get_impl_window(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->impl_window;
}

void gdk_window_espionage_set_impl_window(GdkWindow * self, GdkWindow * impl_window) {
  ((struct _GdkWindow_v3_24_11*)self)->impl_window = impl_window;
}

// GdkWindow::update_and_descendants_freeze_count

guint gdk_window_espionage_get_update_and_descendants_freeze_count(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->update_and_descendants_freeze_count;
}

void gdk_window_espionage_set_update_and_descendants_freeze_count(GdkWindow * self, guint update_and_descendants_freeze_count) {
  ((struct _GdkWindow_v3_24_11*)self)->update_and_descendants_freeze_count = update_and_descendants_freeze_count;
}

// GdkWindow::abs_x

gint gdk_window_espionage_get_abs_x(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->abs_x;
}

void gdk_window_espionage_set_abs_x(GdkWindow * self, gint abs_x) {
  ((struct _GdkWindow_v3_24_11*)self)->abs_x = abs_x;
}

// GdkWindow::abs_y

gint gdk_window_espionage_get_abs_y(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->abs_y;
}

void gdk_window_espionage_set_abs_y(GdkWindow * self, gint abs_y) {
  ((struct _GdkWindow_v3_24_11*)self)->abs_y = abs_y;
}

// GdkWindow::width

gint gdk_window_espionage_get_width(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->width;
}

void gdk_window_espionage_set_width(GdkWindow * self, gint width) {
  ((struct _GdkWindow_v3_24_11*)self)->width = width;
}

// GdkWindow::height

gint gdk_window_espionage_get_height(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->height;
}

void gdk_window_espionage_set_height(GdkWindow * self, gint height) {
  ((struct _GdkWindow_v3_24_11*)self)->height = height;
}

// GdkWindow::shadow_top

gint gdk_window_espionage_get_shadow_top(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_top;
}

void gdk_window_espionage_set_shadow_top(GdkWindow * self, gint shadow_top) {
  ((struct _GdkWindow_v3_24_11*)self)->shadow_top = shadow_top;
}

// GdkWindow::shadow_left

gint gdk_window_espionage_get_shadow_left(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_left;
}

void gdk_window_espionage_set_shadow_left(GdkWindow * self, gint shadow_left) {
  ((struct _GdkWindow_v3_24_11*)self)->shadow_left = shadow_left;
}

// GdkWindow::shadow_right

gint gdk_window_espionage_get_shadow_right(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_right;
}

void gdk_window_espionage_set_shadow_right(GdkWindow * self, gint shadow_right) {
  ((struct _GdkWindow_v3_24_11*)self)->shadow_right = shadow_right;
}

// GdkWindow::shadow_bottom

gint gdk_window_espionage_get_shadow_bottom(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shadow_bottom;
}

void gdk_window_espionage_set_shadow_bottom(GdkWindow * self, gint shadow_bottom) {
  ((struct _GdkWindow_v3_24_11*)self)->shadow_bottom = shadow_bottom;
}

// GdkWindow::num_offscreen_children

guint gdk_window_espionage_get_num_offscreen_children(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->num_offscreen_children;
}

void gdk_window_espionage_set_num_offscreen_children(GdkWindow * self, guint num_offscreen_children) {
  ((struct _GdkWindow_v3_24_11*)self)->num_offscreen_children = num_offscreen_children;
}

// GdkWindow::clip_region

cairo_region_t * gdk_window_espionage_get_clip_region(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->clip_region;
}

void gdk_window_espionage_set_clip_region(GdkWindow * self, cairo_region_t * clip_region) {
  ((struct _GdkWindow_v3_24_11*)self)->clip_region = clip_region;
}

// GdkWindow::cursor

GdkCursor * gdk_window_espionage_get_cursor(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->cursor;
}

void gdk_window_espionage_set_cursor(GdkWindow * self, GdkCursor * cursor) {
  ((struct _GdkWindow_v3_24_11*)self)->cursor = cursor;
}

// GdkWindow::device_cursor

GHashTable * gdk_window_espionage_get_device_cursor(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_cursor;
}

void gdk_window_espionage_set_device_cursor(GdkWindow * self, GHashTable * device_cursor) {
  ((struct _GdkWindow_v3_24_11*)self)->device_cursor = device_cursor;
}

// GdkWindow::shape

cairo_region_t * gdk_window_espionage_get_shape(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->shape;
}

void gdk_window_espionage_set_shape(GdkWindow * self, cairo_region_t * shape) {
  ((struct _GdkWindow_v3_24_11*)self)->shape = shape;
}

// GdkWindow::input_shape

cairo_region_t * gdk_window_espionage_get_input_shape(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->input_shape;
}

void gdk_window_espionage_set_input_shape(GdkWindow * self, cairo_region_t * input_shape) {
  ((struct _GdkWindow_v3_24_11*)self)->input_shape = input_shape;
}

// GdkWindow::devices_inside

GList * gdk_window_espionage_get_devices_inside(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->devices_inside;
}

void gdk_window_espionage_set_devices_inside(GdkWindow * self, GList * devices_inside) {
  ((struct _GdkWindow_v3_24_11*)self)->devices_inside = devices_inside;
}

// GdkWindow::device_events

GHashTable * gdk_window_espionage_get_device_events(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->device_events;
}

void gdk_window_espionage_set_device_events(GdkWindow * self, GHashTable * device_events) {
  ((struct _GdkWindow_v3_24_11*)self)->device_events = device_events;
}

// GdkWindow::source_event_masks

GHashTable * gdk_window_espionage_get_source_event_masks(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->source_event_masks;
}

void gdk_window_espionage_set_source_event_masks(GdkWindow * self, GHashTable * source_event_masks) {
  ((struct _GdkWindow_v3_24_11*)self)->source_event_masks = source_event_masks;
}

// GdkWindow::device_added_handler_id

gulong * gdk_window_espionage_get_device_added_handler_id_ptr(GdkWindow * self) {
  return (gulong *)&((struct _GdkWindow_v3_24_11*)self)->device_added_handler_id;
}

// GdkWindow::device_changed_handler_id

gulong * gdk_window_espionage_get_device_changed_handler_id_ptr(GdkWindow * self) {
  return (gulong *)&((struct _GdkWindow_v3_24_11*)self)->device_changed_handler_id;
}

// GdkWindow::frame_clock

GdkFrameClock * gdk_window_espionage_get_frame_clock(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->frame_clock;
}

void gdk_window_espionage_set_frame_clock(GdkWindow * self, GdkFrameClock * frame_clock) {
  ((struct _GdkWindow_v3_24_11*)self)->frame_clock = frame_clock;
}

// GdkWindow::invalidate_handler

GdkWindowInvalidateHandlerFunc * gdk_window_espionage_get_invalidate_handler_ptr(GdkWindow * self) {
  return (GdkWindowInvalidateHandlerFunc *)&((struct _GdkWindow_v3_24_11*)self)->invalidate_handler;
}

// GdkWindow::drawing_context

GdkDrawingContext * gdk_window_espionage_get_drawing_context(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->drawing_context;
}

void gdk_window_espionage_set_drawing_context(GdkWindow * self, GdkDrawingContext * drawing_context) {
  ((struct _GdkWindow_v3_24_11*)self)->drawing_context = drawing_context;
}

// GdkWindow::opaque_region

cairo_region_t * gdk_window_espionage_get_opaque_region(GdkWindow * self) {
  return ((struct _GdkWindow_v3_24_11*)self)->opaque_region;
}

void gdk_window_espionage_set_opaque_region(GdkWindow * self, cairo_region_t * opaque_region) {
  ((struct _GdkWindow_v3_24_11*)self)->opaque_region = opaque_region;
}

#endif // GDK_WINDOW_ESPIONAGE_H
