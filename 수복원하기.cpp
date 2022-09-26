#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> prime;
bool check[1001];

void solve()
{
	check[1] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		if (check[i])
			continue;

		prime.push_back(i);

		for (int j = i; j <= 1000; j += i)
			check[j] = 1;
	}

	cin >> n;

	while (n--)
	{
		cin >> m;

		for (int i = 0; i < prime.size(); i++)
		{
			int cnt = 0;

			while (!(m % prime[i]))
			{
				m /= prime[i];
				cnt++;
			}

			if (cnt)
				cout << prime[i] << ' ' << cnt << '\n';
		}

		if (m != 1)
			cout << m << ' ' << 1 << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}