#include <iostream>
#include <string>

// Prototype Interface
class Prototype
{
public:
    virtual Prototype *clone() const = 0; // Pure virtual clone method
    virtual void printType() const = 0;
};

// Concrete Prototype 1
class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1 *clone() const override
    {
        return new ConcretePrototype1(*this); // Copy the object
    }

    void printType() const override
    {
        std::cout << "ConcretePrototype1" << std::endl;
    }
};

// Concrete Prototype 2
class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2 *clone() const override
    {
        return new ConcretePrototype2(*this); // Copy the object
    }

    void printType() const override
    {
        std::cout << "ConcretePrototype2" << std::endl;
    }
};

// Client code
int main()
{
    Prototype *prototype1 = new ConcretePrototype1();
    Prototype *prototype2 = new ConcretePrototype2();

    // Clone prototypes
    Prototype *clone1 = prototype1->clone();
    Prototype *clone2 = prototype2->clone();

    clone1->printType(); // Output: ConcretePrototype1
    clone2->printType(); // Output: ConcretePrototype2

    // Clean up
    delete prototype1;
    delete prototype2;
    delete clone1;
    delete clone2;

    return 0;
}
