// 시간복잡도 : O(N * N * M) / 가장 마지막 크레인만이 박스 10000개를 처리할 수 있다고 가정할 때
// 공간복잡도 : 4byte * 10100
// 어려웠던 부분 : n이 50이라는 작은 수라는 것을 간과하여 전부 탐색할 생각조차 안 해서 arr 배열 해결에 시간을 다 써버림 또한 erase는 금기라고 생각해왔는데 erase를 사용한 풀이가 많아서 놀람

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, crane[50], box[10000], arr[50], ans = 1e9;
// 크레인의 무게 제한, 박스의 무게, 이전 크레인이 처리할 수 있는 모든 박스를 처리할 때 i번째 크레인이 처리해야하는 박스 수를 담는 배열

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> crane[i];

	cin >> m;

	for (int i = 0; i < m; i++)
		cin >> box[i];
}

void solution()
{
	// 무게 오름차순으로 정렬해주기
	sort(crane, crane + n);
	sort(box, box + m);

	// 박스의 index, arr 배열의 총합
	int idx = 0, sum = 0;

	for (int i = 0; i < n; i++)
	{
		// 크레인의 무게제한보다 박스가 가볍고 인덱스를 초과하지 않는다면 +1
		while (idx < m && box[idx++] <= crane[i])
			arr[i]++;

		// 총합에 더해주기 및 box[idx++]로 인한 인덱스 수정
		sum += arr[i];
		idx--;

		// sum == m이라면 남은 i번째 arr의 값은 0
		if (sum == m)
			break;
	}

	// 크레인의 무게제한을 초과하는 박스가 있을 때
	if (sum != m)
	{
		cout << -1;
		return;
	}

	// 처리한 박스의 개수, 걸린 시간
	int cnt = 0, ans = 0;

	// 처리한 박스의 개수와 총 박스의 수가 같아지면 탈출
	while (cnt != m)
	{
		// 시간 업데이트
		ans++;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j >= 0; j--)
			{
				// 박스 처리해주기
				if (arr[j])
				{
					arr[j]--;
					cnt++;
					break;
				}
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