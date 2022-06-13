#include <iostream>

using namespace std;

int n, m, root[201], height[201];
// root -> i번째 노드의 부모노드
// rank -> i번째 노드의 트리 높이

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

	if (aroot == broot)                     // 부모노드가 같다면 굳이 합칠 필요 x
		return;

	if (height[aroot] < height[broot])      // broot가 더 높다면
		root[aroot] = broot;

	else
		root[broot] = aroot;

	height[aroot]++;                        // 두 트리의 길이가 같다면 broot 밑에 aroot의 트리가 하나 더 달리는 거기 때문에 +1
}

void solution()
{
	cin >> n >> m;

	// 자신을 부모노드로 등록
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