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

#ifndef GDK_WINDOW_IMPL_CLASS_ESPIONAGE_H
#define GDK_WINDOW_IMPL_CLASS_ESPIONAGE_H

typedef struct _GdkWindowImplClass GdkWindowImplClass;

// Valid for GTK v3.22.0 - v3.24.21
struct _GdkWindowImplClass_v3_22_0
{
  GObjectClass parent_class;
  cairo_surface_t * (* ref_cairo_surface) (GdkWindow *window);
  cairo_surface_t * (* create_similar_image_surface) (GdkWindow *window, cairo_format_t format, int width, int height);
  void (* show) (GdkWindow *window, gboolean already_mapped);
  void (* hide) (GdkWindow *window);
  void (* withdraw) (GdkWindow *window);
  void (* raise) (GdkWindow *window);
  void (* lower) (GdkWindow *window);
  void (* restack_under) (GdkWindow *window, GList *native_siblings);
  void (* restack_toplevel) (GdkWindow *window, GdkWindow *sibling, gboolean above);
  void (* move_resize) (GdkWindow *window, gboolean with_move, gint x, gint y, gint width, gint height);
  void (* move_to_rect) (GdkWindow *window, const GdkRectangle *rect, GdkGravity rect_anchor, GdkGravity window_anchor, GdkAnchorHints anchor_hints, gint rect_anchor_dx, gint rect_anchor_dy);
  void (* set_background) (GdkWindow *window, cairo_pattern_t *pattern);
  GdkEventMask (* get_events) (GdkWindow *window);
  void (* set_events) (GdkWindow *window, GdkEventMask event_mask);
  gboolean (* reparent) (GdkWindow *window, GdkWindow *new_parent, gint x, gint y);
  void (* set_device_cursor) (GdkWindow *window, GdkDevice *device, GdkCursor *cursor);
  void (* get_geometry) (GdkWindow *window, gint *x, gint *y, gint *width, gint *height);
  void (* get_root_coords) (GdkWindow *window, gint x, gint y, gint *root_x, gint *root_y);
  gboolean (* get_device_state) (GdkWindow *window, GdkDevice *device, gdouble *x, gdouble *y, GdkModifierType *mask);
  gboolean (* begin_paint) (GdkWindow *window);
  void (* end_paint) (GdkWindow *window);
  cairo_region_t * (* get_shape) (GdkWindow *window);
  cairo_region_t * (* get_input_shape) (GdkWindow *window);
  void (* shape_combine_region) (GdkWindow *window, const cairo_region_t *shape_region, gint offset_x, gint offset_y);
  void (* input_shape_combine_region) (GdkWindow *window, const cairo_region_t *shape_region, gint offset_x, gint offset_y);
  void (* queue_antiexpose) (GdkWindow *window, cairo_region_t *update_area);
  void (* destroy) (GdkWindow *window, gboolean recursing, gboolean foreign_destroy);
  void (* destroy_foreign) (GdkWindow *window);
  gboolean (* beep) (GdkWindow *window);
  void (* focus) (GdkWindow *window, guint32 timestamp);
  void (* set_type_hint) (GdkWindow *window, GdkWindowTypeHint hint);
  GdkWindowTypeHint (* get_type_hint) (GdkWindow *window);
  void (* set_modal_hint) (GdkWindow *window, gboolean modal);
  void (* set_skip_taskbar_hint) (GdkWindow *window, gboolean skips_taskbar);
  void (* set_skip_pager_hint) (GdkWindow *window, gboolean skips_pager);
  void (* set_urgency_hint) (GdkWindow *window, gboolean urgent);
  void (* set_geometry_hints) (GdkWindow *window, const GdkGeometry *geometry, GdkWindowHints geom_mask);
  void (* set_title) (GdkWindow *window, const gchar *title);
  void (* set_role) (GdkWindow *window, const gchar *role);
  void (* set_startup_id) (GdkWindow *window, const gchar *startup_id);
  void (* set_transient_for) (GdkWindow *window, GdkWindow *parent);
  void (* get_frame_extents) (GdkWindow *window, GdkRectangle *rect);
  void (* set_override_redirect) (GdkWindow *window, gboolean override_redirect);
  void (* set_accept_focus) (GdkWindow *window, gboolean accept_focus);
  void (* set_focus_on_map) (GdkWindow *window, gboolean focus_on_map);
  void (* set_icon_list) (GdkWindow *window, GList *pixbufs);
  void (* set_icon_name) (GdkWindow *window, const gchar *name);
  void (* iconify) (GdkWindow *window);
  void (* deiconify) (GdkWindow *window);
  void (* stick) (GdkWindow *window);
  void (* unstick) (GdkWindow *window);
  void (* maximize) (GdkWindow *window);
  void (* unmaximize) (GdkWindow *window);
  void (* fullscreen) (GdkWindow *window);
  void (* fullscreen_on_monitor) (GdkWindow *window, gint monitor);
  void (* apply_fullscreen_mode) (GdkWindow *window);
  void (* unfullscreen) (GdkWindow *window);
  void (* set_keep_above) (GdkWindow *window, gboolean setting);
  void (* set_keep_below) (GdkWindow *window, gboolean setting);
  GdkWindow * (* get_group) (GdkWindow *window);
  void (* set_group) (GdkWindow *window, GdkWindow *leader);
  void (* set_decorations) (GdkWindow *window, GdkWMDecoration decorations);
  gboolean (* get_decorations) (GdkWindow *window, GdkWMDecoration *decorations);
  void (* set_functions) (GdkWindow *window, GdkWMFunction functions);
  void (* begin_resize_drag) (GdkWindow *window, GdkWindowEdge edge, GdkDevice *device, gint button, gint root_x, gint root_y, guint32 timestamp);
  void (* begin_move_drag) (GdkWindow *window, GdkDevice *device, gint button, gint root_x, gint root_y, guint32 timestamp);
  void (* enable_synchronized_configure) (GdkWindow *window);
  void (* configure_finished) (GdkWindow *window);
  void (* set_opacity) (GdkWindow *window, gdouble opacity);
  void (* set_composited) (GdkWindow *window, gboolean composited);
  void (* destroy_notify) (GdkWindow *window);
  GdkDragProtocol (* get_drag_protocol) (GdkWindow *window, GdkWindow **target);
  void (* register_dnd) (GdkWindow *window);
  GdkDragContext * (* drag_begin) (GdkWindow *window, GdkDevice *device, GList *targets, gint x_root, gint y_root);
  void (* process_updates_recurse) (GdkWindow *window, cairo_region_t *region);
  void (* sync_rendering) (GdkWindow *window);
  gboolean (* simulate_key) (GdkWindow *window, gint x, gint y, guint keyval, GdkModifierType modifiers, GdkEventType event_type);
  gboolean (* simulate_button) (GdkWindow *window, gint x, gint y, guint button, GdkModifierType modifiers, GdkEventType event_type);
  gboolean (* get_property) (GdkWindow *window, GdkAtom property, GdkAtom type, gulong offset, gulong length, gint pdelete, GdkAtom *actual_type, gint *actual_format, gint *actual_length, guchar **data);
  void (* change_property) (GdkWindow *window, GdkAtom property, GdkAtom type, gint format, GdkPropMode mode, const guchar *data, gint n_elements);
  void (* delete_property) (GdkWindow *window, GdkAtom property);
  gint (* get_scale_factor) (GdkWindow *window);
  void (* get_unscaled_size) (GdkWindow *window, int *unscaled_width, int *unscaled_height);
  void (* set_opaque_region) (GdkWindow *window, cairo_region_t *region);
  void (* set_shadow_width) (GdkWindow *window, gint left, gint right, gint top, gint bottom);
  gboolean (* show_window_menu) (GdkWindow *window, GdkEvent *event);
  GdkGLContext * (* create_gl_context) (GdkWindow *window, gboolean attached, GdkGLContext *share, GError **error);
  gboolean (* realize_gl_context) (GdkWindow *window, GdkGLContext *context, GError **error);
  void (* invalidate_for_new_frame) (GdkWindow *window, cairo_region_t *update_area);
  GdkDrawingContext * (* create_draw_context) (GdkWindow *window, const cairo_region_t *region);
  void (* destroy_draw_context) (GdkWindow *window, GdkDrawingContext *context);
};

