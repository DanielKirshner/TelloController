#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>


namespace TelloCommands
{
    constexpr const char* ENABLE_SDK = "command";
    constexpr const char* TAKEOFF    = "takeoff";
    constexpr const char* LAND       = "land";
};

class Tello final
{
    public:
        explicit Tello(const String& ip, const uint16_t port);
        ~Tello() = default;

    public:
        /*
            @brief
                Initialize tello udp connection

            @return
                Boolean flag if the connection successfully initialized
        */
        bool initialize_connection();
        bool enable_sdk();
        bool takeoff();
        bool land();
        
    private:
        /*
            @brief
                Converting command given to buffer and send it to the tello drone
            @param command
                String that represents the command according to the DJI-SDK
            @return
                Boolean flag if the command succeeded
        */
        bool send_command(const String& command);
    
    private:
        static constexpr size_t MAX_PACKET_SIZE = 1024;

    private:
        const String _ip;
        const uint16_t _port;
        WiFiUDP _udp_socket;
};
