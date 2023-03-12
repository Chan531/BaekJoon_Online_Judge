#include <iostream>
#include <vector>
#define N 1001

using namespace std;

int n;
vector<int> prime, ans;
bool check[N], rec;

void primesetting()
{
	check[1] = 1;

	for (int i = 1; i < N; i++)
	{
		if (!check[i])
		{
			prime.push_back(i);

			for (int j = i * 2; j < N; j += i)
				check[j] = 1;
		}
	}
}

void input()
{
	cin >> n;
}

void backtrack(int cnt, int val)
{
	if (rec)
		return;

	if (cnt == 3)
	{
		if (val == n)
		{
			for (auto i : ans)
				cout << i << ' ';

			cout << '\n';
			rec = 1;
		}

		return;
	}

	for (int i = 0; i < prime.size(); i++)
	{
		ans.push_back(prime[i]);
		backtrack(cnt + 1, val + prime[i]);
		ans.pop_back();
	}
}

void solution()
{
	rec = 0;
	backtrack(0, 0);

	if (!rec)
		cout << 0 << '\n';
}

void solve()
{
	primesetting();
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
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