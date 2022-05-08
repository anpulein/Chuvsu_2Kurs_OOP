//
// Created by dimaa on 16.02.2022.
//

#include <iostream>
using namespace std;

struct Test{
    int a;
    float b;
};

class Family{
    private:


    public:
        int number;
    Family(int a) {
        number = a;
    }
        Family(const Family &family): number(family.number) {
        cout << "Copy Construct " << endl;
    };

         void show() {
            cout << "number = " << number;
        }

};


void print(Family family) {
    cout << family.number;
}

Family print_1(Family family) {
    return family;
}

int main() {
    Family family(1);
//    Family family1 = family;
//    Family family2(family1);
//    print(family1);
    Family family3 = print_1(family);
    family3.show();

//
//    Family famil1;
//    famil1.show();




}