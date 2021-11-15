#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, a, b;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		v[i] = i;
	while (m--)
	{
		cin >> a >> b;
		while (a < b)
			swap(v[a++], v[b--]);
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
	return 0;
}