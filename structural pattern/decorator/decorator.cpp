#include <iostream>
#include <string>

using namespace std;

// Base Component (Pizza interface)
class Pizza
{
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Pizza() = default;
};

// Concrete Component (BasicPizza)
class MargheritaPizza : public Pizza
{
public:
    string getDescription() const override
    {
        return "Margherita Pizza";
    }

    double getCost() const override
    {
        return 5.00; // Base cost of the pizza
    }
};

// Concrete Component (PepperoniPizza)
class PepperoniPizza : public Pizza
{
public:
    string getDescription() const override
    {
        return "Pepperoni Pizza";
    }

    double getCost() const override
    {
        return 6.00; // Base cost of the pizza
    }
};

// Base Decorator (Toppings)
class ToppingDecorator : public Pizza
{
protected:
    Pizza *pizza; // Aggregation (decorating another pizza)

public:
    ToppingDecorator(Pizza *p) : pizza(p) {}
    virtual string getDescription() const override = 0;
    virtual double getCost() const override = 0;

    // Ensure we manage memory properly by deleting the decorated pizza
    virtual ~ToppingDecorator()
    {
        delete pizza;
    }
};

// Concrete Decorator (Cheese Topping)
class Cheese : public ToppingDecorator
{
public:
    Cheese(Pizza *p) : ToppingDecorator(p) {}

    string getDescription() const override
    {
        return pizza->getDescription() + ", Cheese";
    }

    double getCost() const override
    {
        return pizza->getCost() + 1.50; // Adding cost for cheese topping
    }
};

// Concrete Decorator (Mushroom Topping)
class Mushroom : public ToppingDecorator
{
public:
    Mushroom(Pizza *p) : ToppingDecorator(p) {}

    string getDescription() const override
    {
        return pizza->getDescription() + ", Mushroom";
    }

    double getCost() const override
    {
        return pizza->getCost() + 1.00; // Adding cost for mushroom topping
    }
};

// Concrete Decorator (Pepperoni Topping)
class Pepperoni : public ToppingDecorator
{
public:
    Pepperoni(Pizza *p) : ToppingDecorator(p) {}

    string getDescription() const override
    {
        return pizza->getDescription() + ", Pepperoni";
    }

    double getCost() const override
    {
        return pizza->getCost() + 1.75; // Adding cost for pepperoni topping
    }
};

// Main function to demonstrate the Decorator Pattern
int main()
{
    // Create a basic pizza
    Pizza *myPizza = new MargheritaPizza();
    cout << myPizza->getDescription() << " Cost: $" << myPizza->getCost() << endl;

    // Add cheese topping
    myPizza = new Cheese(myPizza);
    cout << myPizza->getDescription() << " Cost: $" << myPizza->getCost() << endl;

    // Add mushroom topping
    myPizza = new Mushroom(myPizza);
    cout << myPizza->getDescription() << " Cost: $" << myPizza->getCost() << endl;

    // Add pepperoni topping
    myPizza = new Pepperoni(myPizza);
    cout << myPizza->getDescription() << " Cost: $" << myPizza->getCost() << endl;

    // Manually delete the pizza to free memory
    delete myPizza;

    return 0;
}
