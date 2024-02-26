#include <iostream>
#include <vector>
#include <cstring>
#define N 303

using namespace std;

int n, m, a, b, wc, ec, p[N];
vector<int> w[N], e[N];
bool check[N];

void input()
{
	cin >> n >> m >> a >> b;

	for (int i = 0; i < a; i++)
	{
		int c, d;
		cin >> c >> d;
		w[c].push_back(d);
	}

	for (int i = 0; i < b; i++)
	{
		int c, d;
		cin >> c >> d;
		e[c].push_back(d);
	}
}

bool wdfs(int i)
{
	for (auto j : w[i])
	{
		if (check[j])
			continue;

		check[j] = 1;

		if (!p[j] || wdfs(p[j]))
		{
			p[j] = i;
			return 1;
		}
	}

	return 0;
}

bool edfs(int i)
{
	for (auto j : e[i])
	{
		if (check[j])
			continue;

		check[j] = 1;

		if (!p[j] || edfs(p[j]))
		{
			p[j] = i;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (wdfs(i))
			wc++;

		memset(check, 0, sizeof(check));
	}

	memset(p, 0, sizeof(p));

	for (int i = 1; i <= n; i++)
	{
		if (edfs(i))
			ec++;

		memset(check, 0, sizeof(check));
	}

	wc >= ec ? cout << "그만 알아보자" : cout << "네 다음 힐딱이";
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