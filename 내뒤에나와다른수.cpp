#include <iostream>
#include <vector>
#include <cstring>
#define N 1001010
#define p pair<int, int>

using namespace std;

int n, arr[N], ans[N];
vector<p> v;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= n; i++)
	{
		while (!v.empty() && v.back().first != arr[i])
		{
			ans[v.back().second] = i;
			v.pop_back();
		}

		v.push_back({ arr[i], i });
	}

	for (int i = 1; i <= n; i++) cout <<ans[i] << ' ';
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