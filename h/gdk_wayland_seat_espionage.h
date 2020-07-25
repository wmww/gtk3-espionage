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

typedef struct _GdkWaylandSeat GdkWaylandSeat;

// Valid for GTK v3.22.0 - v3.22.8
struct _GdkWaylandSeat_v3_22_0
{
  GdkSeat parent_instance;
  guint32 id;
  struct wl_seat *wl_seat;
  struct wl_pointer *wl_pointer;
  struct wl_keyboard *wl_keyboard;
  struct wl_touch *wl_touch;
  struct zwp_pointer_gesture_swipe_v1 *wp_pointer_gesture_swipe;
  struct zwp_pointer_gesture_pinch_v1 *wp_pointer_gesture_pinch;
  struct zwp_tablet_seat_v2 *wp_tablet_seat;
  GdkDisplay *display;
  GdkDeviceManager *device_manager;
  GdkDevice *master_pointer;
  GdkDevice *master_keyboard;
  GdkDevice *pointer;
  GdkDevice *wheel_scrolling;
  GdkDevice *finger_scrolling;
  GdkDevice *continuous_scrolling;
  GdkDevice *keyboard;
  GdkDevice *touch_master;
  GdkDevice *touch;
  GdkCursor *cursor;
  GdkKeymap *keymap;
  GHashTable *touches;
  GList *tablets;
  GList *tablet_tools;
  GList *tablet_pads;
  GdkWaylandPointerData pointer_info;
  GdkWaylandPointerData touch_info;
  GdkModifierType key_modifiers;
  GdkWindow *keyboard_focus;
  GdkAtom pending_selection;
  GdkWindow *grab_window;
  uint32_t grab_time;
  gboolean have_server_repeat;
  uint32_t server_repeat_rate;
  uint32_t server_repeat_delay;
  struct wl_callback *repeat_callback;
  guint32 repeat_timer;
  guint32 repeat_key;
  guint32 repeat_count;
  gint64 repeat_deadline;
  GSettings *keyboard_settings;
  uint32_t keyboard_time;
  uint32_t keyboard_key_serial;
  struct gtk_primary_selection_device *primary_data_device;
  struct wl_data_device *data_device;
  GdkDragContext *drop_context;
  GdkWindow *foreign_dnd_window;
  guint gesture_n_fingers;
  gdouble gesture_scale;
  GdkCursor *grab_cursor;
};

// Valid for GTK v3.22.9 - v3.22.15
struct _GdkWaylandSeat_v3_22_9
{
  GdkSeat parent_instance;
  guint32 id;
  struct wl_seat *wl_seat;
  struct wl_pointer *wl_pointer;
  struct wl_keyboard *wl_keyboard;
  struct wl_touch *wl_touch;
  struct zwp_pointer_gesture_swipe_v1 *wp_pointer_gesture_swipe;
  struct zwp_pointer_gesture_pinch_v1 *wp_pointer_gesture_pinch;
  struct zwp_tablet_seat_v2 *wp_tablet_seat;
  GdkDisplay *display;
  GdkDeviceManager *device_manager;
  GdkDevice *master_pointer;
  GdkDevice *master_keyboard;
  GdkDevice *pointer;
  GdkDevice *wheel_scrolling;
  GdkDevice *finger_scrolling;
  GdkDevice *continuous_scrolling;
  GdkDevice *keyboard;
  GdkDevice *touch_master;
  GdkDevice *touch;
  GdkCursor *cursor;
  GdkKeymap *keymap;
  GHashTable *touches;
  GList *tablets;
  GList *tablet_tools;
  GList *tablet_pads;
  GdkWaylandPointerData pointer_info;
  GdkWaylandPointerData touch_info;
  GdkModifierType key_modifiers;
  GdkWindow *keyboard_focus;
  GdkAtom pending_selection;
  GdkWindow *grab_window;
  uint32_t grab_time;
  gboolean have_server_repeat;
  uint32_t server_repeat_rate;
  uint32_t server_repeat_delay;
  struct wl_callback *repeat_callback;
  guint32 repeat_timer;
  guint32 repeat_key;
  guint32 repeat_count;
  gint64 repeat_deadline;
  gint32 nkeys;
  GSettings *keyboard_settings;
  uint32_t keyboard_time;
  uint32_t keyboard_key_serial;
  struct gtk_primary_selection_device *primary_data_device;
  struct wl_data_device *data_device;
  GdkDragContext *drop_context;
  GdkWindow *foreign_dnd_window;
  guint gesture_n_fingers;
  gdouble gesture_scale;
  GdkCursor *grab_cursor;
};

// Valid for GTK v3.22.16 - v3.24.21
struct _GdkWaylandSeat_v3_22_16
{
  GdkSeat parent_instance;
  guint32 id;
  struct wl_seat *wl_seat;
  struct wl_pointer *wl_pointer;
  struct wl_keyboard *wl_keyboard;
  struct wl_touch *wl_touch;
  struct zwp_pointer_gesture_swipe_v1 *wp_pointer_gesture_swipe;
  struct zwp_pointer_gesture_pinch_v1 *wp_pointer_gesture_pinch;
  struct zwp_tablet_seat_v2 *wp_tablet_seat;
  GdkDisplay *display;
  GdkDeviceManager *device_manager;
  GdkDevice *master_pointer;
  GdkDevice *master_keyboard;
  GdkDevice *pointer;
  GdkDevice *wheel_scrolling;
  GdkDevice *finger_scrolling;
  GdkDevice *continuous_scrolling;
  GdkDevice *keyboard;
  GdkDevice *touch_master;
  GdkDevice *touch;
  GdkCursor *cursor;
  GdkKeymap *keymap;
  GHashTable *touches;
  GList *tablets;
  GList *tablet_tools;
  GList *tablet_pads;
  GdkWaylandPointerData pointer_info;
  GdkWaylandPointerData touch_info;
  GdkModifierType key_modifiers;
  GdkWindow *keyboard_focus;
  GdkAtom pending_selection;
  GdkWindow *grab_window;
  uint32_t grab_time;
  gboolean have_server_repeat;
  uint32_t server_repeat_rate;
  uint32_t server_repeat_delay;
  struct wl_callback *repeat_callback;
  guint32 repeat_timer;
  guint32 repeat_key;
  guint32 repeat_count;
  gint64 repeat_deadline;
  GSettings *keyboard_settings;
  uint32_t keyboard_time;
  uint32_t keyboard_key_serial;
  struct gtk_primary_selection_device *primary_data_device;
  struct wl_data_device *data_device;
  GdkDragContext *drop_context;
  GdkWindow *foreign_dnd_window;
  guint gesture_n_fingers;
  gdouble gesture_scale;
  GdkCursor *grab_cursor;
};

