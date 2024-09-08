#include "desktop.hpp"
#include <iostream>

using namespace std;

void Desktop::setMonitor(string pMonitor)
{
    monitor = pMonitor;
}

void Desktop::setKeyboard(string pKeyboard)
{
    keyboard = pKeyboard;
}

void Desktop::setMouse(string pMouse)
{
    mouse = pMouse;
}

void Desktop::setSpeaker(string pSpeaker)
{
    speaker = pSpeaker;
}

void Desktop::setRam(string pRam)
{
    ram = pRam;
}

void Desktop::setProcessor(string pProcessor)
{
    processor = pProcessor;
}

void Desktop::setMotherboard(string pMonitorBrand)
{
    motherboard = pMonitorBrand;
}

void Desktop::showSpecs()
{
    cout << "-----------------------------";
    cout << "Monitor: " << monitor << endl;
    cout << "Keyboard: " << keyboard << endl;
    cout << "Mouse: " << mouse << endl;
    cout << "Speaker: " << speaker << endl;
    cout << "RAM: " << ram << endl;
    cout << "Processor: " << processor << endl;
    cout << "Motherboard: " << motherboard << endl;
}