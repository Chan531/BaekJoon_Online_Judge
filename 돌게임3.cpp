#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> v(1001);           // 0 : 상근, 1 : 창영
	v[1] = 0;
	v[2] = 1;
	v[3] = 0;
	v[4] = 0;
	v[5] = 0;
	for (int i = 6; i <= n; i++)
	{
		if (v[i - 1] == 1 || v[i - 3] == 1 || v[i - 4] == 1)
			v[i] = 0;
		else
			v[i] = 1;
	}
	v[n] ? cout << "CY" : cout << "SK";
	return 0;
}