#include <iostream>

using namespace std;

int n, m;
string word[55], ans[202];

void input()
{
	cin >> m;
	for (int i = 0; i < m; i++) cin >> word[i];
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		int k, l;
		cin >> k;
		string s = "";
		while (k--)
		{
			cin >> l;
			s += word[l];
		}
		ans[i] = s;
	}
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		cout << "Scenario #" << i << ":\n";
		for (int i = 0; i < n; i++) cout << ans[i] << '\n';
		cout << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}