/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans, num[505050];
vector<long long> arr;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		arr.push_back(m);
	}
}

void solution()
{
	while (arr.size() != 1)
	{
		int idx = 0;

		n = arr.size();

		for (int i = 1; i < n; i += 2)
		{
			ans += arr[i] * arr[i - 1];
			num[idx++] = arr[i] + arr[i - 1];
		}

		if (n % 2)
			num[idx++] = arr.back();

		arr.clear();

		for (int i = 0; i < idx; i++)
			arr.push_back(num[i]);
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
}*/

#include <iostream>

using namespace std;

int n;
long long ans, sum, arr[505050];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i], sum += arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
		sum -= arr[i], ans += sum * arr[i];

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