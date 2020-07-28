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

#ifndef GDK_WINDOW_IMPL_WAYLAND_ESPIONAGE_H
#define GDK_WINDOW_IMPL_WAYLAND_ESPIONAGE_H

typedef struct _GdkWindowImplWayland GdkWindowImplWayland;

// Version ID 0
// Valid for GTK v3.22.0 - v3.22.15
struct _GdkWindowImplWayland_v3_22_0
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct zxdg_surface_v6 *xdg_surface;
    struct zxdg_toplevel_v6 *xdg_toplevel;
    struct zxdg_popup_v6 *xdg_popup;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    GdkWaylandWindowExported callback;
    gpointer user_data;
    GDestroyNotify destroy_func;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
};

// Version ID 1
// Valid for GTK v3.22.16 - v3.22.17
struct _GdkWindowImplWayland_v3_22_16
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct zxdg_surface_v6 *xdg_surface;
    struct zxdg_toplevel_v6 *xdg_toplevel;
    struct zxdg_popup_v6 *xdg_popup;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
};

// Version ID 2
// Valid for GTK v3.22.18 - v3.22.24
struct _GdkWindowImplWayland_v3_22_18
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct zxdg_surface_v6 *xdg_surface;
    struct zxdg_toplevel_v6 *xdg_toplevel;
    struct zxdg_popup_v6 *xdg_popup;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 3
// Valid for GTK v3.22.25 - v3.22.29
struct _GdkWindowImplWayland_v3_22_25
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct zxdg_surface_v6 *xdg_surface;
    struct zxdg_toplevel_v6 *xdg_toplevel;
    struct zxdg_popup_v6 *xdg_popup;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 4
// Valid for GTK v3.22.30 - v3.23.0
struct _GdkWindowImplWayland_v3_22_30
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct xdg_surface *xdg_surface;
    struct xdg_toplevel *xdg_toplevel;
    struct xdg_popup *xdg_popup;
    struct zxdg_surface_v6 *zxdg_surface_v6;
    struct zxdg_toplevel_v6 *zxdg_toplevel_v6;
    struct zxdg_popup_v6 *zxdg_popup_v6;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 5
// Valid for GTK v3.23.1 - v3.23.2
struct _GdkWindowImplWayland_v3_23_1
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct xdg_surface *xdg_surface;
    struct xdg_toplevel *xdg_toplevel;
    struct xdg_popup *xdg_popup;
    struct zxdg_surface_v6 *zxdg_surface_v6;
    struct zxdg_toplevel_v6 *zxdg_toplevel_v6;
    struct zxdg_popup_v6 *zxdg_popup_v6;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  unsigned int using_csd : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 6
// Valid for GTK v3.23.3 - v3.24.3
struct _GdkWindowImplWayland_v3_23_3
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct xdg_surface *xdg_surface;
    struct xdg_toplevel *xdg_toplevel;
    struct xdg_popup *xdg_popup;
    struct zxdg_surface_v6 *zxdg_surface_v6;
    struct zxdg_toplevel_v6 *zxdg_toplevel_v6;
    struct zxdg_popup_v6 *zxdg_popup_v6;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  unsigned int using_csd : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  int subsurface_x;
  int subsurface_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 7
// Valid for GTK v3.24.4 - v3.24.16
struct _GdkWindowImplWayland_v3_24_4
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct xdg_surface *xdg_surface;
    struct xdg_toplevel *xdg_toplevel;
    struct xdg_popup *xdg_popup;
    struct zxdg_surface_v6 *zxdg_surface_v6;
    struct zxdg_toplevel_v6 *zxdg_toplevel_v6;
    struct zxdg_popup_v6 *zxdg_popup_v6;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int configuring_popup : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  unsigned int using_csd : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  int subsurface_x;
  int subsurface_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// Version ID 8
