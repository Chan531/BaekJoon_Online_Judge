#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
		cout << '*';

	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';

	for (int i = 0; i < n; i++)
		cout << '*';

	cout << '\n';

	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = 0; j < i; j++)
			cout << ' ';

		cout << '*';

		for (int j = 0; j < n - 2; j++)
			cout << ' ';

		cout << '*';

		for (int j = 0; j < (n - 2 - i) * 2 + 1; j++)
			cout << ' ';

		cout << '*';

		for (int j = 0; j < n - 2; j++)
			cout << ' ';

		cout << "*\n";
	}

	for (int i = 0; i < n - 1; i++)
		cout << ' ';

	cout << '*';

	for (int i = 0; i < n - 2; i++)
		cout << ' ';

	cout << '*';

	for (int i = 0; i < n - 2; i++)
		cout << ' ';

	cout << "*\n";

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < n - 2 - i; j++)
			cout << ' ';

		cout << '*';

		for (int j = 0; j < n - 2; j++)
			cout << ' ';

		cout << '*';

		for (int j = 1; j <= i * 2 + 1; j++)
			cout << ' ';

		cout << '*';

		for (int j = 0; j < n - 2; j++)
			cout << ' ';

		cout << "*\n";
	}

	for (int i = 0; i < n; i++)
		cout << '*';

	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';

	for (int i = 0; i < n; i++)
		cout << '*';

	cout << '\n';
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