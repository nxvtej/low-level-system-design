#include <iostream>
#include <string>

// Abstract Handler class (Support)
class Support
{
protected:
    Support *nextSupport; // Raw pointer to the next handler

public:
    Support() : nextSupport(nullptr) {}

    virtual ~Support() {}

    void setNext(Support *next)
    {
        nextSupport = next;
    }

    virtual void handleRequest(int severity) = 0; // Abstract request handler
};

// Concrete Handler 1: Low Level Support
class LowLevelSupport : public Support
{
public:
    void handleRequest(int severity) override
    {
        if (severity <= 1)
        {
            std::cout << "LowLevelSupport: Handling request of severity " << severity << std::endl;
        }
        else if (nextSupport)
        {
            nextSupport->handleRequest(severity); // Pass to the next handler
        }
    }
};

// Concrete Handler 2: Mid Level Support
class MidLevelSupport : public Support
{
public:
    void handleRequest(int severity) override
    {
        if (severity <= 3)
        {
            std::cout << "MidLevelSupport: Handling request of severity " << severity << std::endl;
        }
        else if (nextSupport)
        {
            nextSupport->handleRequest(severity); // Pass to the next handler
        }
    }
};

// Concrete Handler 3: High Level Support
class HighLevelSupport : public Support
{
public:
    void handleRequest(int severity) override
    {
        if (severity <= 5)
        {
            std::cout << "HighLevelSupport: Handling request of severity " << severity << std::endl;
        }
        else
        {
            std::cout << "HighLevelSupport: Severity " << severity << " is too high to handle!" << std::endl;
        }
    }
};

// Main function
int main()
{
    // Creating handlers
    LowLevelSupport lowLevel;
    MidLevelSupport midLevel;
    HighLevelSupport highLevel;

    // Setting the chain of responsibility
    lowLevel.setNext(&midLevel);
    midLevel.setNext(&highLevel);

    // Handling requests
    lowLevel.handleRequest(1); // Handled by LowLevelSupport
    lowLevel.handleRequest(3); // Handled by MidLevelSupport
    lowLevel.handleRequest(5); // Handled by HighLevelSupport
    lowLevel.handleRequest(6); // Not handled by any support

    return 0;
}
