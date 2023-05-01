#include <iostream>
#include <cstring>

using namespace std;

int n;
bool check[10];

void input()
{
	cin >> n;
}

void solution(int idx)
{
	memset(check, 0, sizeof(check));

	if (n == 0)
	{
		cout << "Case #" << idx << ": INSOMNIA\n";
		return;
	}

	int cnt = 0;
	int inc = n;

	while (1)
	{
		int m = n;

		while (m != 0)
		{
			if (!check[m % 10])
			{
				check[m % 10] = 1;
				cnt++;
			}

			if (cnt == 10)
			{
				cout << "Case #" << idx << ": " << n << '\n';
				return;
			}

			m /= 10;
		}

		n += inc;
	}
}

void solve()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		input();
		solution(i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}