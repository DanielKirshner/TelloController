#include <cstdint>
#include <WiFi.h>
#include <WiFiUdp.h>

const char* const SSID = "TELLO-9F5E9A";
const char* const PASSWORD = "";

const char* const TELLO_IP = "192.168.10.1";
const uint32_t TELLO_PORT = 8889;

const uint32_t MAX_PACKET_SIZE = 255;
char tello_packet[MAX_PACKET_SIZE];

WiFiUDP udp_connection;

void setup()
{
    Serial.begin(115200);
    delay(1000);

    WiFi.begin(SSID, PASSWORD);
    Serial.println("Connecting to TELLO's Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected!");

    udp_connection.begin(TELLO_PORT);

    const String command = "command";

    byte buffer[command.length() + 1];
    command.getBytes(buffer, sizeof(buffer) / sizeof(buffer[0]));
    
    udp_connection.write(buffer, sizeof(buffer) / sizeof(buffer[0]));

    delay(1000);

    const String command2 = "takeoff";

    byte buffer2[command2.length() + 1];
    command2.getBytes(buffer2, sizeof(buffer2) / sizeof(buffer2[0]));
    
    udp_connection.write(buffer2, sizeof(buffer2) / sizeof(buffer2[0]));

    bool read_packet_succeeded = false;
    
    while (!read_packet_succeeded)
    {
        int32_t packetSize = udp_connection.parsePacket();

        Serial.println("Packet size: ");
        Serial.println(packetSize);
        
        if (packetSize != 0)
        {
            int32_t len = udp_connection.read(tello_packet, MAX_PACKET_SIZE);
            
            if (len > 0)
            {
                tello_packet[len] = 0;
            }

            Serial.printf("UDP packet contents: %s\n", tello_packet);
            
            read_packet_succeeded = true;
        } 
    }

}

void loop()
{

}