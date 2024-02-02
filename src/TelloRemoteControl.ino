#include <WiFi.h>
#include <WiFiUdp.h>


// Debug Messages
const String MESSAGE__FIRMWARE_INFO = "Tello Remote-Controller | v0.1";
const String STATUS_MESSAGE__CONNECTING_TO_TELLO_WIFI = "Connecting to Tello's Wi-Fi... ";
const String STATUS_MESSAGE__INITIALIZING_CONNECTION_TO_TELLO = "Initializing a connection to Tello... ";
const String STATUS_MESSAGE__ENABLING_SDK_MODE = "Enabling SDK mode... ";
const String STATUS_MESSAGE_RESPONSE__SUCCESS = "SUCCESS!";
const String STATUS_MESSAGE_RESPONSE__FAIL = "FAIL!";
// Connections parameters constants
const String TELLO_WIFI_SSID = "TELLO-9F5E9A";
const String TELLO_WIFI_PASSWORD = "";
const String TELLO_IP = "192.168.10.1";
const int TELLO_PORT = 8889;
const int LOCAL_PORT = 9000;    // Local port to bind the UDP socket to. Can be any free port.

bool initialized = false;
byte buffer[1000];
WiFiUDP tello_connection;


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
        delay(1);
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

bool enable_sdk_mode()
{
    Serial.print(STATUS_MESSAGE__ENABLING_SDK_MODE);
    tello_connection.beginPacket(TELLO_IP.c_str(), TELLO_PORT);
    String("command").getBytes(buffer, sizeof(buffer) / sizeof(buffer[0]));
    tello_connection.write(buffer, sizeof(buffer) / sizeof(buffer[0]));
    bool succeeded = tello_connection.endPacket();
    Serial.println(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL);
    return succeeded;
}


void setup()
{
    delay(5000);
    initialize();

    delay(1000);
    connect_to_wifi();

    delay(1000);
    if (!initialize_connection_to_tello())
    {
        return;
    }

    delay(1000);
    if (!enable_sdk_mode())
    {
        return;
    }

    initialized = true;
}

void loop()
{
    if (initialized) {
        // TODO: ...
    }
}
