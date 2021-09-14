#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n % 2)
	{
		cout << 0;
		return 0;
	}
	vector<int> v(n + 1);
	v[2] = 3;
	for (int i = 4; i <= n; i += 2)
	{
		v[i] += v[i - 2] * 3 + 2;
		for (int j = i - 4; j > 0; j -= 2)
			v[i] += v[j] * 2;
	}
	cout << v[n];
	return 0;
}