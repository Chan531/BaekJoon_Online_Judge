#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d, e;

void input()
{
	cin >> a >> b >> c >> d >> e;
}

int solution()
{
	return max({ a, b, c, d, e });
}

void solve()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		input();
		cout << "Case #" << i << ": " << solution() << '\n';
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