#ifndef delldesktopbuilder_h
#define delldesktopbuilder_h

#include "desktop_builder.hpp"

class DellDesktopBuilder : public desktop_builder
{
    void buildMonitor();
    void buildMouse();
    void buildKeyboard();
    void buildRam();
    void buildProcessor();
    void buildMotherboard();
    void buildSpeaker();
    Desktop *getDesktop()
    {
        return desktop;
    }
};
#endif