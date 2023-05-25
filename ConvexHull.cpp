#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define N 100010
#define p pair<ll, ll>
#define x first
#define y second

using namespace std;

int n;
vector<p> arr, v;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll a, b;
		char c;
		cin >> a >> b >> c;

		if (c == 'Y')
			arr.push_back({ a, b });
	}
}

int ccw(p a, p b, p c)
{
	ll temp = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
	return (temp > 0) - (temp < 0);
}

bool cmp(p a, p b)
{
	int res = ccw(arr[0], a, b);

	if (res > 0)
		return true;

	else if (res == 0)
	{
		if (a.x == b.x)
			return a.y > b.y;

		return a.x < b.x;
	}

	else
		return false;
}

void solution()
{
	swap(arr[0], *min_element(arr.begin(), arr.end()));
	sort(arr.begin() + 1, arr.end(), cmp);

	v = { arr[0], arr[1] };

	for (int i = 2; i < arr.size(); i++)
	{
		int res = ccw(v[v.size() - 2], v.back(), arr[i]);

		if (res == -1)
		{
			p point = v.back();
			v.pop_back();
			v.push_back(arr[i]);
			v.push_back(point);
			continue;
		}

		v.push_back(arr[i]);
	}

	cout << v.size() << '\n';

	for (auto i : v)
		cout << i.x << ' ' << i.y << '\n';
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