#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, k, m, p, a, b;
int cnt[1001], seq[1001][2];                  // �ش� ���� ������ ������ ����, �ش� ����� ���� (������ i�� ���� 1���� ���, 2�� �̻��� ���)
vector<int> to[1001];                         // �ش� ��忡�� �̾����� ��� ���

void input()
{
	cin >> k >> m >> p;
	while (p--)
	{
		cin >> a >> b;
		cnt[b]++;
		to[a].push_back(b);
	}
}

void solution()
{
	queue<int> q;

	for (int i = 1; i <= m; i++)
	{
		if (!cnt[i])                         // ���������� 0�� ����� ������ 1�� ���� �� ť�� ����
		{
			seq[i][0] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < to[pos].size(); i++)
		{
			int npos = to[pos][i];
			cnt[npos]--;                                    // �湮 ó��

			// ���� ����� ���� ����

			if (seq[npos][0] < seq[pos][0])                // ������ ���簡 �� ũ�ٸ� ���� ���� ����
				seq[npos][0] = seq[pos][0];

			else if (seq[npos][0] == seq[pos][0])          // ������ ���� ���ٸ�
				seq[npos][1] = max(seq[npos][1], seq[pos][0] + 1);

			if (!cnt[npos])                                // ���� ��� ���� ��θ� Ȯ���ߴٸ� ������ ���� �� ť�� ����
			{
				seq[npos][0] = max(seq[npos][0], seq[npos][1]);
				q.push(npos);
			}
		}
	}
	cout << k << ' ' << max(seq[m][0], seq[m][1]) << '\n';
}

void reset()
{
	for (int i = 1; i <= m; i++)
	{
		to[i].clear();
		cnt[i] = 0;
		seq[i][0] = 0;
		seq[i][1] = 0;
	}
}

void solve()
{
	cin >> t;
	while (t--)
	{
		input();
		solution();
		reset();
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