#include <iostream>

using namespace std;

string s, K = "KOREA", Y = "YONSEI";

void input()
{
	cin >> s;
}

void solution()
{
	int kidx = 0, yidx = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (kidx == K.length())
		{
			cout << "KOREA";
			break;
		}

		if (yidx == Y.length())
		{
			cout << "YONSEI";
			break;
		}

		if (s[i] == K[kidx])
			kidx++;

		if (s[i] == Y[yidx])
			yidx++;
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
	cout.tie(NULL);

	solve();
	return 0;
}