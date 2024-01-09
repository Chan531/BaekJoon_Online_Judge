#include <iostream>
#define N 15

using namespace std;

char c;

void solve()
{
	for (int i = 0; i < N * N; i++)
	{
		cin >> c;

		if (c == 'w')
		{
			cout << "chunbae";
			return;
		}

		else if (c == 'b')
		{
			cout << "nabi";
			return;
		}

		else if (c == 'g')
		{
			cout << "yeongcheol";
			return;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}