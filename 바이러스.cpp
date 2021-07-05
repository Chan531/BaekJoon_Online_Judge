#include <iostream>
#include <vector>

using namespace std;

int check[1001];
vector<int> a[1001];
int infect = -1;

void virus(int x)
{
	if (check[x]) return;
	check[x] = true;
	infect++;
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		virus(y);
	}
}

int main(void)
{
	int n, m;
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	virus(1);
	cout << infect;
	return 0;
}