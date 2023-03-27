#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	if (s == "NLCS")
		cout << "North London Collegiate School";

	else if (s == "BHA")
		cout << "Branksome Hall Asia";

	else if (s == "KIS")
		cout << "Korea International School";

	else
		cout << "St. Johnsbury Academy";
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