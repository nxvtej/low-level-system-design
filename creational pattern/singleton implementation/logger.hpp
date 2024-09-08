#ifndef logger_hpp
#define logger_hpp

#include <string>
#include <mutex>
using namespace std;

class Logger
{

private:
    static mutex mtx;
    static int counter;
    static Logger *loggerInstance;
    Logger();

    // another way to call constructors
    Logger(const Logger &);
    Logger &operator=(const Logger &);

public:
    static Logger *getLogger();
    void Log(string msg);
};

#endif