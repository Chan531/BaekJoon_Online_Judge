#include <iostream>
#include <vector>

using namespace std;
vector<int> visited(9);                    // 방문처리
vector<vector<int>> v(9);                  // 다른 숫자 담기
vector<int> w;                             // 출력할 숫자 담기

void backtrack(int a, int n, int m)
{
	if (!m)                                // m이 0이라면, w에 m개의 원소가 담겼다는 뜻이므로 모두 배출(?) 해준다. 깔깔
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = 0; j < v[a].size(); j++)
	{
		if (!visited[v[a][j]])             // 방문하지 않았다면 main과 똑같이 실행
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
	for (int i = 1; i <= n; i++)          // 2차원 벡터를 생성해 자기 자신을 제외한 수들을 모두 넣어준다.
	{
		for (int j = 1; j <= n; j++)
			if (i != j)
				v[i].push_back(j);
	}
	for (int i = 1; i <= n; i++)
	{
		w.push_back(i);                  // w벡터에 자기 자신을 넣어주고 시작한다! (이게 놓쳤던 첫번째 포인트)
		visited[i] = 1;
		backtrack(i, i, m - 1);          // 원소 한 개가 들어있는 상태이므로 m - 1
		w.pop_back();                    // 자기 자신을 넣어주고 시작할 생각을 못했기 때문에 자연스럽게 놓친 두번째 포인트
		visited[i] = 0;
	}
	return 0;
}