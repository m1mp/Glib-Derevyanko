#include <iostream>
#include <string>

// Базовий клас для створення об'єктів
class Product {
public:
    virtual void info() = 0;
};

// Конкретний клас об'єкта
class ConcreteProduct : public Product {
public:
    void info() override {
        std::cout << "Це конкретний продукт" << std::endl;
    }
};

// Фабричний клас для створення об'єктів
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// Конкретна фабрика для створення конкретного продукту
class ConcreteFactory : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

int main() {
    // Створення об'єкту фабрики
    Factory* factory = new ConcreteFactory();

    // Використання фабрики для створення об'єкту продукту
    Product* product = factory->createProduct();

    // Виклик методу info() для об'єкту продукту
    product->info();

    delete product;
    delete factory;

    return 0;
}
