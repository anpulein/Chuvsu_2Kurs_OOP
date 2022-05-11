//
// Created by dimaa on 11.05.2022.
//
#include <iostream>
using namespace std;

template<class T> class Test;
template<class T> ostream &operator<<(ostream &out, Test<T> &t) {
    out << t.getNumber();
    return out;
}

template<class T> class Test {
    T number;
public:
    static T number_st;
    Test(T number) : number(number) {}

    T getNumber() const {
        return number;
    }

    void setNumber(T number) {
        Test::number = number;
    }


    friend ostream &operator<< <>(ostream &out, Test &t);

     T operator+(T num) {
      return this->number + num;
    }
};


template<class T> class Base {
    protected:
        T name;

public:
    Base(T name) : name(name) {}

    Base() {}

    T getName() const {
        return name;
    }

    void setName(T name) {
        Base::name = name;
    }

    virtual void Out() {
        cout << "Base" << name << endl;
    }
};

template<class T1, class T2> class Derived : public Base<T1> {
    T2 age;
public:
    Derived(T1 name, T2 age) : Base<T1>(name), age(age) {}

    T2 getAge() const {
        return age;
    }

    void setAge(T2 age) {
        Derived::age = age;
    }

    void getName() {
        cout << "Dev = " << Base<T1>::name << endl;
    }

    void Out() override {
        cout << "Divered - " << age << endl;
    }
};



void fun(Base<string> *pBase_1) {
    Base<string> *pBase = new Base<string>();
    pBase = pBase_1;
    auto res = dynamic_cast<Derived<string, int>*>(pBase);
    if (res) res->Out();
    else cout << "Передан объект не производного типа" << endl;
}

template<class T> T Test<T>::number_st = 3;

int main() {
    Test<int> t(1);
    cout << "Number = " << t.getNumber() << endl;
    t.setNumber(2);
    cout << "Number = " << t.getNumber() << endl;

    cout << "Friend = " << t << endl;
    cout << "Sum = " << t + 1 << endl;

    Derived<string, int> direved("Dima", 19);
    direved.getName();

    Base<string> b("Dima");
    Derived<string, int> d ("Dima", 19);
    fun(&b);
    fun(&d);


}

