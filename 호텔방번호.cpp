#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int a, b, check[10], cnt;
vector<int> ans;

void input()
{
	cin >> a >> b;
}

bool count()
{
	for (int i = 0; i < 10; i++)
		if (check[i] > 1)
			return false;

	return true;
}

void solution()
{
	cnt = 0;

	for (int i = a; i <= b; i++)
	{
		int temp = i;

		while (temp != 0)
		{
			check[temp % 10]++;
			temp /= 10;
		}

		if (count())
			cnt++;

		memset(check, 0, sizeof(check));
	}

	ans.push_back(cnt);
}

void solve()
{
	while (!cin.eof())
	{
		input();
		solution();
	}

	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}