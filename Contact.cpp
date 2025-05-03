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
			// �ڿ� 0�� �� �� �̻� ���� �� üũ
			if (i + 2 >= s.length() || s[i + 1] == '1' || s[i + 2] == '1')
			{
				ans = "NO";
				break;
			}

			// �ڿ� 0 ��� ó��
			i++;
			while (i < s.length() && s[i] == '0') i++;

			// �ٷ� �ڿ� 1�� ������ üũ
			if (i >= s.length())
			{
				ans = "NO";
				break;
			}

			// �ڿ� 1 ��� ó��
			while (i < s.length() && s[i] == '1') i++;
			i--;
			continue;
		}

		// �ڿ� 1�� ������ üũ
		if (i + 1 < s.length() && s[i + 1] == '1') i++;

		// 100+1+�� Ȯ��
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