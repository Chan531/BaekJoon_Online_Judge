// �ð����⵵ : O(N * N * M) / ���� ������ ũ���θ��� �ڽ� 10000���� ó���� �� �ִٰ� ������ ��
// �������⵵ : 4byte * 10100
// ������� �κ� : n�� 50�̶�� ���� ����� ���� �����Ͽ� ���� Ž���� �������� �� �ؼ� arr �迭 �ذῡ �ð��� �� ����� ���� erase�� �ݱ��� �����ؿԴµ� erase�� ����� Ǯ�̰� ���Ƽ� ���

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, crane[50], box[10000], arr[50], ans = 1e9;
// ũ������ ���� ����, �ڽ��� ����, ���� ũ������ ó���� �� �ִ� ��� �ڽ��� ó���� �� i��° ũ������ ó���ؾ��ϴ� �ڽ� ���� ��� �迭

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> crane[i];

	cin >> m;

	for (int i = 0; i < m; i++)
		cin >> box[i];
}

void solution()
{
	// ���� ������������ �������ֱ�
	sort(crane, crane + n);
	sort(box, box + m);

	// �ڽ��� index, arr �迭�� ����
	int idx = 0, sum = 0;

	for (int i = 0; i < n; i++)
	{
		// ũ������ �������Ѻ��� �ڽ��� ������ �ε����� �ʰ����� �ʴ´ٸ� +1
		while (idx < m && box[idx++] <= crane[i])
			arr[i]++;

		// ���տ� �����ֱ� �� box[idx++]�� ���� �ε��� ����
		sum += arr[i];
		idx--;

		// sum == m�̶�� ���� i��° arr�� ���� 0
		if (sum == m)
			break;
	}

	// ũ������ ���������� �ʰ��ϴ� �ڽ��� ���� ��
	if (sum != m)
	{
		cout << -1;
		return;
	}

	// ó���� �ڽ��� ����, �ɸ� �ð�
	int cnt = 0, ans = 0;

	// ó���� �ڽ��� ������ �� �ڽ��� ���� �������� Ż��
	while (cnt != m)
	{
		// �ð� ������Ʈ
		ans++;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j >= 0; j--)
			{
				// �ڽ� ó�����ֱ�
				if (arr[j])
				{
					arr[j]--;
					cnt++;
					break;
				}
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
	cout.tie(NULL);

	solve();
	return 0;
}