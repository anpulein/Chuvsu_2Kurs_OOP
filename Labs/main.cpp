// лаба 9

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;

struct Bit
{
    string a = ""; // для удобного вывода позиции бит
    int b = 0; // хранит число
};


istream& operator>> (istream& out, Bit& obj) //принимает перегруженный поток cin и само число (его адрес)
{
    out >> obj.a;//в поток ввода записывает число введенное
    return out;//возвращает поток
}

ostream& operator<< (ostream& out, Bit& obj)
{
    out << obj.a;
    return out;
}

// 6
int* sumator(int a, int b, bool p0, char znak) {
    int* ret = NULL;
    if (znak == '+') {
        ret = new int[2];
        if (p0) a++;
        if (a + b >= 9) {
            ret[0] = 1;
            ret[1] = a + b - 9;
        }
        else {
            ret[0] = 0;
            ret[1] = a + b;
        }
    }
    if (znak == '-') {
        ret = new int[2];
        if (p0) b++;
        if (a < b) {
            ret[0] = 1;
            ret[1] = a + 9 - b;
        }
        else {
            ret[0] = 0;
            ret[1] = a - b;
        }
    }
    return ret;
}

// 9
Bit ne(Bit b) {
    for (int i = 0; i < b.a.size(); i++) {
        // 1 -> 9, 2 -> 8, ...
        b.a[i] = 10 - (b.a[i] - '0') + '0';
    }
    return b;
}

Bit i(Bit b1, Bit b2) {  // минимальное по разрядно
    Bit res;
    for (int i = 0; i < min(b1.a.size(), b2.a.size()); i++) {
        char raz = min(b1.a[b1.a.size() - 1 - i], b2.a[b2.a.size() - 1 - i]);
        res.a.push_back(raz);
    }
    return res;
}


Bit ili(Bit b1, Bit b2) {  // максимальное по разрядно
    Bit res;
    for (int i = 0; i < max(b1.a.size(), b2.a.size()); i++) {
        char raz;
        if (b1.a.size() <= i) {
            raz = b2.a[b2.a.size() - 1 - i];
        }
        else if (b2.a.size() <= i) {
            raz = b1.a[b1.a.size() - 1 - i];
        }
        else {
            raz = max(b1.a[b1.a.size() - 1 - i], b2.a[b2.a.size() - 1 - i]);
        }
        res.a.push_back(raz);
    }
    return res;
}
Bit levo(Bit b, int n) {
    while (n > 0) {
        b.a.push_back(b.a[0]);  // ставим в конец
        b.a.erase(b.a.begin());  // удаляем из начала
        n--;
    }
    return b;
}
Bit pravo(Bit b, int n) {
    while (n > 0) {
        b.a.insert(b.a.begin(), b.a[b.a.size() - 1]);  // ставим в начало
        b.a.pop_back();  // удаляем в конце
        n--;
    }
    return b;
}

int main()
{
    Bit s;
    cout << "9. logicheskii operasii" << endl;

    Bit b1, b2;
    cout << "Vvedite chislo v 9, b1: ";
    cin >> b1;
    cout << "Vvedite chislo v 9, b2: ";
    cin >> b2;
    cout << "ne b1:" << ne(b1).a << endl;
    cout << "b1 i b2:" << i(b1, b2).a << endl;
    cout << "b1 ili b2:" << ili(b1, b2).a << endl;
    cout << "b1 v levo na 2: " << levo(b1, 2).a << endl;
    cout << "b1 v pravo na 2: " << pravo(b1, 2).a << endl;

    return 0;
}


