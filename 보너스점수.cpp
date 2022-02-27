#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0, bonus = 0;
string ox;

void input()
{
	cin >> n >> ox;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (ox[i] == 'O')
		{
			ans += i + 1;
			ans += bonus++;
		}
		else
			bonus = 0;
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