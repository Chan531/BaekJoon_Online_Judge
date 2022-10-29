#include <iostream>

using namespace std;

string pw;

void input()
{
	cin >> pw;
}

void solution()
{
	if (pw == "end")
		exit(0);

	bool vow = 0;
	int consonant = 0;
	int vowel = 0;

	for (int i = 0; i < pw.length(); i++)
	{
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
		{
			vow = 1;
			consonant = 0;
			vowel++;
		}

		else
		{
			vowel = 0;
			consonant++;
		}

		if (i != 0 && pw[i - 1] == pw[i] && pw[i] != 'e' && pw[i] != 'o')
		{
			vow = 0;
			break;
		}

		if (consonant == 3 || vowel == 3)
		{
			vow = 0;
			break;
		}
	}

	if (!vow)
		cout << '<' << pw << "> is not acceptable.\n";

	else
		cout << '<' << pw << "> is acceptable.\n";
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