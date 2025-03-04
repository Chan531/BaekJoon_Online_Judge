#include <iostream>
#include <cstring>

using namespace std;

int p, m, ans;
bool visited[505];

void input()
{
	cin >> p >> m;
}

void solution()
{
	memset(visited, 0, sizeof(visited));
	ans = 0;
	
	for (int i = 0; i < p; i++)
	{
		int k;
		cin >> k;
		
		if (visited[k]) ans++;
		else visited[k] = 1;
	}

	cout << ans << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}