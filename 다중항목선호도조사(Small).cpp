#include <iostream>

using namespace std;

struct node {
	string sub, fru, col;
};

int n, m;
string a, b, c;
node arr[1000];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i].sub >> arr[i].fru >> arr[i].col;
}

void solution()
{
	while (m--)
	{
		cin >> a >> b >> c;
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i].sub == a || a == "-")
				if (arr[i].fru == b || b == "-")
					if (arr[i].col == c || c == "-")
						cnt++;
		}

		cout << cnt << '\n';
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