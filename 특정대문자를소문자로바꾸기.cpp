#include <iostream>
#include <string>

using namespace std;

string a, b;

void input()
{
	cin >> a;
	cin.ignore();
	getline(cin, b);
}

void solution()
{
	for (int i = 0; i < b.length(); i += 2)
		for (int j = 0; j < a.length(); j++)
			if (a[j] == b[i])
				a[j] += 32;

	cout << a;
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