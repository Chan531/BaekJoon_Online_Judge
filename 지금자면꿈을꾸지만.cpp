#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, arr[101], ans;

void input()
{
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr + 1, arr + n + 1);

	for (int i = 0; i < a; i++)	// x
	{
		for (int j = 1; j <= n; j++)	// �ڴ� ����
		{
			int temp = 0, cnt = 0;

			for (int k = 1; k <= n; k++)
			{
				if (k < j)	// �ڱ� ���̶��
					temp += a;

				else if (k == j)	// �ڴ� �����̶��
				{
					temp += b * i;
					temp += (a - i);
				}

				else if (k > j)	// �ڰ� �� �� Ǫ�� �������
					temp += (a - i);

				if (temp <= arr[k])	// ������ �ϰ� �� �� ������ ���״ٸ�
					cnt++;

				// ��Ű�� ���ߴٸ� �� ������ �� Ǭ�ɷ� ����.
				else
				{
					if (k < j)
						temp -= a;

					else if (k >= j)
						temp -= (a - i);
				}

				ans = max(ans, cnt);
			}
		}
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

	solve();
	return 0;
}