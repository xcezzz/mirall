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

#include <glib.h>

#include <gtk/gtk.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include <libnautilus-extension/nautilus-extension-types.h>

#include "context-menu.h"
#include "overlay.h"

static GType provider_types[1];
static GType owncloud_extension_type;
static GObjectClass *parent_class;

typedef struct {
    GObject parent_slot;
} OwncloudExtension;

typedef struct {
    GObjectClass parent_slot;
} OwncloudExtensionClass;

/* nautilus extension interface */
void nautilus_module_initialize (GTypeModule  *module);
void nautilus_module_shutdown (void);
void nautilus_module_list_types (const GType **types, int *num_types);

GType owncloud_extension_get_type (void);
static void owncloud_extension_register_type (GTypeModule *module);

void nautilus_module_initialize (GTypeModule  *module)
{
    fprintf(stderr, "Initializing nautilus-owncloud extension\n");
    owncloud_extension_register_type (module);

    provider_types[0] = owncloud_extension_get_type ();
}

void nautilus_module_shutdown (void)
{
    /* Any module-specific shutdown */
}

void nautilus_module_list_types (const GType **types,
                                 int *num_types)
{
    *types = provider_types;
    *num_types = G_N_ELEMENTS (provider_types);
}

GType owncloud_extension_get_type (void)
{
    return owncloud_extension_type;
}

static void owncloud_extension_instance_init (OwncloudExtension *object)
{
}

static void owncloud_extension_class_init(OwncloudExtensionClass *class)
{
    parent_class = g_type_class_peek_parent (class);
}

static void owncloud_extension_register_type (GTypeModule *module)
{
    static const GTypeInfo info = {
        sizeof (OwncloudExtensionClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) owncloud_extension_class_init,
        NULL,
        NULL,
        sizeof (OwncloudExtension),
        0,
        (GInstanceInitFunc) owncloud_extension_instance_init,
    };

    static const GInterfaceInfo menu_provider_iface_info = {
        (GInterfaceInitFunc) owncloud_extension_menu_provider_iface_init,
        NULL,
        NULL
    };

    static const GInterfaceInfo info_provider_iface_info = {
        (GInterfaceInitFunc) owncloud_extension_info_provider_iface_init,
        NULL,
        NULL
    };

    owncloud_extension_type = g_type_module_register_type (module,
                                                           G_TYPE_OBJECT,
                                                           "OwncloudExtension",
                                                           &info, 0);

    g_type_module_add_interface (module,
                                 owncloud_extension_type,
                                 NAUTILUS_TYPE_MENU_PROVIDER,
                                 &menu_provider_iface_info);

    g_type_module_add_interface(module,
                                owncloud_extension_type,
                                NAUTILUS_TYPE_INFO_PROVIDER,
                                &info_provider_iface_info);
}
