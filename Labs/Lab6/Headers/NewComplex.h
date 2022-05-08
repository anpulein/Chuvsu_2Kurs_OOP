//
// Created by dimaa on 13.02.2022.
//

#ifndef UNTITLED_NEWCOMPLEX_H
#define UNTITLED_NEWCOMPLEX_H


#include <iostream>
#include<stddef.h>
#include<malloc.h>


// Глобавльная перегрузка операторов new и delete (Задание 17)
void *operator new(size_t size) {
    std::cout << "Operator new" << "Bite: " << size << std::endl;
    void *m = malloc(size);
    if(!m) std::cout << "Out of memory " << std::endl;
    return m;
}

void operator delete(void *m) {
    std::cout << "Operator delete" << std::endl;
    free(m);
}

class NewComplex {
    private:
        float Im;

    public:
        float Re;
        explicit NewComplex(float re): Re(re) {};
        explicit NewComplex(float re, float im): Re(re), Im(im) {};
        NewComplex *operator->(); // (Задание 16)
        void *operator new(size_t);
        void operator delete(void *);
        void Out();
        float *GetRePtr();
};

NewComplex *NewComplex::operator->() {
    std::cout << "Own operator ->" << std::endl;
}

void *NewComplex::operator new(size_t size) {
    std::cout << "New operation for the class NewComplex, required number of bites: "
    << size << std::endl;
    void *storage = malloc(size);
    if(NULL == storage) {
        std::cout << "Out of memory " << std::endl;
    }

    return storage;
}

void NewComplex::operator delete(void *p) {
    std::cout << "Delete operation for the class NewComplex" << std::endl;
    free(p);
}

void NewComplex::Out() {
    std::cout << "Re: " << this->Re << std::endl
              << "Im: " << this->Im << std::endl;
}

float *NewComplex::GetRePtr() {
    return &Re;
}

#endif //UNTITLED_NEWCOMPLEX_H
