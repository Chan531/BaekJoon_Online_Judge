#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			if (b == 1) sort(v.begin(), v.end());
			else sort(v.begin(), v.end(), greater<int>());
		}

		else
		{
			cin >> b >> c;
			if (b == 0)
			{
				vector<int> temp = { c };
				for (auto i : v)
					temp.push_back(i);
				v = temp;
			}
			else if (b == v.size())
				v.push_back(c);
			else
			{
				vector<int> temp;
				for (int i = 0; i < b; i++)
					temp.push_back(v[i]);
				temp.push_back(c);
				for (int i = b; i < v.size(); i++)
					temp.push_back(v[i]);
				v = temp;
			}
		}
	}

	cout << v.size() << '\n';
	for (auto i : v)
		cout << i << ' ';
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