// Valid for GTK v3.24.17 - v3.24.21
struct _GdkWindowImplWayland_v3_24_17
{
  struct _GdkWindowImpl_v3_22_0 parent_instance;
  GdkWindow *wrapper;
  struct {
    GSList *outputs;
    struct wl_surface *wl_surface;
    struct xdg_surface *xdg_surface;
    struct xdg_toplevel *xdg_toplevel;
    struct xdg_popup *xdg_popup;
    struct zxdg_surface_v6 *zxdg_surface_v6;
    struct zxdg_toplevel_v6 *zxdg_toplevel_v6;
    struct zxdg_popup_v6 *zxdg_popup_v6;
    struct gtk_surface1 *gtk_surface;
    struct wl_subsurface *wl_subsurface;
    struct wl_egl_window *egl_window;
    struct wl_egl_window *dummy_egl_window;
    struct zxdg_exported_v1 *xdg_exported;
    struct org_kde_kwin_server_decoration *server_decoration;
  } display_server;
  EGLSurface egl_surface;
  EGLSurface dummy_egl_surface;
  unsigned int initial_configure_received : 1;
  unsigned int configuring_popup : 1;
  unsigned int mapped : 1;
  unsigned int use_custom_surface : 1;
  unsigned int pending_buffer_attached : 1;
  unsigned int pending_commit : 1;
  unsigned int awaiting_frame : 1;
  unsigned int using_csd : 1;
  GdkWindowTypeHint hint;
  GdkWindow *transient_for;
  GdkWindow *popup_parent;
  PositionMethod position_method;
  cairo_surface_t *staging_cairo_surface;
  cairo_surface_t *committed_cairo_surface;
  cairo_surface_t *backfill_cairo_surface;
  int pending_buffer_offset_x;
  int pending_buffer_offset_y;
  int subsurface_x;
  int subsurface_y;
  gchar *title;
  struct {
    gboolean was_set;
    gchar *application_id;
    gchar *app_menu_path;
    gchar *menubar_path;
    gchar *window_object_path;
    gchar *application_object_path;
    gchar *unique_bus_name;
  } application;
  GdkGeometry geometry_hints;
  GdkWindowHints geometry_mask;
  GdkSeat *grab_input_seat;
  gint64 pending_frame_counter;
  guint32 scale;
  int margin_left;
  int margin_right;
  int margin_top;
  int margin_bottom;
  gboolean margin_dirty;
  int initial_fullscreen_monitor;
  cairo_region_t *opaque_region;
  gboolean opaque_region_dirty;
  cairo_region_t *input_region;
  gboolean input_region_dirty;
  cairo_region_t *staged_updates_region;
  int saved_width;
  int saved_height;
  int unconfigured_width;
  int unconfigured_height;
  int fixed_size_width;
  int fixed_size_height;
  gulong parent_surface_committed_handler;
  struct {
    GdkRectangle rect;
    GdkGravity rect_anchor;
    GdkGravity window_anchor;
    GdkAnchorHints anchor_hints;
    gint rect_anchor_dx;
    gint rect_anchor_dy;
  } pending_move_to_rect;
  struct {
    int width;
    int height;
    GdkWindowState state;
  } pending;
  struct {
    char *handle;
    int export_count;
    GList *closures;
    guint idle_source_id;
  } exported;
  struct zxdg_imported_v1 *imported_transient_for;
  GHashTable *shortcuts_inhibitors;
};

// For internal use only
int gdk_window_impl_wayland_espionage_get_version_id() {
  static int version_id = -1;
  
  if (version_id == -1) {
    if (gtk_get_major_version() != 3) {
      g_error("gtk3-espionage only supports GTK3");
      g_abort();
    }
  
    int combo = gtk_get_minor_version() * 1000 + gtk_get_micro_version();
  
    switch (combo) {
      case 22000:
      case 22001:
      case 22002:
      case 22003:
      case 22004:
      case 22005:
      case 22006:
      case 22007:
      case 22008:
      case 22009:
      case 22010:
      case 22011:
      case 22012:
      case 22013:
      case 22014:
      case 22015:
      case 22016:
      case 22017:
      case 22018:
      case 22019:
      case 22020:
      case 22021:
      case 22022:
      case 22023:
      case 22024:
      case 22025:
      case 22026:
      case 22027:
      case 22028:
      case 22029:
      case 22030:
      case 23000:
      case 23001:
      case 23002:
      case 23003:
      case 24000:
      case 24001:
      case 24002:
      case 24003:
      case 24004:
      case 24005:
      case 24006:
      case 24007:
      case 24008:
      case 24009:
      case 24010:
      case 24011:
      case 24012:
      case 24013:
      case 24014:
      case 24015:
      case 24016:
      case 24017:
      case 24018:
      case 24020:
      case 24021:
        break;
  
      default:
        g_warning(
          "gtk3-espionage was not compiled with support for GTK v%d.%d.%d, program may crash",
          gtk_get_major_version(),
          gtk_get_minor_version(),
          gtk_get_micro_version());
    }
  
    if (combo >= 24017) {
      version_id = 8;
    } else if (combo >= 24004) {
      version_id = 7;
    } else if (combo >= 23003) {
      version_id = 6;
    } else if (combo >= 23001) {
      version_id = 5;
    } else if (combo >= 22030) {
      version_id = 4;
    } else if (combo >= 22025) {
      version_id = 3;
    } else if (combo >= 22018) {
      version_id = 2;
    } else if (combo >= 22016) {
      version_id = 1;
    } else {
      version_id = 0;
    }
  }
  
  return version_id;
}

