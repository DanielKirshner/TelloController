#include "GpioPin.hpp"

#include <Arduino.h>


GpioPin::GpioPin(const uint8_t number, const bool inverted, const Mode mode, const bool enable) :
    _number(number), _inverted(inverted)
{
    set_mode(mode);
    set_state(enable);
}

GpioPin::~GpioPin()
{
    set_mode(DEFAULT_MODE);
}

void GpioPin::set_mode(const Mode mode) const
{
    uint8_t mode_value = INPUT;
    switch (mode)
    {
        case Mode::IN:
            mode_value = INPUT;
            break;
        case Mode::IN_PULLUP:
            mode_value = INPUT_PULLUP;
            break;
        case Mode::OUT:
            mode_value = OUTPUT;
            break;
    }
    pinMode(_number, mode_value);
}

bool GpioPin::get_state() const
{
    return (digitalRead(_number) == HIGH) ^ _inverted;
}

void GpioPin::set_state(const bool enabled) const
{
    digitalWrite(_number, (enabled ^ _inverted) ? HIGH : LOW);
}
