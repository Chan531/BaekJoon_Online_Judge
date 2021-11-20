#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, x, start, end, cnt = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> x;
	start = 0;
	end = n - 1;
	while (start < end)
	{
		if (v[start] + v[end] > x)
			end--;
		else if (v[start] + v[end] < x)
			start++;
		else
		{
			cnt++;
			start++;
			end--;
		}
	}
	cout << cnt;
	return 0;
}