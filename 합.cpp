#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, check[10];                             // check -> ù �������� �ƴ���
long long ans = 0;
pair<long long, int> val[10];                 // first -> ��, second -> ����
string num[50];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
}

void solution()
{
	for (int i = 1; i < 10; i++)             // ���� �ʱ�ȭ
		val[i].second = i;

	for (int i = 0; i < n; i++)
	{
		int len = num[i].length();
		check[num[i][0] - 'A'] = 1;          // ù ���� ǥ��

		for (int j = 0; j < len; j++)
		{
			char alpha = num[i][j];
			val[alpha - 'A'].first += pow(10, len - j - 1);
		}
	}

	sort(val, val + 10, greater<pair<long long, int>>());

	int idx = 8;
	while (1)                                // ù ���ڰ� 0�� �� ���� swap
	{
		if (check[val[9].second])
			val[9].swap(val[idx--]);

		else
			break;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!val[i].first)
			break;

		ans += val[i].first * (9 - i);
	}

	cout << ans;
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