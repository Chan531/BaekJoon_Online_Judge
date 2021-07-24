#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(1000001);
	v[1]++;
	int x, y;
	cin >> x >> y;
	for (int i = 2; i <= y; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i * 2; j <= y; j += i)
				v[j] = 1;
		}
	}
	for (int i = x; i <= y; i++)
	{
		if (v[i] == 0)
			cout << i << '\n';
	}
	return 0;
}