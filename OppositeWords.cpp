#include <iostream>

using namespace std;

void solution()
{
	string word;
	int ans = 0;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
		if (isalpha(word[i]))
			ans += toupper(word[i]);

	ans % 155 ? cout << "No\n" : cout << "Yes\n";
}

void solve()
{
	int n;
	cin >> n;

	while (n--)
	{
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