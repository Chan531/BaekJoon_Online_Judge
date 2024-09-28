#include <iostream>

using namespace std;

long long n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n >= -32768 && n <= 32767)
		cout << "short";

	else if (n >= -2147483648 && n <= 2147483647)
		cout << "int";

	else
		cout << "long long";
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