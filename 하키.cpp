#include <iostream>
#include <cmath>

using namespace std;

int w, h, x, y, p, ans;

void input()
{
	cin >> w >> h >> x >> y >> p;
}

void solution()
{
	while (p--)
	{
		int a, b;
		cin >> a >> b;

		// 왼쪽 반원 확인
		if (pow((a - x), 2) + pow((b - y - h / 2), 2) <= pow((h / 2), 2))
			ans++;

		// 중간 직사각형 확인
		else if (a >= x && a <= x + w && b >= y && b <= y + h)
			ans++;

		// 오른쪽 반원 확인
		else if (pow((a - x - w), 2) + pow((b - y - h / 2), 2) <= pow((h / 2), 2))
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