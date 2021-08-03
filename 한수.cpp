#include <iostream>
#include <string>

using namespace std;

int han(int n)
{
	if (n <= 99)
		return n;
	else if (n < 1000)
	{
		int answer = 99;
		for (int i = 100; i <= n; i++)
		{
			string s = to_string(i);
			if (s[0] - s[1] == s[1] - s[2])
				answer++;
		}
		return answer;
	}
	else
		return 144;
}

int main(void)
{
	int n;
	cin >> n;
	cout << han(n);
	return 0;
}