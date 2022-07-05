#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int arr[40];
vector<int> leftsum, rightsum;
// ����, �����ʿ��� ���� �� �ִ� �� ����
long long ans;

void input()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void searchleftsum(int val, int idx)
{
	for (int i = idx; i < n / 2; i++)
	{
		val += arr[i];
		leftsum.push_back(val);
		searchleftsum(val, i + 1);
		val -= arr[i];
	}
}

void searchrightsum(int val, int idx)
{
	for (int i = idx; i < n; i++)
	{
		val += arr[i];
		rightsum.push_back(val);
		searchrightsum(val, i + 1);
		val -= arr[i];
	}
}

void solution()
{
	searchleftsum(0, 0);
	searchrightsum(0, n / 2);

	sort(leftsum.begin(), leftsum.end());
	sort(rightsum.begin(), rightsum.end());

	// �κ� ������ ���� s�� ��찡 �� sum�迭�� �����ϴ� ���
	ans += (upper_bound(leftsum.begin(), leftsum.end(), s) - leftsum.begin()) - (lower_bound(leftsum.begin(), leftsum.end(), s) - leftsum.begin());
	ans += (upper_bound(rightsum.begin(), rightsum.end(), s) - rightsum.begin()) - (lower_bound(rightsum.begin(), rightsum.end(), s) - rightsum.begin());

	for (int i = 0; i < leftsum.size(); i++)
	{
		long long maxidx = upper_bound(rightsum.begin(), rightsum.end(), s - leftsum[i]) - rightsum.begin();
		long long minidx = lower_bound(rightsum.begin(), rightsum.end(), s - leftsum[i]) - rightsum.begin();
		ans += maxidx - minidx;
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