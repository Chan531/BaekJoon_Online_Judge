#include <iostream>

using namespace std;

int n, m, seq, root[501]; // 0 : cycle
bool check[501]; // �ߺ� üũ ����

void input()
{
	cin >> n >> m;
}

int find(int n)
{
	if (root[n] == 0)
		return 0;

	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	// �ʱ� ����
	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		check[i] = 1;
	}

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		// �Ϲ����� Ʈ�� ����
		if (aroot < broot)
		{
			root[broot] = root[aroot];
			continue;
		}

		else if (aroot > broot)
		{
			root[aroot] = root[broot];
			continue;
		}

		// ����Ŭ �߰� ��
		else
		{
			root[aroot] = 0;
			continue;
		}
	}

	// Ʈ�� ���� �Ǻ�

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		int iroot = find(i);

		if (check[iroot] && root[iroot] != 0)
		{
			check[iroot] = 0;
			cnt++;
		}
	}

	if (cnt == 0)
		cout << "Case " << seq << ": No trees.\n";

	else if (cnt == 1)
		cout << "Case " << seq << ": There is one tree.\n";

	else
		cout << "Case " << seq << ": A forest of " << cnt << " trees.\n";

}

void solve()
{
	for (seq = 1; ; seq++)
	{
		input();

		if (n == 0 && m == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}