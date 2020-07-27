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

#ifndef GDK_WAYLAND_SEAT_ESPIONAGE_H
#define GDK_WAYLAND_SEAT_ESPIONAGE_H

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
  struct _GdkWaylandPointerData_v3_22_0 pointer_info;
  struct _GdkWaylandPointerData_v3_22_0 touch_info;
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
  struct _GdkWaylandPointerData_v3_22_0 pointer_info;
  struct _GdkWaylandPointerData_v3_22_0 touch_info;
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
  struct _GdkWaylandPointerData_v3_22_0 pointer_info;
  struct _GdkWaylandPointerData_v3_22_0 touch_info;
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

// GdkWaylandSeat::parent_instance

GdkSeat * gdk_wayland_seat_espionage_get_parent_instance_ptr(GdkWaylandSeat * self) {
  return (GdkSeat *)&((struct _GdkWaylandSeat_v3_22_16*)self)->parent_instance;
}

// GdkWaylandSeat::id

guint32 * gdk_wayland_seat_espionage_get_id_ptr(GdkWaylandSeat * self) {
  return (guint32 *)&((struct _GdkWaylandSeat_v3_22_16*)self)->id;
}

// GdkWaylandSeat::wl_seat

struct wl_seat * gdk_wayland_seat_espionage_get_wl_seat(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_seat;
}

void gdk_wayland_seat_espionage_set_wl_seat(GdkWaylandSeat * self, struct wl_seat * wl_seat) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_seat = wl_seat;
}

// GdkWaylandSeat::wl_pointer

struct wl_pointer * gdk_wayland_seat_espionage_get_wl_pointer(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_pointer;
}

void gdk_wayland_seat_espionage_set_wl_pointer(GdkWaylandSeat * self, struct wl_pointer * wl_pointer) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_pointer = wl_pointer;
}

// GdkWaylandSeat::wl_keyboard

struct wl_keyboard * gdk_wayland_seat_espionage_get_wl_keyboard(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_keyboard;
}

void gdk_wayland_seat_espionage_set_wl_keyboard(GdkWaylandSeat * self, struct wl_keyboard * wl_keyboard) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_keyboard = wl_keyboard;
}

// GdkWaylandSeat::wl_touch

struct wl_touch * gdk_wayland_seat_espionage_get_wl_touch(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_touch;
}

void gdk_wayland_seat_espionage_set_wl_touch(GdkWaylandSeat * self, struct wl_touch * wl_touch) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wl_touch = wl_touch;
}

// GdkWaylandSeat::wp_pointer_gesture_swipe

struct zwp_pointer_gesture_swipe_v1 * gdk_wayland_seat_espionage_get_wp_pointer_gesture_swipe(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_pointer_gesture_swipe;
}

void gdk_wayland_seat_espionage_set_wp_pointer_gesture_swipe(GdkWaylandSeat * self, struct zwp_pointer_gesture_swipe_v1 * wp_pointer_gesture_swipe) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_pointer_gesture_swipe = wp_pointer_gesture_swipe;
}

// GdkWaylandSeat::wp_pointer_gesture_pinch

struct zwp_pointer_gesture_pinch_v1 * gdk_wayland_seat_espionage_get_wp_pointer_gesture_pinch(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_pointer_gesture_pinch;
}

void gdk_wayland_seat_espionage_set_wp_pointer_gesture_pinch(GdkWaylandSeat * self, struct zwp_pointer_gesture_pinch_v1 * wp_pointer_gesture_pinch) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_pointer_gesture_pinch = wp_pointer_gesture_pinch;
}

// GdkWaylandSeat::wp_tablet_seat

struct zwp_tablet_seat_v2 * gdk_wayland_seat_espionage_get_wp_tablet_seat(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_tablet_seat;
}

void gdk_wayland_seat_espionage_set_wp_tablet_seat(GdkWaylandSeat * self, struct zwp_tablet_seat_v2 * wp_tablet_seat) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wp_tablet_seat = wp_tablet_seat;
}

// GdkWaylandSeat::display

GdkDisplay * gdk_wayland_seat_espionage_get_display(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->display;
}

void gdk_wayland_seat_espionage_set_display(GdkWaylandSeat * self, GdkDisplay * display) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->display = display;
}

// GdkWaylandSeat::device_manager

