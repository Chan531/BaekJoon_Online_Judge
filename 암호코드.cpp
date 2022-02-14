#include <iostream>
#include <vector>

using namespace std;

string code;
vector<int> dp(5001);

void check()
{
	if (code[0] == '0')                                       // 시작이 0인 경우 처리
	{
		cout << 0;
		exit(0);
	}

	for (int i = 0; i < code.length() - 1; i++)               // 0이 연속으로 두 번 이상 나오거나 30, 40 등이 나오는 경우 처리
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

	if (code.length() == 1)                                  // 암호의 시작이 1, 2이면서 한 글자인 경우 처리
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
		if (dp[i] != 0)                                    // 0이 아니라면 처리가 된 경우이므로 넘어감
			continue;

		if (code[i + 1] == '0')                            // 만약 다음 암호가 0이라면
		{
			if (code[i] == '1' || code[i] == '2')          // 1 또는 2 라면 10, 20으로 처리                           
			{
				if (i > 0)
					dp[i + 1] = dp[i - 1];
				else
					dp[i + 1] = 1;
				i++;
				continue;
			}
		}

		if (i == 0)                                        // 시작일 때만 따로 처리
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