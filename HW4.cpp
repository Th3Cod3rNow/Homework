#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

void N1()
{
    string fileName, fileWay;
    int spaces = 0;
    cout << "Enter name of file you want to create: ";
    cin >> fileName;
    cout << "Enter way you want to create your file: ";
    cin >> fileWay;

    ofstream userF(fileWay + fileName + ".txt");

    if (userF.is_open())
    {
        
    }
    else
        cout << "Oops... Something was wrong!\n";

    userF.close();

    ifstream newUserF(fileWay + fileName + ".txt");
    if (newUserF.is_open())
    {
        
    }
    else
        cout << "Oops... Something was wrong!\n";
}

void N2()
{

}


void N3()
{

}

void N4()
{
    
}

void N5()
{
    
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
