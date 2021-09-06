#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		vector<int> v;
		for (int j = 0; j < 3; j++)
		{
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		if (v[0] + v[1] <= v[2])
			cout << "Case #" << i << ": invalid!\n";
		else if (v[0] == v[1] && v[1] == v[2])
			cout << "Case #" << i << ": equilateral\n";
		else if (v[0] == v[1] || v[1] == v[2])
			cout << "Case #" << i << ": isosceles\n";
		else
			cout << "Case #" << i << ": scalene\n";
	}
	return 0;
}