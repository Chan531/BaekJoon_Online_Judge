// ���� �̿��� Ǯ�� -> �켱���� ť���� �޸� �ð� ȿ�� good

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, l;
vector<int> arr(5000001);

void input()
{
	cin >> n >> l;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; i++)
	{
		while (!dq.empty() && dq.back().first > arr[i])    // ���� �� ���� �� �� ���� �ֵ� ����
			dq.pop_back();

		dq.push_back({ arr[i], i });

		while (dq.front().second < i - l + 1)              // ������ ���� �ֵ� ����
			dq.pop_front();

		cout << dq.front().first << ' ';
	}
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


// �켱���� ť�� �̿��� Ǯ�� -> ������ �߻��� ���� ���� but ȿ�� bad
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l;
vector<int> arr(5000001);

void input()
{
	cin >> n >> l;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 1; i <= n; i++)
	{
		pq.push({ arr[i], i });

		while (pq.top().second < i - l + 1)      // ������ ���� �ֵ� ����
			pq.pop();

		cout << pq.top().first << ' ';
	}
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