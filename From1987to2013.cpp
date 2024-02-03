#include <iostream>
#include <cstring>

using namespace std;

int n;
bool check[10];

void input()
{
	cin >> n;
}

void solution()
{
	n++;

	while (1)
	{
		int temp = n;

		while (temp != 0)
		{
			if (check[temp % 10])
			{
				n++;
				break;
			}

			check[temp % 10] = 1;
			temp /= 10;
		}
		
		if (temp == 0)
			break;

		memset(check, 0, sizeof(check));
	}

	cout << n;
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