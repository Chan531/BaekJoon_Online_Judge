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
			return a.y < b.y;

		return a.x < b.x;
	}

	else
		return false;
}

void solution()
{
	// start point 설정
	swap(arr[0], *min_element(arr, arr + n));

	// 나머지 구간 각도 정렬
	sort(arr + 1, arr + n, cmp);

	v = { arr[0], arr[1] };

	for (int i = 2; i < n; i++)
	{
		while (v.size() >= 2 && ccw(v[v.size() - 2], v.back(), arr[i]) != 1)
			v.pop_back();

		v.push_back(arr[i]);
	}

	cout << v.size();
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