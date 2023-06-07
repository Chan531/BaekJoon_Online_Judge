#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

void input()
{
	cin >> n;
}

void solution()
{
	arr = { 1 };

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i)
			continue;

		if (n != i)
			arr.push_back(n / i);

		arr.push_back(i);
	}

	int sum = accumulate(arr.begin(), arr.end(), 0);

	if (sum == n)
	{
		sort(arr.begin(), arr.end());
		cout << n << " = ";

		for (int i = 0; i < arr.size(); i++)
		{
			if (i == (arr.size() - 1))
			{
				cout << arr[i] << '\n';
				break;
			}

			cout << arr[i] << " + ";
		}
	}

	else
		cout << n << " is NOT perfect.\n";
}

void solve()
{
	while (1)
	{
		input();

		if (n == -1)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}