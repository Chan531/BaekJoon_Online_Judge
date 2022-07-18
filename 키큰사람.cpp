#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	double height;
	int idx;
	string name;
};

int n;
double height;
string name;

node arr[50];

bool cmp(node a, node b)
{
	if (a.height == b.height)
		return a.idx < b.idx;

	return a.height > b.height;
}

void input()
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].height;
		arr[i].idx = i;
	}
}

void solution()
{
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
	{
		if (i + 1 == n)
		{
			cout << arr[i].name;
			break;
		}

		cout << arr[i].name << ' ';

		if (arr[i].height != arr[i + 1].height)
			break;
	}

	cout << '\n';
}

void solve()
{
	while (1)
	{
		cin >> n;

		if (!n)
			break;

		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}