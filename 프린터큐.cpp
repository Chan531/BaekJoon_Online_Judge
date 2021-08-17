#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		queue<pair<int, int>> print;
		vector<int> imp;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			print.push(make_pair(num, j));
			imp.push_back(num);
		}
		sort(imp.begin(), imp.end(), greater<int>());
		int j = 0;
		while (1)
		{
			if (imp[j] == print.front().first)
			{
				if (m == print.front().second)
				{
					cout << j + 1 << '\n';
					break;
				}
				print.pop();
				j++;
			}
			else
			{
				print.push(make_pair(print.front().first, print.front().second));
				print.pop();
			}
		}
	}
	return 0;
}