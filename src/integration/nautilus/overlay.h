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

#ifndef OVERLAY_H
#define OVERLAY_H

#include <libnautilus-extension/nautilus-info-provider.h>

void owncloud_extension_info_provider_iface_init(NautilusInfoProviderIface *iface);

NautilusOperationResult owncloud_extension_update_file_info(NautilusInfoProvider *provider,
                                                            NautilusFileInfo *file,
                                                            GClosure *update_complete,
                                                            NautilusOperationHandle **handle);

void owncloud_extension_cancel_update(NautilusInfoProvider *provider, NautilusOperationHandle  *handle);

#endif //OVERLAY_H
