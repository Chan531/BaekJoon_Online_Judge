#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, index = 1;
	long long r, p, st, dis, ans = 0;
	vector<long long> rail, price;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> r;
		rail.push_back(r);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		price.push_back(p);
	}
	st = price[0];
	dis = rail[0];
	while (1)
	{
		if (index == n - 1)
		{
			ans += dis * st;
			break;
		}
		if (st > price[index])
		{
			ans += dis * st;
			st = price[index];
			dis = rail[index];
		}
		else
			dis += rail[index];
		index++;
	}
	cout << ans;
	return 0;
}