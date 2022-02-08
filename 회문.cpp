#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
string str;

struct Node
{
	int start, end, cnt;
};

void solve()
{
	cin >> n;
	while (n--)
	{
		cin >> str;
		int ans = 1e9, l = str.length();
		queue<Node> q;
		q.push({ 0, l - 1, 0 });

		while (!q.empty())
		{
			int start = q.front().start;
			int end = q.front().end;
			int cnt = q.front().cnt;
			q.pop();

			if (start > end)
			{
				ans = min(ans, cnt);
				continue;
			}

			if (str[start] != str[end])
			{
				if (cnt == 1)
				{
					q.push({ 1,0,2 });
					continue;
				}

				if (str[start + 1] == str[end])
					q.push({ start + 1, end, cnt + 1 });

			    if (str[start] == str[end - 1])
					q.push({ start, end - 1, cnt + 1 });

				if (str[start + 1] != str[end] && str[start] != str[end - 1])
				{
					q.push({ 1,0,2 });
					continue;
				}
			}
			else
				q.push({ start + 1, end - 1, cnt });
		}

		cout << ans << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}