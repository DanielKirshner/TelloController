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

bool Debugger::execute_verbosely(const String& message, bool (*action)()) const
{
    if (_enabled)
    {
        Serial.print(message);
    }
    const bool succeeded = action();
    if (_enabled)
    {
        Serial.println(" " + String(succeeded ? _MESSAGE_RESPONSE__SUCCESS : _MESSAGE_RESPONSE__FAIL));
    }
    return succeeded;
}
