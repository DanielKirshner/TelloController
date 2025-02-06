#pragma once

#include <Arduino.h>


class GpioPin final
{
    public:
        enum class Mode
        {
            IN,
            IN_PULLUP,
            OUT
        };

    public:
        static constexpr Mode DEFAULT_MODE = Mode::IN;

    public:
        explicit GpioPin(const uint8_t number,
                         const bool inverted = false,
                         const Mode mode = DEFAULT_MODE,
                         const bool enable = false);
        ~GpioPin();

    public:
        void set_mode(const Mode mode) const;
        bool get_state() const;
        void set_state(const bool enabled) const;

    private:
        const uint8_t _number;
        const bool _inverted;
};
