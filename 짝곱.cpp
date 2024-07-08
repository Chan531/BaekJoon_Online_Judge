#include <iostream>
#include <vector>
#include <algorithm>
#define N 100001

using namespace std;

int n;
vector<int> v, w;
bool check[N];

void init()
{
	check[1] = 1;

	for (int i = 2; i < N / 2; i++)
	{
		if (check[i]) continue;

		v.push_back(i);

		for (int j = i * 2; j < N / 2; j += i)
			check[j] = 1;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] * v[j] > N) break;
			w.push_back(v[i] * v[j]);
		}
	}

	sort(w.begin(), w.end());
}

void input()
{
	cin >> n;
}

void solution()
{
	cout << *lower_bound(w.begin(), w.end(), n) << '\n';
}

void solve()
{
	init();
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