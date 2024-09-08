#ifndef desktopDirector_h
#define desktopDirector_h

#include "desktop_builder.hpp"

class DesktopDirector
{
private:
    desktop_builder *instance_desktop_builider;

public:
    DesktopDirector(desktop_builder *pDesktopBuilder)
    {
        instance_desktop_builider = pDesktopBuilder;
    }
    Desktop *BuildDesktop()
    {
        instance_desktop_builider->buildKeyboard();
        instance_desktop_builider->buildMouse();
        instance_desktop_builider->buildMonitor();
        instance_desktop_builider->buildMotherboard();
        instance_desktop_builider->buildProcessor();
        instance_desktop_builider->buildRam();
        instance_desktop_builider->buildSpeaker();
        return instance_desktop_builider->getDesktop();
    }
};

#endif