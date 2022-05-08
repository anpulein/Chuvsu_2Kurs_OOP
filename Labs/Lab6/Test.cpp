//
// Created by dimaa on 13.02.2022.
//

#include <iostream>
using namespace std;

class Test {
    int test;

    public:
        Test();
        Test(int tst);

        friend Test &operator++(Test &);
        friend Test operator++(Test &tst1, int);
        friend istream &operator>>(istream &, const Test &);
        friend ostream &operator<<(ostream &, const Test &);

        Test operator+(const Test &tst);
};


Test::Test(int tst) {
    Test::test = tst;
}

Test &operator++(Test &tst) {
    ++tst.test;
    return tst;
}

Test operator++(Test &tst, int) {
    tst.test++;
    return tst;
}

ostream &operator<<(ostream &out, const Test &tst) {
    out << "Message: " << tst.test << endl;
}

istream &operator>>(istream &in, const Test &tst) {
    in >> tst.test;
}


Test Test::operator+(const Test &tst) {
    return this->test + tst.test;
}

