#include <iostream>
#include "logger.hpp"

using namespace std;

Logger::Logger()
{
    cout << "New instance created.\n";
}

void Logger::Log(string ms)
{
    cout << "Log: " << ms << "\n";
}