#include <iostream>

using namespace std;

int ax, ay, az, cx, cy, cz;

void input()
{
	cin >> ax >> ay >> az >> cx >> cy >> cz;
}

void solution()
{
	cout << cx - az << ' ' << cy / ay << ' ' << cz - ax;
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