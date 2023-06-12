#include <iostream>
#include <vector>
#include <algorithm>
#define N 50
#define p pair<int, int>
#define x first
#define y second

using namespace std;

int n;
p arr[N];
vector<p> v;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
}

int ccw(p a, p b, p c)
{
	int temp = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
	return (temp > 0) - (temp < 0);
}

int search()
{
	int idx = 0;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[idx].y > v[i].y) continue;
		if (v[idx].y < v[i].y || v[idx].x > v[i].y) idx = i;
	}

	return idx;
}

bool cmp(p a, p b)
{
	int res = ccw(arr[0], a, b);

	if (res < 0)
		return true;

	else if (res == 0)
	{
		if (a.x == b.x)
			return a.y < b.y;

		return a.x < b.x;
	}

	else
		return false;
}

void solution()
{
	swap(arr[0], *min_element(arr, arr + n));
	sort(arr + 1, arr + n, cmp);

	v = { arr[0], arr[1] };

	for (int i = 2; i < n; i++)
	{
		while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], arr[i]) != -1)
			v.pop_back();

		v.push_back(arr[i]);
	}

	cout << v.size() << '\n';

	int idx = search();

	for (int i = idx; i < v.size(); i++)
		cout << v[i].x << ' ' << v[i].y << '\n';

	for (int i = 0; i < idx; i++)
		cout << v[i].x << ' ' << v[i].y << '\n';
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