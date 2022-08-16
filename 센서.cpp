#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans, arr[10000], dif[9999];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		dif[i] = arr[i + 1] - arr[i];

	sort(dif, dif + n - 1);

	for (int i = 0; i < n - k; i++)
		ans += dif[i];

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


/*

// 맨 처음 풀이

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, arr[10000], dif[9999], check[1000001];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		dif[i] = arr[i + 1] - arr[i];

	sort(dif, dif + n - 1, greater<>());

	for (int i = 0; i < k - 1; i++)
		check[dif[i]]++;

	int ans = 0;
	int val = arr[0];

	for (int i = 1; i < n; i++)
	{
		// 집중국 설치
		if (check[arr[i] - arr[i - 1]])
		{
			check[arr[i] - arr[i - 1]]--;
			ans += arr[i - 1] - val;
			val = arr[i];
			continue;
		}

		if (i == n - 1)
			ans += arr[i] - val;
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

*/