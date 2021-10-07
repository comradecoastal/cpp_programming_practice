//
// Created by coastal on 10/7/21.
//

#ifndef DEFAULT_TESTCLASSA_H
#define DEFAULT_TESTCLASSA_H


class TestClassA {
public:

    TestClassA() = default;

    void set_a(int);

    void set_b(int);

    int const get_a();

    int const get_b();

private:
    int a;
    int b;
};

void TestClassA::set_a(int value) {
    b = value;
}

#endif //DEFAULT_TESTCLASSA_H
