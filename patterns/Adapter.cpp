#include <iostream>

// Це інтерфейс, який ми хочемо використовувати
class Target {
public:
    virtual void request() = 0;
};

// Це клас, який ми хочемо адаптувати
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Specific request" << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() override {
        adaptee->specificRequest();
    }
};

class Client {
public:
    void makeRequest(Target* target) {
        target->request();
    }
};

int main() {

    Adaptee adaptee;

    Adapter adapter(&adaptee);

    Client client;
    client.makeRequest(&adapter);

    return 0;
}
