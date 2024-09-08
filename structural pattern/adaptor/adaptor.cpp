#include <iostream>
#include <string>

// Target Interface (What the client expects)
class Socket110V
{
public:
    virtual void plugIn110VDevice() = 0;
    virtual ~Socket110V() = default;
};

// Adaptee (The incompatible class that needs adapting)
class Socket220V
{
public:
    void plugIn220VDevice()
    {
        std::cout << "Device running on 220V power." << std::endl;
    }
};

// Adapter Class (Converts the 220V socket to 110V)
class VoltageAdapter : public Socket110V
{
private:
    Socket220V *socket220V;

public:
    VoltageAdapter(Socket220V *socket) : socket220V(socket) {}

    void plugIn110VDevice() override
    {
        std::cout << "Adapting voltage from 220V to 110V..." << std::endl;
        socket220V->plugIn220VDevice(); // Adapts the power
    }
};

// Client (The 110V device)
class Old110VDevice
{
private:
    Socket110V *socket110V;

public:
    Old110VDevice(Socket110V *socket) : socket110V(socket) {}

    void plugInAndRun()
    {
        std::cout << "Plugging in old 110V device." << std::endl;
        socket110V->plugIn110VDevice();
    }
};

// Main function demonstrating the Adapter Pattern
int main()
{
    // Create a 220V socket
    Socket220V *socket220V = new Socket220V();

    // Use an adapter to convert the 220V socket to 110V for the old device
    Socket110V *adapter = new VoltageAdapter(socket220V);

    // Plug in the old 110V device using the adapter
    Old110VDevice device(adapter);
    device.plugInAndRun();

    // Clean up
    delete socket220V;
    delete adapter;

    return 0;
}
