#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int a, b, c;
	vector<int> v;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(), v.end());
		if (pow(v[0], 2) + pow(v[1], 2) == pow(v[2], 2))
			cout << "right\n";
		else
			cout << "wrong\n";
		v.clear();
	}
	return 0;
}