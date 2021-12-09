#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int ans;

    cout << "Read (1), Find most popular(2) : ";
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
        string alp = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM,.?!\"':;-+=_&%$#@~<>()*/|\\№`[]{}";
        int* counter = new int[alp.size()];

        for (int t = 0; t < alp.size(); t++)
        {
            counter[t] = 0;
        }

        ifstream userF("c:/users/serpuhov/desktop/123.txt");

        if (userF.is_open())
        {
            string fromFile;
            while (getline(userF, fromFile))
            {
                for (char i : fromFile)
                {
                    counter[alp.find(i)] += 1;
                }
            }
        }
        else
            cout << "Smth was wrong!";

        userF.close();

        int maximum = 0;
        int element;
        for (int t = 0; t < alp.size(); t++)
        {
            if (counter[t] > maximum)
            {
                maximum = counter[t];
                element = t;
            }
        }

        ifstream newUserF("c:/users/serpuhov/desktop/123.txt");

        if (newUserF.is_open())
        {
            string fromFile;
            while (getline(newUserF, fromFile))
            {
                for (char i : fromFile)
                {
                    i == alp[element] ? cout << "\x1B[92m" << i << "\033[0m" : cout << i;
                }
                cout << "\n";
            }
        }
        else
            cout << "Smth was wrong!";

        newUserF.close();

        cout << "\n" << alp[element] << " = " << maximum;
    }
    else
        cout << "You can't use this digit!\n";
    return 0;
}
