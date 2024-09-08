#include <iostream>
#include <stack>

// Receiver class: AC (Air Conditioner)
class AC
{
public:
    void turnOn()
    {
        std::cout << "AC is turned ON." << std::endl;
    }

    void turnOff()
    {
        std::cout << "AC is turned OFF." << std::endl;
    }

    void setTemperature(int temp)
    {
        std::cout << "AC temperature set to " << temp << " degrees." << std::endl;
    }
};

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command: Turn On Command
class TurnOnCommand : public Command
{
private:
    AC *ac;

public:
    TurnOnCommand(AC *ac) : ac(ac) {}

    void execute() override
    {
        ac->turnOn();
    }
};

// Concrete Command: Turn Off Command
class TurnOffCommand : public Command
{
private:
    AC *ac;

public:
    TurnOffCommand(AC *ac) : ac(ac) {}

    void execute() override
    {
        ac->turnOff();
    }
};

// Concrete Command: Set Temperature Command
class SetTemperatureCommand : public Command
{
private:
    AC *ac;
    int temperature;

public:
    SetTemperatureCommand(AC *ac, int temp) : ac(ac), temperature(temp) {}

    void execute() override
    {
        ac->setTemperature(temperature);
    }
};

// Invoker: Remote Control
class RemoteControl
{
private:
    Command *command;

public:
    void setCommand(Command *cmd)
    {
        command = cmd;
    }

    void pressButton()
    {
        if (command)
        {
            command->execute();
        }
    }
};

// Client: Configures commands and triggers actions
int main()
{
    AC ac; // Receiver

    // Concrete commands
    TurnOnCommand turnOn(&ac);
    TurnOffCommand turnOff(&ac);
    SetTemperatureCommand setTemp(&ac, 22); // Set AC to 22 degrees

    // Invoker: Remote Control
    RemoteControl remote;

    // Turn on the AC
    remote.setCommand(&turnOn);
    remote.pressButton();

    // Set temperature
    remote.setCommand(&setTemp);
    remote.pressButton();

    // Turn off the AC
    remote.setCommand(&turnOff);
    remote.pressButton();

    return 0;
}
