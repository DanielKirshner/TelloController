#include "WifiConnection.hpp"
#include "Tello.hpp"

#include <cstdint>

// GPIO Pins:
constexpr uint8_t PIN__LINK_LED               = 12;
constexpr uint8_t PIN__BUZZER                 = 5;
constexpr uint8_t PIN__LEFT_JOYSTICK_X_WHEEL  = 15;
constexpr uint8_t PIN__LEFT_JOYSTICK_Y_WHEEL  = 4;
constexpr uint8_t PIN__LEFT_JOYSTICK_BUTTON   = 16;
constexpr uint8_t PIN__RIGHT_JOYSTICK_X_WHEEL = 25;
constexpr uint8_t PIN__RIGHT_JOYSTICK_Y_WHEEL = 33;
constexpr uint8_t PIN__RIGHT_JOYSTICK_BUTTON  = 32;
constexpr uint8_t PIN__LEFT_BUTTON            = 21;
constexpr uint8_t PIN__RIGHT_BUTTON           = 22;

// Debug Messages:
constexpr char* MESSAGE__FIRMWARE_INFO                           = "Tello Remote-Controller | v0.1";
constexpr char* STATUS_MESSAGE__CONNECTING_TO_TELLO_WIFI         = "Connecting to Tello's Wi-Fi...";
constexpr char* STATUS_MESSAGE__INITIALIZING_CONNECTION_TO_TELLO = "Initializing a connection to Tello...";
constexpr char* STATUS_MESSAGE__ENABLING_SDK_MODE                = "Enabling SDK mode...";
constexpr char* STATUS_MESSAGE__TAKING_OFF                       = "Taking-Off...";
constexpr char* STATUS_MESSAGE__LANDING                          = "Landing...";
constexpr char* STATUS_MESSAGE_RESPONSE__SUCCESS                 = "SUCCESS!";
constexpr char* STATUS_MESSAGE_RESPONSE__FAIL                    = "FAIL!";

// Connection parameters:
constexpr char* TELLO_WIFI_SSID = "TELLO-9F5E9A";
constexpr char* TELLO_WIFI_PASSWORD = "";
constexpr char* TELLO_IP = "192.168.10.1";
constexpr uint16_t TELLO_PORT = 8889;

// Global variables:
bool initialized = false;
WifiConnection wifi_connection(TELLO_WIFI_SSID, TELLO_WIFI_PASSWORD);
Tello tello(TELLO_IP, TELLO_PORT);

void initialize()
{
    Serial.begin(9600);
    Serial.println(MESSAGE__FIRMWARE_INFO);
}

void connect_to_wifi()
{
    Serial.print(STATUS_MESSAGE__CONNECTING_TO_TELLO_WIFI);
    wifi_connection.connect();
    Serial.println(" " + String(STATUS_MESSAGE_RESPONSE__SUCCESS));
}

bool initialize_connection_to_tello()
{
    Serial.print(STATUS_MESSAGE__INITIALIZING_CONNECTION_TO_TELLO);
    const bool succeeded = tello.initialize_connection();
    Serial.println(" " + String(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL));
    return succeeded;
}

bool enable_sdk_mode()
{
    Serial.print(STATUS_MESSAGE__ENABLING_SDK_MODE);
    const bool succeeded = tello.send_command(TelloCommands::COMMAND__ENABLE_SDK);
    Serial.println(" " + String(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL));
    return succeeded;
}

bool takeoff()
{
    Serial.print(STATUS_MESSAGE__TAKING_OFF);
    const bool succeeded = tello.send_command(TelloCommands::COMMAND__TAKEOFF);
    Serial.println(" " + String(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL));
    return succeeded;
}

bool land()
{
    Serial.print(STATUS_MESSAGE__LANDING);
    const bool succeeded = tello.send_command(TelloCommands::COMMAND__LAND);
    Serial.println(" " + String(succeeded ? STATUS_MESSAGE_RESPONSE__SUCCESS : STATUS_MESSAGE_RESPONSE__FAIL));
    return succeeded;
}

void fly_direction(const String& direction, const size_t cm_to_move)
{
    if (cm_to_move < 20 || cm_to_move > 500)
    {
        Serial.println("Invalid cm parameter");
        return;
    }
    const String full_command = direction + " " + cm_to_move;
    tello.send_command(full_command);
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
    if (initialized)
    {

    }
}
