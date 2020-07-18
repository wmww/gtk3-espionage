/* This file is part of gtk3-espionage
 *
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 * Copyright © 2020 gtk-espionage/scripts/code.py

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

typedef struct _GdkWindow GdkWindow

// Valid for GTK v3.22.0 - v3.22.18
struct _GdkWindow_v3_22_0
{
  GObject parent_instance;

  GdkWindowImpl *impl; /* window-system-specific delegate object */

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

  /* The paint logic here is a bit complex because of our intermingling of
   * cairo and GL. Let's first go over the cairo-alone case:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region. If
   *     the backend wants it, we redirect drawing to a temporary surface
   *     sized the same as the update region and set `surface_needs_composite`
   *     to TRUE. Otherwise, we paint directly onto the real server-side window.
   *
   *  2) Things paint with cairo using gdk_cairo_create().
   *
   *  3) When everything is painted, the user calls gdk_window_end_paint().
   *     If there was a temporary surface, this is composited back onto the
   *     real backing surface in the appropriate places.
   *
   * This is similar to double buffering, except we only have partial surfaces
   * of undefined contents, and instead of swapping between two buffers, we
   * create a new temporary buffer every time.
   *
   * When we add GL to the mix, we have this instead:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region like
   *     before. We always redirect cairo drawing to a temporary surface when
   *     GL is enabled.
   *
   *  2) Things paint with cairo using gdk_cairo_create(). Whenever
   *     something paints, it calls gdk_window_mark_paint_from_clip() to mark
   *     which regions it has painted in software. We'll learn what this does
   *     soon.
   *
   *  3) Something paints with GL and uses gdk_cairo_draw_from_gl() to
   *     composite back into the scene. We paint this onto the backing
   *     store for the window *immediately* by using GL, rather than
   *     painting to the temporary surface, and keep track of the area that
   *     we've painted in `flushed_region`.
   *
   *  4) Something paints using software again. It calls
   *     gdk_window_mark_paint_from_clip(), which subtracts the region it
   *     has painted from `flushed_region` and adds the region to
   *     `needs_blended_region`.
   *
   *  5) Something paints using GL again, using gdk_cairo_draw_from_gl().
   *     It paints directly to the backing store, removes the region it
   *     painted from `needs_blended_region`, and adds to `flushed_region`.
   *
   *  6) gdk_window_end_paint() is called. It composites the temporary surface
   *     back to the window, using GL, except it doesn't bother copying
   *     `flushed_region`, and when it paints `needs_blended_region`, it also
   *     turns on GL blending.
   *
   * That means that at any point in time, we have three regions:
   *
   *   * `region` - This is the original invalidated region and is never
   *     touched.
   *
   *   * `flushed_region` - This is the portion of `region` that has GL
   *     contents that have been painted directly to the window, and
   *     doesn't have any cairo drawing painted over it.
   *
   *   * `needs_blended_region` - This is the portion of `region` that
   *     GL contents that have part cairo drawing painted over it.
   *     gdk_window_end_paint() will draw this region using blending.
   *
   * `flushed_region` and `needs_blended_region` never intersect, and the
   * rest of `region` that isn't covered by either is the "opaque region",
   * which is any area of cairo drawing that didn't ever intersect with GL.
   * We can paint these from GL without turning on blending.
   **/

  struct {
    /* The temporary surface that we're painting to. This will be composited
     * back into the window when we call end_paint. This is our poor-man's
     * way of doing double buffering. */
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
  /* This is the update_area that was in effect when the current expose
     started. It may be smaller than the expose area if we'e painting
     more than we have to, but it represents the "true" damage. */
  cairo_region_t *active_update_area;
  /* We store the old expose areas to support buffer-age optimizations */
  cairo_region_t *old_updated_area[2];

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
  guint visibility : 2; /* The visibility wrt the toplevel (i.e. based on clip_region) */
  guint native_visibility : 2; /* the native visibility of a impl windows */
  guint viewable : 1; /* mapped and all parents mapped */
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;

  /* The GdkWindow that has the impl, ref:ed if another window.
   * This ref is required to keep the wrapper of the impl window alive
   * for as long as any GdkWindow references the impl. */
  GdkWindow *impl_window;

  guint update_and_descendants_freeze_count;

  gint abs_x, abs_y; /* Absolute offset in impl */
  gint width, height;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;

  guint num_offscreen_children;

  /* The clip region is the part of the window, in window coordinates
     that is fully or partially (i.e. semi transparently) visible in
     the window hierarchy from the toplevel and down */
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

  GdkFrameClock *frame_clock; /* NULL to use from parent or default */
  GdkWindowInvalidateHandlerFunc invalidate_handler;

  GdkDrawingContext *drawing_context;
}

