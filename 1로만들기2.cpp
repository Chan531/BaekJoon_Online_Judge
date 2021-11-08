#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> v(1000001);

int main(void)
{
	int n, num, cnt, i = 1, b = 0;
	vector<int> w;
	queue<pair<int, int>> q;
	cin >> n;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		num = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (v[num] || num > 1000000 || num < 1)
			continue;

		v[num] = cnt;

		if (num == 1)
		{
			cout << cnt << '\n';
			break;
		}

		if (!(num % 3))
			q.push(make_pair(num / 3, cnt + 1));
		if (!(num % 2))
			q.push(make_pair(num / 2, cnt + 1));
		q.push(make_pair(num - 1, cnt + 1));
	}
	while (cnt)
	{
		if (v[i] == cnt)
		{
			if (i == b + 1 || i == b * 2 || i == b * 3)
			{
				w.push_back(i);
				cnt--;
				b = i;
			}
		}
		i++;
	}
	w.push_back(n);
	for (int i = w.size() - 1; i >= 0; i--)
		cout << w[i] << ' ';
	return 0;
}