#include <iostream>
#include <string>


class Product {
public:
    virtual void info() = 0;
};


class ConcreteProduct : public Product {
public:
    void info() override {
        std::cout << "Це конкретний продукт" << std::endl;
    }
};


class Factory {
public:
    virtual Product* createProduct() = 0;
};


class ConcreteFactory : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

int main() {

    Factory* factory = new ConcreteFactory();


    Product* product = factory->createProduct();

    product->info();

    delete product;
    delete factory;

    return 0;
}
