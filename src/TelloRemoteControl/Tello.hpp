#include <Arduino.h>
#include <WiFiUdp.h>


class Tello
{
    private: static constexpr int LOCAL_UDP_SOCKET_PORT = 9000;    // Local port to bind the UDP socket to. Can be any free port.
    private: static constexpr size_t TEMPORARY_BUFFER_SIZE = 1024;

    // Commands:
    public: static constexpr char* COMMAND__ENABLE_SDK = "command";
    public: static constexpr char* COMMAND__TAKEOFF    = "takeoff";
    public: static constexpr char* COMMAND__LAND       = "land";


    private: String ip;
    private: uint16_t port;
    private: WiFiUDP udp_socket;
    private: byte temporaryBuffer[TEMPORARY_BUFFER_SIZE];

    public: Tello(String ip, uint16_t port);

    public: bool initialize_connection();
    public: bool send_command(const String& command);
};
