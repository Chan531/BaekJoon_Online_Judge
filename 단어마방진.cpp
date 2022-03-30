#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, n, visited[20];
string word;

vector<string> list, w;

void input()
{
	cin >> l >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		list.push_back(word);
	}
}

bool check()
{
	for (int i = 0; i < l; i++)
	{
		string st = w[i];
		word = "";
		for (int j = 0; j < l; j++)
			word += w[j][i];

		if (word != st)
			return false;
	}
	return true;
}

void backtrack(int cnt)
{
	if (cnt == l)
	{
		if (check())
		{
			for (auto k : w)
				cout << k << '\n';
			exit(0);
		}
		return;
	}

	for (int j = 0; j < n; j++)
	{
		if (!visited[j])
		{
			visited[j] = 1;
			w.push_back(list[j]);
			backtrack(cnt + 1);
			w.pop_back();
			visited[j] = 0;
		}
	}
}

void solution()
{
	sort(list.begin(), list.end());
	for (int i = 0; i < n; i++)
	{
		visited[i] = 1;
		w.push_back(list[i]);
		backtrack(1);
		w.pop_back();
		visited[i] = 0;
	}
}

void solve()
{
	input();
	solution();
	cout << "NONE";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}