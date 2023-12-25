// Дерев'янко Гліб ІК-21 Будівельник Лікарня

#include <iostream>
#include <string>


class Doctor {
public:
    std::string specialty;

};

class Nurse {
public:
    int experienceYears;

};

class OperatingRoom {
public:
    bool hasSurgeryEquipment;

};

// Будівельник для лікарні
class HospitalBuilder {
public:
    virtual void buildDoctor() = 0;
    virtual void buildNurse() = 0;
    virtual void buildOperatingRoom() = 0;
    virtual ~HospitalBuilder() = default;
};

class ConcreteHospitalBuilder : public HospitalBuilder {
private:
    Doctor doctor;
    Nurse nurse;
    OperatingRoom operatingRoom;

public:
    void buildDoctor() override {
        doctor.specialty = "Cardiologist";
    }

    void buildNurse() override {

        nurse.experienceYears = 5;
    }

    void buildOperatingRoom() override {

        operatingRoom.hasSurgeryEquipment = true;
    }

    std::string getResult() {
        return "Hospital with " + doctor.specialty + " doctor, "
               + std::to_string(nurse.experienceYears) + " years experienced nurse, and "
               + (operatingRoom.hasSurgeryEquipment ? "equipped" : "not equipped") + " operating room.";
    }
};

class HospitalDirector {
private:
    HospitalBuilder* builder;

public:
    HospitalDirector(HospitalBuilder* builder) : builder(builder) {}

    void construct() {
        builder->buildDoctor();
        builder->buildNurse();
        builder->buildOperatingRoom();
    }
};

int main() {

    ConcreteHospitalBuilder concreteBuilder;

    HospitalDirector director(&concreteBuilder);
    director.construct();

    std::string result = concreteBuilder.getResult();

    std::cout << result << std::endl;

    return 0;
}