// GdkWindowImplWayland::parent_instance

GdkWindowImpl * gdk_window_impl_wayland_espionage_get_parent_instance_ptr(GdkWindowImplWayland * self) {
  return (GdkWindowImpl *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->parent_instance;
}

// GdkWindowImplWayland::wrapper

GdkWindow * gdk_window_impl_wayland_espionage_get_wrapper(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->wrapper;
}

void gdk_window_impl_wayland_espionage_set_wrapper(GdkWindowImplWayland * self, GdkWindow * wrapper) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->wrapper = wrapper;
}

// GdkWindowImplWayland::display_server.outputs

GSList * gdk_window_impl_wayland_espionage_get_display_server_outputs(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.outputs;
}

void gdk_window_impl_wayland_espionage_set_display_server_outputs(GdkWindowImplWayland * self, GSList * display_server_outputs) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.outputs = display_server_outputs;
}

// GdkWindowImplWayland::display_server.wl_surface

struct wl_surface * gdk_window_impl_wayland_espionage_get_display_server_wl_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_surface;
}

void gdk_window_impl_wayland_espionage_set_display_server_wl_surface(GdkWindowImplWayland * self, struct wl_surface * display_server_wl_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_surface = display_server_wl_surface;
}

// GdkWindowImplWayland::display_server.xdg_surface

struct xdg_surface * gdk_window_impl_wayland_espionage_get_display_server_xdg_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_surface;
}

void gdk_window_impl_wayland_espionage_set_display_server_xdg_surface(GdkWindowImplWayland * self, struct xdg_surface * display_server_xdg_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_surface = display_server_xdg_surface;
}

// GdkWindowImplWayland::display_server.xdg_toplevel

struct xdg_toplevel * gdk_window_impl_wayland_espionage_get_display_server_xdg_toplevel(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_toplevel;
}

void gdk_window_impl_wayland_espionage_set_display_server_xdg_toplevel(GdkWindowImplWayland * self, struct xdg_toplevel * display_server_xdg_toplevel) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_toplevel = display_server_xdg_toplevel;
}

// GdkWindowImplWayland::display_server.xdg_popup

struct xdg_popup * gdk_window_impl_wayland_espionage_get_display_server_xdg_popup(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_popup;
}

void gdk_window_impl_wayland_espionage_set_display_server_xdg_popup(GdkWindowImplWayland * self, struct xdg_popup * display_server_xdg_popup) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_popup = display_server_xdg_popup;
}

// GdkWindowImplWayland::display_server.zxdg_surface_v6

struct zxdg_surface_v6 * gdk_window_impl_wayland_espionage_get_display_server_zxdg_surface_v6(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_surface_v6;
}

void gdk_window_impl_wayland_espionage_set_display_server_zxdg_surface_v6(GdkWindowImplWayland * self, struct zxdg_surface_v6 * display_server_zxdg_surface_v6) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_surface_v6 = display_server_zxdg_surface_v6;
}

// GdkWindowImplWayland::display_server.zxdg_toplevel_v6

struct zxdg_toplevel_v6 * gdk_window_impl_wayland_espionage_get_display_server_zxdg_toplevel_v6(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_toplevel_v6;
}

void gdk_window_impl_wayland_espionage_set_display_server_zxdg_toplevel_v6(GdkWindowImplWayland * self, struct zxdg_toplevel_v6 * display_server_zxdg_toplevel_v6) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_toplevel_v6 = display_server_zxdg_toplevel_v6;
}

// GdkWindowImplWayland::display_server.zxdg_popup_v6

struct zxdg_popup_v6 * gdk_window_impl_wayland_espionage_get_display_server_zxdg_popup_v6(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_popup_v6;
}

void gdk_window_impl_wayland_espionage_set_display_server_zxdg_popup_v6(GdkWindowImplWayland * self, struct zxdg_popup_v6 * display_server_zxdg_popup_v6) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_popup_v6 = display_server_zxdg_popup_v6;
}

// GdkWindowImplWayland::display_server.gtk_surface

struct gtk_surface1 * gdk_window_impl_wayland_espionage_get_display_server_gtk_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.gtk_surface;
}

void gdk_window_impl_wayland_espionage_set_display_server_gtk_surface(GdkWindowImplWayland * self, struct gtk_surface1 * display_server_gtk_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.gtk_surface = display_server_gtk_surface;
}

// GdkWindowImplWayland::display_server.wl_subsurface

struct wl_subsurface * gdk_window_impl_wayland_espionage_get_display_server_wl_subsurface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_subsurface;
}

