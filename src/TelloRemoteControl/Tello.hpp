#include <Arduino.h>
#include <WiFiUdp.h>


class Tello
{
    private: static const int LOCAL_UDP_SOCKET_PORT = 9000;    // Local port to bind the UDP socket to. Can be any free port.
    private: static const size_t TEMPORARY_BUFFER_SIZE = 1024;

    private: String ip;
    private: uint16_t port;
    private: WiFiUDP udp_socket;
    private: byte temporaryBuffer[TEMPORARY_BUFFER_SIZE];

    public: Tello(String ip, uint16_t port);

    public: bool initialize_connection();
    public: bool send_command(const String& command);
};
