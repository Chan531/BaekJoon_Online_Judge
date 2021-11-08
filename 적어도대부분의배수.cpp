#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, cnt;
	vector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		v[i] = n;
	}
	for (int i = 1; ; i++)
	{
		cnt = 0;
		if (!(i % v[0]))
			cnt++;
		if (!(i % v[1]))
			cnt++;
		if (!(i % v[2]))
			cnt++;
		if (!(i % v[3]))
			cnt++;
		if (!(i % v[4]))
			cnt++;
		if (cnt > 2)
		{
			cout << i;
			break;
		}
	}
	return 0;
}