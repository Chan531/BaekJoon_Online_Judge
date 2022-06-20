#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define p pair<string, int>

using namespace std;

string n, ans;
int k;
unordered_map<string, int> check;
unordered_map<string, int>::iterator it;
// n, k -> k��°�� �ϼ��� n�� k + 2, k + 4, ... ���� �ϼ��� �� �ִ�.

void input()
{
	cin >> n >> k;
}

void solution()
{
	queue<p> q;
	q.push({ n, 0 });
	check[n] = 0;

	while (!q.empty())
	{
		string pos = q.front().first;
		int cnt = q.front().second;
		int length = pos.length();
		q.pop();

		if (cnt >= k)
			break;

		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				string num = pos;
				swap(num[i], num[j]);

				if (num[0] == '0')
					continue;

				// ó�� ���� ���ڶ��
				// ������ üũ�� �����ε� ������ üũ�� ������ ���
				if (check[num] == 0 || (check[num] % 2 != (cnt + 1) % 2))
				{
					check[num] = cnt + 1;
					q.push({ num, cnt + 1 });
					continue;
				}

				// ������ üũ�� ���ڶ��
				if (check[num] % 2 == (cnt + 1) % 2)
				{
					check[num] = cnt + 1;
					continue;
				}
			}
		}
	}

	for (it = check.begin(); it != check.end(); it++)
		if (it->second % 2 == k % 2 && it -> second != 0)
			ans = max(ans, it->first);

	ans == "" ? cout << -1 : cout << ans;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}