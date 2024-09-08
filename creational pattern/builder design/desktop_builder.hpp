#ifndef desktopbuilder_h
#define desktopbuilder_h

#include <iostream>
#include "desktop.hpp"

class desktop_builder
{
protected:
    Desktop *desktop;

public:
    desktop_builder()
    {
        desktop = new Desktop();
    }
    // monitor keyboard mouse keyboard ram processor motherboard

    virtual void buildMonitor() = 0;
    virtual void buildMouse() = 0;
    virtual void buildKeyboard() = 0;
    virtual void buildRam() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMotherboard() = 0;

    virtual void buildSpeaker() = 0;

    virtual Desktop *getDesktop()
    {
        return desktop;
    }
};

#endif