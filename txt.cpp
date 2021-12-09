#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
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

    return 0;
}