GObjectClass gdk_window_impl_class_extract_parent_class(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->parent_class;
}

cairo_surface_t * (*) (GdkWindow *window) gdk_window_impl_class_extract_ref_cairo_surface(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->ref_cairo_surface;
}

cairo_surface_t * (*) (GdkWindow *window, cairo_format_t format, int width, int height) gdk_window_impl_class_extract_create_similar_image_surface(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->create_similar_image_surface;
}

void (*) (GdkWindow *window, gboolean already_mapped) gdk_window_impl_class_extract_show(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->show;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_hide(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->hide;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_withdraw(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->withdraw;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_raise(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->raise;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_lower(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->lower;
}

void (*) (GdkWindow *window, GList *native_siblings) gdk_window_impl_class_extract_restack_under(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->restack_under;
}

void (*) (GdkWindow *window, GdkWindow *sibling, gboolean above) gdk_window_impl_class_extract_restack_toplevel(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->restack_toplevel;
}

void (*) (GdkWindow *window, gboolean with_move, gint x, gint y, gint width, gint height) gdk_window_impl_class_extract_move_resize(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->move_resize;
}

void (*) (GdkWindow *window, const GdkRectangle *rect, GdkGravity rect_anchor, GdkGravity window_anchor, GdkAnchorHints anchor_hints, gint rect_anchor_dx, gint rect_anchor_dy) gdk_window_impl_class_extract_move_to_rect(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->move_to_rect;
}

void (*) (GdkWindow *window, cairo_pattern_t *pattern) gdk_window_impl_class_extract_set_background(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_background;
}

GdkEventMask (*) (GdkWindow *window) gdk_window_impl_class_extract_get_events(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_events;
}

void (*) (GdkWindow *window, GdkEventMask event_mask) gdk_window_impl_class_extract_set_events(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_events;
}

gboolean (*) (GdkWindow *window, GdkWindow *new_parent, gint x, gint y) gdk_window_impl_class_extract_reparent(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->reparent;
}

void (*) (GdkWindow *window, GdkDevice *device, GdkCursor *cursor) gdk_window_impl_class_extract_set_device_cursor(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_device_cursor;
}

void (*) (GdkWindow *window, gint *x, gint *y, gint *width, gint *height) gdk_window_impl_class_extract_get_geometry(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_geometry;
}

void (*) (GdkWindow *window, gint x, gint y, gint *root_x, gint *root_y) gdk_window_impl_class_extract_get_root_coords(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_root_coords;
}

gboolean (*) (GdkWindow *window, GdkDevice *device, gdouble *x, gdouble *y, GdkModifierType *mask) gdk_window_impl_class_extract_get_device_state(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_device_state;
}

gboolean (*) (GdkWindow *window) gdk_window_impl_class_extract_begin_paint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->begin_paint;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_end_paint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->end_paint;
}

cairo_region_t * (*) (GdkWindow *window) gdk_window_impl_class_extract_get_shape(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_shape;
}

cairo_region_t * (*) (GdkWindow *window) gdk_window_impl_class_extract_get_input_shape(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_input_shape;
}

void (*) (GdkWindow *window, const cairo_region_t *shape_region, gint offset_x, gint offset_y) gdk_window_impl_class_extract_shape_combine_region(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->shape_combine_region;
}

void (*) (GdkWindow *window, const cairo_region_t *shape_region, gint offset_x, gint offset_y) gdk_window_impl_class_extract_input_shape_combine_region(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->input_shape_combine_region;
}

void (*) (GdkWindow *window, cairo_region_t *update_area) gdk_window_impl_class_extract_queue_antiexpose(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->queue_antiexpose;
}

void (*) (GdkWindow *window, gboolean recursing, gboolean foreign_destroy) gdk_window_impl_class_extract_destroy(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->destroy;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_destroy_foreign(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->destroy_foreign;
}

gboolean (*) (GdkWindow *window) gdk_window_impl_class_extract_beep(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->beep;
}

void (*) (GdkWindow *window, guint32 timestamp) gdk_window_impl_class_extract_focus(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->focus;
}

void (*) (GdkWindow *window, GdkWindowTypeHint hint) gdk_window_impl_class_extract_set_type_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_type_hint;
}

GdkWindowTypeHint (*) (GdkWindow *window) gdk_window_impl_class_extract_get_type_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_type_hint;
}

void (*) (GdkWindow *window, gboolean modal) gdk_window_impl_class_extract_set_modal_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_modal_hint;
}

void (*) (GdkWindow *window, gboolean skips_taskbar) gdk_window_impl_class_extract_set_skip_taskbar_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_skip_taskbar_hint;
}

