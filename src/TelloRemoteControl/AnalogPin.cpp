#include "AnalogPin.hpp"

AnalogPin::AnalogPin(const uint8_t number) :
    _number(number)
{

}

uint16_t AnalogPin::read_value() const
{
    return analogRead(_number);
}