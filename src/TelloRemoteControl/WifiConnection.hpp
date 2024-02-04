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
        ConnectionStatus connect(const uint64_t timeout_in_ms = 0) const;

    private:
        const WifiCredentials _creds = { };
};