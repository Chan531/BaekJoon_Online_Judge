#include <iostream>
#define N 100000

using namespace std;

int n, arr[N], m, c, a, b, seg[N * 4];

void setarr()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int setseg(int start, int end, int node)
{
	if (start == end)
		return seg[node] = arr[start] % 2;

	int mid = (start + end) / 2;

	return seg[node] = setseg(start, mid, node * 2) + setseg(mid + 1, end, node * 2 + 1);
}

void changearr(int start, int end, int node, int idx, int val)
{
	if (start == idx && end == idx)                     // È¦Â¦ °ª º¯°æ
	{
		seg[node] = val;
		return;
	}

	if (start > idx || end < idx)                       // ¹üÀ§ ¹þ¾î³µÀ» ½Ã out
		return;

	int mid = (start + end) / 2;

	changearr(start, mid, node * 2, idx, val);
	changearr(mid + 1, end, node * 2 + 1, idx, val);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];      // º¯°æµÈ °ª Ã³¸®
}

int getval(int start, int end, int node, int left, int right)
{
	if (start >= left && end <= right)
		return seg[node];

	if (start > right || end < left)
		return 0;

	int mid = (start + end) / 2;

	return getval(start, mid, node * 2, left, right) + getval(mid + 1, end, node * 2 + 1, left, right);
}

void query()
{
	cin >> m;

	while (m--)
	{
		cin >> c >> a >> b;

		if (c == 1)
		{
			arr[a - 1] = b;
			changearr(0, n - 1, 1, a - 1, b % 2);
		}

		else if (c == 2)
			cout << b - a - getval(0, n - 1, 1, a - 1, b - 1) + 1 << '\n';

		else
			cout << getval(0, n - 1, 1, a - 1, b - 1) << '\n';
	}
}

void solve()
{
	setarr();
	setseg(0, n - 1, 1);
	query();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}