//
// Created by dimaa on 16.03.2022.
//
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

#include "Headers/lesson(1234).h"
#include "Headers/Lesson(5).h"
#include "Headers/lesson(67).h"

using namespace std;

void example_show(short i) {
    cout << "/**************************** Example " << i
                            << "****************************/" << endl;
}

std::string Base::stat_word = "a";

int main() {
    {
        example_show(1);

        // Public
        Derived_public derived_public("Hello StarBacks!");
        derived_public.show();

        // Protected
        Derived_protected derived_protected("Hello StarBacks!");
        derived_protected.show();

        // Private
        Derived_private derived_private("Hello StarBacks!");
        derived_private.show();
    }

    {
        cout << endl;
        example_show(2);

        Derived derived("Hello StarBacks!");
    }

    {
        cout << endl;
        example_show(3);
        Derived derived("a");
        cout << "Get from method classes: "; derived.getStatWord();
        derived.setStatWord("b"); // Изменение поля через метод класса
        derived.getA();
        derived.getSt_b();

    }

    {
        cout << endl;
        example_show(4);
        Base base("Hello my");
        Derived derived("Hello my friends");
        cout << base;
        cout << derived;
    }

    {
        cout << endl;
        example_show(5);
        All var(1, 2, 3, 4);

        cout << "meaning 1: " << var.Two_1::Get() << endl;
        cout << "meaning 1: " << var.Two_2::Get() << endl;
    }

    {
        cout << endl;
        example_show(6);
        People *ptr_people;
        AbstractPeople *ptr_abstract_people;

        Employee employee("Dima", "Galkin", 19, "Programmer");
        ptr_people = &employee;
//        ptr_abstract_people = &employee;
        ptr_people->Out();

        Students students("Dima", "Galkin", 19, "ivt-41-20", 4.5);
        ptr_people = &students;
        ptr_people->Out();
    }

    {
        cout << endl;
        example_show(7);
    }

    {
        cout << endl;
        example_show(8);
        People *ptr_people = new People("Dima", "Galkin", 19);
        Employee *ptr_employee = new Employee("Dima", "Galkin", 19, "Programmer");
        Students *ptr_students = new Students("Dima", "Galkin", 19, "ivt-41-21", 4.5);

        fun_employee(ptr_people);
        ptr_people = ptr_employee;
        fun_employee(ptr_people);
        fun_employee(ptr_employee);
        ptr_people = ptr_students;
        fun_students(ptr_people);

    }

    {
        cout << endl;
        example_show(9);

        People ptr_people("Dima", "Galkin", 19);
        Employee ptr_employee("Dima", "Galkin", 19, "Programmer");
        Students ptr_students("Dima", "Galkin", 19, "ivt-41-21", 4.5);

        Employee &employee_ref = ptr_employee;
        People &people_ref = employee_ref;
        dynamic_cast<Employee &>(people_ref).Out();

        Students &students_ref = ptr_students;
        Employee &employee_1ref = reinterpret_cast<Employee &>(students_ref);
        dynamic_cast<Students &>(employee_1ref).Out();
    }
}





