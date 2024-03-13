#include <iostream>
#include <string>

using namespace std;

string a, b;
int arr[2][3], ans[3];

void input()
{
	cin >> a >> b;
}

void init()
{
	int idx = 0;

	for (int i = 0; i < 7; i += 3)
	{
		arr[0][idx] = stoi(a.substr(i, 2));
		arr[1][idx++] = stoi(b.substr(i, 2));
	}
}

void solution()
{
	if (a == b)
	{
		cout << "24:00:00";
		return;
	}

	init();

	if (arr[0][2] > arr[1][2])
	{
		ans[2] += 60 - arr[0][2];
		arr[0][2] = 0;
		arr[0][1]++;
	}

	ans[2] += arr[1][2] - arr[0][2];

	if (arr[0][1] == 60)
		arr[0][0]++;

	arr[0][1] %= 60;

	if (arr[0][1] > arr[1][1])
	{
		ans[1] += 60 - arr[0][1];
		arr[0][1] = 0;
		arr[0][0]++;
	}

	ans[1] += arr[1][1] - arr[0][1];

	arr[0][0] %= 24;

	if (arr[0][0] > arr[1][0])
	{
		ans[0] += 24 - arr[0][0];
		arr[0][0] = 0;
	}

	ans[0] += arr[1][0] - arr[0][0];

	for (int i = 0; i < 3; i++)
	{
		if (ans[i] < 10)
			cout << '0';

		cout << ans[i];

		if (i != 2)
			cout << ':';
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