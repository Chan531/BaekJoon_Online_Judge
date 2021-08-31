#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, num, count = 0, start = 1, end = 1, sum = 0;
	vector<int> v, w(1);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		w.push_back(sum);
	}
	while (1)
	{
		if (start > n || end > n)
			break;
		sum = w[end] - w[start - 1];
		if (sum < m)
			end++;
		else if (sum == m)
		{
			count++;
			start++;
		}
		else
			start++;
	}
	cout << count;
	return 0;
}