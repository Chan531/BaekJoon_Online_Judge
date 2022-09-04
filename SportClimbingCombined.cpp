#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int mul, sum, num;
};

int n;
node arr[100];

bool cmp(node a, node b)
{
	if (a.mul == b.mul)
	{
		if (a.sum == b.sum)
			return a.num < b.num;
		
		return a.sum < b.sum;
	}

	return a.mul < b.mul;
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num, a, b, c;

		cin >> num >> a >> b >> c;
		
		arr[i].mul = a * b * c;
		arr[i].sum = a + b + c;
		arr[i].num = num;
	}
}

void solution()
{
	sort(arr, arr + n, cmp);

	cout << arr[0].num << ' ' << arr[1].num << ' ' << arr[2].num;
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