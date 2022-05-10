#include <iostream>
#define p pair<long long, int>

using namespace std;

int n;
p arr[200001];
long long k;

void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
}

void solution()
{
	int idx = n + 1;

	for (int i = n; i > 0; i--)
	{
		arr[idx].first = arr[i].first;
		arr[idx++].second = arr[i].second;
	}

	idx = 1;
	long long dis = arr[1].first;

	while (1)
	{
		if (dis > k)
		{
			cout << arr[idx].second;
			break;
		}

		dis += arr[++idx].first;
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