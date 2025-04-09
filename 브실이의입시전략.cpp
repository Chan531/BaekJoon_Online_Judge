#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define p pair<int, string>

using namespace std;

int n, m, k, minans, maxans, minidx, maxidx;
map<string, int> info, check;
vector<p> v;

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) 
	{
		string s;
		int a;
		cin >> s >> a;
		info[s] = a;
		v.push_back({ a, s });
	}
}

void solution()
{
	sort(v.begin(), v.end());

	for (int i = 0; i < k; i++)
	{
		string s;
		cin >> s;
		check[s] = 1;
		minans += info[s];
		maxans += info[s];
	}

	int cnt = 0;
	int idx = 0;

	while (cnt != m - k)
	{
		if (check[v[idx].second]) 
		{
			idx++;
			continue;
		}
		minans += v[idx++].first;
		cnt++;
	}

	cnt = 0;
	idx = n - 1;

	while (cnt != m - k)
	{
		if (check[v[idx].second])
		{
			idx--;
			continue;
		}
		maxans += v[idx--].first;
		cnt++;
	}

	cout << minans << ' ' << maxans;
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