// 시간 복잡도 : O(n), 투포인터
// 공간 복잡도 : 100000 * 4byte
// 어려웠던 부분 : x, 다른 잘 알려진 문제와 아예 똑같음

#include <iostream>
#include <cmath>

using namespace std;

int n, arr[100000], ans = 1e9;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	// 투포인터를 위한 인덱스 설정
	int s = 0, e = n - 1;

	while (s < e)
	{
		// 용액 혼합
		int val = arr[s] + arr[e];

		// 절댓값이 더 작은 값이 0에 가까운 값이므로
		if (abs(ans) > abs(val))
			ans = val;

		// 절댓값이 더 큰 수를 넘겨줌
		if (abs(arr[s]) > abs(arr[e]))
			s++;

		else
			e--;
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