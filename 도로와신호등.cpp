#include <iostream>

using namespace std;

struct node {
	int d, r, g;
};

int n, l, ans;
node traffic[101];

void input()
{
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> traffic[i].d >> traffic[i].r >> traffic[i].g;
}

void solution()
{
	int curdis = 0;
	traffic[n].d = l;
	traffic[n].g = 1;

	for (int i = 0; i <= n; i++)
	{
		ans += traffic[i].d - curdis;
		curdis = traffic[i].d;

		int lightsum = traffic[i].r + traffic[i].g;

		if (ans % lightsum < traffic[i].r)
			ans += traffic[i].r - (ans % lightsum);
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
	cout.tie(NULL);

	solve();
	return 0;
}