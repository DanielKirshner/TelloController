#pragma once

#include <Arduino.h>

#include "WifiCredentials.hpp"


class WifiConnection final
{
    public:
        enum class ConnectionStatus : uint32_t
        {
            FAILED = 0,
            TIMED_OUT,
            SUCCEEDED
        };

    public:
        explicit WifiConnection(const WifiCredentials& creds);
        ~WifiConnection() = default;

    public:
        /*
            @brief Trying to connect to the Wi-Fi network using the credentials given with a certain timeout
            @param timeout_in_ms Timeout for trying to connect the Wi-Fi in miliseconds
            @return ConnectionStatus value
        */
        ConnectionStatus connect(const uint64_t timeout_in_ms = 0) const;
        bool disconnect() const;

    private:
        const WifiCredentials _creds = { };
};
