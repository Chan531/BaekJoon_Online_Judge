#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(3001);

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			v[i * 3 + j + 1] = num;
		}
	}
	for (int i = 4; i <= 3 * n; i++)
	{
		if (i % 3 == 1)
			v[i] += min(v[i - 2], v[i - 1]);
		if (i % 3 == 2)
			v[i] += min(v[i - 4], v[i - 2]);
		if (i % 3 == 0)
			v[i] += min(v[i - 5], v[i - 4]);
	}
	cout << *min_element(v.begin() + n * 3 - 2, v.begin() + n * 3 + 1);
	return 0;
}