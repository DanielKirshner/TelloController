#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>

class Debugger final
{
    public:
        explicit Debugger(const bool enabled = false);
        ~Debugger() = default;
    
    public:
        void print_message(const String& message) const;
        bool wrap_in_success_message(const String& message, bool (*function_to_wrap)()) const;

    private:
        static constexpr uint32_t _SERIAL_PORT_BAUD_RATE = 9600;

    private:
        static constexpr char* const _MESSAGE_RESPONSE__SUCCESS = "SUCCESS!";
        static constexpr char* const _MESSAGE_RESPONSE__FAIL    = "FAIL!";

    private:
        bool _enabled;
};