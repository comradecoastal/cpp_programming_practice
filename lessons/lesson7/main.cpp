#include <iostream>
#include <utility>
#include <vector>

class Human {
public:
    explicit Human(const std::string& name) : name(name) {}
    void greet() {
        std::cout << "Hello, I am human!" << std::endl;
    }

    void set_name(const std::string& new_name) {
        if (new_name[0] >= '0' and new_name[0] <= '9') {
            return;
        }
        this->name = new_name;
    }

    std::string get_name() const {
        return this->name;
    }

protected:
    std::string name;
};

class Student : public Human {
public:
    explicit Student(const std::string& name, unsigned group):
        Human(name), group(group) {}

    void set_name(const std::string& new_name) {
        Human::set_name("Student " + new_name);
    }

    void study() {
        std::cout << this->name << " from "
        << this->group<< ": I am studying" << std::endl;
    }

    void teach() {
        std::cout << "Teaching children in EPTS" << std::endl;
    }
private:
    unsigned group;
};

class Connector {
public:
    auto connect_and_get_result() {
        return 0.;
    }

private:
    std::string ip;
};

class ChartBuilder : private Connector {
public:
    auto get_data_and_build_chart() {
        auto result = connect_and_get_result();
//        this->ip = "10.24.255.255"; PROHIBITED
        std::cout << "Building Charts!" << std::endl;
    }
};

class Unit {
public:
    virtual void move() = 0;
};

class Hero : public Unit {
public:
    explicit Hero(const std::string& name = "") : name(name) {}
    void move() override {
        std::cout << "My name is " << name << " and I am moving" << std::endl;
    }
private:
    std::string name;
};

class Creep : public Unit {
    void move() final {
        std::cout << "I am a creep and i am moving" << std::endl;
    }
};

class Powered_Creep : public Creep {
//    void move() override
};

class Teacher {
public:
    Teacher(std::string department) : department(std::move(department)) {}
    void teach() {
        std::cout << "I am teaching" << std::endl;
    }

private:
    std::string department;
};

class SmallPrep : public Student, public Teacher {
public:
    SmallPrep(const std::string& name, unsigned group, std::string department) :
            Student(name, group), Teacher(std::move(department)) {}
};

int main() {
//    Student denis("Old_denis", 831u);
//    denis.study();
//    denis.set_name("Denis");
//    denis.study();

//    Hero faceless_void("Faceless Void");
//    Creep radiant_creep;
//    Creep dire_creep;
//    Hero juggernaut("Juggernaut");
//    Hero timbersaw("Timbersaw");
//
//    std::vector<Unit*> units;
//    units.push_back(&faceless_void);
//    units.push_back(&radiant_creep);
//    units.push_back(&dire_creep);
//    units.push_back(&juggernaut);
//    units.push_back(&timbersaw);
//
//    for(auto& unit: units) {
//        unit->move();
//    }
//
//    Hero someHero = *dynamic_cast<Hero*>(units[0]);
//
//    return 0;

    SmallPrep niki("Nikita", 831, "CS");
    niki.study();
    niki.teach();
}
