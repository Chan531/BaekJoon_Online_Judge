#include <iostream>
#include <algorithm>

using namespace std;

string str;
int n;

void solution()
{
	do {
		n--;
		if (n == 0)
		{
			cout << str << '\n';
			return;
		}
	} while (next_permutation(str.begin(), str.end()));

	cout << "No permutation\n";
}

void solve()
{
	while (cin >> str >> n)
	{
		cout << str << ' ' << n << " = ";
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}