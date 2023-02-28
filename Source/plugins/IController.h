/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "Module.h"
#include "IShell.h"

// @stubgen:include <plugins/IShell.h>

namespace WPEFramework {
namespace Exchange {
namespace IController {

    /* @json */
    struct EXTERNAL ISystemManagement : virtual public Core::IUnknown {

        enum { ID = RPC::ID_CONTROLLER };

        ~ISystemManagement() override = default;

        virtual uint32_t Persist() = 0;
        virtual uint32_t Delete(const string& path) = 0;
        virtual uint32_t StartDiscovery(const uint8_t& ttl) = 0;
        virtual uint32_t Reboot() = 0;
    };
    /* @json */
    struct EXTERNAL ISystemInfo : virtual public Core::IUnknown {
        enum { ID = RPC::ID_CONTROLLER_SYSTEMINFO };
        // @property
        virtual uint32_t Environment(const string& index /* @index */, string& environment /* @out @opaque */ ) const = 0;
        // @property
        virtual uint32_t Configuration(const string& callsign /* @index */, string& configuration /* @out @opaque */) const = 0;
        virtual uint32_t Configuration(const string& callsign /* @index */, const string& configuration /* @opaque */) = 0;
    };

    /* @json */
    struct EXTERNAL ILifeTime : virtual public Core::IUnknown {
        enum { ID = RPC::ID_CONTROLLER_LIFETIME };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = RPC::ID_CONTROLLER_LIFETIME_NOTIFICATION };
            ~INotification() override = default;
            virtual void StateChange(const string& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason) = 0;
        };

        ~ILifeTime() override = default;

        // Pushing notifications to interested sinks
        virtual uint32_t Register(INotification* sink) = 0;
        virtual uint32_t Unregister(INotification* sink) = 0;

        virtual uint32_t Activate(const string& callsign) = 0;
        virtual uint32_t Deactivate(const string& callsign) = 0;
        virtual uint32_t Unavailable(const string& callsign) = 0;
        virtual uint32_t Hibernate(const string& callsign, const uint32_t timeout) = 0;
        virtual uint32_t Suspend(const string& callsign) = 0;
        virtual uint32_t Resume(const string& callsign) = 0;
        virtual uint32_t Clone(const string& callsign, const string& newcallsign, string& response /* @out */) = 0;
    };

    /* @json */
    struct EXTERNAL IMetaData : virtual public Core::IUnknown {
        enum { ID = RPC::ID_CONTROLLER_METADATA };
        ~IMetaData() override = default;

        virtual uint32_t Proxies(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t Status(const string& index /* @index */, string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t Links(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t ProcessInfo(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t Subsystems(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t DiscoveryResults(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t Version(string& response /* @out @opaque */) const = 0;
        // @property
        virtual uint32_t CallStack(const string& index /* @index */, string& callstack /* @out @opaque */) const = 0;
    };
}
} // namespace Exchange
} // namespace WPEFramework
