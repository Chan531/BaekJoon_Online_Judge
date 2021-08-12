#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int num;
	vector<int> si, so;
	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		si.push_back(num);
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		so.push_back(num);
	}
	cout << accumulate(si.begin(), si.end(), 0) + accumulate(so.begin(), so.end(), 0) - *min_element(si.begin(), si.end()) - *min_element(so.begin(), so.end());
	return 0;
}