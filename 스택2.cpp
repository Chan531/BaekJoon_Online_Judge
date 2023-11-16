#include <iostream>
#include <vector>

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
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			cin >> b;
			v.push_back(b);
		}

		else if (a == 2)
		{
			if (v.empty())
				v.push_back(-1);

			cout << v.back() << '\n';
			v.pop_back();
		}

		else if (a == 3)
			cout << v.size() << '\n';

		else if (a == 4)
			v.empty() ? cout << 1 << '\n' : cout << 0 << '\n';

		else
			v.empty() ? cout << -1 << '\n' : cout << v.back() << '\n';
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