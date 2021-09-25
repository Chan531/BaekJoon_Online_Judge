#include <iostream>
#include <vector>

using namespace std;
vector<int> visited(9);                    // �湮ó��
vector<vector<int>> v(9);                  // �ٸ� ���� ���
vector<int> w;                             // ����� ���� ���

void backtrack(int a, int n, int m)
{
	if (!m)                                // m�� 0�̶��, w�� m���� ���Ұ� ���ٴ� ���̹Ƿ� ��� ����(?) ���ش�. ���
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = 0; j < v[a].size(); j++)
	{
		if (!visited[v[a][j]])             // �湮���� �ʾҴٸ� main�� �Ȱ��� ����
		{
			visited[v[a][j]] = 1;
			w.push_back(v[a][j]);
			backtrack(v[a][j], n, m - 1);
			w.pop_back();
			visited[v[a][j]] = 0;
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)          // 2���� ���͸� ������ �ڱ� �ڽ��� ������ ������ ��� �־��ش�.
	{
		for (int j = 1; j <= n; j++)
			if (i != j)
				v[i].push_back(j);
	}
	for (int i = 1; i <= n; i++)
	{
		w.push_back(i);                  // w���Ϳ� �ڱ� �ڽ��� �־��ְ� �����Ѵ�! (�̰� ���ƴ� ù��° ����Ʈ)
		visited[i] = 1;
		backtrack(i, i, m - 1);          // ���� �� ���� ����ִ� �����̹Ƿ� m - 1
		w.pop_back();                    // �ڱ� �ڽ��� �־��ְ� ������ ������ ���߱� ������ �ڿ������� ��ģ �ι�° ����Ʈ
		visited[i] = 0;
	}
	return 0;
}