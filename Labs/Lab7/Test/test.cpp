//
// Created by dimaa on 13.04.2022.
//
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


class Test {
    protected:
    string name;
    public:
        Test(string str) : name(str){};
        virtual void show() {
            cout << "Name: " << name << endl;
        }


        friend ostream &operator <<(ostream &, const Test &);
};

ostream &operator <<(ostream &out, const Test &test) {
    out << "Test << " << test.name << endl;
    return out;
}

class Test_1 : public Test{
    public:
        int age;

    Test_1(const string &str, int age) : Test(str), age(age) {}
    void show() override {
        cout << "Age: " << age << endl;
    }

};

class Test_2 : public Test{
    public:
        int age;
        Test_2(string str, int a) : Test(str), age(a){};
         void show() override {
            cout << "Age: " << age << endl;
        }
};

//std::ostream &operator <<(std::ostream &out, const Test_2 &test2) {
//    out << "Test2 " << test2.age << std::endl;
//    return out;
//}

//void fun(Test_1 *test1)  {
//    Test_2 *test2 = dynamic_cast<Test_2 *>(test1);
//    if (test2) test2->show();
//    else bad_cast(test1);
//}


int main()
{
    {
//        Test test("Dima");
//        Test_2 test2("Dima", 19);
//        Test &ref_test = test;
//        Test_2 &ref_test2 = test2;
//        try  {
//            Test_2 &test21 = dynamic_cast<Test_2 &>(ref_test);
//        } catch (bad_cast b) {
//            cout << b.what();
//        } catch (exception e) {
//            cout << e.what();
//        }
    }


    Test* base_ptr = new Test_1("Dima", 2);
    base_ptr->show();

    Test_2* der2_ptr = (Test_2*)base_ptr;
    der2_ptr->show();

    Test_1* der1_ptr = dynamic_cast<Test_1*>(reinterpret_cast<Test*>(der2_ptr));
    der1_ptr->show();



}

