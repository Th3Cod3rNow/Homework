#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

double quantile(vector<double> x, double per) {
    return x[x.size() * per];
}

vector <double> sortingBuble(vector<double> x)
{
    for (int i = 0; i < x.size() - 1; i++)
    {
        for (int j = x.size() - 1; j > i; j--)
        {
            if (x[j - 1] > x[j])
            {
                double T = x[j - 1];
                x[j - 1] = x[j];
                x[j] = T;
            }
        }
    }

    return x;
}

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

        double digit;
        vector<double> heights;

        while (true)
        {
            cout << "-> ";
            cin >> digit;
            if (digit && digit != 0)
                heights.push_back(digit);
            else
                break;
        }

        int quantile75 = quantile(sortingBuble(heights), 0.75);
        int quantile25 = quantile(sortingBuble(heights), 0.25);
        int interquantile = quantile75 - quantile25;
        double summa = 0;
        int len = 0;

        for (auto i : heights)
        {
            if (i < quantile75 + 1.5 * interquantile && i > quantile25 - 1.5 * interquantile)
            {
                summa += i;
                len++;
            }
        }

        double average = summa / len;
        int count = 0;

        for (auto i : heights)
        {
            i > average ? count++ : NULL;
        }

        cout << "The average height: " << average << "cm.\n";
        cout << count << " people(person) are(is) higher then average height.\n";
    }
    else
        cout << "This number unavailable!\n";

    return 0;
}
