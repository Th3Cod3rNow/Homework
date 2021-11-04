#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

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

void signumFunc(double x)
{
    x > 0 ? cout << "+\n" : x < 0 ? cout << "-\n" : cout << "0\n";
}

void N2()
{
    string usersDigit = numControl();
    signumFunc(stod(usersDigit));
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
    cout << "\x1b[44;1m    Я                   \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m  ЯЯЯЯЯ                 \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m   ЯЯЯ                  \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m  Я   Я                 \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m                        \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m                        \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m                        \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m                        \x1b[0m" << "\x1b[47;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
    cout << "\x1b[44;1m *  *  *  *  *  *  *  * \x1b[0m" << "\x1b[41;1m                                                                          \x1b[0m\n";
}

//void N5()
//{
//
//}

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
//   case 5:
//       N5();
//       doAgain();
//       break;
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
