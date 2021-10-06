#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());
	cout << v[0] * v[2];
	return 0;
}