#include <iostream>
#include <algorithm>

using namespace std;

int n, b, r, ans = 1e9;
char ball[500000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ball[i];

		if (ball[i] == 'B')
			b++;

		else
			r++;
	}
}

void solution()
{
	// R 또는 B만 존재하는 경우

	if (b * r == 0)
	{
		cout << 0;
		return;
	}

	int idx, cnt;

	// 모든 B를 왼쪽으로 옮겨 BR로 만드는 경우

	idx = 0;
	cnt = b;

	while (1)
	{
		if (ball[idx++] == 'R')
		{
			ans = min(ans, cnt);
			break;
		}

		cnt--;
	}

	// 모든 R을 오른쪽으로 옮겨 BR로 만드는 경우

	idx = n - 1;
	cnt = r;

	while (1)
	{
		if (ball[idx--] == 'B')
		{
			ans = min(ans, cnt);
			break;
		}

		cnt--;
	}

	// 모든 R을 왼쪽으로 옮겨 RB로 만드는 경우

	idx = 0;
	cnt = r;

	while (1)
	{
		if (ball[idx++] == 'B')
		{
			ans = min(ans, cnt);
			break;
		}

		cnt--;
	}

	// 모든 B를 오른쪽으로 옮겨 RB로 만드는 경우

	idx = n - 1;
	cnt = b;

	while (1)
	{
		if (ball[idx--] == 'R')
		{
			ans = min(ans, cnt);
			break;
		}

		cnt--;
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