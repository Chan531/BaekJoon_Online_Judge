#include <iostream>
#include <vector>
#include <algorithm>
#define N 10001

using namespace std;

int n;
vector<int> prime, num;
bool check[N];

void input()
{
	cin >> n;
}

void solution()
{
	check[1] = 1;

	for (int i = 2; i < N; i++)
	{
		if (check[i])
			continue;

		prime.push_back(i);

		for (int j = i * 2; j < N; j += i)
			check[j] = 1;
	}

	for (int i = 1; i < prime.size(); i++)
		num.push_back(prime[i - 1] * prime[i]);
	
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] > n)
		{
			cout << num[i];
			break;
		}
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