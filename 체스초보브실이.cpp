#include <iostream>

using namespace std;

int ans;

void input()
{

}

int check(char c)
{
	if (c == 'k') return 0;
	if (c == 'p') return 1;
	if (c == 'n') return 3;
	if (c == 'b') return 3;
	if (c == 'r') return 5;
	if (c == 'q') return 9;
}

void solution()
{
	for (int i = 0; i < 8 * 8; i++)
	{
		char c;
		cin >> c;
		
		if (c == '.')
			continue;

		if (isupper(c))
			ans += check(tolower(c));

		else
			ans += check(c) * -1;
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

	solve();
	return 0;
}