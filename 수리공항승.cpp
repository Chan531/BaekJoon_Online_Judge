#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, num, cnt = 1, j = 1, st;
	cin >> n >> k;
	vector<int> v, w(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	st = v[0];
	while (j < n)
	{
		if (v[j] - st >= k)
		{
			st = v[j];
			cnt++;
		}
		j++;
	}
	cout << cnt;
	return 0;
}