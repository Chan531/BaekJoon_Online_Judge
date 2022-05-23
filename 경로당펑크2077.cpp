#include <iostream>

using namespace std;

int lastword(char c)
{
	if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' || c == 'z' || c == 'x' || c == 'c' || c == 'v')
		return 1;

	return 0;
}

void solve()
{
	int n;
	string name;
	
	cin >> n >> name;

	cout << lastword(name[n - 1]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}