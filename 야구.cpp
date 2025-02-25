#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, ans, idx;
int m[9];
int arr[55][9];
bool visited[9];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
}

int baseball(int n)
{
	int out = 0, o = 0, s = 0, t = 0, ret = 0;
	while (out != 3) {
		idx %= 9;

		// 아웃일 때
		if (arr[n][m[idx]] == 0) out++;

		// 안타일 때
		else if (arr[n][m[idx]] == 1) {
			if (t == 1) {
				ret++;
				t = 0;
			}

			if (s == 1) {
				t = 1;
				s = 0;
			}

			if (o == 1) {
				s = 1;
				o = 0;
			}

			o = 1;
		}


		// 2루타
		else if (arr[n][m[idx]] == 2) {
			if (t == 1) {
				ret++;
				t = 0;
			}

			if (s == 1) {
				ret++;
				s = 0;
			}

			if (o == 1) {
				t = 1;
				o = 0;
			}

			s = 1;
		}

		// 3루타
		else if (arr[n][m[idx]] == 3) {
			if (t == 1) {
				ret++;
				t = 0;
			}

			if (s == 1) {
				ret++;
				s = 0;
			}

			if (o == 1) {
				ret++;
				o = 0;
			}

			t = 1;
		}

		// 홈런
		else {
			if (t == 1) {
				ret++;
				t = 0;
			}

			if (s == 1) {
				ret++;
				s = 0;
			}

			if (o == 1) {
				ret++;
				o = 0;
			}

			ret++;
		}

		idx++;
	}

	return ret;
}

int cal()
{
	int ret = 0;
	idx = 0;

	for (int i = 0; i < n; i++) {
		ret += baseball(i);
	}

	return ret;
}

void backtrack(int idx)
{
	if (idx == 9)
	{
		ans = max(ans, cal());
		return;
	}

	for (int i = 1; i < 9; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		m[idx] = i;
		if (idx == 2) backtrack(idx + 2);
		else backtrack(idx + 1);
		visited[i] = 0;
	}
}

void solution()
{
	backtrack(0);
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