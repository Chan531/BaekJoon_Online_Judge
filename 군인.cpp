#include <iostream>
#define N 505050

using namespace std;

int n, q, arr[N], tree[N * 4][2];

void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;
}

int init(int s = 1, int e = n, int node = 1)
{
	if (s == e)
	{
		tree[node][1] = s;
		return tree[node][0] = arr[s];
	}

	int m = (s + e) / 2;

	return tree[node][0] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int idx, int val)
{
	if (s > idx || e < idx)
		return;

	if (s == e && s == idx)
	{
		tree[node][0] += val;
		return;
	}

	int m = (s + e) / 2;
	update(s, m, node * 2, idx, val);
	update(m + 1, e, node * 2 + 1, idx, val);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
}

int output(int s, int e, int node, int val)
{
	if (s == e)
		return tree[node][1];

	int m = (s + e) / 2;

	if (tree[node * 2][0] >= val)
		return output(s, m, node * 2, val);

	else
		return output(m + 1, e, node * 2 + 1, val - tree[node * 2][0]);
}

void solution()
{
	init();

	while (q--)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c;
			update(1, n, 1, b, c);
		}

		else
		{
			cin >> b;
			cout << output(1, n, 1, b) << '\n';
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

	solve();
	return 0;
}