#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	if (s == "SONGDO")
		cout << "HIGHSCHOOL";

	else if (s == "CODE")
		cout << "MASTER";

	else if (s == "2023")
		cout << "0611";

	else
		cout << "CONTEST";
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