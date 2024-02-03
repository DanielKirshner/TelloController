#include "WifiConnection.hpp"
#include <WiFi.h>


WifiConnection::WifiConnection(String ssid, String password)
{
    this->ssid = ssid;
    this->password = password;
}

WifiConnection::ConnectionAttemptStatus WifiConnection::connect(uint64_t timeout_in_ms) const
{
    WiFi.begin(ssid.c_str(), password.c_str());
    uint64_t start_time = millis();
    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_CONNECT_FAILED)
    {
        if (timeout_in_ms > 0)
        {
            uint64_t current_time = millis();
            if (current_time - start_time >= timeout_in_ms)
            {
                return ConnectionAttemptStatus::TIMED_OUT;
            }
        }
    }
    if (WiFi.status() == WL_CONNECT_FAILED)
    {
        return ConnectionAttemptStatus::FAILED;
    }
    return ConnectionAttemptStatus::SUCCEEDED;
}
