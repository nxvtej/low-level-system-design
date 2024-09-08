#include <iostream>
#include <thread>
#include "logger.hpp"

/*
// great, it works untill we have multithreading
int main(int argc, char *argv[])
{
    Logger *logger1 = Logger::getLogger();
    logger1->Log("this is user one");

    Logger *logger2 = Logger::getLogger();
    logger2->Log("this is user two");

    return 0;
}
*/

// ṭhread safe

void user1()
{
    Logger *logger1 = Logger::getLogger();
    logger1->Log("this is user one");
}

void user2()
{
    Logger *logger2 = Logger::getLogger();
    logger2->Log("this is user two");
}

main(int argc, char *argv[])
{
    thread t1(user1);
    thread t2(user2);

    t1.join();
    t2.join();
    return 0;
}
