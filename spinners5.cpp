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
	int* place;
	string i, child;

	cout << "Enter count of free places and count of children here: ";
	cin >> i >> child;

	if (checking(i) && checking(child))
	{
		place = new int[stoi(i)];
		for (int r = 0; r < stoi(i); r++)
			place[r] = 0;
		for (int y = 0; y < stoi(child); y++)
		{
			if (stoi(i) % 2 == 0)
			{
				i = to_string(stoi(i) / 2);
				place[stoi(i) / 2] = 1;
			}
			else
			{
				i = to_string(stoi(i) / 2 + 1);
				place[stoi(i) / 2 + 1] = 1;
			}
		}

		for (int r = 0; r < stoi(i); r++)
		{
			place[r] == 0 ? cout << "\x1B[91mЯ\033[0m " : cout << "\x1B[92mЯ\033[0m ";
		}
	}
	else
		cout << "You can't use these values!\n";

	return 0;
}
