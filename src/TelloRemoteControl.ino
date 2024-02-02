#include <WiFi.h>
#include <WiFiUdp.h>
#include <cstdint>

// Debug Messages
const String MESSAGE__FIRMWARE_INFO = "Tello Remote-Controller | v0.1";
const String STATUS_MESSAGE__CONNECTING_TO_TELLO_WIFI = "Connecting to Tello's Wi-Fi... ";
const String STATUS_MESSAGE__INITIALIZING_CONNECTION_TO_TELLO = "Initializing a connection to Tello... ";
const String STATUS_MESSAGE__ENABLING_SDK_MODE = "Enabling SDK mode... ";
const String STATUS_MESSAGE_RESPONSE__SUCCESS = "SUCCESS!";
const String STATUS_MESSAGE_RESPONSE__FAIL = "FAIL!";

// Wifi Credentials
const String TELLO_WIFI_SSID = "TELLO-9F5E9A";
const String TELLO_WIFI_PASSWORD = "";
const String TELLO_IP = "192.168.10.1";
constexpr uint16_t TELLO_PORT = 8889;
constexpr uint16_t LOCAL_PORT = 9000;    // Local port to bind the UDP socket to. Can be any free port.

// Globals
bool initialized = false;
WiFiUDP tello_connection;
constexpr size_t BUFFER_SIZE = 1024;
byte buffer[BUFFER_SIZE];

// Constants
constexpr size_t ONE_SECOND_AS_MILISECONDS = 1000;

void sleep(const size_t seconds)
{
    delay(seconds * ONE_SECOND_AS_MILISECONDS);
}

void initialize()
{
    Serial.begin(9600);
    Serial.println(MESSAGE__FIRMWARE_INFO);
}

void connect_to_wifi()
{
    Serial.print(STATUS_MESSAGE__CONNECTING_TO_TELLO_WIFI);
    WiFi.begin(TELLO_WIFI_SSID.c_str(), TELLO_WIFI_PASSWORD.c_str());
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(10);
    }
    Serial.println(STATUS_MESSAGE_RESPONSE__SUCCESS);
}

bool initialize_connection_to_tello()
{
    Serial.print(STATUS_MESSAGE__INITIALIZING_CONNECTION_TO_TELLO);
    bool succeeded = tello_connection.begin(LOCAL_PORT);
    Serial.println(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL);
    return succeeded;
}

bool send_command_to_tello(const String& command_to_send)
{
    tello_connection.beginPacket(TELLO_IP.c_str(), TELLO_PORT);
    String(command_to_send.c_str()).getBytes(buffer, BUFFER_SIZE));
    tello_connection.write(buffer, BUFFER_SIZE));
    bool command_sent_successfully = tello_connection.endPacket();
    Serial.println(command_sent_successfully ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL);
    return command_sent_successfully;
}

bool enable_sdk_mode()
{
    Serial.print(STATUS_MESSAGE__ENABLING_SDK_MODE);
    bool enabling_sdk_status = send_command_to_tello("command");
    return enabling_sdk_status;
}


void setup()
{
    sleep(5);
    initialize();

    sleep(1);
    connect_to_wifi();

    sleep(1);
    if (!initialize_connection_to_tello())
    {
        return;
    }

    sleep(1);
    if (!enable_sdk_mode())
    {
        return;
    }

    initialized = true;
}

void loop()
{
    if (initialized)
    {
        // TODO: ...
    }
}
