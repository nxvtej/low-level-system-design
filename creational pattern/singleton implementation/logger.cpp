#include "logger.hpp"
#include <iostream>

mutex Logger::mtx;

using namespace std;

int Logger::counter = 0;
Logger *Logger::loggerInstance = nullptr;
Logger::Logger()
{
    counter++;
    cout << "New instance counter id:" << counter << "\n";
}

void Logger::Log(string ms)
{
    cout << "Log: " << ms << "\n";
}

/*

this logic is very expensive as its locks and unlocks two times
instead of this we can say

if(instance == null) lock then again check if null
and unlocks it insde the if only

then the funciton is not locked again and again

Logger *Logger::getLogger()
{
    mtx.lock();
    if (loggerInstance == nullptr)
    {

        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}

*/

// here only one time its locked
Logger *Logger::getLogger()
{
    if (loggerInstance == nullptr)
    {

        mtx.lock();
        if (loggerInstance == nullptr)
        {

            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}