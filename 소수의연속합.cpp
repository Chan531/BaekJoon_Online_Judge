#include <iostream>
#include <vector>

using namespace std;
vector<int> v(4000001);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count = 0;
	vector<int> w;
	cin >> n;
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] != 1)
		{
			w.push_back(i);
			for (int j = i * 2; j <= n; j += i)
				v[j] = 1;
		}
	}
	int num = 0;
	while (num < w.size())
	{
		int sum = 0;
		for (int i = num; i < w.size(); i++)
		{
			sum += w[i];
			if (sum == n)
			{
				count++;
				break;
			}
			if (sum > n)
				break;
		}
		num++;
	}
	cout << count;
	return 0;
}