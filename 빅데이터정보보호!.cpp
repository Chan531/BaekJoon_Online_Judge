#include <iostream>

using namespace std;

int n, b, s;
string str;

void input()
{
	cin >> n >> str;
}

void solution()
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')
		{
			i += 6;
			b++;
		}

		else
		{
			i += 7;
			s++;
		}
	}

	if (b == s)
		cout << "bigdata? security!";

	else if (b > s)
		cout << "bigdata?";

	else
		cout << "security!";
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}