void gdk_window_impl_wayland_espionage_set_display_server_wl_subsurface(GdkWindowImplWayland * self, struct wl_subsurface * display_server_wl_subsurface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_subsurface = display_server_wl_subsurface;
}

// GdkWindowImplWayland::display_server.egl_window

struct wl_egl_window * gdk_window_impl_wayland_espionage_get_display_server_egl_window(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.egl_window;
}

void gdk_window_impl_wayland_espionage_set_display_server_egl_window(GdkWindowImplWayland * self, struct wl_egl_window * display_server_egl_window) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.egl_window = display_server_egl_window;
}

// GdkWindowImplWayland::display_server.dummy_egl_window

struct wl_egl_window * gdk_window_impl_wayland_espionage_get_display_server_dummy_egl_window(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.dummy_egl_window;
}

void gdk_window_impl_wayland_espionage_set_display_server_dummy_egl_window(GdkWindowImplWayland * self, struct wl_egl_window * display_server_dummy_egl_window) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.dummy_egl_window = display_server_dummy_egl_window;
}

// GdkWindowImplWayland::display_server.xdg_exported

struct zxdg_exported_v1 * gdk_window_impl_wayland_espionage_get_display_server_xdg_exported(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_exported;
}

void gdk_window_impl_wayland_espionage_set_display_server_xdg_exported(GdkWindowImplWayland * self, struct zxdg_exported_v1 * display_server_xdg_exported) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_exported = display_server_xdg_exported;
}

// GdkWindowImplWayland::display_server.server_decoration

struct org_kde_kwin_server_decoration * gdk_window_impl_wayland_espionage_get_display_server_server_decoration(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.server_decoration;
}

void gdk_window_impl_wayland_espionage_set_display_server_server_decoration(GdkWindowImplWayland * self, struct org_kde_kwin_server_decoration * display_server_server_decoration) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.server_decoration = display_server_server_decoration;
}

// GdkWindowImplWayland::egl_surface

EGLSurface * gdk_window_impl_wayland_espionage_get_egl_surface_ptr(GdkWindowImplWayland * self) {
  return (EGLSurface *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->egl_surface;
}

// GdkWindowImplWayland::dummy_egl_surface

EGLSurface * gdk_window_impl_wayland_espionage_get_dummy_egl_surface_ptr(GdkWindowImplWayland * self) {
  return (EGLSurface *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->dummy_egl_surface;
}

// GdkWindowImplWayland::initial_configure_received

unsigned int gdk_window_impl_wayland_espionage_get_initial_configure_received(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_configure_received;
}

void gdk_window_impl_wayland_espionage_set_initial_configure_received(GdkWindowImplWayland * self, unsigned int initial_configure_received) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_configure_received = initial_configure_received;
}

// GdkWindowImplWayland::configuring_popup

unsigned int gdk_window_impl_wayland_espionage_get_configuring_popup(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->configuring_popup;
}

void gdk_window_impl_wayland_espionage_set_configuring_popup(GdkWindowImplWayland * self, unsigned int configuring_popup) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->configuring_popup = configuring_popup;
}

// GdkWindowImplWayland::mapped

unsigned int gdk_window_impl_wayland_espionage_get_mapped(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->mapped;
}

void gdk_window_impl_wayland_espionage_set_mapped(GdkWindowImplWayland * self, unsigned int mapped) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->mapped = mapped;
}

// GdkWindowImplWayland::use_custom_surface

unsigned int gdk_window_impl_wayland_espionage_get_use_custom_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->use_custom_surface;
}

void gdk_window_impl_wayland_espionage_set_use_custom_surface(GdkWindowImplWayland * self, unsigned int use_custom_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->use_custom_surface = use_custom_surface;
}

// GdkWindowImplWayland::pending_buffer_attached

unsigned int gdk_window_impl_wayland_espionage_get_pending_buffer_attached(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_attached;
}

void gdk_window_impl_wayland_espionage_set_pending_buffer_attached(GdkWindowImplWayland * self, unsigned int pending_buffer_attached) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_attached = pending_buffer_attached;
}

// GdkWindowImplWayland::pending_commit

unsigned int gdk_window_impl_wayland_espionage_get_pending_commit(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_commit;
}

void gdk_window_impl_wayland_espionage_set_pending_commit(GdkWindowImplWayland * self, unsigned int pending_commit) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_commit = pending_commit;
}

// GdkWindowImplWayland::awaiting_frame

unsigned int gdk_window_impl_wayland_espionage_get_awaiting_frame(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->awaiting_frame;
}

