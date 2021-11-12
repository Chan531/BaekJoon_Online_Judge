#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, q, a, b, cnt = 0;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		for (int j = a; j <= n; j += b)
			v[j] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}