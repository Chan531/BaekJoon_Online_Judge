#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, num, ans = 0;
vector<vector<int>> map(8, vector<int>(8)), finish(8, vector<int>(8)), testmap(8, vector<int>(8)), virusmap(8, vector<int>(8)), dir = { {-1, 0},{0, 1},{1,0},{0,-1} };

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            map[i][j] = num;
        }
    }
}

void maketestmap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            testmap[i][j] = map[i][j];
    }
}

void makevirusmap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            virusmap[i][j] = testmap[i][j];
    }
}

void test()
{
    int cnt = 0;
    queue<pair<int, int>> virus;
    makevirusmap();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (virusmap[i][j] == 2)
                virus.push({ i, j });
        }
    }

    while (!virus.empty())
    {
        int y = virus.front().first;
        int x = virus.front().second;
        virus.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = y + dir[k][0];
            int nx = x + dir[k][1];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && virusmap[ny][nx] == 0)
            {
                virusmap[ny][nx] = 2;
                virus.push({ ny, nx });
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!virusmap[i][j])
                cnt++;
        }
    }
    ans = max(ans, cnt);
}

void installwall(int cnt)
{
    if (cnt == 3)
    {
        test();
        return;
    }

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            if (testmap[a][b] == 0)
            {
                testmap[a][b] = 1;
                installwall(cnt + 1);
                testmap[a][b] = 0;
            }
        }
    }
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                maketestmap();
                testmap[i][j] = 1;
                installwall(1);
                testmap[i][j] = 0;
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