GdkDeviceManager * gdk_wayland_seat_espionage_get_device_manager(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->device_manager;
}

void gdk_wayland_seat_espionage_set_device_manager(GdkWaylandSeat * self, GdkDeviceManager * device_manager) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->device_manager = device_manager;
}

// GdkWaylandSeat::master_pointer

GdkDevice * gdk_wayland_seat_espionage_get_master_pointer(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->master_pointer;
}

void gdk_wayland_seat_espionage_set_master_pointer(GdkWaylandSeat * self, GdkDevice * master_pointer) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->master_pointer = master_pointer;
}

// GdkWaylandSeat::master_keyboard

GdkDevice * gdk_wayland_seat_espionage_get_master_keyboard(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->master_keyboard;
}

void gdk_wayland_seat_espionage_set_master_keyboard(GdkWaylandSeat * self, GdkDevice * master_keyboard) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->master_keyboard = master_keyboard;
}

// GdkWaylandSeat::pointer

GdkDevice * gdk_wayland_seat_espionage_get_pointer(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->pointer;
}

void gdk_wayland_seat_espionage_set_pointer(GdkWaylandSeat * self, GdkDevice * pointer) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->pointer = pointer;
}

// GdkWaylandSeat::wheel_scrolling

GdkDevice * gdk_wayland_seat_espionage_get_wheel_scrolling(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->wheel_scrolling;
}

void gdk_wayland_seat_espionage_set_wheel_scrolling(GdkWaylandSeat * self, GdkDevice * wheel_scrolling) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->wheel_scrolling = wheel_scrolling;
}

// GdkWaylandSeat::finger_scrolling

GdkDevice * gdk_wayland_seat_espionage_get_finger_scrolling(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->finger_scrolling;
}

void gdk_wayland_seat_espionage_set_finger_scrolling(GdkWaylandSeat * self, GdkDevice * finger_scrolling) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->finger_scrolling = finger_scrolling;
}

// GdkWaylandSeat::continuous_scrolling

GdkDevice * gdk_wayland_seat_espionage_get_continuous_scrolling(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->continuous_scrolling;
}

void gdk_wayland_seat_espionage_set_continuous_scrolling(GdkWaylandSeat * self, GdkDevice * continuous_scrolling) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->continuous_scrolling = continuous_scrolling;
}

// GdkWaylandSeat::keyboard

GdkDevice * gdk_wayland_seat_espionage_get_keyboard(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard;
}

void gdk_wayland_seat_espionage_set_keyboard(GdkWaylandSeat * self, GdkDevice * keyboard) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard = keyboard;
}

// GdkWaylandSeat::touch_master

GdkDevice * gdk_wayland_seat_espionage_get_touch_master(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->touch_master;
}

void gdk_wayland_seat_espionage_set_touch_master(GdkWaylandSeat * self, GdkDevice * touch_master) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->touch_master = touch_master;
}

// GdkWaylandSeat::touch

GdkDevice * gdk_wayland_seat_espionage_get_touch(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->touch;
}

void gdk_wayland_seat_espionage_set_touch(GdkWaylandSeat * self, GdkDevice * touch) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->touch = touch;
}

// GdkWaylandSeat::cursor

GdkCursor * gdk_wayland_seat_espionage_get_cursor(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->cursor;
}

void gdk_wayland_seat_espionage_set_cursor(GdkWaylandSeat * self, GdkCursor * cursor) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->cursor = cursor;
}

// GdkWaylandSeat::keymap

GdkKeymap * gdk_wayland_seat_espionage_get_keymap(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keymap;
}

void gdk_wayland_seat_espionage_set_keymap(GdkWaylandSeat * self, GdkKeymap * keymap) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keymap = keymap;
}

// GdkWaylandSeat::touches

GHashTable * gdk_wayland_seat_espionage_get_touches(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->touches;
}

void gdk_wayland_seat_espionage_set_touches(GdkWaylandSeat * self, GHashTable * touches) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->touches = touches;
}

// GdkWaylandSeat::tablets

GList * gdk_wayland_seat_espionage_get_tablets(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->tablets;
}

void gdk_wayland_seat_espionage_set_tablets(GdkWaylandSeat * self, GList * tablets) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->tablets = tablets;
}

