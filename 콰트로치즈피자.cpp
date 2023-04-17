#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, cnt;
string s;
unordered_map<string, bool> check;
unordered_map<string, bool>::iterator it;

void input()
{
	cin >> n;

	while (n--)
	{
		cin >> s;
		check[s] = 1;
	}
}

void solution()
{
	for (it = check.begin(); it != check.end(); it++)
	{
		int len = it->first.length();

		if (len < 6)
			continue;

		if (it->first.substr(len - 6, 6) == "Cheese")
			cnt++;
	}

	cnt >= 4 ? cout << "yummy" : cout << "sad";
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