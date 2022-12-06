#include <iostream>
#include <vector>
#define N 10001

using namespace std;

int n, k, m, arr[N];
vector<int> num;
bool prime[N];

void input()
{
	cin >> n;
}

int euler(int n)
{
	if (!prime[n])
		return arr[n] = n - 1;

	int ret = 1;

	for (int i = 0; i < num.size(); i++)
	{
		if (n == 1)
			break;

		if (!(n % num[i]))
		{
			ret *= (num[i] - 1);
			n /= num[i];

			while (n % num[i] == 0)
			{
				ret *= num[i];
				n /= num[i];
			}
		}
	}

	return ret;
}

void solution()
{
	prime[1] = 1;

	// 소수 체크
	for (int i = 2; i <= 10000; i++)
	{
		if (!prime[i])
		{
			num.push_back(i);

			for (int j = i * 2; j <= 10000; j += i)
				prime[j] = 1;
		}
	}

	arr[1] = 2;

	// 오일러 피 함수 적용 및 누적합
	for (int i = 2; i <= 10000; i++)
		arr[i] = euler(i) + arr[i - 1];

	while (n--)
	{
		cin >> k >> m;
		cout << k << ' ' << arr[m] << '\n';
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