#include <iostream>
#include <vector>

using namespace std;

int n, mid = 3;
long long sum;
vector<int> v(1);
char ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (sum < n)
	{
		v.push_back(v.back() * 2 + mid);
		sum += (v[v.size() - 2] + mid);
		mid++;
	}

	mid--;

	while (1)
	{
		int temp = (v.back() - mid) / 2;

		if (n > temp && n <= temp + mid)
		{
			if (n == temp + 1)
			{
				ans = 'm';
				break;
			}

			else
			{
				ans = 'o';
				break;
			}
		}

		if (n > temp + mid)
			n -= (temp + mid);

		v.pop_back();
		mid--;
	}

	cout << ans;
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