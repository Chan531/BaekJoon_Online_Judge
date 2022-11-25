#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define N 1e9

using namespace std;

int n;
vector<int> num;  // n의 약수 저장

void input()
{
	cin >> n;
}

int euler(int n)
{
	int cnt = 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i)
			continue;

		cnt *= (i - 1);
		n /= i;

		while (n % i == 0)
		{
			cnt *= i;
			n /= i;
		}
	}

	if (n != 1)
		cnt *= (n - 1);

	return cnt;
}

void solution()
{
	int ans = -1;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i)
			continue;

		num.push_back(i);

		if (n / i != i)
			num.push_back(n / i);
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] * euler(num[i]) == n)
		{
			ans = num[i];
			break;
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}