void (*) (GdkWindow *window, gboolean skips_pager) gdk_window_impl_class_extract_set_skip_pager_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_skip_pager_hint;
}

void (*) (GdkWindow *window, gboolean urgent) gdk_window_impl_class_extract_set_urgency_hint(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_urgency_hint;
}

void (*) (GdkWindow *window, const GdkGeometry *geometry, GdkWindowHints geom_mask) gdk_window_impl_class_extract_set_geometry_hints(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_geometry_hints;
}

void (*) (GdkWindow *window, const gchar *title) gdk_window_impl_class_extract_set_title(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_title;
}

void (*) (GdkWindow *window, const gchar *role) gdk_window_impl_class_extract_set_role(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_role;
}

void (*) (GdkWindow *window, const gchar *startup_id) gdk_window_impl_class_extract_set_startup_id(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_startup_id;
}

void (*) (GdkWindow *window, GdkWindow *parent) gdk_window_impl_class_extract_set_transient_for(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_transient_for;
}

void (*) (GdkWindow *window, GdkRectangle *rect) gdk_window_impl_class_extract_get_frame_extents(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_frame_extents;
}

void (*) (GdkWindow *window, gboolean override_redirect) gdk_window_impl_class_extract_set_override_redirect(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_override_redirect;
}

void (*) (GdkWindow *window, gboolean accept_focus) gdk_window_impl_class_extract_set_accept_focus(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_accept_focus;
}

