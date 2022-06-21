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
	// 루트노드 초기화
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		// 루트 노드가 같다면 사이클을 이루는 것을 의미
		if (aroot == broot)
		{
			ans = i;
			break;
		}

		// 더 작은 수를 루트노드로 설정
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

// 벡터 사용 풀이
// 메모리 시간 둘 다 더 드는구만

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

	// 루트노드 초기화
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;

		int aroot = find(a, root);
		int broot = find(b, root);

		// 루트 노드가 같다면 사이클을 이루는 것을 의미
		if (aroot == broot)
		{
			ans = i;
			break;
		}

		// 더 작은 수를 루트노드로 설정
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