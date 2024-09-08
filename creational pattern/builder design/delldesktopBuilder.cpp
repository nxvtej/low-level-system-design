#include "delldesktopBuilder.hpp"

/*
 void buildMouse();
    void buildKeyboard();
    void buildRam();
    void buildProcessor();
    void buildMotherboard();
    void buildSpeaker();
    Desktop *getDesktop()
    {
        return desktop;
    }*/
void DellDesktopBuilder::buildMonitor()
{
    desktop->setMonitor("Dell monitor");
}

void DellDesktopBuilder::buildMouse()
{
    desktop->setMouse("Dell mouse");
}

void DellDesktopBuilder::buildKeyboard()
{
    desktop->setKeyboard("Dell keyboard");
}

void DellDesktopBuilder::buildRam()

{
    desktop->setRam("Dell RAM");
}

void DellDesktopBuilder::buildProcessor()
{
    desktop->setProcessor("Dell processor");
}

void DellDesktopBuilder::buildMotherboard()
{
    desktop->setMotherboard("Dell motherboard");
}

void DellDesktopBuilder::buildSpeaker()
{
    desktop->setSpeaker("Dell speaker");
}
