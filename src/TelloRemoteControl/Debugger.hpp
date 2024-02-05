#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>


class Debugger
{
    private:
        static constexpr uint32_t SERIAL_PORT_BAUD_RATE = 9600;

    private:
        static constexpr char* const MESSAGE_RESPONSE__SUCCESS = "SUCCESS!";
        static constexpr char* const MESSAGE_RESPONSE__FAIL    = "FAIL!";


    private:
        bool enabled;

    public:
        Debugger(bool enabled = false);
        void print_message(const String& message) const;
        bool wrap_in_success_message(const String& message, bool (*function_to_wrap)()) const;
};
