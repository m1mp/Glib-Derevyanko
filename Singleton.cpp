#include <iostream>
#include <vector>

class CarShowroom {
private:
    
    CarShowroom() {
    }

    static CarShowroom* instance;

public:
    static CarShowroom* getInstance() {
        if (!instance) {
            instance = new CarShowroom();
        }
        return instance;
    }

    void addCar(const std::string& carModel) {
        cars.push_back(carModel);
    }

    void displayCars() {
        std::cout << "Available Cars in the Showroom:" << std::endl;
        for (const auto& car : cars) {
            std::cout << car << std::endl;
        }
    }

private:
    std::vector<std::string> cars;
};
CarShowroom* CarShowroom::instance = nullptr;

int main() {
    CarShowroom* showroom = CarShowroom::getInstance();

    showroom->addCar("Toyota Camry");
    showroom->addCar("Honda Accord");
    showroom->addCar("Ford Mustang");
    showroom->displayCars();

    return 0;
}
