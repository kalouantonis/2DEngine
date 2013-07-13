#include "Engine.h"

namespace SuperEngine
{
    Timer::Timer(void)
    {
        time(&timer_start);
        reset();
    }

    Timer::~Timer()
    {

    }

    time_t Timer::getTimer()
    {
        time_t curTime;
        time(&curTime);
        return curTime;
    }

    time_t Timer::getStartTimeMillis()
    {
        return difftime(timer_start, getTimer());
    }

    void Timer::sleep(int ms)
    {
        time_t start = getTimer();
        // Do nothing
        while((start + (time_t)ms) > getTimer());
    }

    void Timer::reset()
    {
        stopwatch_start = getTimer();
    }

    bool Timer::stopwatch(int ms)
    {
        if(getTimer() > (stopwatch_start + (time_t)ms))
        {
            stopwatch_start = getTimer();
            return true;
        }
        return false;
    }
};
