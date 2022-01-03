#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int helmet, vest, def;
	vector<int> hel, ves;
	cin >> helmet >> vest;
	while (helmet--)
	{
		cin >> def;
		hel.push_back(def);
	}
	while (vest--)
	{
		cin >> def;
		ves.push_back(def);
	}
	cout << *max_element(hel.begin(), hel.end()) + *max_element(ves.begin(), ves.end());
	return 0;
}	