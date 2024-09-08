#ifndef hpdesktopbuilder_h
#define hpdesktopbuilder_h

#include "desktop_builder.hpp"

class HpDesktopBuilder : public desktop_builder
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