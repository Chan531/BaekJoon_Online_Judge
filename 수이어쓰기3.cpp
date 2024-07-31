#include <iostream>
#include <string>

using namespace std;

string n, str;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= 100000; i++)
		str += to_string(i);

	for (int i = 0; i < str.length(); i++)
	{
		if (n == str.substr(i, n.length()))
		{
			cout << i + 1;
			break;
		}
	}
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