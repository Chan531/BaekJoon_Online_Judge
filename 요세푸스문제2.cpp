#include <iostream>
#include <vector>

using namespace std;

int n, k;
int seg[1 << 18];
vector<int> ans;

void input()
{
	cin >> n >> k;
}

int setseg(int start, int end, int node)
{
	if (start == end)
		return seg[node] = 1;

	int mid = (start + end) / 2;

	return seg[node] = setseg(start, mid, node * 2) + setseg(mid + 1, end, node * 2 + 1);
}

void pop(int start, int end, int idx, int node)
{
	if (start == end && idx == 1)
	{
		ans.push_back(start);
		seg[node] = 0;
		return;
	}

	int mid = (start + end) / 2;

	if (seg[node * 2] >= idx)
		pop(start, mid, idx, node * 2);

	else
		pop(mid + 1, end, idx - seg[node * 2], node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void output()
{
	cout << '<';

	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ", ";

	cout << ans[n - 1] << '>';
}

void solution()
{
	setseg(1, n, 1);

	int m = n;
	int idx = k;

	// k만큼 건너뛰는 원형 큐에서 다음 랭크
	// rank = (rank + k - 2) % size + 1
	while (m--)
	{
		pop(1, n, idx, 1);

		if (m)
			idx = (idx + k - 2) % m + 1;
	}

	output();
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