#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, ans = 0;
vector<int> arr;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
}

void solution()
{
	int inc = 0, dec = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			ans = max(ans, dec);
			dec = 0;
			inc++;
		}
		else if (arr[i] < arr[i - 1])
		{
			ans = max(ans, inc);
			inc = 0;
			dec++;
		}
		else
		{
			inc++;
			dec++;
		}
	}
	ans = max(ans, max(inc, dec));
	cout << ans + 1;
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