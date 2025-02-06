#include "Button.hpp"


Button::Button(const uint8_t gpio_pin_number) :
    _gpio_pin(gpio_pin_number, false, DigitalPin::Mode::IN_PULLUP)
{

}

bool Button::is_pressed() const
{
    return _gpio_pin.get_state()
}
