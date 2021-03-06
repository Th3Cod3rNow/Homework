#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void N1()
{
    double S, n, p;
    cout << "Enter S, n, p to find your mounth pay: ";
    cin >> S >> n >> p;

    (S > 0.) && (n > 0.) && (p > 0.) ? cout << "Your mounth pay: " << setprecision(100) << (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.)) << "\n" : cout << "Something was wrong! Please, check your entered values.\n";
}

void ssuda(double endP, double m, double S, double n, double k, int flag)
{
    for (double p = endP; p > -1.; p += k)
    {
        if ((m < (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.))) && (flag < 6))
        {
            flag++;
            endP = p - k;
            k /= 10;
            ssuda(endP, m, S, n, k, flag);
            break;
        }
        else if ((m == (S * (p / 100.) * pow(1. + (p / 100.), n)) / (12. * (pow(1. + (p / 100.), n) - 1.))) || (flag == 6))
        {
            cout << "Your percent is " << fixed << setprecision(10) << p << "!\n";
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
    int flag = 0;

    if ((S > 0.) && (n > 0.) && (m > 0.) && (m * n * 12 > S))
    {
        ssuda(endP, m, S, n, k, flag);
    }
    else if (m * n * 12 == S)
    {
        cout << "Your percent is 0!\n";
    }
    else
    {
        cout << "Something was wrong! Please, check your entered values.\n";
    }
}

void N3()
{
    string fileName, fileWay;
    cout << "Write here filename you want to create: ";
    cin >> fileName;
    cout << "Write here way where you want to create your file: ";
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
            getline(cin >> ws, userText);

            userF << userText;
        }
    }
    else
    {
        cout << "Oops... Something was wrong!\n";
    }

    userF.close();

    ifstream newUserF(fileWay + fileName + ".txt");

    if (newUserF.is_open())
    {
        string newText;
        getline(newUserF, newText);
        cout << newText << endl;
    }
    else
    {
        cout << "Oops... Something was wrong!\n";
    }
    newUserF.close();
}

void N4()
{
    string fileName, fileWay, fileText;
    cout << "Write here filename you want to create: ";
    cin >> fileName;
    cout << "Write here way where you want to create your file: ";
    cin >> fileWay;

    ifstream userF(fileWay + fileName + ".txt");
    getline(userF, fileText);
    for (int NUM = 0; NUM < fileText.size(); NUM++)
    {
        if (isdigit(fileText[NUM]) && !isdigit(fileText[NUM + 1]))
        {
            cout << fileText[NUM] << " ";
        }
        else if (isdigit(fileText[NUM]) && isdigit(fileText[NUM + 1]))
        {
            cout << fileText[NUM];
        }
    }
    cout << "\n";
    userF.close();
}

string sortingBuble(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = s.length() - 1; j > i; j--)
        {
            if (s[j - 1] > s[j])
            {
                char T = s[j - 1];
                s[j - 1] = s[j];
                s[j] = T;
            }
        }
    }

    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = s.length() - 1; j > i; j--)
        {
            if (toupper(s[j]) < toupper(s[j - 1]))
            {
                char T = s[j - 1];
                s[j - 1] = s[j];
                s[j] = T;
            }
        }
    }

    return s;
}

void N5()
{
    string userText, sortedText;
    cout << "Enter any text here without numbers: ";
    cin >> userText;
    sortedText = sortingBuble(userText);
    userText.size() != 30 ? cout << "Size isn't 30!\n" : cout;
    isdigit(userText[0]) ? cout << "ERROR!\n" : cout << sortedText << "\n";
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
