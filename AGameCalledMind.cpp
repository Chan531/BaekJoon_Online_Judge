#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, char>

using namespace std;

int n;
vector<p> v;

void input()
{
	cin >> n;
}

void solution()
{
	char c = 'A';

	while (n--)
	{
		int m;
		cin >> m;

		while (m--)
		{
			int k;
			cin >> k;

			v.push_back({ k, c });
		}

		c++;
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i.second;
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