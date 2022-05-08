//
// Created by dimaa on 13.02.2022.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Text {
    int Len;
    char *Ref;

    public:
        Text();
        Text(char *Str);
        ~Text();
        Text &operator=(const Text &);
        void Out();
};

Text::Text() {
    Len = 0;
    Ref = new char[Len];
}

Text::Text(char *Str) {
    Ref = new char[Len = strlen(Str) + 1];
    strcpy_s(Ref, Len, Str);
}

Text::~Text() {
    delete Ref;
}

Text &Text::operator=(const Text &Par) {
    if(this == &Par) return *this;
    else {
        delete Ref;
        Ref = new char[strlen(Par.Ref) + 1];
        strcpy_s(Ref, Len - 1, Par.Ref);
    }

    return *this;
}

void Text::Out() {
    cout << "Out text = " << Ref << endl;
}

int main() {
    Text head((char*)"Text Text"), tail;
    tail = head;
    tail.Out();
}

