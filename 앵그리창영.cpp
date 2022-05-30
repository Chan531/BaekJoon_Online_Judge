#include <iostream>

using namespace std;

int n, w, h, d, num;

void input()
{
	cin >> n >> w >> h;
}

void solution()
{
	int d = w * w + h * h;

	while (n--)
	{
		cin >> num;

		if (num * num <= d)
			cout << "DA\n";

		else
			cout << "NE\n";
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
	cout.tie(NULL);

	solve();
	return 0;
}