#include <iostream>

using namespace std;

int n, m, a, b, root[500001], ans;

void input()
{
	cin >> n >> m;
}

int find(int k)
{
	if (root[k] == k)
		return k;

	return root[k] = find(root[k]);
}

void solution()
{
	// ��Ʈ��� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		// ��Ʈ ��尡 ���ٸ� ����Ŭ�� �̷�� ���� �ǹ�
		if (aroot == broot)
		{
			ans = i;
			break;
		}

		// �� ���� ���� ��Ʈ���� ����
		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
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

// ���� ��� Ǯ��
// �޸� �ð� �� �� �� ��±���

/*
#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, ans;

void input()
{
	cin >> n >> m;
}

int find(int k, vector<int> &root)
{
	if (root[k] == k)
		return k;

	return root[k] = find(root[k], root);
}

void solution()
{
	vector<int> root(n + 1);

	// ��Ʈ��� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;

		int aroot = find(a, root);
		int broot = find(b, root);

		// ��Ʈ ��尡 ���ٸ� ����Ŭ�� �̷�� ���� �ǹ�
		if (aroot == broot)
		{
			ans = i;
			break;
		}

		// �� ���� ���� ��Ʈ���� ����
		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
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
*/