#include "Debugger.hpp"
#include "WifiConnection.hpp"
#include "Tello.hpp"

#include <cstdint>


constexpr bool ENABLE_DEBUG_MESSAGES = true;
constexpr const char* FIRMWARE_INFO = "Tello Remote-Controller | v0.1";
namespace StatusMessage
{
    constexpr const char* CONNECTING_TO_TELLO_WIFI         = "Connecting to Tello's Wi-Fi...";
    constexpr const char* INITIALIZING_CONNECTION_TO_TELLO = "Initializing a connection to Tello...";
    constexpr const char* ENABLING_SDK_MODE                = "Enabling SDK mode...";
    constexpr const char* TAKING_OFF                       = "Taking-Off...";
    constexpr const char* LANDING                          = "Landing...";
}
namespace GpioPin
{
    constexpr uint8_t LINK_LED               = 12;
    constexpr uint8_t BUZZER                 = 5;
    constexpr uint8_t LEFT_JOYSTICK_X_WHEEL  = 15;
    constexpr uint8_t LEFT_JOYSTICK_Y_WHEEL  = 4;
    constexpr uint8_t LEFT_JOYSTICK_BUTTON   = 16;
    constexpr uint8_t RIGHT_JOYSTICK_X_WHEEL = 25;
    constexpr uint8_t RIGHT_JOYSTICK_Y_WHEEL = 33;
    constexpr uint8_t RIGHT_JOYSTICK_BUTTON  = 32;
    constexpr uint8_t LEFT_BUTTON            = 21;
    constexpr uint8_t RIGHT_BUTTON           = 22;
}
// Connection parameters:
constexpr const char* TELLO_WIFI_SSID = "TELLO-9F5E9A";
constexpr const char* TELLO_WIFI_PASSWORD = "";
const WifiCredentials wifi_creds = {TELLO_WIFI_SSID, TELLO_WIFI_PASSWORD};
constexpr const char* TELLO_IP = "192.168.10.1";
constexpr uint16_t TELLO_PORT = 8889;


WifiConnection wifi_connection(wifi_creds);
Debugger debugger(ENABLE_DEBUG_MESSAGES);
Tello tello(TELLO_IP, TELLO_PORT);
bool initialized = false;


void initialize()
{
    debugger.print_message(FIRMWARE_INFO);
}

void connect_to_wifi()
{
    debugger.execute_verbosely
    (
        StatusMessage::CONNECTING_TO_TELLO_WIFI,
        []()
        {
            wifi_connection.connect();
            return true;    // Ignored for now.
        }
    );
}

bool initialize_connection_to_tello()
{
    return debugger.execute_verbosely
    (
        StatusMessage::INITIALIZING_CONNECTION_TO_TELLO,
        []()
        {
            return tello.initialize_connection();
        }
    );
}

bool enable_sdk_mode()
{
    return debugger.execute_verbosely
    (
        StatusMessage::ENABLING_SDK_MODE,
        []()
        {
            return tello.enable_sdk();
        }
    );
}

bool takeoff()
{
    return debugger.execute_verbosely
    (
        StatusMessage::TAKING_OFF,
        []()
        {
            return tello.takeoff();
        }
    );
}

bool land()
{
    return debugger.execute_verbosely
    (
        StatusMessage::LANDING,
        []()
        {
            return tello.land();
        }
    );
}

/*void fly_direction(const String& direction, const size_t cm_to_move)
{
    if (cm_to_move < 20 || cm_to_move > 500)
    {
        debugger.print_message("Invalid cm parameter");
        return;
    }
    const String full_command = direction + " " + cm_to_move;
    tello.send_command(full_command);
}*/

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
