#include <iostream>
#include <cstring>

using namespace std;

int n, k, m, ans;
int seg[1 << 15];
// f(n, k) = ((f(n - 1, k) + k) - 1 mod n) + 1

void input()
{
	cin >> n >> k >> m;
}

int setseg(int start, int end, int node)
{
	if (start == end)
		return seg[node] = 1;

	int mid = (start + end) / 2;

	return seg[node] = setseg(start, mid, node * 2) + setseg(mid + 1, end, node * 2 + 1);
}

void remove(int start, int end, int idx, int node)
{
	if (start == end && idx == 1)
	{
		ans = start;
		seg[node] = 0;
		return;
	}

	int mid = (start + end) / 2;

	if (seg[node * 2] >= idx)
		remove(start, mid, idx, node * 2);

	else
		remove(mid + 1, end, idx - seg[node * 2], node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void solution()
{
	memset(seg, 0, sizeof(seg));
	setseg(1, n, 1);

	int a = n;
	int idx = m;

	while (a--)
	{
		remove(1, n, idx, 1);

		if (a)
			idx = (idx + k - 2) % a + 1;
	}

	cout << ans << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (n == 0 && k == 0 && m == 0)
			break;

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

// 맨 처음 시도하던 dp 풀이
/*
#include <iostream>

using namespace std;

int n, k, m;

// f(n, k) = ((f(n - 1, k) + k) - 1 mod n) + 1

void input()
{
	cin >> n >> k >> m;
}

void solution()
{
	int s = 1;

	for (int i = 2; i <= n; i++)
		s = (s + k - 1) % i + 1;

	// 여기서 왜 n * k를 더해줘야하는 지 이유를 모르겠음 ㅠㅠ
	cout << (s - k + m + n * k - 1) % n + 1 << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (n == 0 && k == 0 && m == 0)
			break;

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
*/