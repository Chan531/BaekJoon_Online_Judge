#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, val;
vector<string> ans;
string s;
unordered_map<string, int> check;
unordered_map<string, int>::iterator it;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		check[s]++;
		val = max(val, check[s]);
	}

	for (it = check.begin(); it != check.end(); it++) 
	{
		if (it->second == val)
			ans.push_back(it->first);
	}

	sort(ans.begin(), ans.end());

	for (auto i : ans)
		cout << i << '\n';
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