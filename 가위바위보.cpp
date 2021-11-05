#include <iostream>

using namespace std;

int checkwin(char a, char b)
{
	if (a == 'R')
	{
		if (b == 'R')
			return 0;
		else if (b == 'P')
			return 1;
		else
			return -1;
	}
	else if (a == 'P')
	{
		if (b == 'R')
			return -1;
		else if (b == 'P')
			return 0;
		else
			return 1;
	}
	else
	{
		if (b == 'R')
			return 1;
		else if (b == 'P')
			return -1;
		else
			return 0;
	}
}

int main(void)
{
	int t, n, p1, p2, m;
	char a, b;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		p1 = 0, p2 = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a >> b;
			m = checkwin(a, b);
			if (m == -1)
				p1++;
			else if (m == 1)
				p2++;
		}
		if (p1 > p2)
			cout << "Player 1\n";
		else if (p1 < p2)
			cout << "Player 2\n";
		else
			cout << "TIE\n";
	}
	return 0;
}