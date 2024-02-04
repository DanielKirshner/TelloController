#include <Arduino.h>


class WifiConnection
{
    public: enum class ConnectionAttemptStatus
    {
        FAILED,
        TIMED_OUT,
        SUCCEEDED
    };


    private: String ssid;
    private: String password;

    public: WifiConnection(String ssid, String password);
    public: ConnectionAttemptStatus connect(uint64_t timeout_in_ms = 0) const;
};
