#include <iostream>

using namespace std;

int n, num, arr[20000];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;	
		arr[num] = i;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cout << arr[i] << '\n';
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