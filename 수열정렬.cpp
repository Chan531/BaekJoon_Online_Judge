#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, cnt;
	vector<int> v, w(50, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] > num)
			{
				if (w[j] == -1)
					w[j]++;
				w[j]++;
			}
			else
				cnt++;
		}
		v.push_back(num);
		w[i] = cnt;
	}
	for (int i = 0; i < 50; i++)
	{
		if (w[i] != -1)
			cout << w[i] << ' ';
	}
	return 0;
}