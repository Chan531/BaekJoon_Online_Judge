#include <iostream>

using namespace std;

string n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n.length() / 2; i++)
		cout << n[i];

	cout << ' ';

	for (int i = n.length() / 2; i < n.length(); i++)
		cout << n[i];
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