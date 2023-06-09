#include <iostream>
#include <algorithm>
#define N 300

using namespace std;

int n, a[N], b[N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
}

int battle(int ap, int bp)
{
	// a 승 -> -1, 비김 -> 0, b 승 -> 1

	if (ap == bp)
		return 0;

	if (ap < bp)
	{
		if (ap == 1 && bp == 3)
			return -1;

		return 1;
	}

	if (ap == 3 && bp == 1)
		return 1;

	return -1;
}

void solution()
{
	int cur = 0, an = 0, bn = 0;

	for (int i = 0; i < n; i++)
	{
		int res = battle(a[i], b[i]);

		if (res == 0)
		{
			ans = max(ans, cur);
			cur = 1;
			an ? an = 0, bn = 1 : an = 1, bn = 0;
		}

		// a승
		else if (res == -1)
		{
			// 만약 b가 새로나왔다면 연승
			if (bn)
				cur++;

			// 만약 a가 새로나왔다면 b 연승 초기화
			else
			{
				ans = max(ans, cur);
				cur = 1;
				an = 0;
				bn = 1;
			}
		}

		// b승
		else
		{
			// 만약 a가 새로나왔다면 연승
			if (an)
				cur++;

			// 만약 b가 새로나왔다면 a 연승 초기화
			else
			{
				ans = max(ans, cur);
				cur = 1;
				an = 1;
				bn = 0;
			}
		}
	}

	cout << max(ans, cur);
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