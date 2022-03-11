#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	int cnt, seq, n;
};

bool cmp(node a, node b)
{
	if (a.cnt == b.cnt)
		return a.seq > b.seq;
	return a.cnt < b.cnt;
}

int n, m, num;
map<int, pair<int, int>> arr;
map<int, pair<int, int>>::iterator it;
vector<node> fre;

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (!arr[num].second)
			arr[num] = { 1,i };
		else
			arr[num].first++;
	}
}

void solution()
{
	for (it = arr.begin(); it != arr.end(); it++)
		fre.push_back({ it->second.first, it->second.second, it->first });
	sort(fre.begin(), fre.end(), cmp);
	for (int i = fre.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < fre[i].cnt; j++)
			cout << fre[i].n << ' ';
	}
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