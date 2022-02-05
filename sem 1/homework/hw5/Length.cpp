//
// Created by coastal on 10/7/21.
//

#include "Length.h"

void Length::set_to_inch() {
    mode = LengthUnit::INCH;
}

void Length::set_to_millimeter() {
    mode = LengthUnit::M_METER;
}

void Length::set_to_yard() {
    mode = LengthUnit::YARD;
}

void Length::set_to_centimeter() {
    mode = LengthUnit::C_METER;
}

void Length::set_to_foot() {
    mode = LengthUnit::FOOT;
}

void Length::set_to_meter() {
    mode = LengthUnit::METER;
}


double Length::get_value() const {
    switch (mode) {
        case LengthUnit::M_METER:
            return value;
        case LengthUnit::INCH:
            return value / INCH_TO_MM;
        case LengthUnit::METER:
            return value / METER_TO_MM;
        case LengthUnit::FOOT:
            return value / FOOT_TO_MM;
        case LengthUnit::C_METER:
            return value / CM_TO_MM;
        case LengthUnit::YARD:
            return value / YARD_TO_MM;
    }
    return 0;
}

void Length::set_value(double new_value) {
    switch (mode) {
        case LengthUnit::M_METER:
            value = new_value;
            break;
        case LengthUnit::INCH:
            value = new_value * INCH_TO_MM;
            break;
        case LengthUnit::METER:
            value = new_value * METER_TO_MM;
            break;
        case LengthUnit::FOOT:
            value = new_value * FOOT_TO_MM;
            break;
        case LengthUnit::C_METER:
            value = new_value * CM_TO_MM;
            break;
        case LengthUnit::YARD:
            value = new_value * YARD_TO_MM;
            break;
    }
}

Length::Length(double new_value, LengthUnit new_mode) : mode(new_mode) {
    set_value(new_value);
}

std::ostream &operator<<(std::ostream &out, Length length) {
    out << length.get_value();
    switch (length.mode) {
        case LengthUnit::M_METER:
            out << "mm";
            break;
        case LengthUnit::INCH:
            out << '"';
            break;
        case LengthUnit::METER:
            out << "m";
            break;
        case LengthUnit::FOOT:
            out << "'";
            break;
        case LengthUnit::C_METER:
            out << "cm";
            break;
        case LengthUnit::YARD:
            out << "yd";
            break;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Length length) {
    double new_value;
    in >> new_value;
    length.set_value(new_value);
    return in;
}

Length operator+(Length a, Length b) {
    Length c(a);
    c.value += b.value;
    return c;
}

Length operator-(Length a, Length b) {
    Length c(a);
    c.value -= b.value;
    return c;
}

void Length::set_mode(LengthUnit unit) {
    mode = unit;
}




