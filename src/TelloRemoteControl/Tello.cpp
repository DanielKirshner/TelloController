#include "Tello.hpp"

Tello::Tello(const String& ip, const uint16_t port) : 
    _ip(ip), 
    _port(port)
{

}

bool Tello::initialize_connection()
{
    static constexpr uint16_t LOCAL_UDP_SOCKET_PORT = 9000;
    return _udp_socket.begin(LOCAL_UDP_SOCKET_PORT);
}

bool Tello::send_command(const String& command)
{
    byte packet_buffer[MAX_PACKET_SIZE];
    _udp_socket.beginPacket(_ip.c_str(), _port);
    command.getBytes(packet_buffer, sizeof(packet_buffer) / sizeof(packet_buffer[0]));
    _udp_socket.write(packet_buffer, command.length());
    return _udp_socket.endPacket();
}