#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<long long int> v(91);
	v[1]++;
	v[2]++;
	for (int i = 3; i <= n; i++)
		v[i] = v[i - 1] + v[i - 2];
	cout << v[n];
	return 0;
}