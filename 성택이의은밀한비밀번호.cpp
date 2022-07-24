#include <iostream>

using namespace std;

int n;
string s;

void solution()
{
	int sl = s.length();

	if (sl >= 6 && sl <= 9)
		cout << "yes\n";

	else
		cout << "no\n";
}

void solve()
{
	cin >> n;

	while (n--)
	{
		cin >> s;
		solution();
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