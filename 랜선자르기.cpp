#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n, k, maxp = 0;

long long int cutlan(long long int left, long long int right)
{
	if (left > right)
	{
		return maxp;
	}
	long long int mid = (left + right) / 2;
	int piece = 0;
	int i = v.size() - 1;
	while (i >= 0 && mid <= v[i])
	{
		piece += v[i] / mid;
		i--;
	}
	if (piece >= k)
	{
		if (mid > maxp)
		{
			maxp = mid;
		}
		left = mid + 1;
		return cutlan(left, right);
	}
	if (piece < k)
	{
		right = mid - 1;
		return cutlan(left, right);
	}
}

int main(void)
{
	int num;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	if (k == 1)
		cout << v[v.size() - 1];
	else
		cout << cutlan(1, v[n - 1]);
	return 0;
}