#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> v(31);
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		v[n]++;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (v[i] == 0)
			cout << i << '\n';
	}
	return 0;
}