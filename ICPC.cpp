#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	if (a + d > b + c)
		cout << "Persepolis";

	else if (a + d < b + c)
		cout << "Esteghlal";

	else
	{
		if (d > b)
			cout << "Persepolis";

		else if (d < b)
			cout << "Esteghlal";

		else
			cout << "Penalty";
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