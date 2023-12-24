#include <iostream>

using namespace std;

int a, b;

void solve()
{
	while (cin >> a >> b)
		cout << b / (a + 1) << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}