#include "Tello.hpp"


Tello::Tello(const String& ip, uint16_t port)
{
    this->ip = ip;
    this->port = port;
}

bool Tello::initialize_connection()
{
    return udp_socket.begin(LOCAL_UDP_SOCKET_PORT);
}

bool Tello::send_command(const String& command)
{
    udp_socket.beginPacket(ip.c_str(), port);
    command.getBytes(temporaryBuffer, sizeof(temporaryBuffer) / sizeof(temporaryBuffer[0]));
    udp_socket.write(temporaryBuffer, command.length());
    return udp_socket.endPacket();
}
