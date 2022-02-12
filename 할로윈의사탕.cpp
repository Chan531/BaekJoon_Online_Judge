#include <iostream>
#include <vector>

using namespace std;

int t, c, v;

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> c >> v;
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
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