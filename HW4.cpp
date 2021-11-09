#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

string numControl()
{
    string NUM;
    int flag = 1;
    cin >> NUM;
    for (char letter : NUM)
    {
        if (!isdigit(letter) && letter != '-' && letter != '.')
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        return NUM + ' ';
    else
    {
        cout << "Please, enter digit!\n";
        numControl();
    }
}

void N1()
{
    string fileName, fileWay;
    cout << "Enter name of file you want to create: ";
    cin >> fileName;
    cout << "Enter way you want to create your file: ";
    cin >> fileWay;

    ofstream userF(fileWay + fileName + ".txt");

    if (userF.is_open())
    {
        string allNums = "";
        cout << "Enter 10 digits: ";
        for (int i = 0; i < 10; i++)
        {
            allNums += numControl();
        }
        userF << allNums;
    }
    else
        cout << "Oops... Something was wrong!\n";

    userF.close();

    ifstream newUserF(fileWay + fileName + ".txt");

    if (newUserF.is_open())
    {
        string strFromFile;
        string digitForSum = "";
        double summa = 0;
        getline(newUserF, strFromFile);
        for (int k = 0; k < strFromFile.size(); k++)
        {
            if (strFromFile[k] != ' ')
            {
                digitForSum += strFromFile[k];
            }
            else
            {
                summa += stod(digitForSum);
                digitForSum = "";
            }
        }
        cout << summa << endl;
    }
    else
        cout << "Oops... Something was wrong!\n";
}

int signumFunc(double x)
{
    if (x > 0)
        return 1;
    else if (x < 0)
        return -1;
    else
        return 0;
}

void N2()
{
    string usersDigit = numControl();
    cout << signumFunc(stod(usersDigit)) << endl;
}

void triangle()
{
    double A, B, angle;
    cout << "Enter A and B sides and an angle between them: ";
    cin >> A >> B >> angle;

    A > 0 && B > 0 && angle > 0 ? cout << "Your area is - " << 1. / 2. * A * B * sin(angle) << endl : cout << "Your can't use these values!";
}

void square()
{
    double A, B;
    cout << "Enter A and B sides: ";
    cin >> A >> B;

    A > 0 && B > 0 ? cout << "Your area is - " << A * B << endl : cout << "Your can't use these values!";
}

void circle()
{
    double R;
    cout << "Enter radius of your circle: ";
    cin >> R;

    R > 0 ? cout << "Your area is - " << M_PI * pow(R, 2) << endl : cout << "Your can't use these values!";
}

void err()
{
    cout << "Sorry, you can't find area of this shape.\n";
}

void N3()
{
    string ans;
    cout << "What shape area you wanna find? (triangle/square/circle) ";
    cin >> ans;
    ans == "triangle" ? triangle() : ans == "square" ? square() : ans == "circle" ? circle() : err();
}

void N4()
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    int changings[40] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int x = 1;

    for (int l = 0; l < 40; l++)
    {
        int allStars = 0;
        for (double i = 0; i < M_PI * 2.5; i += 0.018)
        {
            int iterator = 0;
            for (int n = 32; n < 302; n++)
            {
                if (n < 50)
                    SetPixel(hdc, x, n + changings[l] * sin(i), RGB(0, 0, 0));
                else if (n >= 50 && n < 176 && i < M_PI)
                {
                    if (x == 6 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 7 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 7 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 8 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 8 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 8 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 9 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 9 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 9 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 9 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 9 + 21 * allStars && n == 68 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 10 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 10 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 11 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 11 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 12 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 12 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 56 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 13 + 21 * allStars && n == 57 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 58 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 59 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 13 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 54 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 14 + 21 * allStars && n == 55 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 56 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 57 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 58 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 59 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 14 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 56 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 15 + 21 * allStars && n == 57 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 58 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 59 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 15 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 16 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 16 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 17 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 63 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 17 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 18 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 62 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 64 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 65 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 66 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 18 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 19 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 19 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 19 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 19 + 21 * allStars && n == 67 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 19 + 21 * allStars && n == 68 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 20 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 20 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 20 + 21 * allStars && n == 61 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 21 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                    }
                    else if (x == 21 + 21 * allStars && n == 60 + 21 * (iterator - 1))
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                    }
                    else if (x == 22 + 21 * allStars && n == 59 + 21 * iterator)
                    {
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                        iterator++;
                        if (allStars < 7)
                            allStars += 1;
                    }
                    else
                        SetPixel(hdc, x, n + changings[l] * sin(i), RGB(0, 0, 130));
                }
                else if (((68 <= n && n < 86) || (104 <= n && n < 122) || (140 <= n && n < 158)) && i >= M_PI || (176 <= n && n < 194) || (212 <= n && n < 230) || (248 <= n && n < 266))
                {
                    SetPixel(hdc, x, n + changings[l] * sin(i), RGB(255, 255, 255));
                }
                else if (n >= 284)
                {
                    SetPixel(hdc, x, n + changings[l] * sin(i), RGB(0, 0, 0));
                }
                else
                {
                    SetPixel(hdc, x, n + changings[l] * sin(i), RGB(147, 0, 0));
                }
            }
            x += 1;
        }
        x = 1;
    }

    ReleaseDC(hwnd, hdc);
    cin.ignore();
}

