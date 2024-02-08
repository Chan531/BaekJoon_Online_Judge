#include <iostream>
#include <vector>

using namespace std;

int n, m, arr[303], check[1000001];
vector<int> v;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	m = n;

	while (1)
	{
		bool res = 1;

		for (int i = 0; i < n; i++)
		{
			check[arr[i] % m]++;

			if (check[arr[i] % m] > 1)
			{
				res = 0;
				break;
			}

			v.push_back(arr[i] % m);
		}

		while (!v.empty())
		{
			check[v.back()] = 0;
			v.pop_back();
		}

		if (res)
		{
			cout << m << '\n';
			break;
		}

		m++;
	}
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