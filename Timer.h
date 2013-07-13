#ifndef _TIMER_H_
#define _TIMER_H_

#include "Engine.h"
#include <ctime>

namespace SuperEngine
{
    class Timer
    {
    private:
        time_t timer_start;
        time_t stopwatch_start;

    public:
        Timer(void);
        ~Timer(void);

        time_t getTimer();
        time_t getStartTimeMillis();
        void sleep(int ms);
        void reset();
        bool stopwatch(int ms);
    };
};

#endif
