#pragma once

#include "DigitalPin.hpp"

#include <Arduino.h>


class Button final
{
    public:
        explicit Button(const uint8_t gpio_pin_number);
        ~Button() = default;

    public:
        bool is_pressed() const;

    private:
        const DigitalPin _gpio_pin;
};
