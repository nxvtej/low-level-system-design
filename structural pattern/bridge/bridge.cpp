#include <iostream>
#include <string>

// Implementation Interface (Device)
class Device
{
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void setVolume(int volume) = 0;
    virtual ~Device() = default;
};

// Concrete Implementation (TV)
class TV : public Device
{
public:
    void powerOn() override
    {
        std::cout << "TV is powered on." << std::endl;
    }

    void powerOff() override
    {
        std::cout << "TV is powered off." << std::endl;
    }

    void setVolume(int volume) override
    {
        std::cout << "TV volume set to " << volume << "." << std::endl;
    }
};

// Concrete Implementation (Radio)
class Radio : public Device
{
public:
    void powerOn() override
    {
        std::cout << "Radio is powered on." << std::endl;
    }

    void powerOff() override
    {
        std::cout << "Radio is powered off." << std::endl;
    }

    void setVolume(int volume) override
    {
        std::cout << "Radio volume set to " << volume << "." << std::endl;
    }
};

// Abstraction (RemoteControl)
class RemoteControl
{
protected:
    Device *device; // Bridge to the implementation (device)

public:
    RemoteControl(Device *dev) : device(dev) {}

    virtual void togglePower() = 0;
    virtual void volumeUp() = 0;
    virtual void volumeDown() = 0;
    virtual ~RemoteControl() = default;
};

// Refined Abstraction (BasicRemote)
class BasicRemote : public RemoteControl
{
private:
    bool powerOn = false;
    int volume = 10;

public:
    BasicRemote(Device *dev) : RemoteControl(dev) {}

    void togglePower() override
    {
        if (powerOn)
        {
            device->powerOff();
            powerOn = false;
        }
        else
        {
            device->powerOn();
            powerOn = true;
        }
    }

    void volumeUp() override
    {
        volume += 1;
        device->setVolume(volume);
    }

    void volumeDown() override
    {
        volume -= 1;
        device->setVolume(volume);
    }
};

// Refined Abstraction (AdvancedRemote)
class AdvancedRemote : public BasicRemote
{
public:
    AdvancedRemote(Device *dev) : BasicRemote(dev) {}

    void mute()
    {
        std::cout << "Muting device." << std::endl;
        device->setVolume(0);
    }
};

// Main function demonstrating the Bridge Pattern
int main()
{
    Device *tv = new TV();
    Device *radio = new Radio();

    // Using basic remote for TV
    RemoteControl *basicRemoteForTV = new BasicRemote(tv);
    basicRemoteForTV->togglePower(); // Turns TV on
    basicRemoteForTV->volumeUp();    // Increases TV volume

    std::cout << "------------------" << std::endl;

    // Using advanced remote for Radio
    AdvancedRemote *advancedRemoteForRadio = new AdvancedRemote(radio);
    advancedRemoteForRadio->togglePower(); // Turns Radio on
    advancedRemoteForRadio->volumeUp();    // Increases Radio volume
    advancedRemoteForRadio->mute();        // Mutes the Radio

    // Clean up
    delete basicRemoteForTV;
    delete advancedRemoteForRadio;
    delete tv;
    delete radio;

    return 0;
}
