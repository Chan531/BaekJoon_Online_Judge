#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 1e9;
vector<int> num;
bool check[6];

void input()
{
	cin >> n;
}

void setnum()
{
	int m = n;

	while (m != 0)
	{
		num.push_back(m % 10);
		m /= 10;
	}
}

void backtrack(int cnt, int val)
{
	if (cnt == num.size())
	{
		if (n < val)
			ans = min(ans, val);

		return;
	}

	for (int i = 0; i < num.size(); i++)
	{
		if (check[i])
			continue;

		check[i] = 1;
		backtrack(cnt + 1, val + num[i] * pow(10, cnt));
		check[i] = 0;
	}
}

void solution()
{
	setnum();
	backtrack(0, 0);
	ans == 1e9 ? cout << 0 : cout << ans;
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