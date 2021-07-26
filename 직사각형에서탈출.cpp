#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	vector<int> v;
	v.push_back(abs(x - w));
	v.push_back(abs(y - h));
	v.push_back(x);
	v.push_back(y);
	cout << *min_element(v.begin(), v.end());
	return 0;
}