#include <iostream>
#include <algorithm>

using namespace std;

int n, m, map[500][500], ans;
int dir[57][2] = { {0, 1}, {0, 2}, {0, 3}, {1, 0}, {2, 0}, {3, 0}, {0, 1}, {1, 0}, {1, 1}, {1, 0}, {2, 0}, {2, 1},
{1, 0}, {0, 1}, {0, 2}, {0, 1}, {1, 1}, {2, 1}, {0, 1}, {0, 2}, {-1, 2}, {0, 1}, {-1, 1}, {-2, 1},
{1, 0}, {1, 1}, {1, 2}, {0, 1}, {1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 2}, {0, 1}, {1, 0}, {-1, 1},
{1, 0}, {1, 1}, {2, 1}, {0, 1}, {1, 1}, {1, 2}, {0, 1}, {-1, 1}, {-1, 2}, {0, 1}, {-1, 1}, {1, 1},
{-1, 0}, {1, 0}, {0, 1}, {1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, 2}, {1, 1} };

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void testcase(int t)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = t; k < t + 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void solution()
{
	for (int i = 0; i < 19; i++)
		testcase(3 * i);

	cout << ans << '\n';
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

/* ���� Ǭ Ǯ��...������������������������
������ 8ms ����....
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, map[500][500], ans;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void case1()             // ��
{
	int dir[3][2] = { {1, 0},{2,0},{3,0} };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case2()             // ��
{
	int dir[3][2] = { {0, 1},{0,2},{0,3} };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case3()             // ��
{
	int dir[3][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case4()             // ��(1)
{
	int dir[3][2] = { { 0, 1 }, { 1, 0 }, { 0, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case5()             // ��(2)
{
	int dir[3][2] = { { 1, 0 }, { 2, 0 }, { 2, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case6()             // ��(3)
{
	int dir[3][2] = { { 0, 1 }, { 0, 2 }, { -1, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case7()             // ��(4)
{
	int dir[3][2] = { { 0, 1 }, { 1, 1 }, { 2, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case8()             // ����(1)
{
	int dir[3][2] = { { 1, 0 }, { 1, 1 }, { 2, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case9()             // ����(2)
{
	int dir[3][2] = { { 0, 1 }, { -1, 1 }, { -1, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case10()             // ��
{
	int dir[3][2] = { { 0, 1 }, { -1, 1 }, { 1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case11()             // ��
{
	int dir[3][2] = { { 1, 0 }, { 1, -1 }, { 1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case12()             // ��
{
	int dir[3][2] = { { 0, 1 }, { 0, 2 }, { 1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case13()             // ��
{
	int dir[3][2] = { { 1, 0 }, { 2, 0 }, { 1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case14()             // ��(5)
{
	int dir[3][2] = { { 0, 1 }, { -1, 1 }, { -2, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case15()             // ��(6)
{
	int dir[3][2] = { { 1, 0 }, { 1, 1 }, { 1, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case16()             // ��(7)
{
	int dir[3][2] = { { 1, 0 }, { 0, 1 }, { 2, 0 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case17()             // ��(8)
{
	int dir[3][2] = { { 0, 1 }, { 0, 2 }, { 1, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case18()             // ����(3)
{
	int dir[3][2] = { { 0, 1 }, { 1, 0 }, { -1, 1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void case19()             // ����(4)
{
	int dir[3][2] = { { 0, 1 }, { 1, 1 }, { 1, 2 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = map[i][j];
			int cnt = 0;

			for (int k = 0; k < 3; k++)
			{
				int ny = i + dir[k][0];
				int nx = j + dir[k][1];

				if (ny >= n || ny < 0 || nx >= m || nx < 0)
					break;

				sum += map[ny][nx];
				cnt++;
			}

			if (cnt == 3)
				ans = max(ans, sum);
		}
	}
}

void solution()
{
	case1();
	case2();
	case3();
	case4();
	case5();
	case6();
	case7();
	case8();
	case9();
	case10();
	case11();
	case12();
	case13();
	case14();
	case15();
	case16();
	case17();
	case18();
	case19();

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