// Valid for GTK v3.22.19 - v3.24.10
struct _GdkWindow_v3_22_19
{
  GObject parent_instance;

  GdkWindowImpl *impl; /* window-system-specific delegate object */

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

  /* The paint logic here is a bit complex because of our intermingling of
   * cairo and GL. Let's first go over the cairo-alone case:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region. If
   *     the backend wants it, we redirect drawing to a temporary surface
   *     sized the same as the update region and set `surface_needs_composite`
   *     to TRUE. Otherwise, we paint directly onto the real server-side window.
   *
   *  2) Things paint with cairo using gdk_cairo_create().
   *
   *  3) When everything is painted, the user calls gdk_window_end_paint().
   *     If there was a temporary surface, this is composited back onto the
   *     real backing surface in the appropriate places.
   *
   * This is similar to double buffering, except we only have partial surfaces
   * of undefined contents, and instead of swapping between two buffers, we
   * create a new temporary buffer every time.
   *
   * When we add GL to the mix, we have this instead:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region like
   *     before. We always redirect cairo drawing to a temporary surface when
   *     GL is enabled.
   *
   *  2) Things paint with cairo using gdk_cairo_create(). Whenever
   *     something paints, it calls gdk_window_mark_paint_from_clip() to mark
   *     which regions it has painted in software. We'll learn what this does
   *     soon.
   *
   *  3) Something paints with GL and uses gdk_cairo_draw_from_gl() to
   *     composite back into the scene. We paint this onto the backing
   *     store for the window *immediately* by using GL, rather than
   *     painting to the temporary surface, and keep track of the area that
   *     we've painted in `flushed_region`.
   *
   *  4) Something paints using software again. It calls
   *     gdk_window_mark_paint_from_clip(), which subtracts the region it
   *     has painted from `flushed_region` and adds the region to
   *     `needs_blended_region`.
   *
   *  5) Something paints using GL again, using gdk_cairo_draw_from_gl().
   *     It paints directly to the backing store, removes the region it
   *     painted from `needs_blended_region`, and adds to `flushed_region`.
   *
   *  6) gdk_window_end_paint() is called. It composites the temporary surface
   *     back to the window, using GL, except it doesn't bother copying
   *     `flushed_region`, and when it paints `needs_blended_region`, it also
   *     turns on GL blending.
   *
   * That means that at any point in time, we have three regions:
   *
   *   * `region` - This is the original invalidated region and is never
   *     touched.
   *
   *   * `flushed_region` - This is the portion of `region` that has GL
   *     contents that have been painted directly to the window, and
   *     doesn't have any cairo drawing painted over it.
   *
   *   * `needs_blended_region` - This is the portion of `region` that
   *     GL contents that have part cairo drawing painted over it.
   *     gdk_window_end_paint() will draw this region using blending.
   *
   * `flushed_region` and `needs_blended_region` never intersect, and the
   * rest of `region` that isn't covered by either is the "opaque region",
   * which is any area of cairo drawing that didn't ever intersect with GL.
   * We can paint these from GL without turning on blending.
   **/

  struct {
    /* The temporary surface that we're painting to. This will be composited
     * back into the window when we call end_paint. This is our poor-man's
     * way of doing double buffering. */
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
  /* This is the update_area that was in effect when the current expose
     started. It may be smaller than the expose area if we'e painting
     more than we have to, but it represents the "true" damage. */
  cairo_region_t *active_update_area;
  /* We store the old expose areas to support buffer-age optimizations */
  cairo_region_t *old_updated_area[2];

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
  guint visibility : 2; /* The visibility wrt the toplevel (i.e. based on clip_region) */
  guint native_visibility : 2; /* the native visibility of a impl windows */
  guint viewable : 1; /* mapped and all parents mapped */
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;

  /* The GdkWindow that has the impl, ref:ed if another window.
   * This ref is required to keep the wrapper of the impl window alive
   * for as long as any GdkWindow references the impl. */
  GdkWindow *impl_window;

  guint update_and_descendants_freeze_count;

  gint abs_x, abs_y; /* Absolute offset in impl */
  gint width, height;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;

  guint num_offscreen_children;

  /* The clip region is the part of the window, in window coordinates
     that is fully or partially (i.e. semi transparently) visible in
     the window hierarchy from the toplevel and down */
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

  GdkFrameClock *frame_clock; /* NULL to use from parent or default */
  GdkWindowInvalidateHandlerFunc invalidate_handler;

  GdkDrawingContext *drawing_context;

  cairo_region_t *opaque_region;
}

// Valid for GTK v3.24.11 - v3.24.21
struct _GdkWindow_v3_24_11
{
  GObject parent_instance;

