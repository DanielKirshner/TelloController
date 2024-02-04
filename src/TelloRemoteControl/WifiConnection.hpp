#pragma once

#include <Arduino.h>


class WifiConnection
{
    public:
        enum class ConnectionAttemptStatus
        {
            FAILED,
            TIMED_OUT,
            SUCCEEDED
        };


    private:
        String ssid;
        String password;

    public:
        WifiConnection(const String& ssid, const String& password);
        ConnectionAttemptStatus connect(uint64_t timeout_in_ms = 0) const;
};
