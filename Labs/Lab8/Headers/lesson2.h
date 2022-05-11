//
// Created by dimaa on 10.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_LESSON2_H
#define CHUVSU_2KURS_OOP_LESSON2_H
#include <iostream>
#include <utility>
using namespace std;

template<class Type> class Char {
    private:
        char ch;
        int number;

    public:
        static int age;
        Char(Type ch, int number) : ch(ch), number(number) {}

        char getCh() const {
            return ch;
        }

        void setCh(char ch) {
            Char::ch = ch;
        }

        int getNumber() const {
            return number;
        }

        void setNumber(int number) {
            Char::number = number;
        }

        virtual void Out();

        void plusAge() {
            age++;
        }

        static void plus() {
            cout << "plus Base";
        }

        friend ofstream &operator<<(ofstream &out, const Char<Type> &);
};

template<class Type> ofstream &operator<<(ofstream &out, const Char<Type> &ch) {
    out << ch.ch << endl;
    return out;
}


template<class Type> void Char<Type>::Out() {
    cout << "Template base: " << ch << endl;
}

template<class Type_1, class Type_2> class String : public Char<Type_1> {
    private:
        char str[15];

    public:
        String(char ch, int number, char str[]) : Char<Type_1>(ch, number) {
            for (int i = 0; i < 15; ++i) {
                this->str[i] = str[i];
            }
        }
        void Out();

        static void plus() {
            cout << "plus Derived";
        }
};

template<class Type_1, class Type_2> ofstream &operator<<(ofstream &out, const String<Type_1, Type_2> &ch) {
    out << ch.ch << endl;
    return out;
}


template<class Type_1, class  Type_2> void String<Type_1, Type_2>::Out() {
    Char<Type_1>::Out();
    cout << "Template derived: " << str << endl;
}

#endif //CHUVSU_2KURS_OOP_LESSON2_H
