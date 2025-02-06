#include "Led.hpp"


Led::Led(const uint8_t gpio_pin_number, const bool turn_on) :
    _gpio_pin(gpio_pin_number, false, GpioPin::Mode::OUT, turn_on) {}

void Led::turn_on() const
{
    _gpio_pin.set_state(true);
}

void Led::turn_off() const
{
    _gpio_pin.set_state(false);
}
