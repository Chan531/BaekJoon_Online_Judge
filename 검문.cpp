#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, arr[100];
vector<int> sub, ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			sub.push_back(abs(arr[i] - arr[j]));
		}
	}

	for (int i = 0; i < sub.size() - 1; i++)
		sub[i + 1] = gcd(sub[i], sub[i + 1]);

	int num = sub[sub.size() - 1];

	for (int i = 1; ; i++)
	{
		if ((num % i) == 0)
		{
			if (num / i < i)
				break;

			if (i * i != num)
				ans.push_back(i);

			ans.push_back(num / i);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << ' ';
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