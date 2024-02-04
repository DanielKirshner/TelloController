#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>

namespace TelloCommands
{
    static constexpr char* COMMAND__ENABLE_SDK = "command";
    static constexpr char* COMMAND__TAKEOFF    = "takeoff";
    static constexpr char* COMMAND__LAND       = "land";
}

class Tello final
{
    public:
        explicit Tello(const String& ip, const uint16_t port);
        ~Tello() = default;

    public:
        bool initialize_connection();
        bool send_command(const String& command);
    
    private:
        const String _ip;
        const uint16_t _port;
        WiFiUDP _udp_socket;
};