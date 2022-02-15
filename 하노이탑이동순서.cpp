#include <iostream>
#include <cmath>

using namespace std;

int n;

void hanoi(int from, int by, int to, int num)
{
	if (num == 1)                                // 맨 맽 원판만 남았다는 것을 의미하므로 출발지에서 목적지로 옮겨놓음
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(from, to, by, num - 1);                // n - 1개의 원판을 출발지에서 경유지로 옮겨야 하므로 -> 그래야 맨 밑 원판을 출발지에서 목적지로 옮기는 게 가능함
	cout << from << ' ' << to << '\n';           // n - 1개의 원판을 모두 경유지로 옮겨 놓았으므로 마지막 원판을 목적지로 놓아야 함
	hanoi(by, from, to, num - 1);                // 경유지에 옮겨 놓은 n - 1개의 원판을 목적지로 옮겨야 함 -> 이 때 출발지를 경유지로 이용
}

void solve()
{
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';          // 하노이탑 실행 횟수 
	hanoi(1, 2, 3, n);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}