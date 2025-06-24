#pragma once

#include <Arduino.h>


class DigitalPin final
{
    public:
        enum class Mode
        {
            IN = 0,
            IN_PULLUP,
            OUT
        };

    public:
        static constexpr Mode DEFAULT_MODE = Mode::IN;

    public:
        explicit DigitalPin(const uint8_t number,
                            const bool inverted = false,
                            const Mode mode = DEFAULT_MODE,
                            const bool enable = false);
        ~DigitalPin();

    public:
        void set_mode(const Mode mode) const;
        bool get_state() const;
        void set_state(const bool enabled) const;

    private:
        const uint8_t _number;
        const bool _inverted;
};
