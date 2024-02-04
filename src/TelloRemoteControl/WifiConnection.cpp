#include "WifiConnection.hpp"

#include <WiFi.h>

WifiConnection::WifiConnection(const String& ssid, const String& password) :
    _creds(WifiCredentials(ssid, password))
{

}

ConnectionStatus WifiConnection::connect(const uint64_t timeout_in_ms) const
{
    WiFi.begin(_creds.ssid.c_str(), _creds.password.c_str());
    const uint64_t start_time = millis();
    
    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_CONNECT_FAILED)
    {
        if (timeout_in_ms > 0)
        {
            uint64_t current_time = millis();
            if (current_time - start_time >= timeout_in_ms)
            {
                return ConnectionStatus::TIMED_OUT;
            }
        }
    }

    if (WiFi.status() == WL_CONNECT_FAILED)
    {
        return ConnectionStatus::FAILED;
    }
    return ConnectionStatus::SUCCEEDED;
}