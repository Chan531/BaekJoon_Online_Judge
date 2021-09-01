#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> v(1), w;
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 1; j <= i; j++)
			v.push_back(i);
	}
	for (int i = 1; i < v.size(); i++)
		v[i] += v[i - 1];
	cout << v[m] - v[n - 1];
	return 0;
}