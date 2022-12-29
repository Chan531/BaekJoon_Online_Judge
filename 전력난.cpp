// �ð����⵵ : �켱���� ť ���� �� ���� O(n * log n), ����ȭ�� �и����� O(log m)�� m�� �ݺ� -> O(m * log m)
// �������⵵ : 200000 * 4byte (root[N]) + �ִ� 200000���� ������ ��� node�� �켱���� ť 200000 * 12byte -> 320kb
// ������� �κ� : �ּ� ���д� Ʈ���� ���� Ǯ�� �� �� �ִٴ� �� �� ���� ĳġ���� ���߰�(�� 10�� �Һ�) ĳġ�� ���� �켱���� ť�� ���Լ��� �����ϴ� �������� �Ǵٽ� ���۸� �� ���� �켱���� ť�� �и������� �ð����⵵�� ȥ�� ������ ������ ���ϰ� �ٷ� ���۸��ع��� �������� �׷��� �ʵ���.

#include <iostream>
#include <queue>
#define N 200000 // ���� �� m�� �ִ� (0 �� x, y < m)

using namespace std;

struct node {
	int x, y, dis;
	// �� ��ȣ x, y�� �� ������ �Ÿ�
};

int n, m, root[N];
// ���� ��, ���� ��

void input()
{
	cin >> m >> n;
}

// �켱���� ť �������� ����
struct cmp
{
	bool operator()(node a, node b)
	{
		return a.dis > b.dis;
	}
};

// �и� ���� ó��
int find(int a)
{
	if (a == root[a])
		return a;

	return root[a] = find(root[a]);
}

void solution()
{
	// �ּ� ���д� Ʈ�� Ȱ���� ���� �������� �켱���� ť
	priority_queue<node, vector<node>, cmp> pq;
	int ans = 0;

	while (n--)
	{
		// x�� ���� y�� �� ���̿� ����� ���ΰ� ������ �� �Ÿ��� z����
		int x, y, z;
		cin >> x >> y >> z;

		// ������ ���� �˱� ���� ��� �Ÿ� �����ֱ�
		ans += z;
		pq.push({ x,y,z });
	}

	// �и� ���� ��Ʈ �ʱ� ����
	for (int i = 0; i < m; i++)
		root[i] = i;

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int dis = pq.top().dis;
		pq.pop();

		// �Ҽӵ� ���� ã���ֱ�
		int xroot = find(x);
		int yroot = find(y);

		// ���� ���ٸ� ����Ŭ �߻�
		if (xroot == yroot)
			continue;

		// �� �Ÿ��� ������ �Ѿ��ϹǷ� ������ �Ÿ� x
		ans -= dis;

		// �� ���� ���� ������ ��ǥ������ ����
		if (xroot < yroot)
			root[yroot] = xroot;

		else
			root[xroot] = yroot;
	}

	cout << ans << '\n';
}

void solve()
{
	while (1)
	{
		input();

		// �Է��� �������� ù �ٿ� 0�� 2�� �־�����.
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