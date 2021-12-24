#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> switchtree(262144);

void updateswitchtree(int start, int end, int node)
{
	if (switchtree[node].second)
	{
		switchtree[node].first = (end - start + 1) - switchtree[node].first;
		if (start != end)
		{
			switchtree[node * 2].second = !switchtree[node * 2].second;
			switchtree[node * 2 + 1].second = !switchtree[node * 2 + 1].second;
		}
		switchtree[node].second = 0;
	}
}

void changestatus(int start, int end, int left, int right, int node)
{
	updateswitchtree(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		switchtree[node].second = !switchtree[node].second;
		updateswitchtree(start, end, node);
		return;
	}

	int mid = (start + end) / 2;

	changestatus(start, mid, left, right, node * 2);
	changestatus(mid + 1, end, left, right, node * 2 + 1);
	switchtree[node].first = switchtree[node * 2].first + switchtree[node * 2 + 1].first;
}

int getvalue(int start, int end, int left, int right, int node)
{
	updateswitchtree(start, end, node);

	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return switchtree[node].first;

	int mid = (start + end) / 2;

	return getvalue(start, mid, left, right, node * 2) + getvalue(mid + 1, end, left, right, node * 2 + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, task, a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> task >> a >> b;
		if (task == 0)
			changestatus(0, n - 1, a - 1, b - 1, 1);
		else
			cout << getvalue(0, n - 1, a - 1, b - 1, 1) << '\n';
	}
	return 0;
}