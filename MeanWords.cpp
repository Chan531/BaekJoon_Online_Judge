#include <iostream>

using namespace std;

int n, val[1010], cnt[1010];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			val[j] += s[j];
			cnt[j]++;
		}
	}

	int idx = 0;

	while (cnt[idx] != 0)
	{
		cout << (char) (val[idx] / cnt[idx++]);
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