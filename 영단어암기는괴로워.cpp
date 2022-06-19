#include <iostream>
#include <unordered_map>
#include <algorithm>
#define p pair<int, string>

using namespace std;

int n, m, idx = 1;
p note[100001];
string word;
unordered_map<string, int> idxrecord;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> word;

		if (word.length() < m)
			continue;

		if (!idxrecord[word])
		{
			idxrecord[word] = idx;
			note[idx++] = { 1, word };
			continue;
		}

		note[idxrecord[word]].first++;
	}
}

bool cmp(p a, p b)
{
	if (a.first == b.first)
	{
		if (a.second.length() == b.second.length())
		{
			return a.second < b.second;
		}
		return a.second.length() > b.second.length();
	}
	return a.first > b.first;
}

void solution()
{
	sort(note + 1, note + idx, cmp);

	for (int i = 1; i < idx; i++)
		cout << note[i].second << '\n';
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