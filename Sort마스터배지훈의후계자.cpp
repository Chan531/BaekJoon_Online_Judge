#include <iostream>
#include <algorithm>
#include <unordered_map>
#define N 200000

using namespace std;

int n, m, arr[N];
unordered_map<int ,int> seq;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (seq[arr[i]])
			continue;
			
		seq[arr[i]] = i + 1;
	}

	while (m--)
	{
		int a;
		cin >> a;

		if (seq[a])
			cout << seq[a] - 1 << '\n';

		else
			cout << -1 << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}