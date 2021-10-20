#include <iostream>
#include <vector>

using namespace std;

vector<long long> v, tree(2097153);

long long settree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = v[start];

	int mid = (start + end) / 2;

	return tree[node] = settree(start, mid, node * 2) + settree(mid + 1, end, node * 2 + 1);
}

void changenum(int start, int end, int node, int cn, long long tn)
{
	if (start > cn || end < cn)
		return;

	tree[node] += tn;

	if (start == end)
		return;

	int mid = (start + end) / 2;

	changenum(start, mid, node * 2, cn, tn);
	changenum(mid + 1, end, node * 2 + 1, cn, tn);
}

long long sectionsum(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return 0;

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;

	return sectionsum(start, mid, node * 2, left, right) + sectionsum(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	long long a, b, c, num;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	settree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			changenum(0, n - 1, 1, b - 1, c - v[b - 1]);
			v[b - 1] = c;
		}
		else
			cout << sectionsum(0, n - 1, 1, b - 1, c - 1) << '\n';
	}
	return 0;
}