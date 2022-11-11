#include <iostream>

using namespace std;

int s, m, l;

void input()
{
	cin >> s >> m >> l;
}

void solution()
{
	s + 2 * m + 3 * l >= 10 ? cout << "happy" : cout << "sad";
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