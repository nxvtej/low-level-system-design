#include <iostream>

// Strategy Interface
class OperationStrategy
{
public:
    virtual int execute(int a, int b) = 0; // Pure virtual function
    virtual ~OperationStrategy() {}
};

// Concrete Strategy 1: Addition
class AddOperation : public OperationStrategy
{
public:
    int execute(int a, int b) override
    {
        return a + b;
    }
};

// Concrete Strategy 2: Multiplication
class MultiplyOperation : public OperationStrategy
{
public:
    int execute(int a, int b) override
    {
        return a * b;
    }
};

// Context Class
class Calculator
{
private:
    OperationStrategy *strategy;

public:
    Calculator(OperationStrategy *strategy) : strategy(strategy) {}

    void setStrategy(OperationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    int calculate(int a, int b)
    {
        return strategy->execute(a, b);
    }
};

// Main function
int main()
{
    Calculator calculator(new AddOperation());

    int result = calculator.calculate(3, 5); // Using addition strategy
    std::cout << "Addition: " << result << std::endl;

    calculator.setStrategy(new MultiplyOperation());
    result = calculator.calculate(3, 5); // Using multiplication strategy
    std::cout << "Multiplication: " << result << std::endl;

    return 0;
}
