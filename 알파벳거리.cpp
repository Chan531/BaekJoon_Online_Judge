#include <iostream>

using namespace std;

int main(void)
{
	int n;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		cout << "Distances: ";
		for (int j = 0; j < s1.length(); j++)
		{
			if (s2[j] - s1[j] < 0)
				cout << s2[j] - s1[j] + 26 << ' ';
			else
				cout << s2[j] - s1[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}