// GdkWaylandSeat::tablet_tools

GList * gdk_wayland_seat_espionage_get_tablet_tools(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->tablet_tools;
}

void gdk_wayland_seat_espionage_set_tablet_tools(GdkWaylandSeat * self, GList * tablet_tools) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->tablet_tools = tablet_tools;
}

// GdkWaylandSeat::tablet_pads

GList * gdk_wayland_seat_espionage_get_tablet_pads(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->tablet_pads;
}

void gdk_wayland_seat_espionage_set_tablet_pads(GdkWaylandSeat * self, GList * tablet_pads) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->tablet_pads = tablet_pads;
}

// GdkWaylandSeat::pointer_info

GdkWaylandPointerData * gdk_wayland_seat_espionage_get_pointer_info_ptr(GdkWaylandSeat * self) {
  return (GdkWaylandPointerData *)&((struct _GdkWaylandSeat_v3_22_16*)self)->pointer_info;
}

// GdkWaylandSeat::touch_info

GdkWaylandPointerData * gdk_wayland_seat_espionage_get_touch_info_ptr(GdkWaylandSeat * self) {
  return (GdkWaylandPointerData *)&((struct _GdkWaylandSeat_v3_22_16*)self)->touch_info;
}

// GdkWaylandSeat::key_modifiers

GdkModifierType * gdk_wayland_seat_espionage_get_key_modifiers_ptr(GdkWaylandSeat * self) {
  return (GdkModifierType *)&((struct _GdkWaylandSeat_v3_22_16*)self)->key_modifiers;
}

// GdkWaylandSeat::keyboard_focus

GdkWindow * gdk_wayland_seat_espionage_get_keyboard_focus(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_focus;
}

void gdk_wayland_seat_espionage_set_keyboard_focus(GdkWaylandSeat * self, GdkWindow * keyboard_focus) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_focus = keyboard_focus;
}

// GdkWaylandSeat::pending_selection

GdkAtom * gdk_wayland_seat_espionage_get_pending_selection_ptr(GdkWaylandSeat * self) {
  return (GdkAtom *)&((struct _GdkWaylandSeat_v3_22_16*)self)->pending_selection;
}

// GdkWaylandSeat::grab_window

GdkWindow * gdk_wayland_seat_espionage_get_grab_window(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_window;
}

void gdk_wayland_seat_espionage_set_grab_window(GdkWaylandSeat * self, GdkWindow * grab_window) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_window = grab_window;
}

// GdkWaylandSeat::grab_time

uint32_t gdk_wayland_seat_espionage_get_grab_time(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_time;
}

void gdk_wayland_seat_espionage_set_grab_time(GdkWaylandSeat * self, uint32_t grab_time) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_time = grab_time;
}

// GdkWaylandSeat::have_server_repeat

gboolean gdk_wayland_seat_espionage_get_have_server_repeat(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->have_server_repeat;
}

void gdk_wayland_seat_espionage_set_have_server_repeat(GdkWaylandSeat * self, gboolean have_server_repeat) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->have_server_repeat = have_server_repeat;
}

// GdkWaylandSeat::server_repeat_rate

uint32_t gdk_wayland_seat_espionage_get_server_repeat_rate(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->server_repeat_rate;
}

void gdk_wayland_seat_espionage_set_server_repeat_rate(GdkWaylandSeat * self, uint32_t server_repeat_rate) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->server_repeat_rate = server_repeat_rate;
}

// GdkWaylandSeat::server_repeat_delay

uint32_t gdk_wayland_seat_espionage_get_server_repeat_delay(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->server_repeat_delay;
}

void gdk_wayland_seat_espionage_set_server_repeat_delay(GdkWaylandSeat * self, uint32_t server_repeat_delay) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->server_repeat_delay = server_repeat_delay;
}

// GdkWaylandSeat::repeat_callback

struct wl_callback * gdk_wayland_seat_espionage_get_repeat_callback(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_callback;
}

void gdk_wayland_seat_espionage_set_repeat_callback(GdkWaylandSeat * self, struct wl_callback * repeat_callback) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_callback = repeat_callback;
}

// GdkWaylandSeat::repeat_timer

