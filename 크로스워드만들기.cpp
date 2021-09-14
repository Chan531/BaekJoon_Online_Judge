#include <iostream>

using namespace std;

int main(void)
{
	string a, b;
	cin >> a >> b;
	int ai = -1, bi = -1, al = a.length(), bl = b.length();
	for (int i = 0; i < al; i++)
	{
		for (int j = 0; j < bl; j++)
		{
			if (a[i] == b[j])
			{
				ai = i;
				bi = j;
				break;
			}
		}
		if (ai != -1 && bi != -1)
			break;
	}
	for (int i = 0; i < bl; i++)
	{
		if (i == bi)
		{
			cout << a << '\n';
			continue;
		}
		for (int j = 0; j < al; j++)
		{
			if (j == ai)
				cout << b[i];
			else
				cout << '.';
		}
		cout << '\n';
	}
	return 0;
}