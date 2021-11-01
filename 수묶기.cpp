#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, index = 0, ans = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	while (index + 1 < n && v[index] <= 0)
	{
		if (v[index + 1] <= 0)
		{
			ans += v[index] * v[index + 1];
			v[index] = 0;
			v[index + 1] = 0;
		}
		index += 2;
	}
	index = n - 1;
	while(index - 1 >= 0 && v[index] > 0)
	{
		if (v[index - 1] > 1)
		{
			ans += v[index] * v[index - 1];
			v[index] = 0;
			v[index - 1] = 0;
		}
		index -= 2;
	}
	for (int i = 0; i < n; i++)
		ans += v[i];
	cout << ans;
	return 0;
}