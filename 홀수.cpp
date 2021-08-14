#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v;
	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (num % 2 == 1)
			v.push_back(num);
	}
	if (!v.empty())
	{
		cout << accumulate(v.begin(), v.end(), 0) << '\n' << *min_element(v.begin(), v.end());
		return 0;
	}
	cout << -1;
	return 0;
}