  GdkWindowImpl *impl; /* window-system-specific delegate object */

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

  /* The paint logic here is a bit complex because of our intermingling of
   * cairo and GL. Let's first go over the cairo-alone case:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region. If
   *     the backend wants it, we redirect drawing to a temporary surface
   *     sized the same as the update region and set `surface_needs_composite`
   *     to TRUE. Otherwise, we paint directly onto the real server-side window.
   *
   *  2) Things paint with cairo using gdk_cairo_create().
   *
   *  3) When everything is painted, the user calls gdk_window_end_paint().
   *     If there was a temporary surface, this is composited back onto the
   *     real backing surface in the appropriate places.
   *
   * This is similar to double buffering, except we only have partial surfaces
   * of undefined contents, and instead of swapping between two buffers, we
   * create a new temporary buffer every time.
   *
   * When we add GL to the mix, we have this instead:
   *
   *  1) gdk_window_begin_paint_region() is called with an update region like
   *     before. We always redirect cairo drawing to a temporary surface when
   *     GL is enabled.
   *
   *  2) Things paint with cairo using gdk_cairo_create(). Whenever
   *     something paints, it calls gdk_window_mark_paint_from_clip() to mark
   *     which regions it has painted in software. We'll learn what this does
   *     soon.
   *
   *  3) Something paints with GL and uses gdk_cairo_draw_from_gl() to
   *     composite back into the scene. We paint this onto the backing
   *     store for the window *immediately* by using GL, rather than
   *     painting to the temporary surface, and keep track of the area that
   *     we've painted in `flushed_region`.
   *
   *  4) Something paints using software again. It calls
   *     gdk_window_mark_paint_from_clip(), which subtracts the region it
   *     has painted from `flushed_region` and adds the region to
   *     `needs_blended_region`.
   *
   *  5) Something paints using GL again, using gdk_cairo_draw_from_gl().
   *     It paints directly to the backing store, removes the region it
   *     painted from `needs_blended_region`, and adds to `flushed_region`.
   *
   *  6) gdk_window_end_paint() is called. It composites the temporary surface
   *     back to the window, using GL, except it doesn't bother copying
   *     `flushed_region`, and when it paints `needs_blended_region`, it also
   *     turns on GL blending.
   *
   * That means that at any point in time, we have three regions:
   *
   *   * `region` - This is the original invalidated region and is never
   *     touched.
   *
   *   * `flushed_region` - This is the portion of `region` that has GL
   *     contents that have been painted directly to the window, and
   *     doesn't have any cairo drawing painted over it.
   *
   *   * `needs_blended_region` - This is the portion of `region` that
   *     GL contents that have part cairo drawing painted over it.
   *     gdk_window_end_paint() will draw this region using blending.
   *
   * `flushed_region` and `needs_blended_region` never intersect, and the
   * rest of `region` that isn't covered by either is the "opaque region",
   * which is any area of cairo drawing that didn't ever intersect with GL.
   * We can paint these from GL without turning on blending.
   **/

  struct {
    /* The temporary surface that we're painting to. This will be composited
     * back into the window when we call end_paint. This is our poor-man's
     * way of doing double buffering. */
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
  /* This is the update_area that was in effect when the current expose
     started. It may be smaller than the expose area if we'e painting
     more than we have to, but it represents the "true" damage. */
  cairo_region_t *active_update_area;
  /* We store the old expose areas to support buffer-age optimizations */
  cairo_region_t *old_updated_area[2];

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
  guint visibility : 2; /* The visibility wrt the toplevel (i.e. based on clip_region) */
  guint native_visibility : 2; /* the native visibility of a impl windows */
  guint viewable : 1; /* mapped and all parents mapped */
  guint applied_shape : 1;
  guint in_update : 1;
  guint geometry_dirty : 1;
  guint event_compression : 1;
  guint frame_clock_events_paused : 1;

  /* The GdkWindow that has the impl, ref:ed if another window.
   * This ref is required to keep the wrapper of the impl window alive
   * for as long as any GdkWindow references the impl. */
  GdkWindow *impl_window;

  guint update_and_descendants_freeze_count;

  gint abs_x, abs_y; /* Absolute offset in impl */
  gint width, height;
  gint shadow_top;
  gint shadow_left;
  gint shadow_right;
  gint shadow_bottom;

  guint num_offscreen_children;

  /* The clip region is the part of the window, in window coordinates
     that is fully or partially (i.e. semi transparently) visible in
     the window hierarchy from the toplevel and down */
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

  GdkFrameClock *frame_clock; /* NULL to use from parent or default */
  GdkWindowInvalidateHandlerFunc invalidate_handler;

  GdkDrawingContext *drawing_context;

  cairo_region_t *opaque_region;
}

