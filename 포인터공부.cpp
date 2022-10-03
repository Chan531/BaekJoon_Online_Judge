#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	string x = "a";
	string y = "ptr";

	cout << "int a;\n";

	for (int i = 1; i <= n; i++)
	{
		cout << "int ";

		for (int j = 1; j <= i; j++)
			cout << '*';

		if (i == 1)
			cout << y << " = &" << x << ";\n";

		else if (i == 2)
			cout << y << i << " = &" << x << ";\n";

		else
			cout << y << i << " = &" << x << i - 1 << ";\n";


		if (i == 1)
			x = y;
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