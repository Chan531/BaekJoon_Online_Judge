#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, count = 0;
	vector<int> v;
	for (int i = 1; i <= 8; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	vector<int> w(v);
	vector<int> x(v);
	sort(w.begin(), w.end());
	sort(x.begin(), x.end(), greater<int>());
	for (int i = 0; i < 8; i++)
	{
		if (v[i] == w[i])
			count++;
	}
	if (count == 8)
	{
		cout << "ascending";
		return 0;
	}
	else
	{
		count = 0;
		for (int i = 0; i < 8; i++)
		{
			if (v[i] == x[i])
				count++;
		}
	}
	if (count == 8)
	{
		cout << "descending";
		return 0;
	}
	else
		cout << "mixed";
	return 0;
}