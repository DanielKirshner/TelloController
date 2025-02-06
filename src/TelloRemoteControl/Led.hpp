#pragma once

#include <Arduino.h>

#include "GpioPin.hpp"


class Led final
{
    public:
        explicit Led(const uint8_t gpio_pin_number, const bool turn_on = false);
        ~Led() = default;

    public:
        void turn_on() const;
        void turn_off() const;

    private:
        const GpioPin _gpio_pin;
};
