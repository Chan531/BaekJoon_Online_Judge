#include <iostream>
#include <vector>
#include <cmath>
#define N 10001

using namespace std;

int a, b;
vector<int> p, prime;
bool check[N];

void input()
{
	cin >> a >> b;
}

void init()		// 에라토스테네스의 체 전처리
{
	for (int i = 2; i < N; i++)
	{
		if (check[i])
			continue;

		prime.push_back(i);

		for (int j = i * 2; j < N; j += i)
			check[j] = 1;
	}

	p.push_back(5);
	p.push_back(7);
	p.push_back(11);
}

int reverse(int num, int size)
{
	int ret = 0;

	while (num != 0)
	{
		ret += (num % 10) * pow(10, --size);
		num /= 10;
	}

	return ret;
}

bool isPrime(int tar)
{
	if (tar < N)
		return !check[tar];

	for (int i = 0; i < prime.size(); i++)
	{
		if (prime[i] > tar)
			return true;

		if (tar % prime[i])
			continue;

		return false;
	}

	return true;
}

void solution()
{
	init();

	for (int i = 3; i < 8; i++)
	{
		int s = pow(10, (i - 2) / 2);
		int e = pow(10, i / 2);

		if (!(i % 2))
			continue;

		for (int j = s; j < e; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				int tar = j * pow(10, (i + 1) / 2) + k * pow(10, (i - 1) / 2) + reverse(j, i / 2);

				if (isPrime(tar))
					p.push_back(tar);
			}
		}
	}

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] < a)
			continue;

		if (p[i] > b)
			break;

		cout << p[i] << '\n';
	}

	cout << -1;
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