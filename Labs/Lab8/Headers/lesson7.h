//
// Created by dimaa on 11.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_LESSON7_H
#define CHUVSU_2KURS_OOP_LESSON7_H
#include <string>
using namespace std;

class Person {
    private:
        string name;
        int age;
        int price;

public:
    Person(const string &name, int age, int price) : name(name), age(age), price(price) {}

    bool operator==(const Person &rhs) const {
        return name == rhs.name;
    }

    bool operator!=(const Person &rhs) const {
        return !(rhs == *this);
    }


};

class Student {
    private:
        string name;
        int age;
        int exchange;

public:
    Student(const string &name, int age, int exchange) : name(name), age(age), exchange(exchange) {}

    bool operator==(const Student &rhs) const {
        return name == rhs.name;
    }

    bool operator!=(const Student &rhs) const {
        return !(rhs == *this);
    }


};

#endif //CHUVSU_2KURS_OOP_LESSON7_H
