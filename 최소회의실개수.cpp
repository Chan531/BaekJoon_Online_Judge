// �ð����⵵ : �켱���� ť ���� �� ���� O(n * log n)
// �������⵵ : 100000 * 8byte (p arr[100000])
// ������� �κ� : �� ó�� ���÷ȴ� ���̵� �̺� Ž���ε� �߰��� Ǯ�̸� �ƿ� ������ �� ���� �̺� Ž���� �ƴѰ�? �;��µ� ������������ ���� �켱���� ť�� �ƿ� ������ �� �ؼ� �˰��� �з��� ���� ���� �� ���� �ᱹ ���۸��� �ϰ� ���� ���� ���� �켱���� ť ���� �Լ��� �� ���۸� ��

#include <iostream>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, ans;
p arr[100000]; // ȸ���� ���۰� ���� ��� �迭

// �켱���� ť �������� ����
struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	// ȸ�� ���� �ð� �������� ����
	sort(arr, arr + n);

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		// ���� ȸ���� �� �ð��� ���� ȸ���� ���� �ð����� �۴ٸ� �̹� ���� ȸ���̹Ƿ� ����
		while (!pq.empty() && pq.top() <= arr[i].first)
			pq.pop();

		// ȸ�� �� �ð� ����
		pq.push(arr[i].second);

		// ���� �� ���� ����Ǵ� �ִ� ȸ�� ������ �ִ�� �ʿ��� ȸ�ǽ� ������ ���Ѵ�.
		ans = max(ans, (int)pq.size());
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