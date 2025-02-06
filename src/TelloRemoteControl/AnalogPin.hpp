#pragma once

#include <Arduino.h>


class AnalogPin final
{
    public:
        explicit AnalogPin(const uint8_t number);
        ~AnalogPin() = default;

    public:
        uint16_t read_value() const;

    private:
        const uint8_t _number;
};