void gdk_window_impl_wayland_espionage_set_awaiting_frame(GdkWindowImplWayland * self, unsigned int awaiting_frame) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->awaiting_frame = awaiting_frame;
}

// GdkWindowImplWayland::using_csd

unsigned int gdk_window_impl_wayland_espionage_get_using_csd(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->using_csd;
}

void gdk_window_impl_wayland_espionage_set_using_csd(GdkWindowImplWayland * self, unsigned int using_csd) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->using_csd = using_csd;
}

// GdkWindowImplWayland::hint

GdkWindowTypeHint * gdk_window_impl_wayland_espionage_get_hint_ptr(GdkWindowImplWayland * self) {
  return (GdkWindowTypeHint *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->hint;
}

// GdkWindowImplWayland::transient_for

GdkWindow * gdk_window_impl_wayland_espionage_get_transient_for(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->transient_for;
}

void gdk_window_impl_wayland_espionage_set_transient_for(GdkWindowImplWayland * self, GdkWindow * transient_for) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->transient_for = transient_for;
}

// GdkWindowImplWayland::popup_parent

GdkWindow * gdk_window_impl_wayland_espionage_get_popup_parent(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->popup_parent;
}

void gdk_window_impl_wayland_espionage_set_popup_parent(GdkWindowImplWayland * self, GdkWindow * popup_parent) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->popup_parent = popup_parent;
}

// GdkWindowImplWayland::position_method

PositionMethod * gdk_window_impl_wayland_espionage_get_position_method_ptr(GdkWindowImplWayland * self) {
  return (PositionMethod *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->position_method;
}

// GdkWindowImplWayland::staging_cairo_surface

cairo_surface_t * gdk_window_impl_wayland_espionage_get_staging_cairo_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->staging_cairo_surface;
}

void gdk_window_impl_wayland_espionage_set_staging_cairo_surface(GdkWindowImplWayland * self, cairo_surface_t * staging_cairo_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->staging_cairo_surface = staging_cairo_surface;
}

// GdkWindowImplWayland::committed_cairo_surface

cairo_surface_t * gdk_window_impl_wayland_espionage_get_committed_cairo_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->committed_cairo_surface;
}

void gdk_window_impl_wayland_espionage_set_committed_cairo_surface(GdkWindowImplWayland * self, cairo_surface_t * committed_cairo_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->committed_cairo_surface = committed_cairo_surface;
}

// GdkWindowImplWayland::backfill_cairo_surface

cairo_surface_t * gdk_window_impl_wayland_espionage_get_backfill_cairo_surface(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->backfill_cairo_surface;
}

void gdk_window_impl_wayland_espionage_set_backfill_cairo_surface(GdkWindowImplWayland * self, cairo_surface_t * backfill_cairo_surface) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->backfill_cairo_surface = backfill_cairo_surface;
}

// GdkWindowImplWayland::pending_buffer_offset_x

int gdk_window_impl_wayland_espionage_get_pending_buffer_offset_x(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_x;
}

void gdk_window_impl_wayland_espionage_set_pending_buffer_offset_x(GdkWindowImplWayland * self, int pending_buffer_offset_x) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_x = pending_buffer_offset_x;
}

// GdkWindowImplWayland::pending_buffer_offset_y

int gdk_window_impl_wayland_espionage_get_pending_buffer_offset_y(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_y;
}

void gdk_window_impl_wayland_espionage_set_pending_buffer_offset_y(GdkWindowImplWayland * self, int pending_buffer_offset_y) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_y = pending_buffer_offset_y;
}

// GdkWindowImplWayland::subsurface_x

int gdk_window_impl_wayland_espionage_get_subsurface_x(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_x;
}

void gdk_window_impl_wayland_espionage_set_subsurface_x(GdkWindowImplWayland * self, int subsurface_x) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_x = subsurface_x;
}

// GdkWindowImplWayland::subsurface_y

int gdk_window_impl_wayland_espionage_get_subsurface_y(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_y;
}

void gdk_window_impl_wayland_espionage_set_subsurface_y(GdkWindowImplWayland * self, int subsurface_y) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_y = subsurface_y;
}

// GdkWindowImplWayland::title

gchar * gdk_window_impl_wayland_espionage_get_title(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->title;
}

void gdk_window_impl_wayland_espionage_set_title(GdkWindowImplWayland * self, gchar * title) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->title = title;
}

// GdkWindowImplWayland::application.was_set

gboolean gdk_window_impl_wayland_espionage_get_application_was_set(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.was_set;
}

void gdk_window_impl_wayland_espionage_set_application_was_set(GdkWindowImplWayland * self, gboolean application_was_set) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.was_set = application_was_set;
}

// GdkWindowImplWayland::application.application_id

