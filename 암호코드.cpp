#include <iostream>
#include <vector>

using namespace std;

string code;
vector<int> dp(5001);

void check()
{
	if (code[0] == '0')                                       // ������ 0�� ��� ó��
	{
		cout << 0;
		exit(0);
	}

	for (int i = 0; i < code.length() - 1; i++)               // 0�� �������� �� �� �̻� �����ų� 30, 40 ���� ������ ��� ó��
	{
		if (code[i] == '0' && code[i + 1] == '0')
		{
			cout << 0;
			exit(0);
		}

		if (code[i] >= '3' && code[i + 1] == '0')
		{
			cout << 0;
			exit(0);
		}
	}

	if (code.length() == 1)                                  // ��ȣ�� ������ 1, 2�̸鼭 �� ������ ��� ó��
	{
		cout << 1;
		exit(0);
	}
}

void solve()
{
	cin >> code;
	check();
	for (int i = 0; i < code.length(); i++)
	{
		if (dp[i] != 0)                                    // 0�� �ƴ϶�� ó���� �� ����̹Ƿ� �Ѿ
			continue;

		if (code[i + 1] == '0')                            // ���� ���� ��ȣ�� 0�̶��
		{
			if (code[i] == '1' || code[i] == '2')          // 1 �Ǵ� 2 ��� 10, 20���� ó��                           
			{
				if (i > 0)
					dp[i + 1] = dp[i - 1];
				else
					dp[i + 1] = 1;
				i++;
				continue;
			}
		}

		if (i == 0)                                        // ������ ���� ���� ó��
		{
			dp[0] = 1;
			continue;
		}

		dp[i] += dp[i - 1];
		if (code[i - 1] != '0' && (code[i - 1] - '0') * 10 + code[i] - '0' <= 26)
		{
			if (i > 1)
				dp[i] += dp[i - 2];
			else
				dp[i]++;
		}
		dp[i] %= 1000000;
	}
	cout << dp[code.length() - 1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}