#include <iostream>
#include <string>

using namespace std;

int checking(string str)
{
	for (char c : str)
	{
		if (isdigit(c))
			return 1;
	}
	return 0;
}

int main()
{
	string loposti;

	cout << "Enter count of blades here: ";
	cin >> loposti;

	if (checking(loposti))
	{
		int g = stoi(loposti);
		if (g >= 3 && g != 5)
		{
			int i = 0;
			while (stoi(loposti) - 4 * i != 0)
			{
				if ((stoi(loposti) - 4 * i) % 3 == 0)
				{
					cout << "4: " << i << "\n3: " << (stoi(loposti) - 4 * i) / 3 << endl;
					break;
				}
				i++;
			}
		}
		else
			cout << "You can't make spinners!\n";
	}
	else
		cout << "You can't use these values!\n";

	return 0;
}
