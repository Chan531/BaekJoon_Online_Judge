#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v(n + 1);
		v[1] = 1;
		v[2] = 2;
		v[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			v[i] = v[i - 3] + v[i - 2] + v[i - 1];
		}
		cout << v[n] << '\n';
	}
	return 0;
}