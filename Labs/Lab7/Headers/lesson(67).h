//
// Created by dimaa on 13.04.2022.
//

#ifndef UNTITLED_LESSON_67_H
#define UNTITLED_LESSON_67_H
#include <iostream>
#include <string>
#include <typeinfo>

class People {
    std::string name;
    std::string surname;
    int age;

    public:

    People(const std::string &name, const std::string &surname, int age) : name(name), surname(surname), age(age) {}

    People() {}

    virtual void Out() {
            std::cout << "People { \nname = " << name
                      << "\nsurname = " << surname
                      << "\nage = " << age << " }" << std::endl;
        }
};

class AbstractPeople {
    virtual void Out() = 0;
};

class Employee : public People, AbstractPeople {
    std::string speciality;

    public:

    Employee(const std::string &name, const std::string &surname, int age, const std::string &speciality) : People(name,
                                                                                                                   surname,
                                                                                                                   age),
                                                                                                            speciality(
                                                                                                                    speciality) {}
    void Out()  {
            std::cout << "Employee { \nspeciality = " << speciality << " }" << std::endl;
        }

};

class Students : public People, AbstractPeople {
    std::string group;
    double average_score;

    public:

    Students(const std::string &name, const std::string &surname, int age, const std::string &group,
             double averageScore) : People(name, surname, age), group(group), average_score(averageScore) {}

    virtual void Out()  {
            std::cout << "Students { \ngroup = " << group
                      << "\naverage_score = " << average_score << " }" << std::endl;
        }
};

void fun_employee(People *pBase) {
    Employee *pDerived = dynamic_cast<Employee *>(pBase);
    if (pDerived) pDerived->Out();
    else std::cout << "Exception (no derived class)" << std::endl;
}

void fun_students(People *pBase) {
    Students *pDerived = dynamic_cast<Students *>(pBase);
    if (pDerived) pDerived->Out();
    else std::cout << "Exception (no derived class)" << std::endl;
}

#endif //UNTITLED_LESSON_67_H
