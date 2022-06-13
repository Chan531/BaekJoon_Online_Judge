#include <iostream>

using namespace std;

int n, m, root[201], height[201];
// root -> i��° ����� �θ���
// rank -> i��° ����� Ʈ�� ����

int find(int num)
{
	if (root[num] == num)
		return num;

	return root[num] = find(root[num]);
}

void connect(int a, int b)
{
	int aroot = find(a);
	int broot = find(b);

	if (aroot == broot)                     // �θ��尡 ���ٸ� ���� ��ĥ �ʿ� x
		return;

	if (height[aroot] < height[broot])      // broot�� �� ���ٸ�
		root[aroot] = broot;

	else
		root[broot] = aroot;

	height[aroot]++;                        // �� Ʈ���� ���̰� ���ٸ� broot �ؿ� aroot�� Ʈ���� �ϳ� �� �޸��� �ű� ������ +1
}

void solution()
{
	cin >> n >> m;

	// �ڽ��� �θ���� ���
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool check;
			cin >> check;
			
			if (check)
				connect(i, j);
		}
	}

	int a, b;
	cin >> a;

	while (cin >> b)
	{
		if (find(a) != find(b))
		{
			cout << "NO";
			return;
		}

		a = b;
	}

	cout << "YES";
}

void solve()
{
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