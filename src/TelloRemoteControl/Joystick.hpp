#pragma once

#include "AnalogPin.hpp"
#include "Button.hpp"

#include <Arduino.h>


class Joystick final
{
    public:
        explicit Joystick(const uint8_t button_pin_number,
                          const uint8_t x_wheel_pin_number,
                          const uint8_t y_wheel_pin_number);
        ~Joystick() = default;

    public:
        bool is_button_pressed() const;

    private:
        Button _button;
        AnalogPin _x_wheel_pin;
        AnalogPin _y_wheel_pin;
};
