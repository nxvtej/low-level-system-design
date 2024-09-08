#include <iostream>
#include "logger.hpp"

int main(int argc, char *argv[])
{
    Logger *logger1 = new Logger();
    logger1->Log("this is user one");

    Logger *logger2 = new Logger();
    logger2->Log("this is user two");

    return 0;
}