#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;
	vector<int> v(1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 1; i <= n; i++)
	{
		vector<int> m;
		for (int j = 0; j <= i / 2 + 1; j++)
		{
			m.push_back(v[j] + v[i - j]);
		}
		v[i] = *max_element(m.begin(), m.end());
	}
	cout << v[n];
	return 0;
}