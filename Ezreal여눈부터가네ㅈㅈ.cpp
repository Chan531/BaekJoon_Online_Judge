#include <iostream>
#include <vector>
#define num 1000000007;

using namespace std;

int n;	
long long arr[3][1516];      // 나머지, 자릿수

void setdp()
{
	arr[0][1] = 0;
	arr[1][1] = 0;
	arr[2][1] = 1;
}

void solve()
{
	cin >> n;
	setdp();
	for (int i = 2; i <= n; i++)
	{
		arr[0][i] = (arr[1][i - 1] + arr[2][i - 1]) % num;
		arr[1][i] = (arr[0][i - 1] + arr[2][i - 1]) % num;
		arr[2][i] = (arr[0][i - 1] + arr[1][i - 1]) % num;
	}
	cout << arr[0][n];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}