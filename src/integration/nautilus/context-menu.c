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

#include <gtk/gtk.h>

#include "context-menu.h"

void owncloud_extension_menu_provider_iface_init(
        NautilusMenuProviderIface *iface)
{
    iface->get_file_items = owncloud_extension_get_file_items;

}

GList * owncloud_extension_get_file_items (NautilusMenuProvider *provider,
                                                  GtkWidget *window,
                                                  GList *files)
{
    NautilusMenuItem *item;
    GList *l;
    GList *ret;

    (void*) window;

#if 0
    /* This extension only operates on selections that include only
         * owncloud files */
    for (l = files; l != NULL; l = l->next) {
        NautilusFileInfo *file = NAUTILUS_FILE_INFO (l->data);
        if (!nautilus_file_is_mime_type (file, "application/x-owncloud")) {
            return;
        }
    }
#endif

    for (l = files; l != NULL; l = l->next) {
        NautilusFileInfo *file = NAUTILUS_FILE_INFO (l->data);
        char *name;
        name = nautilus_file_info_get_name (file);
        g_print ("selected %s\n", name);
        g_free (name);
    }

    item = nautilus_menu_item_new ("OwncloudExtension::do_stuff",
                                   "Do ownCloud Stuff",
                                   "Do important owncloud-related stuff to the selected files",
                                   NULL /* icon name */);
    g_signal_connect (item, "activate", G_CALLBACK (item_activated_cb), provider);
    g_object_set_data_full ((GObject*) item, "owncloud_extension_files",
                            nautilus_file_info_list_copy (files),
                            (GDestroyNotify)nautilus_file_info_list_free);
    ret = g_list_append (NULL, item);

    return ret;
}

void item_activated_cb (NautilusMenuItem *item, gpointer user_data)
{
    GList *files;
    GList *l;

    files = g_object_get_data ((GObject *) item, "owncloud_extension_files");

    for (l = files; l != NULL; l = l->next) {
        NautilusFileInfo *file = NAUTILUS_FILE_INFO (l->data);
        char *name;
        name = nautilus_file_info_get_name (file);
        g_print ("doing stuff with %s\n", name);
        g_free (name);
    }
}
