#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			v.push_back(num);
		}
		cout << (*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end())) * 2 << '\n';
	}
	return 0;
}