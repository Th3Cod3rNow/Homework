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
        string userText;
        bool flag = true;
        cout << "Enter your numbers here: ";
        getline(cin >> ws, userText);

        while (userText[0] == ' ')
        {
            userText.erase(userText[0], 1);
        }

        for (int c = 0; c < userText.size(); c++)
        {
            if (userText[c] == ' ')
            {
                spaces++;
            }
            if (((!isdigit(userText[c])) && (userText[c] != ' ') && (userText[c] != '-') && (userText[c] != '.')) || (userText[c] + userText[c + 1] == ' .') || (userText[c] + userText[c + 1] == '. ') || (userText[c] + userText[c + 1] + userText[c + 2] == ' . ') || (userText[c] + userText[c + 1] + userText[c + 2] == ' - ') || (isdigit(userText[c]) && userText[c + 1] == '-'))
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            userF << userText;
        else
            cout << "You can use only numbers! For example: 1 -1 1.23 -1.23\n";
    }
    else
        cout << "Oops... Something was wrong!\n";

    userF.close();
    
    if (spaces == 9)
    {
        ifstream newUserF(fileWay + fileName + ".txt");
        if (newUserF.is_open())
        {
            string s, newS;
            double sum = 0.;
            getline(newUserF, s);
            stringstream x;
            x << s;
            vector<double> array;
            while (array.size() != 10)
            {
                x >> newS;
                array.push_back(stod(newS));
            }
            for (int i = 0; i < 10; i++)
            {
                sum += array[i];
            }                                         // c:/users/serpuhov/desktop/
            cout << setprecision(100) << sum << endl; // 272.4  -323423 34234 -324.34343434343 7 6 5 3 3 10
        }
    }
    else
        cout << "Please, check your numbers. It should be 10!\n";
    
}

void N2()
{

}


void N3()
{

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

bool comp(char c1, char c2)
{
    return tolower(c1) < tolower(c2);
}

void N5()
{
    string userText;
    cout << "Enter any text here without numbers: ";
    cin >> userText;
    sort(userText.begin(), userText.end(), comp);

    userText.size() == 30 && !isdigit(userText[0]) ? cout << userText << "\n" : cout << "ERROR!\n";
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
