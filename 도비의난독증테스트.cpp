#include <iostream>
#include <algorithm>
#define p pair<string, int>

using namespace std;

int n;
string str[1000];
p compstr[1000];

void input()
{
	cin >> n;

	if (n == 0)
		exit(0);

	for (int i = 0; i < n; i++)
		cin >> str[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		string word = str[i];
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		compstr[i].first = word;
		compstr[i].second = i;
	}

	sort(compstr, compstr + n);

	cout << str[compstr[0].second] << '\n';
}

void solve()
{
	while (1)
	{
		input();
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