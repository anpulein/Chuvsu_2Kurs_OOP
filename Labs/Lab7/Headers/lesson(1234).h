//
// Created by dimaa on 27.03.2022.
//

#ifndef UNTITLED_LESSON_1234_H
#define UNTITLED_LESSON_1234_H

#include <iostream>
#include <string>
#include <sstream>

class Base {
    protected:
        std::string word;
public:
    static std::string stat_word;
    const int a = 1; // Обязательная инициализация
    int b = 2;
    int &st_b = b;

    Base(std::string word) {
        std::cout << "Start construct Base" << std::endl;
        this->word = word;
    }

    void show() {
        std::cout << "Word: " << word << std::endl;
    }

    friend std::ostream &operator <<(std::ostream &, const Base &);

    ~Base() {
        std::cout << "End Base" << std::endl;
    }

};


std::ostream &operator <<(std::ostream &out, const Base &b) {
    out << "Func friend Base: " << b.word << std::endl;
    return out;
}



class Derived: Base {

public:

    int count_word_in_line;

    Derived(std::string word): Base(word) {
        std::cout << "Start construct Derived" << std::endl;
        std::stringstream stream(word);
        std::string oneWord;
        count_word_in_line = 0;

        while (stream >> oneWord) {++count_word_in_line;}
    }

    void show() {
        Base::show();
        std::cout << "Count words: " << count_word_in_line << std::endl << std::endl;
    }

    static void getStatWord() {
        std::cout << stat_word << std::endl;
    }

    static void setStatWord(std::string str) {
        stat_word = str;
    }

    void getA() {
        std::cout << a << std::endl;
    }

    void getSt_b() {
        std::cout << st_b << std::endl;
    }

    ~Derived() {
        std::cout << "End Derived" << std::endl;
    }
};

std::ostream &operator <<(std::ostream &out, const Derived &d) {
    out << "Func friend Derived: " << d.count_word_in_line << std::endl;
    return out;
}

class Derived_public: public Base {
    int count_word_in_line;

public:
    Derived_public(std::string word): Base(word) {
        std::stringstream stream(word);
        std::string oneWord;
        count_word_in_line = 0;

        while (stream >> oneWord) {++count_word_in_line;}
    }

    void show() {
        std::cout << "\t Derived (public)" << std::endl;
        Base::show();
        std::cout << "Count words: " << count_word_in_line << std::endl << std::endl;
    }
};

class Derived_protected: protected Base {
    int count_word_in_line;

public:
    Derived_protected(std::string word): Base(word) {
        std::stringstream stream(word);
        std::string oneWord;
        count_word_in_line = 0;

        while (stream >> oneWord) {++count_word_in_line;}
    }

    void show() {
        std::cout << "\t Derived (protected)" << std::endl;
        std::cout << "Word: " << word << std::endl; // Если поле в области protected, или если поле private
                                       // Base::show()
        std::cout << "Count words: " << count_word_in_line << std::endl << std::endl;
    }
};

class Derived_private: private Base {
    int count_word_in_line;

public:
    Derived_private(std::string word): Base(word) {
        std::stringstream stream(word);
        std::string oneWord;
        count_word_in_line = 0;

        while (stream >> oneWord) {++count_word_in_line;}
    }

    void show() {
        std::cout << "\t Derived (private)" << std::endl;
        std::cout << "Word (private): " << word << std::endl; // только если поле в области protected
        Base::show();
        std::cout << "Count words: " << count_word_in_line << std::endl << std::endl;
    }
};


#endif //UNTITLED_LESSON_1234_H
