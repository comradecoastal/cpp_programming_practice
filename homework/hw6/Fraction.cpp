//
// Created by coastal on 10/14/21.
//

#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

// из второго задания
std::vector<std::string> split(const std::string &line, char splitChar = ' ');

std::ostream &operator<<(std::ostream &out, Fraction frac) {
    if (frac.denominator != 1) {
        out << frac.numerator << '/' << frac.denominator;
    } else {
        out << frac.numerator;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &frac) {
    /**
     * Input numerator and denominator as fraction "12/3", "-2/3"
     */
    std::string input;
    in >> input;
    std::vector<std::string> new_input = split(input, '/');

    if (new_input.size() == 2) {
        std::stringstream stream;
        stream << new_input.at(0) << " " << new_input.at(1);
//        std::cout << new_input.at(0) << " " << new_input.at(1) << std::endl;
        int num;
        unsigned den;
        stream >> num >> den;
//        std::cout << num << " " << den << std::endl;
        frac = Fraction(num, den);
        return in;
    }
    frac = Fraction();
    return in;
}

void Fraction::set_numerator(int num) {
    numerator = num;
    simplify();
}

void Fraction::set_denominator(unsigned int den) {
    if (den == 0) return;
    denominator = den;
    simplify();
}

int Fraction::get_numerator() const {
    return numerator;
}

unsigned Fraction::get_denominator() const {
    return denominator;
}

//double Fraction::to_double() const {
//    return double(numerator) / denominator;
//}

Fraction operator+(Fraction a, Fraction b) {
    return {static_cast<int>(a.numerator * b.denominator + b.numerator * a.denominator), a.denominator * b.denominator};
}

Fraction operator-(Fraction a, Fraction b) {
    return {static_cast<int>(a.numerator * b.denominator - b.numerator * a.denominator), a.denominator * b.denominator};
}

Fraction operator*(Fraction a, Fraction b) {
    return {a.numerator * b.numerator, a.denominator * b.denominator};
}

Fraction operator/(Fraction a, Fraction b) {
    int sign;
    sign = (b.numerator > 0) ? 1 : -1;
    if (b.numerator == 0) {
        std::cout << "Can't divide by 0!" << std::endl;
        return {};
    }
    return {static_cast<int>(a.numerator * b.denominator * sign), a.denominator * abs(b.numerator)};
}

bool operator==(Fraction a, Fraction b) {
    return (a.numerator == b.numerator) && (a.denominator = b.denominator);
}

bool operator!=(Fraction a, Fraction b) {
    return (a.numerator != b.numerator) || (a.denominator != b.denominator);
}

bool operator<(Fraction a, Fraction b) {
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator<=(Fraction a, Fraction b) {
    return a.numerator * b.denominator <= b.numerator * a.denominator;
}

bool operator>(Fraction a, Fraction b) {
    return a.numerator * b.denominator > b.numerator * a.denominator;
}

bool operator>=(Fraction a, Fraction b) {
    return a.numerator * b.denominator >= b.numerator * a.denominator;
}

Fraction &Fraction::operator++() {
    numerator += int(denominator);
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= int(denominator);
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    numerator += int(denominator);
    return temp;
}

Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    numerator -= int(denominator);
    return temp;
}

Fraction &Fraction::operator=(Fraction frac) {
    numerator = frac.numerator;
    denominator = frac.denominator;
    return *this;
}

Fraction::operator double() const {
    return double(numerator) / denominator;
}

std::vector<std::string> split(const std::string &line, char splitChar) {
    /**
     * Function splits a sting into a vector of strings along specified character
     *
     * @param line string that is being split
     * @param spitChar character to be split along
     * @return vector of strings
     */

    std::vector<std::string> array; // output vector
    std::string tmpString;
    int pos = 0;
    int posNew; // position variables
    int len = line.size(); // length of input string

    // cycle breaks when no more ' ' is found (posNew == -1)
    while (pos > -1) {
        posNew = line.find(splitChar, pos); // search for ' ' starting from pos position
//        std::cout << posNew << std::endl;
        if (posNew != -1) { // test if ' ' was found
            tmpString = line.substr(pos, posNew - pos);
            pos = posNew + 1; // pos is now put after the ' ' that has been found
        } else {
            tmpString = line.substr(pos, len - pos);
            pos = -1; // condition to exit cycle
        }

        // test that tmpString is not empty
        if (tmpString.length() > 0) {
            array.push_back(tmpString);
        }

    }

    return array;
}

