#include <iostream>
#include <vector>
#define N 1000000000

using namespace std;

int n;
vector<int> ans, fibo = { 1, 1 };

void init()
{
	while (1)
	{
		if (fibo.back() > N)
			break;

		fibo.push_back(fibo.back() + fibo[fibo.size() - 2]);
	}
}

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = fibo.size() - 1; i >= 0; i--)
		if (fibo[i] <= n)
			ans.push_back(fibo[i]), n -= ans.back();

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';

	ans.clear();
	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	init();

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}