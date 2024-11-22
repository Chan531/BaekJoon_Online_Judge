#include <iostream>

using namespace std;

int n;
long long arr[101];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solution(int idx)
{
	while (n != 2)
	{
		for (int i = 1; i <= (n + 1) / 2; i++)
			arr[i] += arr[n - i + 1];

		n = (n + 1) / 2;
	}

	cout << "Case #" << idx << ": ";
	if (arr[1] > arr[2]) cout << "Alice\n";
	else cout << "Bob\n";
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution(i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}