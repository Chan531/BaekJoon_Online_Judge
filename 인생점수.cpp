#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, score;
	string str;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		score = 0;
		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
				continue;

			score += str[i] - 'A' + 1;
		}

		score == 100 ? cout << "PERFECT LIFE\n" : cout << score << '\n';
	}
	return 0;
}