void N5()
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    int x = 20;
    int iterator = 2;

    for (double i = 0; i < M_PI * 20; i += 0.06)
    {
        SetPixel(hdc, x, 130 - 50 * sin(i), RGB(255, 255, 255));
        SetPixel(hdc, x, 130, RGB(0, 250, 120));
        if (20 <= x && x < 26)
        {
            if (x == 20)
            {
                for (int n = 118; n < 127; n++)
                {
                    SetPixel(hdc, x - 10, n, RGB(0, 250, 120));
                }
                for (int n = 70; n < 180; n++)
                {
                    SetPixel(hdc, x, n, RGB(0, 250, 120));
                }
            }
            else if (21 <= x && x < 25)
            {
                SetPixel(hdc, x - 10, 117, RGB(0, 250, 120));
                SetPixel(hdc, x - 10, 127, RGB(0, 250, 120));
            }
            else if (x == 25)
            {
                for (int n = 118; n < 127; n++)
                {
                    SetPixel(hdc, x - 10, n, RGB(0, 250, 120));
                }
            }
        }
        else if (x == (int)(16.625 * iterator))
        {
            for (int n = 130; n < 138; n++)
            {
                SetPixel(hdc, x, n, RGB(0, 250, 120));
            }
            iterator++;
        }
        x++;
    }

    ReleaseDC(hwnd, hdc);
    cin.ignore();
}

void N6()
{
    string romDigits;
    int flag = 1;
    int newFlag = 0;

    cout << "Enter your Roman numerals here: ";
    cin >> romDigits;

    for (int z = 0; z < romDigits.size(); z++)
    {
        if (romDigits[z] == romDigits[z + 1] && romDigits[z] == romDigits[z + 2] && romDigits[z] == romDigits[z + 3] && romDigits[z] == 'X' && romDigits[z] == 'M' && romDigits[z] == 'C' && romDigits[z] == 'I')
        {
            cout << "ERROR!";
            flag = 0;
            break;
        }
        else if (romDigits[z] == romDigits[z + 1] && romDigits[z] == 'V' && romDigits[z] == 'L' && romDigits[z] == 'D')
        {
            cout << "ERROR!";
            flag = 0;
            break;
        }
        else if (romDigits[z] != 'V' && romDigits[z] != 'L' && romDigits[z] != 'D' && romDigits[z] != 'X' && romDigits[z] != 'M' && romDigits[z] != 'C' && romDigits[z] != 'I')
        {
            cout << "ERROR!";
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i < 4000; i++)
        {
            int l = i;
            string roman = "";
            for (int k = 0; k < (int)(l / 1000); k++)
            {
                roman += 'M';
            }
            l %= 1000;
            if (l - (l % 100) == 900)
            {
                roman += "CM";
                l -= 900;
            }
            for (int k = 0; k < (int)(l / 500); k++)
            {
                roman += 'D';
            }
            l %= 500;
            if (l - (l % 100) == 400)
            {
                roman += "CD";
                l -= 400;
            }
            for (int k = 0; k < (int)(l / 100); k++)
            {
                roman += 'C';
            }
            l %= 100;
            if (l - (l % 10) == 90)
            {
                roman += "XC";
                l -= 90;
            }
            for (int k = 0; k < (int)(l / 50); k++)
            {
                roman += 'L';
            }
            l %= 50;
            if (l - (l % 10) == 40)
            {
                roman += "XL";
                l -= 90;
            }
            for (int k = 0; k < (int)(l / 10); k++)
            {
                roman += 'X';
            }
            l %= 10;
            if (l == 9)
            {
                roman += "IX";
                l -= 9;
            }
            for (int k = 0; k < (int)(l / 5); k++)
            {
                roman += 'V';
            }
            l %= 5;
            if (l == 4)
            {
                roman += "IV";
                l -= 4;
            }
            for (int k = 0; k < (int)(l / 1); k++)
            {
                roman += 'I';
            }
            if (romDigits == roman)
            {
                cout << romDigits << " is " << i << endl;
                newFlag = 1;
                break;
            }
        }
    }
    if (newFlag == 0)
    {
        cout << "This digit is unbelievable!\n";
    }
}

