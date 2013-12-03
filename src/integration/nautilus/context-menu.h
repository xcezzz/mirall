// Copyright (C) by Daniel Molkentin <danimo@owncloud.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

#ifndef CONTEXT_MENU_H
#define CONTEXT_MENU_H

#include <libnautilus-extension/nautilus-menu-provider.h>

void owncloud_extension_menu_provider_iface_init(NautilusMenuProviderIface *iface);

GList * owncloud_extension_get_file_items (NautilusMenuProvider *provider,
                GtkWidget *window,
                GList *files);

void item_activated_cb (NautilusMenuItem *item, gpointer user_data);

#endif //CONTEXT_MENU_H
