#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, j, cnt;
	vector<int> v(11), w(11);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	for (int i = 1; i <= n; i++)
	{
		j = 0;
		cnt = 0;
		while (1)
		{
			if (cnt == v[i] && !w[j])
			{
				w[j] = i;
				break;
			}
			if (!w[j])
				cnt++;
			j++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << w[i] << ' ';
	return 0;
}