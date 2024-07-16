#include <iostream>

using namespace std;

string str[3];
bool check[3];

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> str[i];
}

void solution()
{
	for (int i = 0; i < 3; i++)
	{
		if (str[i][0] == 'l')
			check[0] = 1;

		else if (str[i][0] == 'k')
			check[1] = 1;

		else if (str[i][0] == 'p')
			check[2] = 1;
	}

	if (check[0] && check[1] && check[2])
		cout << "GLOBAL";

	else
		cout << "PONIX";
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