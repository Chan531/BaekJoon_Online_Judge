#include <iostream>
#include <string>

using namespace std;

int n;
char map[5][32];
string code;

void input()
{
	for (int i = 0; i < 5; i++)
	{
		string s;
		getline(cin, s);
		n = s.length();

		for (int j = 0; j < n; j++)
			map[i][j] = s[j];
	}
}

string check(int cnt, int j)
{
	if (cnt == 5) return "1";
	else if (cnt == 9) return "4";
	else if (cnt == 7) return "7";
	else if (cnt == 13) return "8";
	else if (cnt == 12)
	{
		if (map[2][j + 1] == ' ') return "0";
		else if (map[3][j] == ' ') return "9";
		else return "6";
	}
	else
	{
		if (map[1][j + 2] == ' ') return "5";
		else if (map[3][j + 2] == ' ') return "2";
		else return "3";
	}
}

void solution()
{
	for (int j = 0; j < n; j += 4)
	{
		int cnt = 0;

		for (int i = 0; i < 5; i++)
			for (int k = 0; k < 3; k++)
				if (map[i][j + k] == '*')
					cnt++;

		code += check(cnt, j);
	}

	int ans = stoi(code);

	if (ans % 6) cout << "BOOM!!";
	else cout << "BEER!!";
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