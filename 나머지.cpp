#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(42);
	int n = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		v[n % 42]++;
	}
	n = 0;
	for (int i = 0; i < 42; i++)
	{
		if (v[i] != 0)
			n++;
	}
	cout << n;
	return 0;
}