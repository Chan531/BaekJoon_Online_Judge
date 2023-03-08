#include <iostream>

using namespace std;

int n, s, t;
string str;

void input()
{
	cin >> n >> str;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 's')
			s++;

		else
			t++;
	}

	int idx = 0;

	while (s != t)
	{
		if (str[idx] == 's')
			s--;

		else
			t--;

		idx++;
	}
	
	for (int i = idx; i < n; i++)
		cout << str[i];
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
	cout.tie(NULL);

	solve();
	return 0;
}