void (*) (GdkWindow *window, gboolean focus_on_map) gdk_window_impl_class_extract_set_focus_on_map(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_focus_on_map;
}

void (*) (GdkWindow *window, GList *pixbufs) gdk_window_impl_class_extract_set_icon_list(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_icon_list;
}

void (*) (GdkWindow *window, const gchar *name) gdk_window_impl_class_extract_set_icon_name(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_icon_name;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_iconify(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->iconify;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_deiconify(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->deiconify;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_stick(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->stick;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_unstick(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->unstick;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_maximize(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->maximize;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_unmaximize(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->unmaximize;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_fullscreen(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->fullscreen;
}

void (*) (GdkWindow *window, gint monitor) gdk_window_impl_class_extract_fullscreen_on_monitor(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->fullscreen_on_monitor;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_apply_fullscreen_mode(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->apply_fullscreen_mode;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_unfullscreen(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->unfullscreen;
}

void (*) (GdkWindow *window, gboolean setting) gdk_window_impl_class_extract_set_keep_above(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_keep_above;
}

void (*) (GdkWindow *window, gboolean setting) gdk_window_impl_class_extract_set_keep_below(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_keep_below;
}

GdkWindow * (*) (GdkWindow *window) gdk_window_impl_class_extract_get_group(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_group;
}

void (*) (GdkWindow *window, GdkWindow *leader) gdk_window_impl_class_extract_set_group(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_group;
}

void (*) (GdkWindow *window, GdkWMDecoration decorations) gdk_window_impl_class_extract_set_decorations(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_decorations;
}

gboolean (*) (GdkWindow *window, GdkWMDecoration *decorations) gdk_window_impl_class_extract_get_decorations(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_decorations;
}

void (*) (GdkWindow *window, GdkWMFunction functions) gdk_window_impl_class_extract_set_functions(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_functions;
}

void (*) (GdkWindow *window, GdkWindowEdge edge, GdkDevice *device, gint button, gint root_x, gint root_y, guint32 timestamp) gdk_window_impl_class_extract_begin_resize_drag(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->begin_resize_drag;
}

void (*) (GdkWindow *window, GdkDevice *device, gint button, gint root_x, gint root_y, guint32 timestamp) gdk_window_impl_class_extract_begin_move_drag(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->begin_move_drag;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_enable_synchronized_configure(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->enable_synchronized_configure;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_configure_finished(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->configure_finished;
}

void (*) (GdkWindow *window, gdouble opacity) gdk_window_impl_class_extract_set_opacity(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_opacity;
}

void (*) (GdkWindow *window, gboolean composited) gdk_window_impl_class_extract_set_composited(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_composited;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_destroy_notify(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->destroy_notify;
}

GdkDragProtocol (*) (GdkWindow *window, GdkWindow **target) gdk_window_impl_class_extract_get_drag_protocol(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_drag_protocol;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_register_dnd(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->register_dnd;
}

GdkDragContext * (*) (GdkWindow *window, GdkDevice *device, GList *targets, gint x_root, gint y_root) gdk_window_impl_class_extract_drag_begin(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->drag_begin;
}

void (*) (GdkWindow *window, cairo_region_t *region) gdk_window_impl_class_extract_process_updates_recurse(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->process_updates_recurse;
}

void (*) (GdkWindow *window) gdk_window_impl_class_extract_sync_rendering(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->sync_rendering;
}

gboolean (*) (GdkWindow *window, gint x, gint y, guint keyval, GdkModifierType modifiers, GdkEventType event_type) gdk_window_impl_class_extract_simulate_key(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->simulate_key;
}

gboolean (*) (GdkWindow *window, gint x, gint y, guint button, GdkModifierType modifiers, GdkEventType event_type) gdk_window_impl_class_extract_simulate_button(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->simulate_button;
}

gboolean (*) (GdkWindow *window, GdkAtom property, GdkAtom type, gulong offset, gulong length, gint pdelete, GdkAtom *actual_type, gint *actual_format, gint *actual_length, guchar **data) gdk_window_impl_class_extract_get_property(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_property;
}

void (*) (GdkWindow *window, GdkAtom property, GdkAtom type, gint format, GdkPropMode mode, const guchar *data, gint n_elements) gdk_window_impl_class_extract_change_property(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->change_property;
}

void (*) (GdkWindow *window, GdkAtom property) gdk_window_impl_class_extract_delete_property(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->delete_property;
}

gint (*) (GdkWindow *window) gdk_window_impl_class_extract_get_scale_factor(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_scale_factor;
}

void (*) (GdkWindow *window, int *unscaled_width, int *unscaled_height) gdk_window_impl_class_extract_get_unscaled_size(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->get_unscaled_size;
}

void (*) (GdkWindow *window, cairo_region_t *region) gdk_window_impl_class_extract_set_opaque_region(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_opaque_region;
}

void (*) (GdkWindow *window, gint left, gint right, gint top, gint bottom) gdk_window_impl_class_extract_set_shadow_width(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->set_shadow_width;
}

gboolean (*) (GdkWindow *window, GdkEvent *event) gdk_window_impl_class_extract_show_window_menu(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->show_window_menu;
}

GdkGLContext * (*) (GdkWindow *window, gboolean attached, GdkGLContext *share, GError **error) gdk_window_impl_class_extract_create_gl_context(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->create_gl_context;
}

gboolean (*) (GdkWindow *window, GdkGLContext *context, GError **error) gdk_window_impl_class_extract_realize_gl_context(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->realize_gl_context;
}

void (*) (GdkWindow *window, cairo_region_t *update_area) gdk_window_impl_class_extract_invalidate_for_new_frame(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->invalidate_for_new_frame;
}

GdkDrawingContext * (*) (GdkWindow *window, const cairo_region_t *region) gdk_window_impl_class_extract_create_draw_context(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->create_draw_context;
}

void (*) (GdkWindow *window, GdkDrawingContext *context) gdk_window_impl_class_extract_destroy_draw_context(GdkWindowImplClass* self) {
  return ((struct _GdkWindowImplClass_v3_22_0*)self)->destroy_draw_context;
}

#endif // GDK_WINDOW_IMPL_CLASS_ESPIONAGE_H
