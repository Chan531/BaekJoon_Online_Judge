#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
	int m, n, i = 1;
	vector<int> v;
	cin >> m >> n;
	while (i * i <= n)
	{
		if (i * i >= m)
			v.push_back(i * i);
		i++;
	}
	if (!v.empty())
	{
		cout << accumulate(v.begin(), v.end(), 0) << '\n' << v[0];
	}
	else
		cout << -1;
	return 0;
}