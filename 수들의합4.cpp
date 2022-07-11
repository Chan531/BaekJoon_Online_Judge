#include <iostream>
#include <unordered_map>

using namespace std;

int n, k, arr[200001];
unordered_map<int, long long> sum;
long long ans;

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solution()
{
	sum[0]++;

	for (int i = 1; i <= n; i++)
	{
		ans += sum[arr[i] - k];
		sum[arr[i]]++;
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