gchar * gdk_window_impl_wayland_espionage_get_application_application_id(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_id;
}

void gdk_window_impl_wayland_espionage_set_application_application_id(GdkWindowImplWayland * self, gchar * application_application_id) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_id = application_application_id;
}

// GdkWindowImplWayland::application.app_menu_path

gchar * gdk_window_impl_wayland_espionage_get_application_app_menu_path(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.app_menu_path;
}

void gdk_window_impl_wayland_espionage_set_application_app_menu_path(GdkWindowImplWayland * self, gchar * application_app_menu_path) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.app_menu_path = application_app_menu_path;
}

// GdkWindowImplWayland::application.menubar_path

gchar * gdk_window_impl_wayland_espionage_get_application_menubar_path(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.menubar_path;
}

void gdk_window_impl_wayland_espionage_set_application_menubar_path(GdkWindowImplWayland * self, gchar * application_menubar_path) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.menubar_path = application_menubar_path;
}

// GdkWindowImplWayland::application.window_object_path

gchar * gdk_window_impl_wayland_espionage_get_application_window_object_path(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.window_object_path;
}

void gdk_window_impl_wayland_espionage_set_application_window_object_path(GdkWindowImplWayland * self, gchar * application_window_object_path) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.window_object_path = application_window_object_path;
}

// GdkWindowImplWayland::application.application_object_path

gchar * gdk_window_impl_wayland_espionage_get_application_application_object_path(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_object_path;
}

void gdk_window_impl_wayland_espionage_set_application_application_object_path(GdkWindowImplWayland * self, gchar * application_application_object_path) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_object_path = application_application_object_path;
}

// GdkWindowImplWayland::application.unique_bus_name

gchar * gdk_window_impl_wayland_espionage_get_application_unique_bus_name(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.unique_bus_name;
}

void gdk_window_impl_wayland_espionage_set_application_unique_bus_name(GdkWindowImplWayland * self, gchar * application_unique_bus_name) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.unique_bus_name = application_unique_bus_name;
}

// GdkWindowImplWayland::geometry_hints

GdkGeometry * gdk_window_impl_wayland_espionage_get_geometry_hints_ptr(GdkWindowImplWayland * self) {
  return (GdkGeometry *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->geometry_hints;
}

// GdkWindowImplWayland::geometry_mask

GdkWindowHints * gdk_window_impl_wayland_espionage_get_geometry_mask_ptr(GdkWindowImplWayland * self) {
  return (GdkWindowHints *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->geometry_mask;
}

// GdkWindowImplWayland::grab_input_seat

GdkSeat * gdk_window_impl_wayland_espionage_get_grab_input_seat(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->grab_input_seat;
}

void gdk_window_impl_wayland_espionage_set_grab_input_seat(GdkWindowImplWayland * self, GdkSeat * grab_input_seat) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->grab_input_seat = grab_input_seat;
}

// GdkWindowImplWayland::pending_frame_counter

gint64 * gdk_window_impl_wayland_espionage_get_pending_frame_counter_ptr(GdkWindowImplWayland * self) {
  return (gint64 *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_frame_counter;
}

// GdkWindowImplWayland::scale

guint32 * gdk_window_impl_wayland_espionage_get_scale_ptr(GdkWindowImplWayland * self) {
  return (guint32 *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->scale;
}

// GdkWindowImplWayland::margin_left

int gdk_window_impl_wayland_espionage_get_margin_left(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_left;
}

void gdk_window_impl_wayland_espionage_set_margin_left(GdkWindowImplWayland * self, int margin_left) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_left = margin_left;
}

// GdkWindowImplWayland::margin_right

int gdk_window_impl_wayland_espionage_get_margin_right(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_right;
}

void gdk_window_impl_wayland_espionage_set_margin_right(GdkWindowImplWayland * self, int margin_right) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_right = margin_right;
}

// GdkWindowImplWayland::margin_top

int gdk_window_impl_wayland_espionage_get_margin_top(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_top;
}

void gdk_window_impl_wayland_espionage_set_margin_top(GdkWindowImplWayland * self, int margin_top) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_top = margin_top;
}

// GdkWindowImplWayland::margin_bottom

int gdk_window_impl_wayland_espionage_get_margin_bottom(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_bottom;
}

void gdk_window_impl_wayland_espionage_set_margin_bottom(GdkWindowImplWayland * self, int margin_bottom) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_bottom = margin_bottom;
}

// GdkWindowImplWayland::margin_dirty

gboolean gdk_window_impl_wayland_espionage_get_margin_dirty(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_dirty;
}

void gdk_window_impl_wayland_espionage_set_margin_dirty(GdkWindowImplWayland * self, gboolean margin_dirty) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_dirty = margin_dirty;
}

