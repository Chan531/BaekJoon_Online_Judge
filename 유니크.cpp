#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, score[200], cnt[101];
vector<int> arr[200];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int m;
			cin >> m;

			arr[i].push_back(m);
		}
	}
}

void solution()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
			cnt[arr[j][i]]++;

		for (int j = 0; j < n; j++)
			if (cnt[arr[j][i]] == 1)
				score[j] += arr[j][i];

		memset(cnt, 0, sizeof(cnt));
	}

	for (int i = 0; i < n; i++)
		cout << score[i] << '\n';
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