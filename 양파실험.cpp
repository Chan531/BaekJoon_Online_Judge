#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, s = 1, e = 1;

void input()
{
	cin >> n >> a >> b;
}

void solution()
{
	while(n--)
	{
		s += a;
		e += b;

		if (s < e)
			swap(s, e);

		if (s == e)
			e--;
	}

	cout << s << ' ' << e;
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