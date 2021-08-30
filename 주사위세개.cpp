#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> v(7);
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		v[n]++;
	}
	for (int i = 1; i < 7; i++)
	{
		if (v[i] == 3)
		{
			cout << 10000 + i * 1000;
			return 0;
		}
	}
	for (int i = 1; i < 7; i++)
	{
		if (v[i] == 2)
		{
			cout << 1000 + i * 100;
			return 0;
		}
	}
	for (int i = 6; i > 0; i--)
	{
		if (v[i] == 1)
		{
			cout << i * 100;
			return 0;
		}
	}
}