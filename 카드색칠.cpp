#include <iostream>
#include <cstring>
#define N 1010100

using namespace std;

int n, arr[N];
bool check[4];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (arr[i])
		{
			if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1])
			{
				cout << -1;
				return;
			}

			continue;
		}

		memset(check, 0, sizeof(check));

		check[arr[i - 1]] = 1;
		check[arr[i + 1]] = 1;

		for (int j = 1; j <= 3; j++)
		{
			if (!check[j])
			{
				arr[i] = j;
				break;
			}
		}		
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
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