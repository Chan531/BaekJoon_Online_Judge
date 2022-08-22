#include <iostream>

using namespace std;

int n, ans;
char a, num[10000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		
		if (num[i] == a)
			ans++;
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