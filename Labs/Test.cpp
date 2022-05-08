#include <iostream>
using namespace std;

const int competition_count = 5;

class cat {
private:
    string name;
    string color;
    int competition[competition_count] = {0};
    int prestige = 5;
public:
    cat() {
        name = "no_cat";
        color = "no_color";
    }

    cat(string na, string co, int n) : name(na), color(co), prestige(n) {}

    cat(const cat &kitty) : name(kitty.name), color(kitty.color), prestige(kitty.prestige) {
        for (int i = 0; i < competition_count; i++)competition[i] = kitty.competition[i];
    }


    int &operator[](int i);

    cat& operator+(const cat &kitty);


    friend ostream &operator<<(ostream &out, const cat &kitty);

    friend istream &operator>>(istream &in, cat &kitty);
};

cat& cat::operator+(const cat& kitty) {
    name.append(" и ");
    name.append(kitty.name);
    color.append(" и ");
    color.append(kitty.color);
    for (int i = 0; i < competition_count; i++) {
        competition[i] = (competition[i] + kitty.competition[i]) / 2;
    }
    prestige = (prestige + kitty.prestige) / 2;
    return *this;
}

cat& (cat::*cat_ptr) (const cat&) = &cat::operator+;

int main() {

    cat Masya("Masya", "orange", 4);
    cat Jora("Jora", "black", 5);

    cout << Masya->*cat_ptr(Jora);
}