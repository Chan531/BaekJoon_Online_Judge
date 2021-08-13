#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num, sum = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		sum = 0;	
		for (int j = 0; j < 4; j++)
		{
			cin >> num;
			sum += num;
		}
		v.push_back(sum);
	}
	cout << max_element(v.begin(), v.end()) - v.begin() + 1 << ' ' << *max_element(v.begin(), v.end());
	return 0;
}