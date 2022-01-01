#include <iostream>
#include <vector>

using namespace std;
vector<long long> arr;
vector<pair<long long, int>> status(262144);

void lazyprop(int start, int end, int node)
{
	if (status[node].second == 1)
	{
		long long value = status[node].first;
		status[node].first = 0;
		status[node].second = 0;
		if (start == end)
		{
			arr[start] += value;
			return;
		}
		if (start != end)
		{
			status[node * 2].first += value;
			status[node * 2 + 1].first += value;
			status[node * 2].second = 1;
			status[node * 2 + 1].second = 1;
		}
	}
}

long long getvalue(int start, int end, int node, int idx)
{
	if (start > idx || end < idx)
		return 0;

	lazyprop(start, end, node);

	if (start == end)
		return arr[start];

	int mid = (start + end) / 2;

	return getvalue(start, mid, node * 2, idx) + getvalue(mid + 1, end, node * 2 + 1, idx);
}

void updatestatus(int start, int end, int left, int right, int node, long long value)
{
	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		status[node].first += value;
		status[node].second = 1;
		return;
	}

	int mid = (start + end) / 2;

	updatestatus(start, mid, left, right, node * 2, value);
	updatestatus(mid + 1, end, left, right, node * 2 + 1, value);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, qry, a, b;
	long long num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> qry;
		if (qry == 1)
		{
			cin >> a >> b >> num;
			updatestatus(0, n - 1, a - 1, b - 1, 1, num);
		}
		else
		{
			cin >> num;
			cout << getvalue(0, n - 1, 1, num - 1) << '\n';
		}
	}
	return 0;
}