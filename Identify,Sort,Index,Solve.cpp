#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int i, d;
	string s;
};

bool cmp(node a, node b) {
	return a.i < b.i;
}

int n;
node arr[100];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].s >> arr[i].i >> arr[i].d;
}

void solution()
{
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
	{
		char c = arr[i].s[arr[i].d - 1];

		if (isdigit(c) || isupper(c))
			cout << c;

		else
			cout << (char) toupper(c);
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

	solve();
	return 0;
}