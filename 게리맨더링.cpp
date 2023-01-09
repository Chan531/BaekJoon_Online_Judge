// �ð����⵵ : O(2^10 / 2 * N * N) 2^10 / 2 -> �� ������ ����(2�� ���� ������ 12345�� Ȯ���ϸ� 678910�� Ȯ���� �ʿ䰡 ���� ����), N * N -> ��� ��尡 ���� ����Ǿ��ִ� ������ �� 
// ������� �� : �� ó�� 30�� ���� ����� �����ϴٰ� �ð��� �� ����.. �ڵ带 �ĺ��ٰ� ���̵� ���� �� ���̽�. �������� �������� �Ű� �� ���ǵ��� ���Ƽ� �¿�Ʋ.. �ڵ� �� �� ������ �ٽ� ġ�ϱ� ����. �������� �������� ���� target �迭�� �������� ������

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, pop[11], target[11], popsum, poppart, ans = 1e9;
// pop -> i��° ����� �α���, target -> ���ű��� ���Ῡ�θ� Ȯ���� �� Ÿ���� �Ǵ� ��� üũ, popsum -> �� �α���, poppart -> �� ���ű��� �α���
vector<int> con[11];
// i��° ���� ����� ��� ����
string rec = "";
// '0'�� '1'�� ���ű� ������ ���
unordered_map<string, int> check;
// ���ű� �ߺ� üũ ���� (ex. 123 456�� üũ�� �� ���߿� 456 123 üũ ����)

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> pop[i];
		popsum += pop[i]; // �α��� �Է°� ���ÿ� ���س���
	}

	for (int i = 1; i <= n; i++)
	{
		int m, q;
		cin >> m;

		while (m--)
		{
			cin >> q;
			con[i].push_back(q); // ����� ��� ���
		}
	}
}

// �ߺ� üũ ������ ���� '0', '1' ������ �Լ�
string rev(string rec)
{
	for (int i = 0; i < n; i++)
	{
		if (rec[i] == '0')
			rec[i] = '1';

		else
			rec[i] = '0';
	}

	return rec;
}

// ����� �������� Ȯ��
bool bfs(char c)
{
	queue<int> q;
	poppart = 0; // �� ���ű��� �� �α���
	int cnt = 0; // �� ���ű��� �� ��� ���� - 1 (queue�� ���� �� �������� ����)
	memset(target, 0, sizeof(target)); // taget�迭 ����

	for (int i = 1; i <= n; i++)
	{
		// ���� ���ű��� �ƴ϶�� pass
		if (rec[i - 1] != c)
			continue;
		
		// ���� ���ű� �α��� �����ֱ�
		poppart += pop[i];

		// bfs ������ ���� ù ���ű� ���� queue�� �־��ֱ⸸ �ϱ�
		if (q.empty())
		{
			q.push(i);
			continue;
		}

		// �������� üũ
		target[i] = 1;
		cnt++;
	}

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < con[pos].size(); i++)
		{
			int next = con[pos][i];

			// Ÿ���̶��
			if (target[next] == 1)
			{
				target[next] = 0;
				cnt--;
				q.push(next);
			}
		}
	}

	// �� ����Ǿ� �ִٸ�
	if (cnt == 0)
		return true;

	return false;
}

// ��� ������ ���� ���� ��Ʈ��ŷ
void backtrack(int node, int target, int cnt)
{
	// ���ű� ���� ������ ��ǥġ�� ä�����ٸ�
	if (target == cnt)
	{
		if (check[rec] != 1)
		{
			// �ߺ� ���� üũ
			check[rec] = 1;
			check[rev(rec)] = 1;

			// �� �������� ������ ���ű� ��� ������� ������ ��
			if (bfs('0') && bfs('1'))
				ans = min(ans, abs(popsum - 2 * poppart));
		}

		return;
	}

	for (int i = node + 1; i <= n; i++)
	{
		rec[i - 1] = '1';
		backtrack(i, target, cnt + 1);
		rec[i - 1] = '0';
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		rec += '0';

	// ���� ���, ��ǥġ ��� ����, ���� ��� ����
	for (int i = 1; i < n; i++)
		backtrack(0, i, 0);

	// ans�� �״�ζ�� �� �������� ���� �� ������ �ǹ���
	ans == 1e9 ? cout << -1 : cout << ans;
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