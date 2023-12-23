#include <iostream>
#include <string>

// Abstract base class representing the prototype
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() {}
};

// Concrete prototype class
class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {}

    // Copy constructor for cloning
    ConcretePrototype(const ConcretePrototype& other) : data(other.data) {}

    // Clone method to create a copy of the object
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    // Print information about the object
    void printInfo() const override {
        std::cout << "ConcretePrototype: " << data << std::endl;
    }
};

int main() {
    // Create an instance of the prototype
    ConcretePrototype original("Original Data");
    
    // Clone the prototype to create a new object
    Prototype* clonedObject = original.clone();
    
    // Print information about both objects
    original.printInfo();
    clonedObject->printInfo();
    
    // Cleanup
    delete clonedObject;

    return 0;
}
