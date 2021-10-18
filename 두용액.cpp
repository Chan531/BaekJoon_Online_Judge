#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n, num, answer = 2000000001, n1, n2;
	cin >> n;
	vector<int> v(n);
	int start = 0, end = n - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());
	while (start != end)
	{
		if (answer > abs(v[start] + v[end]))
		{
			answer = abs(v[start] + v[end]);
			n1 = v[start];
			n2 = v[end];
		}
		if (abs(v[start]) > abs(v[end]))
			start++;
		else
			end--;
	}
	cout << n1 << ' ' << n2;
	return 0;
}