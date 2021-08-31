#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, s, num, min = 100001, start = 1, end = 1, sum = 0;
	vector<int> v, w(1);
	cin >> n >> s;
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
		if (end > n || start > n)
			break;
		sum = w[end] - w[start - 1];
		if (sum < s)
			end++;
		else
		{
			if (min > end - start + 1)
				min = end - start + 1;
			start++;
		}
	}
	min != 100001 ? cout << min : cout << 0;
	return 0;
}