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

GdkWindowImpl gdk_window_impl_wayland_extract_parent_instance(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->parent_instance;
}

GdkWindow * gdk_window_impl_wayland_extract_wrapper(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->wrapper;
}

GSList * gdk_window_impl_wayland_extract_display_server_outputs(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.outputs;
}

struct wl_surface * gdk_window_impl_wayland_extract_display_server_wl_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_surface;
}

struct xdg_surface * gdk_window_impl_wayland_extract_display_server_xdg_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_surface;
}

struct xdg_toplevel * gdk_window_impl_wayland_extract_display_server_xdg_toplevel(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_toplevel;
}

struct xdg_popup * gdk_window_impl_wayland_extract_display_server_xdg_popup(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_popup;
}

struct zxdg_surface_v6 * gdk_window_impl_wayland_extract_display_server_zxdg_surface_v6(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_surface_v6;
}

struct zxdg_toplevel_v6 * gdk_window_impl_wayland_extract_display_server_zxdg_toplevel_v6(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_toplevel_v6;
}

struct zxdg_popup_v6 * gdk_window_impl_wayland_extract_display_server_zxdg_popup_v6(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.zxdg_popup_v6;
}

struct gtk_surface1 * gdk_window_impl_wayland_extract_display_server_gtk_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.gtk_surface;
}

struct wl_subsurface * gdk_window_impl_wayland_extract_display_server_wl_subsurface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.wl_subsurface;
}

struct wl_egl_window * gdk_window_impl_wayland_extract_display_server_egl_window(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.egl_window;
}

struct wl_egl_window * gdk_window_impl_wayland_extract_display_server_dummy_egl_window(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.dummy_egl_window;
}

struct zxdg_exported_v1 * gdk_window_impl_wayland_extract_display_server_xdg_exported(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.xdg_exported;
}

struct org_kde_kwin_server_decoration * gdk_window_impl_wayland_extract_display_server_server_decoration(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->display_server.server_decoration;
}

EGLSurface gdk_window_impl_wayland_extract_egl_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->egl_surface;
}

EGLSurface gdk_window_impl_wayland_extract_dummy_egl_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->dummy_egl_surface;
}

unsigned int gdk_window_impl_wayland_extract_initial_configure_received(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_configure_received;
}

unsigned int gdk_window_impl_wayland_extract_configuring_popup(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->configuring_popup;
}

unsigned int gdk_window_impl_wayland_extract_mapped(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->mapped;
}

unsigned int gdk_window_impl_wayland_extract_use_custom_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->use_custom_surface;
}

unsigned int gdk_window_impl_wayland_extract_pending_buffer_attached(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_attached;
}

unsigned int gdk_window_impl_wayland_extract_pending_commit(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_commit;
}

unsigned int gdk_window_impl_wayland_extract_awaiting_frame(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->awaiting_frame;
}

unsigned int gdk_window_impl_wayland_extract_using_csd(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->using_csd;
}

GdkWindowTypeHint gdk_window_impl_wayland_extract_hint(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->hint;
}

GdkWindow * gdk_window_impl_wayland_extract_transient_for(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->transient_for;
}

GdkWindow * gdk_window_impl_wayland_extract_popup_parent(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->popup_parent;
}

PositionMethod gdk_window_impl_wayland_extract_position_method(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->position_method;
}

cairo_surface_t * gdk_window_impl_wayland_extract_staging_cairo_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->staging_cairo_surface;
}

cairo_surface_t * gdk_window_impl_wayland_extract_committed_cairo_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->committed_cairo_surface;
}

cairo_surface_t * gdk_window_impl_wayland_extract_backfill_cairo_surface(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->backfill_cairo_surface;
}

int gdk_window_impl_wayland_extract_pending_buffer_offset_x(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_x;
}

int gdk_window_impl_wayland_extract_pending_buffer_offset_y(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_buffer_offset_y;
}

int gdk_window_impl_wayland_extract_subsurface_x(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_x;
}

int gdk_window_impl_wayland_extract_subsurface_y(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->subsurface_y;
}

gchar * gdk_window_impl_wayland_extract_title(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->title;
}

gboolean gdk_window_impl_wayland_extract_application_was_set(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.was_set;
}

gchar * gdk_window_impl_wayland_extract_application_application_id(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_id;
}

gchar * gdk_window_impl_wayland_extract_application_app_menu_path(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.app_menu_path;
}

