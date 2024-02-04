#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>


class Debugger
{
    private: static constexpr uint32_t SERIAL_PORT_BAUD_RATE = 9600;

    // Message Responses:
    private: static constexpr char* const MESSAGE_RESPONSE__SUCCESS = "SUCCESS!";
    private: static constexpr char* const MESSAGE_RESPONSE__FAIL    = "FAIL!";

    
    private: bool enabled;

    public: Debugger(bool enabled = false);

    public: void initialize() const;
    public: void print_message(const String& message) const;
    public: bool wrap_in_success_message(const String& message, bool (*function_to_wrap)()) const;
};
