#include <iostream>

using namespace std;

string s, ans;

void input()
{
	cin >> s;
}

void solution()
{
	ans = "YES";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			// 뒤에 0이 두 개 이상 오는 지 체크
			if (i + 2 >= s.length() || s[i + 1] == '1' || s[i + 2] == '1')
			{
				ans = "NO";
				break;
			}

			// 뒤에 0 모두 처리
			i++;
			while (i < s.length() && s[i] == '0') i++;

			// 바로 뒤에 1이 오는지 체크
			if (i >= s.length())
			{
				ans = "NO";
				break;
			}

			// 뒤에 1 모두 처리
			while (i < s.length() && s[i] == '1') i++;
			i--;
			continue;
		}

		// 뒤에 1이 오는지 체크
		if (i + 1 < s.length() && s[i + 1] == '1') i++;

		// 100+1+도 확인
		else if (i - 2 >= 0 && s[i - 2] == '1') i -= 2;
		else
		{
			ans = "NO";
			break;
		}
	}

	cout << ans << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while(tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}