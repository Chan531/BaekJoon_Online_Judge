#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<double> tree;
int m, h = 0;

long long int cuttree(long long int left, long long int right)
{
	int mid = (left + right) / 2;
	int i = tree.size() - 1;
	long long int sum = 0;
	while (i >= 0 && tree[i] > mid)
	{
		sum += tree[i] - mid;
		i--;
	}
	if (left == right)
	{
		if (sum < m)
			return left -1;
		else
			return right;
	}
	if (sum == m)
	{
		return mid;
	}
	if (sum > m)
	{
		left = mid + 1;
		return cuttree(left, right);
	}
	if (sum < m)
	{
		right = mid - 1;
		return cuttree(left, right);
	}
}
int main(void)
{
	int n, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tree.push_back(num);
	}
	if (n == 1)
	{
		cout << num - m;
		return 0;
	}
	sort(tree.begin(), tree.end());
	cout << cuttree(0, tree[tree.size() - 1]);
	return 0;
}