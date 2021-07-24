#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v(10001);
	vector<int> contain;
	v[1]++;
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i * 2; j <= n; j += i)
				v[j] = 1;
		}
	}
	for (int i = m; i <= n; i++)
		if (v[i] == 0)
			contain.push_back(i);
	if (contain.size() == 0)
		cout << -1;
	else
		cout << accumulate(contain.begin(), contain.end(), 0) << '\n' << *min_element(contain.begin(), contain.end());
	return 0;
}