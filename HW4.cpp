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
