#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int numbers(string word)
{
	for (char i : word)
	{
		if (!isdigit(i))
			return 0;
	}
	return 1;
}

int main()
{
	vector <int>line;
	vector <int>column;
	string checkN, checkM;
	int N, M, fullsumm = 0;

	cout << "Enter length and width here: ";
	cin >> checkN >> checkM;

	if (numbers(checkM) && numbers(checkN))
	{
		N = stoi(checkN);
		M = stoi(checkM);

		for (int i = 1; i <= N; i++)
		{
			for (int k = 1; k <= M; k++)
			{
				line.push_back(i);
				column.push_back(k);
			}
		}

		for (int i = 0; i < line.size(); i++)
		{
			int forC = 0, summa = 0;
			while (M - forC >= column[i])
			{
				summa += N - (line[i] - 1);
				forC++;
			}
			cout << line[i] << "x" << column[i] << " -> " << summa << endl;
			fullsumm += summa;
		}

		cout << "Total number of rectangles: \x1B[93m" << fullsumm << "\033[0m\n";
	}
	else
		cout << "Your values are wrong!\n";

	return 0;
}
