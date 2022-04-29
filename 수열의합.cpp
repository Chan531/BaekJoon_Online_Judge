#include <iostream>
#include <vector>

using namespace std;

int n, l;
vector<int> ans;

void input()
{
	cin >> n >> l;
}

void solution()
{
	for (int i = l; i <= 100; i++)
	{
		if (i % 2 && !(n % i))                  // 홀수라면 나눴을 때 나머지가 0이어야 함
		{
			int start = n / i - i / 2;
			int end = n / i + i / 2;

			if (start < 0)                      // 음수가 포함되면 out
				continue;

			for (int j = start; j <= end; j++)
				ans.push_back(j);

			break;
		}

		if (!(i % 2) && n % i == i / 2)         // 짝수라면 나눴을 때 나머지가 i / 2와 같아야 함
		{
			int start = n / i - i / 2 + 1;
			int end = n / i + i / 2;

			if (start < 0)                      // 음수가 포함되면 out
				continue;

			for (int j = start; j <= end; j++)
				ans.push_back(j);

			break;
		}
	}

	if (ans.empty())
		cout << -1;

	else
		for (auto i : ans)
			cout << i << ' ';
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