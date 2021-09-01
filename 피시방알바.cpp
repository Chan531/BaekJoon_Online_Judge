#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, rej = 0;
	vector<int> v(101);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[num]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (v[i] > 1)
			rej += v[i] - 1;
	}
	cout << rej;
	return 0;
}