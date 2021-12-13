#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int place[9][6] = 
    {
        {1, 2, 3, 4, 53, 54},
        {5, 6, 7, 8, 51, 52},
        {9, 10, 11, 12, 49, 50},
        {13, 14, 15, 16, 47, 48},
        {17, 18, 19, 20, 45, 46},
        {21, 22, 23, 24, 43, 44},
        {25, 26, 27, 28, 41, 42},
        {29, 30, 31, 32, 39, 40},
        {33, 34, 35, 36, 37, 38}
    };

    int freePlaceCount, freePlace, i = 0;
    vector<int> helper;
    vector<int> flats;

    cout << "Count of free places: ";
    cin >> freePlaceCount;
    cout << "Enter number of free place and put on <ENTER>\n";

    if (freePlaceCount <= 54 && freePlaceCount >= 1)
    {
        while (i != freePlaceCount)
        {
            cout << "-> ";
            cin >> freePlace;
            if (freePlace >= 1 && freePlace <= 54 && find(helper.begin(), helper.end(), freePlace) == helper.end())
            {
                helper.push_back(freePlace);
                i++;
            }
            else if (find(helper.begin(), helper.end(), freePlace) != helper.end())
                cout << "You have already noted this place!\n";
            else
                cout << "Please, try again. This place is unavailable!\n";
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (find(helper.begin(), helper.end(), place[i][j]) != helper.end())
                place[i][j] = 0;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        int summa = 0;
        for (int j = 0; j < 6; j++)
        {
            summa += place[i][j];
        }
        if (summa == 0)
            flats.push_back(i);
    }

    cout << "\n | ";
    for (int g = 1; g <= 35; g += 4)
    {
        if (g <= 8)
        {
            if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) == helper.end())
                cout << "\x1B[92m" << g << "\t\033[0m\x1B[91m" << g + 2 << "\033[0m  |\t";
            else if (find(helper.begin(), helper.end(), g + 2) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
                cout << "\x1B[91m" << g << "\033[0m\t\x1B[92m" << g + 2 << "\033[0m  |\t";
            else if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) != helper.end())
                cout << "\x1B[92m" << g << "\t" << g + 2 << "\033[0m  |\t";
            else
                cout << "\x1B[91m" << g << "\t" << g + 2 << "\033[0m  |\t";
        }
        else
        {
            if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) == helper.end())
                cout << "\x1B[92m" << g << "\t\033[0m\x1B[91m" << g + 2 << "\033[0m |\t";
            else if (find(helper.begin(), helper.end(), g + 2) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
                cout << "\x1B[91m" << g << "\033[0m\t\x1B[92m" << g + 2 << "\033[0m |\t";
            else if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) != helper.end())
                cout << "\x1B[92m" << g << "\t" << g + 2 << "\033[0m |\t";
            else
                cout << "\x1B[91m" << g << "\t" << g + 2 << "\033[0m |\t";
        }
    }
    cout << "\n | ";
    for (int g = 2; g <= 36; g += 4)
    {
        if (g <= 8)
        {
            if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) == helper.end())
                cout << "\x1B[92m" << g << "\t\033[0m\x1B[91m" << g + 2 << "\033[0m  |\t";
            else if (find(helper.begin(), helper.end(), g + 2) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
                cout << "\x1B[91m" << g << "\033[0m\t\x1B[92m" << g + 2 << "\033[0m  |\t";
            else if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) != helper.end())
                cout << "\x1B[92m" << g << "\t" << g + 2 << "\033[0m  |\t";
            else
                cout << "\x1B[91m" << g << "\t" << g + 2 << "\033[0m  |\t";
        }
        else
        {
            if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) == helper.end())
                cout << "\x1B[92m" << g << "\t\033[0m\x1B[91m" << g + 2 << "\033[0m |\t";
            else if (find(helper.begin(), helper.end(), g + 2) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
                cout << "\x1B[91m" << g << "\033[0m\t\x1B[92m" << g + 2 << "\033[0m |\t";
            else if (find(helper.begin(), helper.end(), g) != helper.end() && find(helper.begin(), helper.end(), g + 2) != helper.end())
                cout << "\x1B[92m" << g << "\t" << g + 2 << "\033[0m |\t";
            else
                cout << "\x1B[91m" << g << "\t" << g + 2 << "\033[0m |\t";
        }
    }
    cout << "\n |                                                                                                                                         |\n | ";
    for (int g = 54; g >= 37; g -= 2)
    {
        if (find(helper.begin(), helper.end(), g - 1) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
            cout << "\x1B[92m" << g - 1 << "\t\033[0m\x1B[91m" << g << "\033[0m |\t";
        else if (find(helper.begin(), helper.end(), g - 1) != helper.end() && find(helper.begin(), helper.end(), g) == helper.end())
            cout << "\x1B[91m" << g - 1 << "\033[0m\t\x1B[92m" << g << "\033[0m |\t";
        else if (find(helper.begin(), helper.end(), g - 1) != helper.end() && find(helper.begin(), helper.end(), g) != helper.end())
            cout << "\x1B[92m" << g - 1 << "\t" << g << "\033[0m |\t";
        else
            cout << "\x1B[91m" << g - 1 << "\t" << g << "\033[0m |\t";
    }
    cout << "\n\n";
    
    if (flats.size() > 0)
    {
        int count = 1, maximum = 1;
        for (int k = 0; k < flats.size() - 1; k++)
        {
            if (flats[k + 1] - flats[k] == 1)
                count++;
            else
            {
                count = 1;
            }
            maximum = max(count, maximum);
        }
    
        cout << maximum << " flats(flat) are(is) free nearby!\n";
    }
    else
        cout << "There are no free flats!\n";

    return 0;
}
