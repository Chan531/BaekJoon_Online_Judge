#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

struct node {
	ll y, x;
	int idx;
};

int n;
node arr[2020];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
		arr[i].idx = i;
	}
}

int ccw(node a, node b, node c)
{
	ll temp = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
	return (temp > 0) - (temp < 0);
}

ll dir(node a, node b)
{
	return pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2);
}

bool dir_cmp(node a, node b)
{
	return dir(arr[0], a) - dir(arr[0], b) > 0;
}

bool cmp(node a, node b)
{
	int res = ccw(arr[0], a, b);

	if (res > 0)
		return true;

	else if (res == 0)
		return dir(arr[0], b) - dir(arr[0], a) > 0;

	else
		return false;
}

void init()
{
	node point = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (point.y < arr[i].y)
			continue;

		if (point.y > arr[i].y || point.x > arr[i].x)
			point = arr[i];
	}

	swap(arr[0], arr[point.idx]);
}

void solution()
{
	init();
	sort(arr + 1, arr + n, cmp);

	int idx = n - 1;

	while (ccw(arr[0], arr[idx], arr[idx - 1]) == 0)
		idx--;

	sort(arr + idx, arr + n, dir_cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].idx << ' ';

	cout << '\n';
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