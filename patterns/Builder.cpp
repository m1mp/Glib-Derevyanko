#include <iostream>
#include <string>

class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void showInfo() const {
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() = 0;
    virtual ~Builder() {}
};

class ConcreteBuilder : public Builder {
public:
    void buildPartA() override {
        product_.setPartA("PartA");
    }

    void buildPartB() override {
        product_.setPartB("PartB");
    }

    void buildPartC() override {
        product_.setPartC("PartC");
    }

    Product getResult() override {
        return product_;
    }

private:
    Product product_;
};

class Director {
public:
    Director(Builder* builder) : builder_(builder) {}

    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }

private:
    Builder* builder_;
};

int main() {

    ConcreteBuilder concreteBuilder;

    Director director(&concreteBuilder);

    director.construct();

    Product finalProduct = concreteBuilder.getResult();

    finalProduct.showInfo();

    return 0;
}
