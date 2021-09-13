#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n, index;
	vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	if (accumulate(v.begin(), v.end(), 0) >= 100)
		cout << "OK";
	else
	{
		index = min_element(v.begin(), v.end()) - v.begin();
		if (index == 0)
			cout << "Soongsil";
		else if (index == 1)
			cout << "Korea";
		else
			cout << "Hanyang";
	}
	return 0;
}