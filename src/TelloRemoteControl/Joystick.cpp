#include "Joystick.hpp"

Joystick::Joystick(const uint8_t button_pin_number,
                   const uint8_t x_wheel_pin_number,
                   const uint8_t y_wheel_pin_number) : 
    _button(button_pin_number),
    _x_wheel_pin(x_wheel_pin_number),
    _y_wheel_pin(y_wheel_pin_number)
{
    
}

bool Joystick::is_button_pressed() const
{
    return _button.is_pressed();
}
