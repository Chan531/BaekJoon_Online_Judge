#include <iostream>
#include <string>

using namespace std;

string kda;
int k, d, a;

void input()
{
	cin >> kda;
}

void solution()
{
	string num = "";
	int idx = 0;

	while (kda[idx] != '/')
	{
		num += kda[idx++];
	}

	k = stoi(num);
	num = "";
	idx++;

	while (kda[idx] != '/')
	{
		num += kda[idx++];
	}

	d = stoi(num);
	num = "";
	idx++;

	while (idx != kda.length())
	{
		num += kda[idx++];
	}

	a = stoi(num);

	if (d == 0 || k + a < d)
		cout << "hasu";

	else
		cout << "gosu";
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