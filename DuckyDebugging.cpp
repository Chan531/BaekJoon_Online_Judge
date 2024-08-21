#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{

}

void solution()
{
	while (1)
	{
		getline(cin, s);
		if (s.back() == '.')
			cout << "*Nod*" << endl;
		else if (s.back() == '?')
			cout << "Quack!" << endl;
		else if (s == "I quacked the code!")
			break;
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