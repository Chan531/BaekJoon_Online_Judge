#include <iostream>
#include <vector>
#define N 45000		// 2 * 1e9의 제곱근 범위
#define ll long long

using namespace std;

int k, ans;
vector<ll> v;
bool check[N];

void input()
{
	cin >> k;
}

int cal(int n)
{
	ll ret = n;

	for (int a = 0; a < v.size(); a++)
	{
		ll av = v[a];
		if (av > n) break;
		ret -= n / av;

		for (int b = a + 1; b < v.size(); b++)
		{
			ll bv = av * v[b];
			if (bv > n) break;
			ret += n / bv;

			for (int c = b + 1; c < v.size(); c++)
			{
				ll cv = bv * v[c];
				if (cv > n) break;
				ret -= n / cv;

				for (int d = c + 1; d < v.size(); d++)
				{
					ll dv = cv * v[d];
					if (dv > n) break;
					ret += n / dv;

					for (int e = d + 1; e < v.size(); e++)
					{
						ll ev = dv * v[e];
						if (ev > n) break;
						ret -= n / ev;

						for (int f = e + 1; f < v.size(); f++)
						{
							ll fv = ev * v[f];
							if (fv > n) break;
							ret += n / fv;
						}
					}
				}
			}
		}
	}

	return ret;
}

void solution()
{
	for (int i = 2; i < N; i++)
	{
		if (check[i])
			continue;

		v.push_back(i * i);

		for (int j = i * 2; j < N; j += i)
			check[j] = 1;
	}

	ll s = k;
	ll e = 2 * k;

	while (s <= e)
	{
		ll m = (s + e) / 2;
		int cnt = cal(m);

		if (cnt == k)
		{
			while (cal(m) == k)
				m--;

			ans = m + 1;
			break;
		}

		(cnt > k) ? e = m - 1 : s = m + 1;
	}

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

	solve();
	return 0;
}