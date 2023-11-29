#include <iostream>
#include <memory>

class AbstractProductA {
public:
    virtual void displayInfo() const = 0;
};

class AbstractProductB {
public:
    virtual void displayInfo() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void displayInfo() const override {
        std::cout << "Concrete Product A1\n";
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void displayInfo() const override {
        std::cout << "Concrete Product A2\n";
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void displayInfo() const override {
        std::cout << "Concrete Product B1\n";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void displayInfo() const override {
        std::cout << "Concrete Product B2\n";
    }
};

class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
};

// Конкретні реалізації фабрик
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

void clientCode(const AbstractFactory& factory) {
    auto productA = factory.createProductA();
    auto productB = factory.createProductB();

    productA->displayInfo();
    productB->displayInfo();
}

int main() {
    ConcreteFactory1 factory1;
    std::cout << "Client is using Concrete Factory 1:\n";
    clientCode(factory1);

    std::cout << "\n";

    ConcreteFactory2 factory2;
    std::cout << "Client is using Concrete Factory 2:\n";
    clientCode(factory2);

    return 0;
}
