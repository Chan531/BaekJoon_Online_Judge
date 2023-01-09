// 시간복잡도 : O(2^10 / 2 * N * N) 2^10 / 2 -> 총 조합의 개수(2로 나눈 이유는 12345를 확인하면 678910을 확인할 필요가 없기 때문), N * N -> 모든 노드가 서로 연결되어있는 상태일 때 
// 어려웠던 점 : 맨 처음 30분 정도 방법만 생각하다가 시간을 다 보냄.. 코드를 쳐보다가 아이디어가 생각 난 케이스. 생각보다 문제에서 신경 쓸 조건들이 많아서 맞왜틀.. 코드 싹 다 지워서 다시 치니까 맞음. 전역으로 선언하지 않은 target 배열이 원인으로 추정됨

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, pop[11], target[11], popsum, poppart, ans = 1e9;
// pop -> i번째 노드의 인구수, target -> 선거구의 연결여부를 확인할 때 타깃이 되는 노드 체크, popsum -> 총 인구수, poppart -> 한 선거구의 인구수
vector<int> con[11];
// i번째 노드와 연결된 노드 모음
string rec = "";
// '0'과 '1'로 선거구 나누고 기록
unordered_map<string, int> check;
// 선거구 중복 체크 방지 (ex. 123 456을 체크한 후 나중에 456 123 체크 방지)

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> pop[i];
		popsum += pop[i]; // 인구수 입력과 동시에 더해놓음
	}

	for (int i = 1; i <= n; i++)
	{
		int m, q;
		cin >> m;

		while (m--)
		{
			cin >> q;
			con[i].push_back(q); // 연결된 노드 기록
		}
	}
}

// 중복 체크 방지를 위한 '0', '1' 리버스 함수
string rev(string rec)
{
	for (int i = 0; i < n; i++)
	{
		if (rec[i] == '0')
			rec[i] = '1';

		else
			rec[i] = '0';
	}

	return rec;
}

// 연결된 노드들인지 확인
bool bfs(char c)
{
	queue<int> q;
	poppart = 0; // 한 선거구의 총 인구수
	int cnt = 0; // 한 선거구의 총 노드 개수 - 1 (queue에 넣은 건 더해주지 않음)
	memset(target, 0, sizeof(target)); // taget배열 재사용

	for (int i = 1; i <= n; i++)
	{
		// 같은 선거구가 아니라면 pass
		if (rec[i - 1] != c)
			continue;
		
		// 같은 선거구 인구수 더해주기
		poppart += pop[i];

		// bfs 시작을 위해 첫 선거구 노드는 queue에 넣어주기만 하기
		if (q.empty())
		{
			q.push(i);
			continue;
		}

		// 나머지는 체크
		target[i] = 1;
		cnt++;
	}

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < con[pos].size(); i++)
		{
			int next = con[pos][i];

			// 타겟이라면
			if (target[next] == 1)
			{
				target[next] = 0;
				cnt--;
				q.push(next);
			}
		}
	}

	// 다 연결되어 있다면
	if (cnt == 0)
		return true;

	return false;
}

// 모든 조합을 보기 위한 백트래킹
void backtrack(int node, int target, int cnt)
{
	// 선거구 지역 개수가 목표치로 채워졌다면
	if (target == cnt)
	{
		if (check[rec] != 1)
		{
			// 중복 방지 체크
			check[rec] = 1;
			check[rev(rec)] = 1;

			// 두 구역으로 나눠진 선거구 모두 연결됨을 충족할 때
			if (bfs('0') && bfs('1'))
				ans = min(ans, abs(popsum - 2 * poppart));
		}

		return;
	}

	for (int i = node + 1; i <= n; i++)
	{
		rec[i - 1] = '1';
		backtrack(i, target, cnt + 1);
		rec[i - 1] = '0';
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		rec += '0';

	// 현재 노드, 목표치 노드 개수, 현재 노드 개수
	for (int i = 1; i < n; i++)
		backtrack(0, i, 0);

	// ans가 그대로라면 두 구역으로 나눌 수 없음을 의미함
	ans == 1e9 ? cout << -1 : cout << ans;
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