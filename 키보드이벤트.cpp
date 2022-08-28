#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int time, idx;
	char alpha;
};

int n, m;
node arr[1000];

bool cmp(node a, node b) {

	if (a.time == b.time)
		return a.idx < b.idx;

	return a.time < b.time;
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> arr[i].idx >> arr[i].time >> arr[i].alpha;
}

void solution()
{
	sort(arr, arr + m, cmp);

	for (int i = 0; i < m; i++)
		cout << arr[i].alpha;
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