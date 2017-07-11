/*
 * Copyright (C) 2017 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alberto Aguirre <alberto.aguirre@canonical.com>
 *
 */
#ifndef MULTIPASS_VM_IMAGE_VAULT_H
#define MULTIPASS_VM_IMAGE_VAULT_H

#include <multipass/fetch_type.h>
#include <multipass/progress_monitor.h>

#include <functional>
namespace multipass
{
class Query;
class VMImage;
class VMImageVault
{
public:
    using PrepareAction = std::function<VMImage(const VMImage&)>;
    virtual VMImage fetch_image(const FetchType& fetch_type, const Query& query, const PrepareAction& prepare,
                                const ProgressMonitor& monitor) = 0;
    virtual void remove(const std::string& name) = 0;
};
}
#endif // MULTIPASS_VM_IMAGE_VAULT_H
