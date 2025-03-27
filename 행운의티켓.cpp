#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int ans;

void input()
{
	cin >> s;
}

int getSum(string s)
{
	int ret = 0;

	for (int i = 0; i < s.length(); i++)
		ret += s[i] - '0';
	
	return ret;
}

void solution()
{
	for (int i = 1; i <= s.length() / 2; i++)
	{
		for (int j = 0; j <= s.length() - i * 2; j++)
		{
			string a = s.substr(j, i);
			string b = s.substr(j + i, i);
			int asum = getSum(a);
			int bsum = getSum(b);
			if (asum == bsum) ans = a.length() * 2;
		}
	}

	cout << ans;
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