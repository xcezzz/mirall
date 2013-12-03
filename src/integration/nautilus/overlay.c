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

#include "overlay.h"

#include <gio/gio.h>

#include <libnautilus-extension/nautilus-file-info.h>

void owncloud_extension_info_provider_iface_init(NautilusInfoProviderIface *iface)
{
    iface->update_file_info = owncloud_extension_update_file_info;
    iface->cancel_update = owncloud_extension_cancel_update;
}


NautilusOperationResult owncloud_extension_update_file_info(NautilusInfoProvider *provider,
                                                            NautilusFileInfo *file,
                                                            GClosure *update_complete,
                                                            NautilusOperationHandle **handle)
{
    printf("Requesting emblem for %s\n", nautilus_file_info_get_uri(file));
    //nautilus_file_info_add_emblem(file, "ubuntuone-synchronized");
}



void owncloud_extension_cancel_update(NautilusInfoProvider *provider, NautilusOperationHandle *handle)
{
    (void*) provider;
    (void*) handle;
}
