#include <iostream>
#include <algorithm>

using namespace std;

int n, w, h, l;

void input()
{
	cin >> n >> w >> h >> l;
}

void solution()
{
	cout << min(n, (w / l) * (h / l));
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