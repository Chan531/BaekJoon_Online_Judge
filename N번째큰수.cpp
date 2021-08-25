#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		for (int j = 0; j < 10; j++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cout << v[7] << '\n';
	}
	return 0;
}