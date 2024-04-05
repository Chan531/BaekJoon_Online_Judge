#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#define N 10100
#define p pair<int, string>

using namespace std;

int n, idx;
unordered_map<string, int> m;
unordered_map<string, int>::iterator it;
p arr[N];

bool cmp(p a, p b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first > b.first;
}

void input()
{
	cin >> n;
}

int check(string s)
{
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int calc(int a)
{
	if (a <= 100)
		return 10;

	a -= 100;

	if (a % 50)
		return 10 + (a / 50 + 1) * 3;

	return 10 + (a / 50) * 3;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		int val = check(a);
		m[b] += val;
	}

	idx = 0;

	for (it = m.begin(); it != m.end(); it++)
		arr[idx++] = { calc(it->second), it->first };

	sort(arr, arr + idx, cmp);

	for (int i = 0; i < idx; i++)
		cout << arr[i].second << ' ' << arr[i].first << '\n';
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