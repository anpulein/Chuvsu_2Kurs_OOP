//
// Created by dimaa on 12.02.2022.
//

#include <iostream>
#include "Headers/Family.h"
#include "Headers/Math.h"
#include "Headers/NewComplex.h"
using namespace std;

void showFamily();
void showMath();
void showComplex();
void showComplexPtr();

int main() {

    showFamily();
    showMath();
    showComplex();
    showComplexPtr();

}


void showFamily() {
    Family me;
    me.setSurName("Galkin");
    me.setName("Dmitry");
    me.setPatronymic("Sergeyevich");
    me.setAge(19);
    me.setSex("Male");
    me.setStatus("Student");

    cout << "{\n" << "\tFullName: " << me.getFullName()
         << ",\n" << "\tAge: " << me.getAge()
         << ",\n" << "\tSex: " << me.isSex()
         << ",\n" << "\tStatus: " << me.getStatus() << "\n}" << endl;

    cout << "-------------------------------------------" << endl;
}

void showMath() {
    Math math(0.5, 1, 5, 7, 5.4, 6.1);
    Math math1(math); // Срабатывает копирующий конструктор

    cout << "Math(complex) = " << math.showComplex() << endl;
    cout << "Math1(complex) = " << math1.showComplex() << endl;

    cout << "-------------------------------------------" << endl;
}

void showComplex() {
    NewComplex newComplex(1.2, 0.6);
    newComplex->Out();

    NewComplex *ptr_newComplex_1 = new NewComplex(1.7, 2.9);
    ptr_newComplex_1->Out();
    delete ptr_newComplex_1;
    cout << "......................................" << endl;
    NewComplex *ptr_newComplex_2 = ::new NewComplex(1.7, 2.9); // Глобальный вызов
    ptr_newComplex_2->Out();
    delete ptr_newComplex_2;

    cout << "-------------------------------------------" << endl;
}

float NewComplex::*ptr_NewComplex = &NewComplex::Re;
float *(NewComplex::*Ptr_GetRePtr)() = &NewComplex::GetRePtr;
void (NewComplex::*Ptr_OutPtr)() = &NewComplex::Out;

void showComplexPtr() {
    NewComplex num(1.5, 1.5);
    num.Re = 6.8;
    // Объект класса
    cout << "The usual way: " << num.Re << endl;
    cout << "Component pointer: " << num.*ptr_NewComplex << endl;
    // Указатель на объект типа NewComplex
    NewComplex *Ptr_NewComplex = &num;
    Ptr_NewComplex->Re = 7.1;
    cout << "The usual way pointer obj: " << Ptr_NewComplex->Re << endl;
    cout << "Component pointer: " << Ptr_NewComplex->*ptr_NewComplex << endl;

    cout << "......................................" << endl;

    NewComplex newComplex(1.5, 7.8);
    cout << "Through class object: " << *(newComplex.*Ptr_GetRePtr)() << endl;
    NewComplex *ptr_newCommplex = &newComplex;
    cout << "Pointer: " << *(ptr_newCommplex->*Ptr_GetRePtr)() << endl;

    (newComplex.*Ptr_OutPtr)();
    (ptr_newCommplex->*Ptr_OutPtr)();

    cout << "-------------------------------------------" << endl;
}