#include <iostream>
#include <vector>
#define N 1010

using namespace std;

int n, m;
vector<int> arr[N];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cout << arr[i].size() << '\n';
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