#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	if (s == "fdsajkl;" || s == "jkl;fdsa")
		cout << "in-out";

	else if (s == "asdf;lkj" || s == ";lkjasdf")
		cout << "out-in";

	else if (s == "asdfjkl;")
		cout << "stairs";

	else if (s == ";lkjfdsa")
		cout << "reverse";

	else
		cout << "molu";
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