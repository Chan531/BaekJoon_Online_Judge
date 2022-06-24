#include <iostream>

using namespace std;

void solution(int a)
{
	if (a % 2)
		cout << a << " is odd\n";

	else
		cout << a << " is even\n";
}

void solve()
{
	int n, m;
	cin >> n;

	while (n--)
	{
		cin >> m;
		solution(m);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}