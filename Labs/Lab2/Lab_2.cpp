#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int count;

double arctg (double x, double e) {
    double y = M_PI / 2, a = 1;
    int n = 0;
    count = 0;
    double localX;
    do {
        localX = exp(log(x) * (2 * n + 1));
//        localX = pow(x, 2 * n + 1);
        if(count % 2 == 0) {
            a = -1 / ((2 * n + 1) * localX);
        } else {
            a = 1 / ((2 * n + 1) * localX);
        }
        y += a;
        count++;
        n++;
    } while(fabs(a) > e);
    return y;
}

int main() {

    system("chcp 65001");
    double STX, ENX;
    double dx;
    double e;
    goto label;
    label: e = 0.5;

    cout << "Введите начальное значение интервала STX: "; cin >> STX;
    cout << "Введите конечное значение интервала ENX: "; cin >> ENX;
    cout << "Введите шаг dx: "; cin >> dx;
    cout << "Введите погрешность eps: "; cin >> e;

    cout << '|' << setw(3) << 'x' << setw(3) << '|' << setw(12) << "arctg(x)"
    << setw(5) << '|' << setw(12) << "atan(x)" << setw(5) << '|' << setw(3) << 'n' << setw(3) << '|' << endl;

    for(double x = STX; x <= ENX; x += dx) {
        double y = arctg(x, e);
        cout << '|' << setw(3) << x << setw(3) << '|' << setw(12) << y
             << setw(5) << '|' << setw(12) << atan(x) << setw(5) << '|' << setw(3) << count << setw(3) << '|' << endl;
    }


}