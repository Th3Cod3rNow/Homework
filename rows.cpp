#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int ans;
    cout << "V12(1), V19(2): ";
    cin >> ans;

    if (ans == 1)
    {
        int n;
        cout << "Enter N: ";
        cin >> n;

        if (n)
        {
            double result1 = 0;
            double result2 = 0;

            for (int k = 1; k <= n; k++)
            {
                double summa = 0;
                for (double l = 1; l <= k; l++)
                    summa += 1 / l;
                result1 += pow(summa, k);
            }
            for (double k = 1; k <= n; k++)
            {
                double summa = 1;
                for (double l = 1.; l <= k; l++)
                    summa *= l;
                result2 += pow(summa, k);
            }
            cout << "Result: " << result2 / result1 << endl;
        }
    }
    else if (ans == 2)
    {
        cout << "\x1B[93mHEIGHT ANALYSIS\033[0m\n";
        cout << "Enter height (cm) and put on <ENTER>.\nFor ending enter 0 and put on <ENTER>\n";
        
        int j = 0;

        ofstream newF("c:/users/serpuhov/desktop/1.txt");
        if (newF.is_open())
        {
            for (int i = 0; ; i++)
            {
                double height;
                cout << "-> ";
                cin >> height;
                if (height && height != 0)
                {
                    newF << height << " ";
                }
                else
                    break;
            }
        }
        else
            cout << "Smth was wrong!";

        newF.close();

        ifstream f("c:/users/serpuhov/desktop/1.txt");
        if (f.is_open())
        {
            string str, word;
            int k = 0;
            getline(f, str);
            for (char c : str)
            {
                c == ' ' ? k++ : NULL;
            }
            double* numbers = new double[k];
            int j = 0;
            for (int c = 0; c < str.size(); c++)
            {
                if (str[c] != ' ')
                {
                    word += str[c];
                }
                else
                {
                    numbers[j] = stod(word);
                    word = "";
                    j++;
                }
            }
            double summa = 0;
            int count = 0;
            int u = 0;
            for (int c = 0; c < k; c++)
            {
                summa += numbers[c];
                count++;
            }
            cout << "The average height: " << summa / count << "\n";
            for (int c = 0; c < k; c++)
            {
                numbers[c] > summa / count ? u++: NULL;
            }
            cout << u << " peaople(person) are(is) above average height." << "\n";
        }
        else
            cout << "Smth was wrong!";

        f.close();
    }
    else
        cout << "This number unavailable!\n";

    return 0;
}
