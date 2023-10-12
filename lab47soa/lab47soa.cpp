#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double taylorSeries(double x, double eps, int& n) {
    double term = x, sum = x;
    n = 1;
    while (abs(term) > eps) {
        term *= -x * x / (2 * n * (2 * n + 1));
        sum += term;
        ++n;
    }
    return sum;
}

int main() {
    double xp, xk, dx, eps;
    cout << "Введіть значення xp: ";
    cin >> xp;
    cout << "Введіть значення xk: ";
    cin >> xk;
    cout << "Введіть значення dx: ";
    cin >> dx;
    cout << "Введіть значення eps: ";
    cin >> eps;

    cout << setw(10) << "x" << setw(10) << "atan(x)" << setw(10) << "Ряд Тейлора" << setw(10) << "n" << '\n';
    for (double x = xp; x <= xk; x += dx) {
        int n;
        double taylor = taylorSeries(x, eps, n);
        cout << setw(10) << x << setw(10) << atan(x) << setw(10) << taylor << setw(10) << n << '\n';
    }

    return 0;
}