#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>

namespace TelloCommands
{
    constexpr char* const ENABLE_SDK = "command";
    constexpr char* const TAKEOFF    = "takeoff";
    constexpr char* const LAND       = "land";
};

class Tello final
{
    public:
        explicit Tello(const String& ip, const uint16_t port);
        ~Tello() = default;

    public:
        /*
            @brief
                Converting command given to buffer and send it to the tello drone
            @param command
                String that represents the command according to the DJI-SDK
            @return
                Boolean flag if the command succeeded
        */
        bool send_command(const String& command);
        /*
            @brief
                Initialize tello udp connection

            @return
                Boolean flag if the connection successfully initialized
        */
        bool initialize_connection();
    
    private:
        static constexpr size_t MAX_PACKET_SIZE = 1024;

    private:
        const String _ip;
        const uint16_t _port;
        WiFiUDP _udp_socket;
};