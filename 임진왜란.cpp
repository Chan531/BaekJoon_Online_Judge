#include <iostream>
#include <unordered_map>

using namespace std;

int n, cnt;
string str[3030];
unordered_map<string, int> check;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		check[s] = i;
	}

	for (int i = 0; i < n; i++)
		cin >> str[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (check[str[i]] < check[str[j]])
				cnt++;

	cout << cnt << '/' << n * (n - 1) / 2;
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