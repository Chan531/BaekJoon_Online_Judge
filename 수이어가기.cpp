#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, max = 0, maxindex = 0, index = 0, m1, m2;
	cin >> n;
	vector<vector<int>> v((n + 1) / 2 + 1);
	for (int i = n / 2; i <= n; i++)
	{
		m1 = n;
		m2 = i;
		v[index].push_back(m1);
		v[index].push_back(m2);
		for (int j = 0; ; j++)
		{
			if (j % 2)
			{
				if (m2 - m1 < 0)
					break;
				v[index].push_back(m2 - m1);
				m2 = m2 - m1;
			}
			else
			{
				if (m1 - m2 < 0)
					break;
				v[index].push_back(m1 - m2);
				m1 = m1 - m2;
			}
		}
		if (max < v[index].size())
		{
			max = v[index].size();
			maxindex = index;
		}
		index++;
	}
	cout << max << '\n';
	for (auto i : v[maxindex])
		cout << i << ' ';
	return 0;
}