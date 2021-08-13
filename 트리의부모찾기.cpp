#include <iostream>
#include <vector>

using namespace std;
vector<int> r[100001];
vector<int> v(100001);

void recordparent(int p, int n)
{
	v[n] = p;
	for (int i = 0; i < r[n].size(); i++)
	{
		if (v[r[n][i]] == 0)
			recordparent(n, r[n][i]);
	}
}

int main(void)
{
	int n, num1, num2;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> num1 >> num2;
		r[num1].push_back(num2);
		r[num2].push_back(num1);
	}
	recordparent(1, 1);
	for (int i = 2; i <= n; i++)
		cout << v[i] << '\n';
	return 0;
}