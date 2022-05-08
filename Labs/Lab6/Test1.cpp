//
// Created by dimaa on 13.02.2022.
//
#include <iostream>
using namespace std;

class Test2; // Прототип класса Test2
class Test1 {

    int name;

    public:
        Test1(int val) {
            name = val;
        }

        void func(Test2);
        friend class Test2;


};



class Test2 {

    Test1 tst1;

    public:
        friend void Test1::func(Test2);
        void fun_1();
        void fun_2();
};