guint32 * gdk_wayland_seat_espionage_get_repeat_timer_ptr(GdkWaylandSeat * self) {
  return (guint32 *)&((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_timer;
}

// GdkWaylandSeat::repeat_key

guint32 * gdk_wayland_seat_espionage_get_repeat_key_ptr(GdkWaylandSeat * self) {
  return (guint32 *)&((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_key;
}

// GdkWaylandSeat::repeat_count

guint32 * gdk_wayland_seat_espionage_get_repeat_count_ptr(GdkWaylandSeat * self) {
  return (guint32 *)&((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_count;
}

// GdkWaylandSeat::repeat_deadline

gint64 * gdk_wayland_seat_espionage_get_repeat_deadline_ptr(GdkWaylandSeat * self) {
  return (gint64 *)&((struct _GdkWaylandSeat_v3_22_16*)self)->repeat_deadline;
}

// GdkWaylandSeat::keyboard_settings

GSettings * gdk_wayland_seat_espionage_get_keyboard_settings(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_settings;
}

void gdk_wayland_seat_espionage_set_keyboard_settings(GdkWaylandSeat * self, GSettings * keyboard_settings) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_settings = keyboard_settings;
}

// GdkWaylandSeat::keyboard_time

uint32_t gdk_wayland_seat_espionage_get_keyboard_time(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_time;
}

void gdk_wayland_seat_espionage_set_keyboard_time(GdkWaylandSeat * self, uint32_t keyboard_time) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_time = keyboard_time;
}

// GdkWaylandSeat::keyboard_key_serial

uint32_t gdk_wayland_seat_espionage_get_keyboard_key_serial(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_key_serial;
}

void gdk_wayland_seat_espionage_set_keyboard_key_serial(GdkWaylandSeat * self, uint32_t keyboard_key_serial) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->keyboard_key_serial = keyboard_key_serial;
}

// GdkWaylandSeat::primary_data_device

struct gtk_primary_selection_device * gdk_wayland_seat_espionage_get_primary_data_device(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->primary_data_device;
}

void gdk_wayland_seat_espionage_set_primary_data_device(GdkWaylandSeat * self, struct gtk_primary_selection_device * primary_data_device) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->primary_data_device = primary_data_device;
}

// GdkWaylandSeat::data_device

struct wl_data_device * gdk_wayland_seat_espionage_get_data_device(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->data_device;
}

void gdk_wayland_seat_espionage_set_data_device(GdkWaylandSeat * self, struct wl_data_device * data_device) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->data_device = data_device;
}

// GdkWaylandSeat::drop_context

GdkDragContext * gdk_wayland_seat_espionage_get_drop_context(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->drop_context;
}

void gdk_wayland_seat_espionage_set_drop_context(GdkWaylandSeat * self, GdkDragContext * drop_context) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->drop_context = drop_context;
}

// GdkWaylandSeat::foreign_dnd_window

GdkWindow * gdk_wayland_seat_espionage_get_foreign_dnd_window(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->foreign_dnd_window;
}

void gdk_wayland_seat_espionage_set_foreign_dnd_window(GdkWaylandSeat * self, GdkWindow * foreign_dnd_window) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->foreign_dnd_window = foreign_dnd_window;
}

// GdkWaylandSeat::gesture_n_fingers

guint gdk_wayland_seat_espionage_get_gesture_n_fingers(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->gesture_n_fingers;
}

void gdk_wayland_seat_espionage_set_gesture_n_fingers(GdkWaylandSeat * self, guint gesture_n_fingers) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->gesture_n_fingers = gesture_n_fingers;
}

// GdkWaylandSeat::gesture_scale

gdouble * gdk_wayland_seat_espionage_get_gesture_scale_ptr(GdkWaylandSeat * self) {
  return (gdouble *)&((struct _GdkWaylandSeat_v3_22_16*)self)->gesture_scale;
}

// GdkWaylandSeat::grab_cursor

GdkCursor * gdk_wayland_seat_espionage_get_grab_cursor(GdkWaylandSeat * self) {
  return ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_cursor;
}

void gdk_wayland_seat_espionage_set_grab_cursor(GdkWaylandSeat * self, GdkCursor * grab_cursor) {
  ((struct _GdkWaylandSeat_v3_22_16*)self)->grab_cursor = grab_cursor;
}

#endif // GDK_WAYLAND_SEAT_ESPIONAGE_H
