//
// Created by coastal on 10/7/21.
//

#ifndef DEFAULT_LENGTH_H
#define DEFAULT_LENGTH_H

#include <iostream>

static const double INCH_TO_MM = 25.4;
static const double METER_TO_MM = 10e3;
static const double FOOT_TO_MM = 304.8;
static const double CM_TO_MM = 10;
static const double YARD_TO_MM = 914.4;

enum class LengthUnit {
    M_METER,
    INCH,
    METER,
    YARD,
    FOOT,
    C_METER,
};

class Length {
public:
    // empty constructor
    Length(): mode(LengthUnit::M_METER), value(0) {};

    // value for mm constructor
    explicit Length(double new_value): mode(LengthUnit::M_METER), value(new_value) {};

    // unit constructor
    explicit Length(LengthUnit new_mode) : mode(new_mode), value(0) {};

    // unit and value constructor
    Length(double new_value, LengthUnit new_mode);

    // copy constructor
    Length(Length const &another) = default;

    // length mode
    void set_to_millimeter();
    void set_to_inch();
    void set_to_yard();
    void set_to_meter();
    void set_to_centimeter();
    void set_to_foot();

    void set_mode(LengthUnit unit);

    // output
    double get_value() const;

    // input
    void set_value(double);

    // addition and subtraction
    friend Length operator + (Length a, Length b);
    friend Length operator - (Length a, Length b);

    // output, input operators
    friend std::ostream& operator << (std::ostream& out, Length length);

    friend std::istream& operator >> (std::istream& in, Length length);

private:
    LengthUnit mode;
    double value; // stored in millimeters
};


#endif //DEFAULT_LENGTH_H
