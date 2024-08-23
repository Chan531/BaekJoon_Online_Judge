#include <iostream>
#include <unordered_map>
#define N 1010

using namespace std;

int n, ans;
bool seq[N];
unordered_map<string, int> m;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		m[s] = i;
	}
}

void solution()
{
	while (n--)
	{
		string s;
		cin >> s;
		int e = m[s];

		for (int i = 1; i < e; i++)
		{
			// 앞 차 중 한 차라도 등장하지 않았다면 증가
			if (!seq[i])
			{
				ans++;
				break;
			}
		}

		seq[e] = 1;
	}

	cout << ans;
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

	solve();
	return 0;
}