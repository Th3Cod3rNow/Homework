#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int usersDigit;
    cout << "Enter your digit here: ";
    cin >> usersDigit;

    if (usersDigit)
    {
        for (int i = 2; i <= usersDigit; i++)
        {
            if (i == 2 || i == 3 || i == 5 || i == 7)
                cout << i << " ";
            else if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
                cout << i << " ";
        }
        cout << "\n";
    }
    else
        cout << "\x1B[91mERROR\033[0m\n";
}
