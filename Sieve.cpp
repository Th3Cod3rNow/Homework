#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numbers;
    cout << "Enter last simple digit here : ";
    cin >> numbers;

    int* allDigits = new int[numbers - 2];
    int* simpleDigits = new int[numbers - 2];
    
    for (int i = 2; i <= numbers; i++)
    {
        allDigits[i - 2] = i;
        simpleDigits[i - 2] = i;
    }
    for (int i = 2; pow(i, 2) < numbers; i++)
    {
        if (simpleDigits[i-2])
            for (int j = i * 2; j < numbers; j += i)
                simpleDigits[j-2] = 0;
    }
    int iterator = 1;
    for (int k = 0; k <= numbers - 2; k++)
    {
        iterator == 1 ? cout << "\t" : cout << "";
        allDigits[k] == simpleDigits[k] ? cout << "\x1B[92m" << allDigits[k] << "\t\033[0m" : cout << "\x1B[91m" << allDigits[k] << "\t\033[0m";
        iterator++;
        iterator % 10 == 0 ? cout << "\n" : cout << "";
    }

    return 0;
}
