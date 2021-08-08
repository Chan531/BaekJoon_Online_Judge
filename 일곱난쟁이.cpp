#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num, sum = 0, r1, r2;
	vector<int> v, w;
	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		sum += num;
		v.push_back(num);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - v[i] - v[j] == 100)
			{
				r1 = i;
				r2 = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != r1 && i != r2)
			w.push_back(v[i]);
	}
	sort(w.begin(), w.end());
	for (auto i : w)
		cout << i << '\n';
	return 0;
}