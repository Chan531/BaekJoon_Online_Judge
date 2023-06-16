#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int p, f, s, v, c;
};

int n, mp, mf, ms, mv, tp, tf, ts, tv, tc, minc = 1e9;
vector<vector<int>> ans;
node arr[15];

void input()
{
	cin >> n >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++)
		cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
}

void add(int idx)
{
	tp += arr[idx].p;
	tf += arr[idx].f;
	ts += arr[idx].s;
	tv += arr[idx].v;
	tc += arr[idx].c;
}

bool check()
{
	if (mp > tp || mf > tf || ms > ts || mv > tv)
		return false;

	return true;
}

void solution()
{
	for (int i = 1; i < (1 << n); i++)
	{
		vector<int> list;
		tp = 0, tf = 0, ts = 0, tv = 0, tc = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				add(j);
				list.push_back(j + 1);
			}
		}

		if (check())
		{
			if (minc > tc)
			{
				minc = tc;
				ans.clear();
				ans.push_back(list);
			}

			else if (minc == tc)
				ans.push_back(list);
		}
	}

	if (minc == 1e9)
	{
		cout << -1;
		return;
	}

	cout << minc << '\n';
	sort(ans.begin(), ans.end());

	for (auto i : ans[0])
		cout << i << ' ';
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