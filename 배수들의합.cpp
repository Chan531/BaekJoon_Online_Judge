#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n, m, num;
	vector<int> k, mul;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		k.push_back(num);
	}
	for (auto i : k)
	{
		int x = 1;
		while (i * x <= n)
		{
			mul.push_back(i * x++);
		}
	}
	sort(mul.begin(), mul.end());
	mul.erase(unique(mul.begin(), mul.end()), mul.end());
	cout << accumulate(mul.begin(), mul.end(), 0);
}