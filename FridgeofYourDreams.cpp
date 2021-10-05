#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, answer;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		answer = 0;
		cin >> s;
		for (int j = 0; j < 24; j++)
		{
			if (s[j] == '1')
				answer += pow(2, 24 - j - 1);
		}
		cout << answer << '\n';
	}
	return 0;
}