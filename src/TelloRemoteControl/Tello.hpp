#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>


class Tello
{
    private:
        static constexpr int LOCAL_UDP_SOCKET_PORT = 9000;    // Local port to bind the UDP socket to. Can be any free port.
        static constexpr size_t TEMPORARY_BUFFER_SIZE = 1024;

    public:
        static constexpr char* const COMMAND__ENABLE_SDK = "command";
        static constexpr char* const COMMAND__TAKEOFF    = "takeoff";
        static constexpr char* const COMMAND__LAND       = "land";


    private:
        String ip;
        uint16_t port;
        WiFiUDP udp_socket;
        byte temporaryBuffer[TEMPORARY_BUFFER_SIZE];

    public:
        Tello(const String& ip, uint16_t port);
        bool initialize_connection();
        bool send_command(const String& command);
};
