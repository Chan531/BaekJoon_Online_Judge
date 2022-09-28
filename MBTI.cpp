#include <iostream>

using namespace std;

int n, ans;
string mbti, str;

void input()
{
	cin >> mbti >> n;
}

void solution()
{
	while (n--)
	{
		cin >> str;

		if (str == mbti)
			ans++;
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