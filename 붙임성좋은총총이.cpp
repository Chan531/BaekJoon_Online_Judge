#include <iostream>
#include <unordered_map>

using namespace std;

int n, ans;
unordered_map<string, int> check;
unordered_map<string, int>::iterator it;

void input()
{
	cin >> n;
}

void solution()
{
	check["ChongChong"] = 1;

	while (n--)
	{
		string a, b;
		cin >> a >> b;

		if (check[a])
			check[b] = 1;

		else if (check[b])
			check[a] = 1;
	}

	for (it = check.begin(); it != check.end(); it++)
		if (it->second == 1)
			ans++;

	cout << ans;
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