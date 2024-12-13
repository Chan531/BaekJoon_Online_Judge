#include <iostream>
#define p pair<string, string>

using namespace std;

int n, m, l;
string s;
p st[1010];

void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> l >> s;
		string str = "";
		for (int j = 0; j < 7; j++)
		{
			char c;
			cin >> c;
			str += c;
		}
		st[i] = { str, s };
	}
}

void solution()
{
	while (m--)
	{
		string str = "";
		for (int i = 0; i < 3; i++)
		{
			char c;
			cin >> c;
			str += c;
		}
		int idx = -1, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (st[i].first.substr(0, 3) == str)
			{
				idx = i;
				cnt++;
			}
		}

		if (!cnt) cout << "!\n";
		else if (cnt > 1) cout << "?\n";
		else cout << st[idx].second << '\n';
	}
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