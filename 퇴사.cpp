#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, d, p;
	cin >> n;
	vector<int> day(1), price(1), exp(n + 2);
	for (int i = 0; i < n; i++)
	{
		cin >> d >> p;
		day.push_back(d);
		price.push_back(p);
	}
	for (int i = 1; i <= n; i++)
	{
		exp[i] = *max_element(exp.begin(), exp.begin() + i + 1);
		if (i + day[i] <= n + 1)
			exp[i + day[i]] = max(exp[i + day[i]], exp[i] + price[i]);
	}
	cout << *max_element(exp.begin(), exp.end());
	return 0;
}