gchar * gdk_window_impl_wayland_extract_application_menubar_path(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.menubar_path;
}

gchar * gdk_window_impl_wayland_extract_application_window_object_path(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.window_object_path;
}

gchar * gdk_window_impl_wayland_extract_application_application_object_path(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.application_object_path;
}

gchar * gdk_window_impl_wayland_extract_application_unique_bus_name(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->application.unique_bus_name;
}

GdkGeometry gdk_window_impl_wayland_extract_geometry_hints(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->geometry_hints;
}

GdkWindowHints gdk_window_impl_wayland_extract_geometry_mask(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->geometry_mask;
}

GdkSeat * gdk_window_impl_wayland_extract_grab_input_seat(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->grab_input_seat;
}

gint64 gdk_window_impl_wayland_extract_pending_frame_counter(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_frame_counter;
}

guint32 gdk_window_impl_wayland_extract_scale(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->scale;
}

int gdk_window_impl_wayland_extract_margin_left(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_left;
}

int gdk_window_impl_wayland_extract_margin_right(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_right;
}

int gdk_window_impl_wayland_extract_margin_top(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_top;
}

int gdk_window_impl_wayland_extract_margin_bottom(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_bottom;
}

gboolean gdk_window_impl_wayland_extract_margin_dirty(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->margin_dirty;
}

int gdk_window_impl_wayland_extract_initial_fullscreen_monitor(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->initial_fullscreen_monitor;
}

cairo_region_t * gdk_window_impl_wayland_extract_opaque_region(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region;
}

gboolean gdk_window_impl_wayland_extract_opaque_region_dirty(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->opaque_region_dirty;
}

cairo_region_t * gdk_window_impl_wayland_extract_input_region(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region;
}

gboolean gdk_window_impl_wayland_extract_input_region_dirty(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->input_region_dirty;
}

cairo_region_t * gdk_window_impl_wayland_extract_staged_updates_region(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->staged_updates_region;
}

int gdk_window_impl_wayland_extract_saved_width(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_width;
}

int gdk_window_impl_wayland_extract_saved_height(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->saved_height;
}

int gdk_window_impl_wayland_extract_unconfigured_width(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_width;
}

int gdk_window_impl_wayland_extract_unconfigured_height(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->unconfigured_height;
}

int gdk_window_impl_wayland_extract_fixed_size_width(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_width;
}

int gdk_window_impl_wayland_extract_fixed_size_height(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->fixed_size_height;
}

gulong gdk_window_impl_wayland_extract_parent_surface_committed_handler(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->parent_surface_committed_handler;
}

GdkRectangle gdk_window_impl_wayland_extract_pending_move_to_rect_rect(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect;
}

GdkGravity gdk_window_impl_wayland_extract_pending_move_to_rect_rect_anchor(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor;
}

GdkGravity gdk_window_impl_wayland_extract_pending_move_to_rect_window_anchor(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.window_anchor;
}

GdkAnchorHints gdk_window_impl_wayland_extract_pending_move_to_rect_anchor_hints(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.anchor_hints;
}

gint gdk_window_impl_wayland_extract_pending_move_to_rect_rect_anchor_dx(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dx;
}

gint gdk_window_impl_wayland_extract_pending_move_to_rect_rect_anchor_dy(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending_move_to_rect.rect_anchor_dy;
}

int gdk_window_impl_wayland_extract_pending_width(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.width;
}

int gdk_window_impl_wayland_extract_pending_height(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.height;
}

GdkWindowState gdk_window_impl_wayland_extract_pending_state(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->pending.state;
}

char * gdk_window_impl_wayland_extract_exported_handle(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.handle;
}

int gdk_window_impl_wayland_extract_exported_export_count(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.export_count;
}

GList * gdk_window_impl_wayland_extract_exported_closures(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.closures;
}

guint gdk_window_impl_wayland_extract_exported_idle_source_id(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->exported.idle_source_id;
}

struct zxdg_imported_v1 * gdk_window_impl_wayland_extract_imported_transient_for(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->imported_transient_for;
}

GHashTable * gdk_window_impl_wayland_extract_shortcuts_inhibitors(GdkWindowImplWayland* self) {
  return ((struct _GdkWindowImplWayland_v3_24_17*)self)->shortcuts_inhibitors;
}

#endif // GDK_WINDOW_IMPL_WAYLAND_ESPIONAGE_H
