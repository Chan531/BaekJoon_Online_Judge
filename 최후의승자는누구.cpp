#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, k, player[101];
vector<int> card[101];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int num;
			cin >> num;

			card[i].push_back(num);
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		sort(card[i].begin(), card[i].end(), greater<int>());

	vector<p> point;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			point.push_back({ card[j][i], j });

		sort(point.begin(), point.end(), greater<p>());

		int maxval = point[0].first;

		for (int j = 0; j < n; j++)
		{
			if (maxval == point[j].first)
				player[point[j].second]++;

			else
				break;
		}

		point.clear();
	}

	int maxpoint = *max_element(player, player + n);

	for (int i = 0; i < n; i++)
		if (maxpoint == player[i])
			cout << i + 1 << ' ';
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