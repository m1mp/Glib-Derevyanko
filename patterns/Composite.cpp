#include <iostream>
#include <vector>

class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        for (const auto& child : children) {
            child->operation();
        }
    }

    ~Composite() override {
        for (auto& child : children) {
            delete child;
        }
    }
};

int main() {

    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();
    Leaf* leaf3 = new Leaf();
    Composite* composite = new Composite();

    composite->add(leaf1);
    composite->add(leaf2);

    Composite* composite2 = new Composite();
    composite2->add(leaf3);

    composite->add(composite2);

    leaf1->operation();  
    composite->operation();  
    delete composite;

    return 0;
}
