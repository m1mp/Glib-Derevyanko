#include <iostream>

class Implementor {
public:
    virtual void operationImpl() = 0;
};

class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor A" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor B" << std::endl;
    }
};

class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        implementor->operationImpl();
    }
};

int main() {

    ConcreteImplementorA implA;
    ConcreteImplementorB implB;

    RefinedAbstraction abstractionA(&implA);
    RefinedAbstraction abstractionB(&implB);

    abstractionA.operation(); 
    abstractionB.operation();

    return 0;
}
