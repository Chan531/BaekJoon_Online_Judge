#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int n;
ll ans;
vector<ll> arr;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		arr.push_back(m);
	}
}

void solution()
{
	while (arr.size() != 1)
	{
		int idx = 0;

		for (int i = 0; i < arr.size(); i++)
			if (arr[idx] < arr[i])
				idx = i;

		if (idx == arr.size() - 1)
		{
			ans += arr[idx] + arr[idx - 1];
			arr.erase(arr.begin() + idx - 1);
		}

		else
		{
			ans += arr[idx] + arr[idx + 1];
			arr.erase(arr.begin() + idx + 1);
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

	solve();
	return 0;
}


/*

다른 사람 풀이 확인하고 푼 풀이

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n, arr[1010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	cout << *max_element(arr, arr + n) * (n - 2) + accumulate(arr, arr + n, 0);
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

*/