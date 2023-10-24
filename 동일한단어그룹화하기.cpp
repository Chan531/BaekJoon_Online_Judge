#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> check;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		string s;
		cin >> s;

		sort(s.begin(), s.end());
		check[s]++;
	}

	cout << check.size();
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