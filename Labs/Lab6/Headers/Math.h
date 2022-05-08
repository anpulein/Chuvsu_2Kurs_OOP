//
// Created by dimaa on 13.02.2022.
//

#ifndef UNTITLED_MATH_H
#define UNTITLED_MATH_H

#include <complex>
#include <iostream>

class Math {

    public:
        float F;
        int I;
        const int Fix;
        int &Ref;
        std::complex<float> Complex;


//        Math(float f, int i, const int fix, int &ref);
         Math(float re, float im, int fix, int ref): Complex(re, im), Fix(fix), Ref(ref) {};
         Math(float f, int i, int fix, int ref, float re, float im): F(f), I(i), Fix(fix), Ref(ref), Complex(re, im) {};
         Math(const Math &mt): F(mt.F), I(mt.I), Fix(mt.Fix), Ref(mt.Ref), Complex(mt.Complex) {
             std::cout << "Copy constructor works" << std::endl;
         };

         std::complex<float> showComplex();
};

std::complex<float> Math::showComplex() {
    return Math::Complex;
}




//Math::Math(float f, int i, const int fix, int &ref) {
//
//}


#endif //UNTITLED_MATH_H
