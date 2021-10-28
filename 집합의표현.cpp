#include <iostream>
#include <vector>

using namespace std;

vector<int> v(1000001);

int find(int n)
{
	if (v[n] == n)
		return n;

	return v[n] = find(v[n]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	x > y ? v[x] = y : v[y] = x;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, c, num;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		v[i] = i;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a)
			find(b) == find(c) ? cout << "YES\n" : cout << "NO\n";
		else
			merge(b, c);
	}
	return 0;
}