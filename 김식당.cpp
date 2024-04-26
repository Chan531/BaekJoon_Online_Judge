#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m;
vector<p> v;

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (n--)
	{
		string s;
		cin >> s;

		if (s == "order")
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ b, a });
		}

		else if (s == "sort")
			sort(v.begin(), v.end());

		else
		{
			int a;
			cin >> a;

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].second == a)
				{
					v.erase(v.begin() + i);
					break;
				}
			}
		}

		if (v.empty())
			cout << "sleep\n";

		else
		{
			for (auto i : v)
				cout << i.second << ' ';

			cout << '\n';
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