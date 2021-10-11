#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void N1()
{
    double S, n, p;
    cout << "Enter S, n, p to find your mounth pay: ";
    cin >> S >> n >> p;

    (S > 0.) && (n > 0.) && (p > 0.) ? cout << "Your mounth pay: " << (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.)) << "\n" : cout << "Something was wrong! Please, check your entered values.\n";
}

void ssuda(double endP, double m, double S, double n, double k)
{
    for (double p = endP; p > -1.; p += k)
    {
        if ((m < (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.))) && (to_string(p).size() < 7))
        {
            endP = p - k;
            k /= 10;
            ssuda(endP, m, S, n, k);
            break;
        }
        else if ((m == (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.))) || (to_string(p).size() == 7))
        {
            cout << "Your percent is " << p << " !\n";
            break;
        }
    }
}

void N2()
{
    double m, S, n, endP;
    cout << "Enter m, S, n to find your percent: ";
    cin >> m >> S >> n;
    double k = 1.;
    endP = 0.;

    if ((S > 0.) && (n > 0.) && (m > 0.) && (m * n * 12 >= S))
    {
        ssuda(endP, m, S, n, k);
    }
    else
    {
        cout << "Something was wrong! Please, check your entered values.\n";
    }
}


void N3()
{
    string fileName, fileWay;
    cout << "Enter name of file you want to create: ";
    cin >> fileName;
    cout << "Enter way you want to create your file: ";
    cin >> fileWay;

    ofstream userF(fileWay + fileName + ".txt");

    if (userF.is_open())
    {
        char ans;
        cout << "File was created!\nDo you want to write smth in your file? (y/n) ";
        cin >> ans;

        if (ans == 'y')
        {
            string userText;
            cout << "Enter your text here: ";
            cin >> userText;

            userF << userText;
        }
    }
    else
    {
        cout << "Oops... Something was wrong!\n";
    }

    userF.close();
}

void N4()
{
    string fileName, fileWay, fileText;
    cout << "Enter name of file you want to read: ";
    cin >> fileName;
    cout << "Enter the way to your file: ";
    cin >> fileWay;

    ifstream userF(fileWay + fileName + ".txt");
    getline(userF, fileText);
    for (char letter : fileText)
    {
        if (isdigit(letter))
        {
            cout << letter << " ";
        }
    }
    cout << "\n";
    userF.close();
}

void N5()
{
    string userText;
    cout << "Enter any text here without numbers: ";
    cin >> userText;
    sort(userText.begin(), userText.end());

    userText.size() == 30 || isdigit(userText[0]) ? cout << userText << "\n" : cout << "ERROR!\n";
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
