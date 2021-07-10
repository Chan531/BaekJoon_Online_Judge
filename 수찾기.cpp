#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v, w;

int binarysearch(int n)
{
	int left = 0;
	int right = v.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (n == v[mid])
		{
			return 1;
		}
		else if (n < v[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return 0;
}

int main(void)
{
	int n, num, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		w.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		cout << binarysearch(w[i]) << '\n';
	}
}