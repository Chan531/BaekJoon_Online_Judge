#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		double n = 0;
		double num = 0;
		double sum = 0;
		double per = 0;
		double ave = 0;
		vector<int> list;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			sum += num;
			list.push_back(num);
		}
		for (auto i : list)
		{
			if (i > sum / n)
				ave++;
		}
		per = ave / n;
		cout << fixed;
		cout.precision(3);
		cout << per * 100 << '%' << '\n';
	}
	return 0;
}