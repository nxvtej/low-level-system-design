#ifndef desktop_h
#define desktop_h

#include <string>
using namespace std;
class Desktop
{
private:
    std::string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherboard;

public:
    void setMonitor(string pmonitor);

    void setKeyboard(string pkeyboard);
    void setMouse(string pmouse);
    void setSpeaker(string pspeaker);
    void setRam(string pram);
    void setProcessor(string pprocessor);
    void setMotherboard(string pmotherboard);

    void showSpecs();
};

#endif