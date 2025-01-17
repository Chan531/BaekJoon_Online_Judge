#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{

}

void solution()
{
	cin >> a >> b >> c >> d;

	if (a >= b) cout << "Watermelon";
	else if (a >= c) cout << "Pomegranates";
	else if (a >= d) cout << "Nuts";
	else cout << "Nothing";
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