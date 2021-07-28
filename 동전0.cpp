#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, num;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	int count = v.size() - 1;
	int coin = 0;
	while (k != 0)
	{
		if (k < v[count])
			count--;
		else
		{
			k -= v[count];
			coin++;
		}
	}
	cout << coin;
	return 0;
}