#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n, k;
double arr[100000], sum, trim, adjust;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}

void solution()
{
	sort(arr, arr + n);

	// 절사 평균
	double t = sum;
	int cnt = 0;

	while (cnt != k)
	{
		sum -= arr[cnt];
		sum -= arr[n - cnt - 1];
		cnt++;
	}

	trim = sum / (n - 2 * k);

	sum = t;

	// 보정 평균
	cnt = 0;

	while (cnt != k)
	{
		sum += arr[k] - arr[cnt];
		sum += arr[n - k - 1] - arr[n - cnt - 1];
		cnt++;
	}

	adjust = sum / n;

	cout << fixed;
	cout.precision(2);

	// 1을 0.99999999로 표현하는 double형의 오차 고려
	cout << trim + 1e-9 << '\n' << adjust + 1e-9;
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