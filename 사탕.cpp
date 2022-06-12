#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, box[1000];
// 사탕의 개수, 박스 개수

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		box[i] = a * b;
	}
}

void solution()
{
	sort(box, box + m, greater<int>());

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		n -= box[i];
		cnt++;

		if (n <= 0)
			break;
	}

	cout << cnt << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}