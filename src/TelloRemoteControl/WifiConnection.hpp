#pragma once

#include <Arduino.h>

struct WifiCredentials
{
    String ssid;
    String password;
};

enum class ConnectionStatus : uint32_t
{
    FAILED = 0,
    TIMED_OUT,
    SUCCEEDED
};

class WifiConnection final
{
    public:
        explicit WifiConnection(const String& ssid, const String& password);
        ~WifiConnection() = default;

    public:
        /*
            @brief Trying to connect to the Wi-Fi network using the credentials given with a certain timeout
            @param timeout_in_ms Timeout for trying to connect the Wi-Fi in miliseconds
            @return ConnectionStatus value
        */
        ConnectionStatus connect(const uint64_t timeout_in_ms = 0) const;

    private:
        const WifiCredentials _creds = { };
};