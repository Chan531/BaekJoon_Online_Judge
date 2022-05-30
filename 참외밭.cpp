#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, maxh, maxw, minh, minw;
p arr[7];

void input()
{
	cin >> n;
	
	for (int i = 0; i < 6; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	arr[6].first = arr[0].first;
	arr[6].second = arr[0].second;

	for (int i = 0; i < 6; i++)
	{
		int dif = arr[i].first - arr[i + 1].first;

		if (dif == 1 || dif == 3 || dif == -2)
		{
			arr[i].first = 0;
			arr[i + 1].first = 0;
			minh = arr[i].second;
			minw = arr[i + 1].second;
			break;
		}
	}

	if (arr[6].first == 0)
		arr[0].first = 0;

	int idx = 0;

	for (int i = 0; i < 6; i++)
	{
		if (arr[i].first > 2)
			maxh = max(arr[i].second, maxh);
	}

	idx = 0;

	for (int i = 0; i < 6; i++)
	{
		if (arr[i].first < 3 && arr[i].first > 0)
			maxw = max(arr[i].second, maxw);
	}

	cout << (maxh * maxw - minh * minw) * n;
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