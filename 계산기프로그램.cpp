#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans;
string s, c;
vector<string> cal;

void input()
{
	while (1)
	{
		cin >> s;

		if (s == "=")
			break;

		cal.push_back(s);
	}
}

void calculate(int n)
{
	if (c == "+")
		ans += n;

	else if (c == "-")
		ans -= n;

	else if (c == "*")
		ans *= n;

	else
		ans /= n;
}

void solution()
{
	for (int i = 0; i < cal.size(); i++)
	{
		if (i == 0)
			ans = stoi(cal[i]);

		else if (i % 2)
			c = cal[i];

		else
			calculate(stoi(cal[i]));
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
	cout.tie(NULL);

	solve();
	return 0;
}