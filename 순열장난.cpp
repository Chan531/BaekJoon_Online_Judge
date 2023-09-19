#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
bool check[55];
vector<int> ans;
string s;

void input()
{
	cin >> s;
}

void init()
{
	if (s.length() <= 9)
		n = s.length();

	else
		n += (s.length() - 9) / 2 + 9;
}

void backtrack(int idx, int cnt)
{
	if (cnt == n)
	{
		for (auto i : ans)
			cout << i << ' ';

		exit(0);
	}

	int tar = s[idx] - '0';

	if (tar && !check[tar])
	{
		check[tar] = 1;
		ans.push_back(tar);
		backtrack(idx + 1, cnt + 1);
		ans.pop_back();
		check[tar] = 0;
	}

	if (idx == s.length() - 1)
		return;

	tar = stoi(s.substr(idx, 2));

	if (n >= tar && !check[tar])
	{
		check[tar] = 1;
		ans.push_back(tar);
		backtrack(idx + 2, cnt + 1);
		ans.pop_back();
		check[tar] = 0;
	}
}

void solution()
{
	init();
	backtrack(0, 0);
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