// GdkWindowImplWayland::initial_fullscreen_monitor

int gdk_window_impl_wayland_espionage_get_initial_fullscreen_monitor(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_fullscreen_monitor;
}

void gdk_window_impl_wayland_espionage_set_initial_fullscreen_monitor(GdkWindowImplWayland * self, int initial_fullscreen_monitor) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_fullscreen_monitor = initial_fullscreen_monitor;
}

// GdkWindowImplWayland::opaque_region

cairo_region_t * gdk_window_impl_wayland_espionage_get_opaque_region(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region;
}

void gdk_window_impl_wayland_espionage_set_opaque_region(GdkWindowImplWayland * self, cairo_region_t * opaque_region) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region = opaque_region;
}

// GdkWindowImplWayland::opaque_region_dirty

gboolean gdk_window_impl_wayland_espionage_get_opaque_region_dirty(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region_dirty;
}

void gdk_window_impl_wayland_espionage_set_opaque_region_dirty(GdkWindowImplWayland * self, gboolean opaque_region_dirty) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region_dirty = opaque_region_dirty;
}

// GdkWindowImplWayland::input_region

cairo_region_t * gdk_window_impl_wayland_espionage_get_input_region(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region;
}

void gdk_window_impl_wayland_espionage_set_input_region(GdkWindowImplWayland * self, cairo_region_t * input_region) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region = input_region;
}

// GdkWindowImplWayland::input_region_dirty

gboolean gdk_window_impl_wayland_espionage_get_input_region_dirty(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region_dirty;
}

void gdk_window_impl_wayland_espionage_set_input_region_dirty(GdkWindowImplWayland * self, gboolean input_region_dirty) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region_dirty = input_region_dirty;
}

// GdkWindowImplWayland::staged_updates_region

cairo_region_t * gdk_window_impl_wayland_espionage_get_staged_updates_region(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->staged_updates_region;
}

void gdk_window_impl_wayland_espionage_set_staged_updates_region(GdkWindowImplWayland * self, cairo_region_t * staged_updates_region) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->staged_updates_region = staged_updates_region;
}

// GdkWindowImplWayland::saved_width

int gdk_window_impl_wayland_espionage_get_saved_width(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_width;
}

void gdk_window_impl_wayland_espionage_set_saved_width(GdkWindowImplWayland * self, int saved_width) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_width = saved_width;
}

// GdkWindowImplWayland::saved_height

int gdk_window_impl_wayland_espionage_get_saved_height(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_height;
}

void gdk_window_impl_wayland_espionage_set_saved_height(GdkWindowImplWayland * self, int saved_height) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_height = saved_height;
}

// GdkWindowImplWayland::unconfigured_width

int gdk_window_impl_wayland_espionage_get_unconfigured_width(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_width;
}

void gdk_window_impl_wayland_espionage_set_unconfigured_width(GdkWindowImplWayland * self, int unconfigured_width) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_width = unconfigured_width;
}

// GdkWindowImplWayland::unconfigured_height

int gdk_window_impl_wayland_espionage_get_unconfigured_height(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_height;
}

void gdk_window_impl_wayland_espionage_set_unconfigured_height(GdkWindowImplWayland * self, int unconfigured_height) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_height = unconfigured_height;
}

// GdkWindowImplWayland::fixed_size_width

int gdk_window_impl_wayland_espionage_get_fixed_size_width(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_width;
}

void gdk_window_impl_wayland_espionage_set_fixed_size_width(GdkWindowImplWayland * self, int fixed_size_width) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_width = fixed_size_width;
}

// GdkWindowImplWayland::fixed_size_height

int gdk_window_impl_wayland_espionage_get_fixed_size_height(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_height;
}

void gdk_window_impl_wayland_espionage_set_fixed_size_height(GdkWindowImplWayland * self, int fixed_size_height) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_height = fixed_size_height;
}

// GdkWindowImplWayland::parent_surface_committed_handler

