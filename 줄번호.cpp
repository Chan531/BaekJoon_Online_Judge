#include <iostream>
#include <string>

using namespace std;

int n;
string s;

void input()
{
	cin >> n;
	cin.ignore();
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		getline(cin, s);
		cout << i << ". " << s << '\n';
	}
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