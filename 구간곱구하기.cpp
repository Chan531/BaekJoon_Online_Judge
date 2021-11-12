#include <iostream>
#include <vector>

using namespace std;
vector<long long> v(1000001), tree(2097153);
long long x = 1000000007;

long long setsectionmul(int start, int end, int node)
{
	if (start == end)
		return tree[node] = v[start];

	int mid = (start + end) / 2;

	return tree[node] = (setsectionmul(start, mid, node * 2) * setsectionmul(mid + 1, end, node * 2 + 1)) % x;
}

long long sectionmul(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return 1;

	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return (sectionmul(start, mid, node * 2, left, right) * sectionmul(mid + 1, end, node * 2 + 1, left, right)) % x;
}

long long changemul(int start, int end, int node, int index)
{
	if (start > index || end < index)
		return tree[node];

	if (start == index && end == index)
		return tree[node] = v[index];

	int mid = (start + end) / 2;

	return tree[node] = (changemul(start, mid, node * 2, index) * changemul(mid + 1, end, node * 2 + 1, index)) % x;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, a, b;
	long long num, c;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	setsectionmul(0, n - 1, 1);
	for (int j = 0; j < m + k; j++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			v[b - 1] = c;
			changemul(0, n - 1, 1, b - 1);
		}
		else
			cout << sectionmul(0, n - 1, 1, b - 1, c - 1) << '\n';
	}
	return 0;
}