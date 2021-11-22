#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int checking(string x)
{
    for (char l : x)
    {
        if (isdigit(l))
            return 1;
        else
            return 0;
    }
}

int main()
{
    int firstNum, secondNum, helper1, helper2;
    cout << "Enter 2 digits here: ";
    cin >> firstNum >> secondNum;

    if (checking(to_string(firstNum)) && checking(to_string(secondNum)) && firstNum <= 2147483647 && secondNum <= 2147483647)
    {
        helper1 = max(firstNum, secondNum);
        helper2 = min(firstNum, secondNum);

        while (helper1 % helper2 != 0)
        {
            int V = helper2;
            helper2 = helper1 % helper2;
            helper1 = V;
        }
        cout << "Devision: " << helper2 << endl;

        helper1 = max(firstNum, secondNum);
        helper2 = min(firstNum, secondNum);

        while (helper1 != helper2)
        {
            int NUM = helper2;
            helper2 = max(helper1, helper2) - min(helper1, helper2);
            helper1 = NUM;
        }
        cout << "Subtraction: " << helper2 << endl;
    }
    else
        cout << "Sorry, your digits are wrong!\n";
}
