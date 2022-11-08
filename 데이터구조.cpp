#include <iostream>
#define N 2000000

using namespace std;

int n, seg[1 << 22], pop; // 1 << 22 == 2^22

void input()
{
	cin >> n;
}

void addnum(int start, int end, int num, int node)
{
	if (start > num || end < num)
		return;

	if (start == end && start == num)
	{
		seg[node]++;
		return;
	}

	int mid = (start + end) / 2;

	addnum(start, mid, num, node * 2);
	addnum(mid + 1, end, num, node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void output(int start, int end, int left, int right, int idx, int node)
{
	if (idx > right || idx < left || left > right)
		return;

	if (start == end)
	{
		pop = start;
		seg[node]--;
		return;
	}

	int mid = (start + end) / 2;

	if (idx <= seg[node * 2])
		output(start, mid, 1, seg[node * 2], idx, node * 2);

	else
		output(mid + 1, end, 1, seg[node * 2 + 1], idx - seg[node * 2], node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void solution()
{
	while (n--)
	{
		int t, x;
		
		cin >> t >> x;

		// x를 S에 추가
		if (t == 1)
			addnum(1, N, x, 1);

		// x번째로 작은 수 응답
		else
		{
			output(1, N, 1, seg[1], x, 1);
			cout << pop << '\n';
		}
	}
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