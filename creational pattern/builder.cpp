#include <iostream>
#include <string>

// Product class representing the House
class House
{
public:
    bool hasPool;
    bool hasGarage;
    bool hasGarden;
    int numberOfFloors;

    void showDetails() const
    {
        std::cout << "House details:\n";
        std::cout << "Has Pool: " << (hasPool ? "Yes" : "No") << "\n";
        std::cout << "Has Garage: " << (hasGarage ? "Yes" : "No") << "\n";
        std::cout << "Has Garden: " << (hasGarden ? "Yes" : "No") << "\n";
        std::cout << "Number of Floors: " << numberOfFloors << "\n";
    }
};

// Abstract Builder class
class HouseBuilder
{
public:
    virtual ~HouseBuilder() {}
    virtual void buildPool() = 0;
    virtual void buildGarage() = 0;
    virtual void buildGarden() = 0;
    virtual void buildFloors(int floors) = 0;
    virtual House *getHouse() = 0;
};

// Concrete Builder class
class ConcreteHouseBuilder : public HouseBuilder
{
private:
    House *house;

public:
    ConcreteHouseBuilder()
    {
        this->house = new House();
    }

    ~ConcreteHouseBuilder()
    {
        delete house;
    }

    void buildPool() override
    {
        house->hasPool = true;
    }

    void buildGarage() override
    {
        house->hasGarage = true;
    }

    void buildGarden() override
    {
        house->hasGarden = true;
    }

    void buildFloors(int floors) override
    {
        house->numberOfFloors = floors;
    }

    House *getHouse() override
    {
        return house;
    }
};

// Director class
class HouseDirector
{
private:
    HouseBuilder *builder;

public:
    HouseDirector(HouseBuilder *b) : builder(b) {}

    void constructLuxuryHouse()
    {
        builder->buildPool();
        builder->buildGarage();
        builder->buildGarden();
        builder->buildFloors(3);
    }

    void constructSimpleHouse()
    {
        builder->buildGarage();
        builder->buildFloors(1);
    }
};

int main()
{
    // Create the builder
    ConcreteHouseBuilder *builder = new ConcreteHouseBuilder();

    // Create the director and use it to build a luxury house
    HouseDirector director(builder);
    director.constructLuxuryHouse();

    // Get the constructed house
    House *luxuryHouse = builder->getHouse();
    luxuryHouse->showDetails();

    // Now build a simple house
    delete builder;
    builder = new ConcreteHouseBuilder();
    HouseDirector simpleDirector(builder);
    simpleDirector.constructSimpleHouse();

    House *simpleHouse = builder->getHouse();
    simpleHouse->showDetails();

    // Clean up
    delete builder;

    return 0;
}
