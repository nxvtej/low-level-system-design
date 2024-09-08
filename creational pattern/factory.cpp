#include <iostream>
#include <memory>

class Product
{
public:
    virtual void use() const = 0;
    virtual ~Product() {}
};

// Concrete Product 1
class ConcreteProductA : public Product
{
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductA\n";
    }
};

// Concrete Product 2
class ConcreteProductB : public Product
{
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductB\n";
    }
};

// Factory Interface
class Creator
{
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() {}
};

// Concrete Factory 1
class ConcreteCreatorA : public Creator
{
public:
    std::unique_ptr<Product> createProduct() const override
    {
        return std::make_unique<ConcreteProductA>();
    }
};

// Concrete Factory 2
class ConcreteCreatorB : public Creator
{
public:
    std::unique_ptr<Product> createProduct() const override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

// Client code
void clientCode(const Creator &creator)
{
    std::unique_ptr<Product> product = creator.createProduct();
    product->use();
}

int main()
{
    std::cout << "App: Using ConcreteCreatorA\n";
    ConcreteCreatorA creatorA;
    clientCode(creatorA);

    std::cout << "App: Using ConcreteCreatorB\n";
    ConcreteCreatorB creatorB;
    clientCode(creatorB);

    return 0;
}
