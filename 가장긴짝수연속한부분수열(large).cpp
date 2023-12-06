#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000100
#define p pair<int, int>

using namespace std;

int n, k, arr[N], cur, ans, s, e;
vector<p> v;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void init()
{
	int pre = arr[0] % 2;
	int cnt = 1;

	for (int i = 1; i < n; i++)
	{
		if (pre == arr[i] % 2)
		{
			cnt++;
			continue;
		}

		v.push_back({ cnt, pre });
		pre = arr[i] % 2;
		cnt = 1;
	}

	v.push_back({ cnt, pre });
}

void solution()
{
	init();

	// 첫 홀수 집단은 고려할 필요가 없음
	if (arr[0] % 2)
	{
		s++;
		e++;
	}

	while (s < v.size() && e < v.size())
	{
		while (e < v.size())
		{
			if (!v[e].second)
			{
				cur += v[e].first;
				e++;
				continue;
			}

			if (k < v[e].first)
				break;

			k -= v[e++].first;
		}

		ans = max(ans, cur);
		cur -= v[s].first;

		if (s == v.size())
			break;

		if (s + 1 != e)
			k += v[++s].first;

		s++;

		if (s == e)
			e++;
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