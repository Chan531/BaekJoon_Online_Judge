#include <iostream>

using namespace std;

int n, b, bc, s, sc, arr[14];

void input()
{
	cin >> n;

	for (int i = 0; i < 14; i++)
		cin >> arr[i];
}

void solution()
{
	b = n;
	s = n;

	for (int i = 0; i < 14; i++)
	{
		if (b >= arr[i])
		{
			bc += b / arr[i];
			b %= arr[i];
		}
	}

	int inc = 0, dec = 0;

	for (int i = 1; i < 14; i++)
	{
		if (arr[i - 1] < arr[i])
		{
			dec = 0;
			inc++;
		}

		else if (arr[i - 1] > arr[i])
		{
			inc = 0;
			dec++;
		}

		if (inc >= 3)
		{
			s += sc * arr[i];
			sc = 0;
		}

		if (dec >= 3)
		{
			sc += s / arr[i];
			s %= arr[i];
		}
	}

	if (b + bc * arr[13] == s + sc * arr[13])
		cout << "SAMESAME";

	else if (b + bc * arr[13] > s + sc * arr[13])
		cout << "BNP";

	else
		cout << "TIMING";
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