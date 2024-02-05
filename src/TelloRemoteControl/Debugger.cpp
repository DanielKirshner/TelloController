#include "Debugger.hpp"


Debugger::Debugger(bool enabled)
{
    this->enabled = enabled;
    if (enabled)
    {
        Serial.begin(SERIAL_PORT_BAUD_RATE);
    }
}

void Debugger::print_message(const String& message) const
{
    if (enabled)
    {
        Serial.println(message);
    }
}

bool Debugger::wrap_in_success_message(const String& message, bool (*function_to_wrap)()) const
{
    if (enabled)
    {
        Serial.print(message);
    }
    const bool succeeded = function_to_wrap();
    if (enabled)
    {
        Serial.println(" " + String(succeeded ? MESSAGE_RESPONSE__SUCCESS : MESSAGE_RESPONSE__FAIL));
    }
    return succeeded;
}
