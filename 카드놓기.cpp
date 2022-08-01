#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
string ans, arr[10], choose[4];
unordered_map<string, int> check;
bool visited[10];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void backtrack(int cnt)
{
	if (cnt == k)
	{
		for (int i = 0; i < k; i++)
			ans += choose[i];

		check[ans] = 1;
		ans = "";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;

		choose[cnt] = arr[i];
		visited[i] = 1;
		backtrack(cnt + 1);
		visited[i] = 0;
		choose[cnt] = "";
	}
}

void solution()
{
	backtrack(0);

	cout << check.size();
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