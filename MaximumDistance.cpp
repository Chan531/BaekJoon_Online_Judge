#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	vector<int> v, w;
	ans = 0;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		w.push_back(k);
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] == w[j]) ans = max(ans, j - i);

	cout << "The maximum distance is " << ans << "\n\n";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}