void N7()
{
    int m, b, c;
    int s = 0;
    cout << "Enter m, b and c: ";
    cin >> m >> b >> c;

    if (0 < m && m <= c && c > 0 && 0 < b && b <= c)
    {
        for (int i = 0; i <= b; i++)
        {
            s = (m * s + b) % c;
            cout << s << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "You can't use these digits!\n";
    }
}
string forEight(int f)
{
    for (int i = 0; i < 4000; i++)
    {
        int l = i;
        string roman = "";
        for (int k = 0; k < (int)(l / 1000); k++)
        {
            roman += 'M';
        }
        l %= 1000;
        if (l - (l % 100) == 900)
        {
            roman += "CM";
            l -= 900;
        }
        for (int k = 0; k < (int)(l / 500); k++)
        {
            roman += 'D';
        }
        l %= 500;
        if (l - (l % 100) == 400)
        {
            roman += "CD";
            l -= 400;
        }
        for (int k = 0; k < (int)(l / 100); k++)
        {
            roman += 'C';
        }
        l %= 100;
        if (l - (l % 10) == 90)
        {
            roman += "XC";
            l -= 90;
        }
        for (int k = 0; k < (int)(l / 50); k++)
        {
            roman += 'L';
        }
        l %= 50;
        if (l - (l % 10) == 40)
        {
            roman += "XL";
            l -= 90;
        }
        for (int k = 0; k < (int)(l / 10); k++)
        {
            roman += 'X';
        }
        l %= 10;
        if (l == 9)
        {
            roman += "IX";
            l -= 9;
        }
        for (int k = 0; k < (int)(l / 5); k++)
        {
            roman += 'V';
        }
        l %= 5;
        if (l == 4)
        {
            roman += "IV";
            l -= 4;
        }
        for (int k = 0; k < (int)(l / 1); k++)
        {
            roman += 'I';
        }
        if (f == i)
        {
            return roman;
        }
    }
}

void N8()
{
    int sellers, products, greenSeller1, redSeller1, greenSeller2, redSeller2;
    int moneyMax = 0;
    int moneyMin = 2 * pow(10, 9);
    int comMax = 0;
    int comMin = 2 * pow(10, 9);
    double moneySum = 0;
    double comSum = 0;
    cout << "Enter sellers count and products count here: ";
    cin >> sellers >> products;

    double** aTable = new double* [sellers];
    for (int count = 0; count < sellers; count++)
    {
        aTable[count] = new double [products];
        for (int i = 0; i < products; i++)
        {
            int item;
            cout << "Enter the quantity of " << i + 1 << " item for " << count + 1 << " seller: ";
            cin >> item;

            aTable[count][i] = item;
        }
    }
    double** bTable = new double* [products];
    for (int count = 0; count < products; count++)
    {
        bTable[count] = new double[2];
        double item1, item2;
        cout << "Enter the cost of " << count + 1 << " item: ";
        cin >> item1;
        cout << "Enter the commission of " << count + 1 << " item: ";
        cin >> item2;

        bTable[count][0] = item1;
        bTable[count][1] = item2;
    }
    double** cTable = new double* [sellers];
    for (int count = 0; count < sellers; count++)
    {
        cTable[count] = new double[2];
        cTable[count][0] = 0;
        for (int j = 0; j < products; j++)
        {
            cTable[count][0] += aTable[count][j] * bTable[j][0];
        }
        moneySum += cTable[count][0];
        if (cTable[count][0] < moneyMin)
        {
            moneyMin = cTable[count][0];
            redSeller1 = count + 1;
        }
        if (cTable[count][0] > moneyMax)
        {
            moneyMax = cTable[count][0];
            greenSeller1 = count + 1;
        }
        cTable[count][1] = 0;
        for (int j = 0; j < products; j++)
        {
            cTable[count][1] += aTable[count][j] * bTable[j][1];
        }
        comSum += cTable[count][1];
        if (cTable[count][1] < comMin)
        {
            comMin = cTable[count][1];
            redSeller2 = count + 1;
        }
        if (cTable[count][1] > comMax)
        {
            comMax = cTable[count][1];
            greenSeller2 = count + 1;
        }
    }


    cout << "\n\x1B[92mЯ\033[0m - earned the most.\n\x1B[91mЯ\033[0m - earned least of all.\n\n";
    cout << "\t";
    for (int top = 0; top < products; top++)
    {
        cout << "\t" << forEight(top + 1);
    }
    cout << "\t\t\tCost\tComission\t\t\tProduct earnings\tComission earning\n" ;
    for (int layer1 = 0; layer1 < sellers; layer1++)
    {
        if (layer1 + 1 == greenSeller1)
            cout << "\x1B[92mSeller " << layer1 + 1 << "\033[0m ";
        else if (layer1 + 1 == redSeller1)
            cout << "\x1B[91mSeller " << layer1 + 1 << "\033[0m ";
        else
            cout << "Seller " << layer1 + 1 << " ";
        for (int layer2 = 0; layer2 < products; layer2++)
        {
            cout << "\t" << aTable[layer1][layer2];
        }
        if (layer1 < products)
            cout << "\t\t" << forEight(layer1 + 1) << "\t" << bTable[layer1][0] << "\t" << bTable[layer1][1];
        else
        {
            for (int y = 0; y < 4; y++)
            {
                cout << "\t";
            }
        }
        cout << "\t\t\t\t" << cTable[layer1][0] << "\t\t\t" << cTable[layer1][1];
        cout << "\n";
    }
    if (products > sellers)
    {
        for (int layer1 = sellers; layer1 < products; layer1++)
        {
            for (int y = 0; y <= products + 2; y++)
            {
                cout << "\t";
            }
            cout << forEight(layer1 + 1)  << "\t" << bTable[layer1][0] << "\t" << bTable[layer1][1] << endl;
        }
    }

    cout << "\n\x1B[92mЯ\033[0m - got more commission.\n\x1B[91mЯ\033[0m - got less commission.\n\n";
    cout << "\t";
    for (int top = 0; top < products; top++)
    {
        cout << "\t" << forEight(top + 1);
    }
    cout << "\t\t\tCost\tComission\t\t\tProduct earnings\tComission earning\n";
    for (int layer1 = 0; layer1 < sellers; layer1++)
    {
        if (layer1 + 1 == greenSeller2)
            cout << "\x1B[92mSeller " << layer1 + 1 << "\033[0m ";
        else if (layer1 + 1 == redSeller2)
            cout << "\x1B[91mSeller " << layer1 + 1 << "\033[0m ";
        else
            cout << "Seller " << layer1 + 1 << " ";
        for (int layer2 = 0; layer2 < products; layer2++)
        {
            cout << "\t" << aTable[layer1][layer2];
        }
        if (layer1 < products)
            cout << "\t\t" << forEight(layer1 + 1) << "\t" << bTable[layer1][0] << "\t" << bTable[layer1][1];
        else
        {
            for (int y = 0; y < 4; y++)
            {
                cout << "\t";
            }
        }
        cout << "\t\t\t\t" << cTable[layer1][0] << "\t\t\t" << cTable[layer1][1];
        cout << "\n";
    }
    if (products > sellers)
    {
        for (int layer1 = sellers; layer1 < products; layer1++)
        {
            for (int y = 0; y <= products + 2; y++)
            {
                cout << "\t";
            }
            cout << forEight(layer1 + 1) << "\t" << bTable[layer1][0] << "\t" << bTable[layer1][1] << endl;
        }
    }

    cout << "\n\x1B[93mALL SALES MONEY: " << moneySum << "\nALL COMISSIONS MONEY: " << comSum << "\nALL MONEY: " << comSum + moneySum << "\033[0m\n";
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
    case 6:
        N6();
        doAgain();
        break;
    case 7:
        N7();
        doAgain();
        break;
    case 8:
        N8();
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
    if (ans == 'y')
    {
        system("cls");
        main();
    }
}
