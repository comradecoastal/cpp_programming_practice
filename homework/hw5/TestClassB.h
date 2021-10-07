//
// Created by coastal on 10/7/21.
//

#ifndef DEFAULT_TESTCLASSB_H
#define DEFAULT_TESTCLASSB_H


class TestClassB {
public:

    TestClassB() = default;

    void set_a(int);

    void set_b(int);

    int const get_a();

    int const get_b();

private:
    int a;
    int b;
};


#endif //DEFAULT_TESTCLASSB_H
