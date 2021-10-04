#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

void N1()
{
    double h, R, r, l;
    cout << "Enter h, R, r to find V and S of your cone: ";
    cin >> h >> R >> r;
    l = pow(pow(R - r, 2.) + pow(h, 2.), 1. / 2.);

    ((r == 0. && R > 0.) || (r > 0. && R == 0.) || (r > 0. && R > 0.)) && (r != R) && (h >= 0) ? cout << "V = " << 1. / 3. * M_PI * h * (pow(R, 2.) + R * r + pow(r, 2.)) << "\n" << "S = " << M_PI * (pow(R, 2.) + (R + r) * l + pow(r, 2.)) << "\n" : cout << "ERROR!\n";
}

void N2()
{
    double x, a;
    cout << "To find w enter x and a: ";
    cin >> x >> a;

    a >= pow(x, 2.) && (x != 0) ? (abs(x) < 1. ? cout << "w = " << a * log(abs(x)) << "\n" : cout << "w = " << pow(a - pow(x, 2.), 1. / 2.) << "\n") : cout << "ERROR!\n";
}

void N3()
{
    double x, y, b;
    cout << "Enter x, y and b to find z: ";
    cin >> x >> y >> b;

    (b - x >= 0.) && (b - y > 0.) ? cout << "z = " << log(b - y) * pow(b - x, 1. / 2.) << "\n" : cout << "Sorry, you can't count it.\n";
}

void N4()
{
    int n;
    cout << "Enter any number: ";
    cin >> n;

    n > 0 ? (cout << n << " " << n + 1 << " " << n + 2 << " " << n + 3 << " " << n + 4 << " " << n + 5 << " " << n + 6 << " " << n + 7 << " " << n + 8 << " " << n + 9 << " " << "\n") : (cout << "1 2 3 4 5 6 7 8 9 10\n");
}

void N5()
{
    for (double x = -4.; x < 4.; x += 0.5)
    {
        x != 1 ? cout << (pow(x, 2.) - 2. * x + 2.) / (x - 1.) << "\n" : cout << "You can't devide by 0!\n";
    }
}

void doAgain();

int main()
{
    int NUM;
    cout << "Enter any number of exercise u want to see: ";
    cin >> NUM;

    switch (NUM)
    {
    case 1:
        N1();
        doAgain();
        break;
    case 2:
        N2();
        doAgain();
        break;
    case 3:
        N3();
        doAgain();
        break;
    case 4:
        N4();
        doAgain();
        break;
    case 5:
        N5();
        doAgain();
        break;
    default:
        cout << "This number is unavailable!";
        break;
    }

    return 0;
}

void doAgain()
{
    char ans;
    cout << "Would you like to continue? (y/n) ";
    cin >> ans;
    ans == 'y' ? main() : 0;
}
