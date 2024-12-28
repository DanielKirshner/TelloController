#include "Debugger.hpp"


Debugger::Debugger(const bool enabled) :
    _enabled(enabled)
{
    if (enabled)
    {
        Serial.begin(_SERIAL_PORT_BAUD_RATE);
    }
}

void Debugger::print_message(const String& message) const
{
    if (_enabled)
    {
        Serial.println(message);
    }
}

bool Debugger::wrap_in_success_message(const String& message, bool (*function_to_wrap)()) const
{
    if (_enabled)
    {
        Serial.print(message);
    }
    const bool succeeded = function_to_wrap();
    if (_enabled)
    {
        Serial.println(" " + String(succeeded ? _MESSAGE_RESPONSE__SUCCESS : _MESSAGE_RESPONSE__FAIL));
    }
    return succeeded;
}
