#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, count = 0;
	cin >> n;
	vector<int> v(2);
	vector<int> w;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		w.push_back(num);
	}
	sort(w.begin(), w.end());
	for (int i = 2; i <= w[w.size() - 1]; i++)
		v.push_back(i);

	for (int i = 2; i <= w[w.size() - 1]; i++)
	{
		if (v[i] == 0)
			continue;

		for (int j = 2 * i; j <= w[n - 1]; j += i)
		{
			v[j] = 0;
		}
	}

	for (auto i : w)
	{
		if (v[i] != 0)
			count++;
	}
	cout << count;
	return 0;
}