gulong * gdk_window_impl_wayland_espionage_get_parent_surface_committed_handler_ptr(GdkWindowImplWayland * self) {
  return (gulong *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->parent_surface_committed_handler;
}

// GdkWindowImplWayland::pending_move_to_rect.rect

GdkRectangle * gdk_window_impl_wayland_espionage_get_pending_move_to_rect_rect_ptr(GdkWindowImplWayland * self) {
  return (GdkRectangle *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect;
}

// GdkWindowImplWayland::pending_move_to_rect.rect_anchor

GdkGravity * gdk_window_impl_wayland_espionage_get_pending_move_to_rect_rect_anchor_ptr(GdkWindowImplWayland * self) {
  return (GdkGravity *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor;
}

// GdkWindowImplWayland::pending_move_to_rect.window_anchor

GdkGravity * gdk_window_impl_wayland_espionage_get_pending_move_to_rect_window_anchor_ptr(GdkWindowImplWayland * self) {
  return (GdkGravity *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.window_anchor;
}

// GdkWindowImplWayland::pending_move_to_rect.anchor_hints

GdkAnchorHints * gdk_window_impl_wayland_espionage_get_pending_move_to_rect_anchor_hints_ptr(GdkWindowImplWayland * self) {
  return (GdkAnchorHints *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.anchor_hints;
}

// GdkWindowImplWayland::pending_move_to_rect.rect_anchor_dx

gint gdk_window_impl_wayland_espionage_get_pending_move_to_rect_rect_anchor_dx(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dx;
}

void gdk_window_impl_wayland_espionage_set_pending_move_to_rect_rect_anchor_dx(GdkWindowImplWayland * self, gint pending_move_to_rect_rect_anchor_dx) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dx = pending_move_to_rect_rect_anchor_dx;
}

// GdkWindowImplWayland::pending_move_to_rect.rect_anchor_dy

gint gdk_window_impl_wayland_espionage_get_pending_move_to_rect_rect_anchor_dy(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dy;
}

void gdk_window_impl_wayland_espionage_set_pending_move_to_rect_rect_anchor_dy(GdkWindowImplWayland * self, gint pending_move_to_rect_rect_anchor_dy) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dy = pending_move_to_rect_rect_anchor_dy;
}

// GdkWindowImplWayland::pending.width

int gdk_window_impl_wayland_espionage_get_pending_width(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.width;
}

void gdk_window_impl_wayland_espionage_set_pending_width(GdkWindowImplWayland * self, int pending_width) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.width = pending_width;
}

// GdkWindowImplWayland::pending.height

int gdk_window_impl_wayland_espionage_get_pending_height(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.height;
}

void gdk_window_impl_wayland_espionage_set_pending_height(GdkWindowImplWayland * self, int pending_height) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.height = pending_height;
}

// GdkWindowImplWayland::pending.state

GdkWindowState * gdk_window_impl_wayland_espionage_get_pending_state_ptr(GdkWindowImplWayland * self) {
  return (GdkWindowState *)&((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.state;
}

// GdkWindowImplWayland::exported.handle

char * gdk_window_impl_wayland_espionage_get_exported_handle(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.handle;
}

void gdk_window_impl_wayland_espionage_set_exported_handle(GdkWindowImplWayland * self, char * exported_handle) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.handle = exported_handle;
}

// GdkWindowImplWayland::exported.export_count

int gdk_window_impl_wayland_espionage_get_exported_export_count(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.export_count;
}

void gdk_window_impl_wayland_espionage_set_exported_export_count(GdkWindowImplWayland * self, int exported_export_count) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.export_count = exported_export_count;
}

// GdkWindowImplWayland::exported.closures

GList * gdk_window_impl_wayland_espionage_get_exported_closures(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.closures;
}

void gdk_window_impl_wayland_espionage_set_exported_closures(GdkWindowImplWayland * self, GList * exported_closures) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.closures = exported_closures;
}

// GdkWindowImplWayland::exported.idle_source_id

guint gdk_window_impl_wayland_espionage_get_exported_idle_source_id(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.idle_source_id;
}

void gdk_window_impl_wayland_espionage_set_exported_idle_source_id(GdkWindowImplWayland * self, guint exported_idle_source_id) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.idle_source_id = exported_idle_source_id;
}

// GdkWindowImplWayland::imported_transient_for

struct zxdg_imported_v1 * gdk_window_impl_wayland_espionage_get_imported_transient_for(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->imported_transient_for;
}

void gdk_window_impl_wayland_espionage_set_imported_transient_for(GdkWindowImplWayland * self, struct zxdg_imported_v1 * imported_transient_for) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->imported_transient_for = imported_transient_for;
}

// GdkWindowImplWayland::shortcuts_inhibitors

GHashTable * gdk_window_impl_wayland_espionage_get_shortcuts_inhibitors(GdkWindowImplWayland * self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->shortcuts_inhibitors;
}

void gdk_window_impl_wayland_espionage_set_shortcuts_inhibitors(GdkWindowImplWayland * self, GHashTable * shortcuts_inhibitors) {
  ((struct _GdkWindowImplWayland_v3_24_17*)self)->shortcuts_inhibitors = shortcuts_inhibitors;
}

#endif // GDK_WINDOW_IMPL_WAYLAND_ESPIONAGE_H
