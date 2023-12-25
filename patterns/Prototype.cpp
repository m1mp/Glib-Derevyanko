#include <iostream>
#include <string>


class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {}

    ConcretePrototype(const ConcretePrototype& other) : data(other.data) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void printInfo() const override {
        std::cout << "ConcretePrototype: " << data << std::endl;
    }
};

int main() {
    ConcretePrototype original("Original Data");

    Prototype* clonedObject = original.clone();
    

    original.printInfo();
    clonedObject->printInfo();
    

    delete clonedObject;

    return 0;
}
