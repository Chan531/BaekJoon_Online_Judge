#include <iostream>
#include <cmath>
#include <algorithm>
#define N 101010
#define ll long long

using namespace std;

int n, m;
ll arr[N], tree[N * 4][3], ad[N * 4], sq[N * 4];	// 0 -> sum, 1 -> max, 2 -> min

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;
}

void update(int node)
{
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
	tree[node][1] = max(tree[node * 2][1], tree[node * 2 + 1][1]);
	tree[node][2] = min(tree[node * 2][2], tree[node * 2 + 1][2]);
}

void init(int s, int e, int node)
{
	if (s == e)
	{
		tree[node][0] = arr[s];
		tree[node][1] = arr[s];
		tree[node][2] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	update(node);
}

void lazy_add(int s, int e, int node)
{
	tree[node][0] += ad[node] * (e - s + 1);
	tree[node][1] += ad[node];
	tree[node][2] += ad[node];
	if (s != e)
	{
		ad[node * 2] += ad[node];
		ad[node * 2 + 1] += ad[node];
	}
	ad[node] = 0;
}

void lazy_sqr(int s, int e, int node)
{
	tree[node][0] = (sq[node] + ad[node]) * (e - s + 1);
	tree[node][1] = sq[node] + ad[node];
	tree[node][2] = sq[node] + ad[node];
	if (s != e)
	{
		sq[node * 2] = sq[node];
		ad[node * 2] = ad[node];
		sq[node * 2 + 1] = sq[node];
		ad[node * 2 + 1] = ad[node];
	}
	sq[node] = 0;
	ad[node] = 0;
}

void check(int s, int e, int node)
{
	if (!ad[node] && !sq[node]) return;

	/* add만 발생할 시 */
	if (!sq[node]) lazy_add(s, e, node);

	/* sqrt도 해야하는 경우 */
	else lazy_sqr(s, e, node);
}

void add(int s, int e, int node, int l, int r, ll val)
{
	check(s, e, node);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		if (!sq[node])
		{
			ad[node] += val;
			check(s, e, node);
			return;
		}
	}

	int m = (s + e) / 2;
	add(s, m, node * 2, l, r, val);
	add(m + 1, e, node * 2 + 1, l, r, val);
	update(node);
}

void sqr(int s, int e, int node, int l, int r)
{
	check(s, e, node);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		int sqx = sqrt(tree[node][1]);
		int sqn = sqrt(tree[node][2]);

		if (sqx == sqn)
		{
			sq[node] = sqx;
			check(s, e, node);
			return;
		}

		// 구간의 max값과 min값의 차이가 1이라면 이를 한 번에 처리해줄 수 있다.
		// sqrt로 인해 변하는 값의 차이가 동일하기 때문이다.
		// ex) 24와 25가 존재하고 이를 sqrt처리한다면 4, 5가 된다. 이 둘은 모두 20이라는 값을 빼면 나타난다.
		// (sqrt(a) != sqrt(b)) && (a == b + 1)을 만족한다면, a와 b 모두 (b - sqrt(b))를 빼주면 된다.
		// sqrt 쿼리지면 add 쿼리로 해결 가능
		if (tree[node][1] == tree[node][2] + 1)
		{
			ad[node] = sqn - tree[node][2];
			check(s, e, node);
			return;
		}
	}

	int m = (s + e) / 2;
	sqr(s, m, node * 2, l, r);
	sqr(m + 1, e, node * 2 + 1, l, r);
	update(node);
}

ll output(int s, int e, int node, int l, int r)
{
	check(s, e, node);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[node][0];

	int m = (s + e) / 2;
	return output(s, m, node * 2, l, r) + output(m + 1, e, node * 2 + 1, l, r);
}

void solution()
{
	init(1, n, 1);

	while (m--)
	{
		int a, b, c;
		ll d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			add(1, n, 1, b, c, d);
		}

		else if (a == 2)
		{
			cin >> b >> c;
			sqr(1, n, 1, b, c);
		}

		else
		{
			cin >> b >> c;
			cout << output(1, n, 1, b, c) << '\n';
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