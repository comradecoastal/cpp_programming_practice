#ifndef DEFAULT_FRACTION_H
#define DEFAULT_FRACTION_H

#include <iostream>


class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int val) : numerator(val), denominator(1) {}

    Fraction(int num, unsigned den) : numerator(num), denominator(den) { simplify(); }

    Fraction(Fraction const &another) = default;

    // setters
    void set_numerator(int num);

    void set_denominator(unsigned den);

    // getters
    int get_numerator() const;

    unsigned get_denominator() const;

    // conversion to double
//    double to_double() const;

    // conversion operator

    explicit operator double() const;

    // = operator
    Fraction &operator=(Fraction frac);

    // output and input operator
    friend std::ostream &operator<<(std::ostream &out, Fraction frac);

    friend std::istream &operator>>(std::istream &in, Fraction &frac);

    // arithmetic operators
    friend Fraction operator+(Fraction a, Fraction b);

    friend Fraction operator-(Fraction a, Fraction b);

    friend Fraction operator*(Fraction a, Fraction b);

    friend Fraction operator/(Fraction a, Fraction b);

    // increment and decrement
    Fraction &operator++();

    Fraction &operator--();

    Fraction operator++(int);

    Fraction operator--(int);

    // boolean operators
    friend bool operator==(Fraction a, Fraction b);

    friend bool operator!=(Fraction a, Fraction b);

    friend bool operator<(Fraction a, Fraction b);

    friend bool operator<=(Fraction a, Fraction b);

    friend bool operator>(Fraction a, Fraction b);

    friend bool operator>=(Fraction a, Fraction b);

private:
    // reduce fraction. this function is called after every operation
    void simplify() {
        int divisor = abs(gcd(numerator, denominator));
        if (divisor == 1) return;
        else {
            numerator /= divisor;
            denominator /= divisor;
        }
        simplify();
    }

    // euclid algorithm
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        else return gcd(b, a % b);
    }

    int numerator;
    unsigned denominator;

};


#endif //DEFAULT_FRACTION_H
