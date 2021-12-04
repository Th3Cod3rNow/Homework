#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int ans;

    cout << "Read (1), Write(2) : ";
    cin >> ans;

    string theWay, fileText, userText, fullText;
    cout << "Enter way to your file here: ";
    cin >> theWay;
    
    if (ans == 1)
    {
        ifstream userF(theWay);
        if (userF.is_open())
        {
            while (getline(userF, fileText))
            {
                cout << fileText << endl;
            }
        }
        else
            cout << "Error\n";
    }
    else if (ans == 2)
    {
        cout << "Enter your text here: \n";
        while (true)
        {
            cin.ignore();
            getline(std::cin, userText);
            if (userText.empty())
                break;
            fullText += userText + "\n";
        }
        ofstream userF(theWay, ios::app);
        if (userF.is_open())
        {
            userF << fullText;
        }
        else
            cout << "Error\n";
    }
    else
        cout << "You can't use this digit!\n";
    return 0;
}
