#include <iostream>
#include <cstring>

using namespace std;

string a, b;
int idx = 1, alpha[26];

void solution()
{
	for (int i = 0; i < a.length(); i++)
		alpha[a[i] - 'a']++;

	for (int i = 0; i < b.length(); i++)
		alpha[b[i] - 'a']--;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] != 0)
		{
			cout << "Case " << idx << ": different\n";
			return;
		}
	}

	cout << "Case " << idx << ": same\n";
}

void solve()
{
	while (1)
	{
		cin >> a >> b;

		if (a == "END" && b == "END")
			break;

		solution();
		memset(alpha, 0, sizeof(alpha));
		idx++;
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