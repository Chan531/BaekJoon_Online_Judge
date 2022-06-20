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
// n, k -> k번째에 완성된 n은 k + 2, k + 4, ... 에도 완성될 수 있다.

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

				// 처음 보는 숫자라면
				// 이전에 체크한 숫자인데 직전에 체크한 숫자일 경우
				if (check[num] == 0 || (check[num] % 2 != (cnt + 1) % 2))
				{
					check[num] = cnt + 1;
					q.push({ num, cnt + 1 });
					continue;
				}

				// 이전에 체크한 숫자라면
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