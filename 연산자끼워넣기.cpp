#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[11], op[4], minans = 1e9, maxans = -1e9;              // 숫자 개수, 수 배열, 연산 기호 개수

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
}

int calculate(int seq, int val, int num)
{
	if (seq == 0)
		return val + num;
	else if (seq == 1)
		return val - num;
	else if (seq == 2)
		return val * num;
	else
		return val / num;
}

void backtrack(int cnt, int val)
{
	if (cnt == n - 1)
	{
		maxans = max(val, maxans);
		minans = min(val, minans);
		return;
	}

	for (int j = 0; j < 4; j++)
	{
		if (op[j])
		{
			op[j]--;
			backtrack(cnt + 1, calculate(j, val, arr[cnt + 1]));
			op[j]++;
		}
	}
}

void solution()
{
	for (int i = 0; i < 4; i++)
	{
		if (op[i])
			backtrack(0, arr[0]);
	}
	cout << maxans << '\n' << minans;
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