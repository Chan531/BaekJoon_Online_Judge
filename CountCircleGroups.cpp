#include <iostream>
#include <cstring>
#include <cmath>
#define N 3030

using namespace std;

struct node {
	int y, x, r;
};

int n, ans, root[N];
node arr[N];
bool check[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].x >> arr[i].y >> arr[i].r;
}

void init()
{
	for (int i = 1; i <= n; i++)
		root[i] = i;

	memset(check, 0, sizeof(check));
	ans = 0;
}

int find(int idx)
{
	if (root[idx] == idx)
		return idx;

	return root[idx] = find(root[idx]);
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2) <= pow(arr[i].r + arr[j].r, 2))
			{
				int iroot = find(i);
				int jroot = find(j);

				if (iroot < jroot)
					root[jroot] = iroot;

				else if (iroot > jroot)
					root[iroot] = jroot;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!check[find(root[i])])
			ans++, check[root[i]] = 1;

	cout << ans << '\n';
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