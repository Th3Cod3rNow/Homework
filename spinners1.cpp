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
	string osnova, loposti, maxCost;

	cout << "Enter costs of foundation, blades and max cost of spinner here: ";
	cin >> osnova >> loposti >> maxCost;

	if (checking(osnova) && checking(loposti) && checking(maxCost))
	{
		cout << (stoi(maxCost) - stoi(osnova)) / stoi(loposti) << "blades on your spinner." << endl;
	}
	else
		cout << "You can't use these values!\n";

	return 0;
}
