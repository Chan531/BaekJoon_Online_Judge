#include <iostream>
#include <vector>

using namespace std;

int a, b;
vector<int> ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	while (a != 0 || b != 0)
	{
		ans.push_back(a % 10 + b % 10);
		a /= 10;
		b /= 10;
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
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