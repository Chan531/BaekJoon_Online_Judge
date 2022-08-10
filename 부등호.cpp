#include <iostream>
#include <vector>

using namespace std;

int n;
char sign[9];
bool check[10];
vector<string> list;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> sign[i];
}

void backtrack(string num, int idx)
{
	if (idx == n)
	{
		list.push_back(num);
		return;
	}

	for (char i = '0'; i <= '9'; i++)
	{
		if (check[i - '0'])
			continue;

		if (sign[idx] == '<' && num[idx] < i)
		{
			check[i - '0'] = 1;
			backtrack(num + i, idx + 1);
			check[i - '0'] = 0;
		}

		if (sign[idx] == '>' && num[idx] > i)
		{
			check[i - '0'] = 1;
			backtrack(num + i, idx + 1);
			check[i - '0'] = 0;
		}
	}
}

void solution()
{
	for (char i = '0'; i <= '9'; i++)
	{
		string num = "";
		check[i - '0'] = 1;
		backtrack(num + i, 0);
		check[i - '0'] = 0;
	}

	cout << list[list.size() - 1] << '\n' << list[0];
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