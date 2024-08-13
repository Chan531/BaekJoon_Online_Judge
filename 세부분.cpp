#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, ans;
int l;

void input()
{
	cin >> s;
}

void solution()
{
	ans = s;
	l = s.length();

	for (int i = 1; i <= l - 2; i++)
	{
		string temp = s.substr(0, i);
		reverse(temp.begin(), temp.end());
		string str = temp;
		for (int j = 1; j <= l - i - 1; j++)
		{
			temp = s.substr(i, j);
			reverse(temp.begin(), temp.end());
			string temp2 = s.substr(i + j, l - i - j);
			reverse(temp2.begin(), temp2.end());
			ans = min(ans, str + temp + temp2);
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