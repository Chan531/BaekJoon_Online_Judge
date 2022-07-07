#include <iostream>
#include <unordered_map>

using namespace std;

int n;
long long a[200001], b[200001], ans;
unordered_map<long long, int> dif;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		b[i] += b[i - 1];
	}
}

void solution()
{
	// dif > 0이라면 조건을 만족하는 구간이 반드시 존재함.
	for (int i = 0; i <= n; i++)
	{
		ans += dif[a[i] - b[i]];
		dif[a[i] - b[i]]++;
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