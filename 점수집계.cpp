#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<int> v;
		for (int j = 0; j < 5; j++)
		{
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4)
			cout << "KIN\n";
		else
			cout << v[1] + v[2] + v[3] << '\n';
	}
	return 0;
}