#ifndef DEFAULT_SMARTDOUBLEPTR_H
#define DEFAULT_SMARTDOUBLEPTR_H


#include <algorithm>
#include <iostream>

class SmartDoublePtr {
public:
    explicit SmartDoublePtr(double value) {
        pointer = new double(value);
        to_be_deleted = true;
    }

    explicit SmartDoublePtr(double *ptr) {
        pointer = ptr;
        to_be_deleted = false;
    }

    SmartDoublePtr() {
        to_be_deleted = true;
        pointer = new double(0);
    }

    SmartDoublePtr(SmartDoublePtr &smart) = delete;

    SmartDoublePtr(SmartDoublePtr &&smart) noexcept {
        if (this == &smart) return;

//        if (to_be_deleted) delete pointer;
        pointer = smart.pointer;
        smart.pointer = nullptr;
        to_be_deleted = smart.to_be_deleted;
        smart.to_be_deleted = false;
    }

    SmartDoublePtr &operator=(SmartDoublePtr &smart) = delete;

    SmartDoublePtr &operator=(SmartDoublePtr &&smart) noexcept {
        if (this == &smart) return *this;
        if (to_be_deleted) delete pointer;
        pointer = smart.pointer;
        smart.pointer = nullptr;
        to_be_deleted = smart.to_be_deleted;
        smart.to_be_deleted = false;

        return *this;
    }

    // getter
    double getValue() const {
        return *pointer;
    }

    // setter
    void set_value(double value) {
        *pointer = value;
    }

    // get value operator
    friend double &operator*(const SmartDoublePtr &smart) {
        return *smart.pointer;
    }

    // out operator
    friend std::ostream &operator<<(std::ostream &out, const SmartDoublePtr &smart) {
        out << smart.pointer;
        return out;
    }

    ~SmartDoublePtr() {
        if (to_be_deleted) delete pointer;
    }

private:
    double *pointer;
    bool to_be_deleted;
};


#endif //DEFAULT_SMARTDOUBLEPTR_H
