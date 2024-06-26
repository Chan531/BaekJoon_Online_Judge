#include <iostream>
#include <vector>
#define N 33333

using namespace std;

int n;
vector<int> v, prime[9];
bool check[N];

void input()
{
	cin >> n;
}

void init()
{
	check[1] = 1;

	for (int i = 2; i < N; i++)
	{
		if (check[i]) continue;

		v.push_back(i);

		for (int j = i * 2; j < N; j += i)
			check[j] = 1;
	}
}

void solution()
{
	init();
	prime[1] = { 2, 3, 5, 7 };

	for (int i = 2; i <= n; i++)
	{
		for (auto j : prime[i - 1])
		{
			for (int k = 1; k < 10; k++)
			{
				int temp = j * 10 + k;

				for (int l = 0; l < v.size(); l++)
				{
					if (v[l] >= temp)
					{
						prime[i].push_back(temp);
						break;
					}

					if (temp % v[l] == 0) break;

					if (l == v.size() - 1)
						prime[i].push_back(temp);
				}
			}
		}
	}

	for (auto i : prime[n])
		cout << i << '\n';
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