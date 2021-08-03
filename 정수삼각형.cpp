#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	int index = 2;
	vector<int> v(1);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> num;
			v.push_back(num);
		}
	}
	v[2] += v[1];
	v[3] += v[1];
	for (int i = 4; i <= (n * (n + 1) / 2); i++)
	{
		if (i >= (index * (index + 1)) / 2)
		{
			v[i] += v[i - index];
			index++;
		}
		else
			v[i] += max(v[i - index + 1], v[i - index]);
	}
	cout << *max_element(v.begin() + (n * (n - 1) / 2), v.end());
	return 0;
}