#include <iostream>

class SmartDoublePtr {
public:

    // constructors
    explicit SmartDoublePtr(double value) {
        pointer = new double(value);
        to_be_deleted = true;
    }

    explicit SmartDoublePtr(double *value) {
        pointer = value;
        to_be_deleted = false;
    }

    SmartDoublePtr() {
        pointer = new double(0);
        to_be_deleted = true;
    }

    SmartDoublePtr(SmartDoublePtr const &smart) {
        pointer = new double(*smart.pointer);
        to_be_deleted = true;
    }

    // get value
    double getValue() const {
        return *pointer;
    }

    // get value operator
    friend double operator*(const SmartDoublePtr &smart) {
        return *smart.pointer;
    }

    // out operator
    friend std::ostream &operator<<(std::ostream &out, const SmartDoublePtr &smart) {
        out << smart.pointer;
        return out;
    }

    // destructor
    ~SmartDoublePtr() {
        if (to_be_deleted) {
            delete pointer;
        }
    }

//    ~SmartDoublePtr() = default;

private:
    double *pointer;
    bool to_be_deleted;
};


int main() {
    SmartDoublePtr a(2);
    double b = 9.9;
    SmartDoublePtr c(&b);

    SmartDoublePtr e = a;

    std::cout << e << std::endl;
    std::cout << a << " " << c << " " << e << std::endl;
    std::cout << a.getValue() << " " << (*c) << std::endl;
}
