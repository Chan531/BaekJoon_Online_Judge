#include <iostream>
#include <vector>
#include <algorithm>
#define pa pair<int, int>

using namespace std;

int n, m, p, ans = -1;
vector<pa> score;

void input()
{
	cin >> n >> m >> p;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		score.push_back({ num, 0 });
	}
}

void solution()
{
	while (score.size() > p)
		score.pop_back();

	if (score.size() < p)
		score.push_back({ m, 1 });

	if (score.size() >= p && score.back().first < m)
		score.push_back({ m, 1 });

	sort(score.begin(), score.end(), greater<pa>());
	
	for (int i = 0; i < score.size(); i++)
	{
		if (i > p)
			break;

		if (score[i].first == m && score[i].second == 1)
		{
			ans = i + 1;
			break;
		}
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