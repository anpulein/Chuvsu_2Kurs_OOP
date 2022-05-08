//
// Created by dimaa on 27.03.2022.
//

#ifndef UNTITLED_LESSON_5_H
#define UNTITLED_LESSON_5_H

class One {
    int one_1, one_2;

public:
    One(int o_1, int o_2):one_1(o_1), one_2(o_2) {};
    int Get() {
        std::cout << "address is object: " << this << ' ';
        return one_1;
    }
};

class Two_1 : public One {
    long two_1;
    public:
        Two_1(int o_1, int o_2): One(o_1, o_2){};
};

class Two_2 : public One {
    char two_2;
    public:
        Two_2(int o_1, int o_2): One(o_1, o_2){};
};

class All: public Two_1, public Two_2 {
    public:
        All(int o_1, int o_2, int o_3, int o_4): Two_1(o_1, o_2), Two_2(o_3, o_4){};
};

#endif //UNTITLED_LESSON_5_H
