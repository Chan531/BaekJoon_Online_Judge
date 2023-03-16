#include <iostream>
#define min 129
#define max 138

using namespace std;

int n, l, ans, arr[1000000];

void input()
{
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	double alc = 0;
	l *= -1;

	for (int i = 0; i < n; i++)
	{
		alc += arr[i];

		if (l >= 0)
			alc -= arr[l];

		if (alc >= min && alc <= max)
			ans++;

		l++;
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