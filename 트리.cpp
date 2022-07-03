#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
bool val[50];
vector<int> child[50];
// val -> ������������ ��� ���� (1 == ����), child -> �ڽ� ��� ���

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		// ��Ʈ��尡 �ƴ϶��
		if (num != -1)
			child[num].push_back(i);
	}

	cin >> m;
}

void solution()
{
	queue<int> q;
	q.push(m);
	val[m] = 1;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < child[pos].size(); i++)
		{
			int npos = child[pos][i];

			if (!val[npos])
			{
				val[npos] = 1;
				q.push(npos);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (val[i])
			continue;

		// ���� �������� ���� ���������
		if (!child[i].size())
				ans++;

		else
		{
			for (int j = 0; j < child[i].size(); j++)
			{
				// �ڽ� ��尡 �����ִٸ�
				if (!val[child[i][j]])
					break;

				// �ڽ��� ��� ������ �����
				if (j == child[i].size() - 1)
					ans++;
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