#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> v(501502);
	v[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int start = i * (i + 1) / 2;
		int end = (i + 2) * (i + 1) / 2;
		for (int j = start; j < end; j++)
		{
			if (j == start || j == end - 1)
				v[j] = 1;
			else
				v[j] = (v[j - i - 1] + v[j - i]) % 10007;
		}
	}
	cout << v[n * (n + 1) / 2 + k];
	return 0;
}