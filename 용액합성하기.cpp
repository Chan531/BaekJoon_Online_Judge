// �ð� ���⵵ : O(n), ��������
// ���� ���⵵ : 100000 * 4byte
// ������� �κ� : x, �ٸ� �� �˷��� ������ �ƿ� �Ȱ���

#include <iostream>
#include <cmath>

using namespace std;

int n, arr[100000], ans = 1e9;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	// �������͸� ���� �ε��� ����
	int s = 0, e = n - 1;

	while (s < e)
	{
		// ��� ȥ��
		int val = arr[s] + arr[e];

		// ������ �� ���� ���� 0�� ����� ���̹Ƿ�
		if (abs(ans) > abs(val))
			ans = val;

		// ������ �� ū ���� �Ѱ���
		if (abs(arr[s]) > abs(arr[e]))
			s++;

		else
			e--;
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