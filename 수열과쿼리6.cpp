#include <iostream>
#include <algorithm>
#define N 100001
#define K 1024

using namespace std;

struct node {
	int s, e, idx;
};

bool cmp(node a, node b)
{
	if (a.s / K == b.s / K)
		return a.e < b.e;

	return a.s / K < b.s / K;
}

int n, q, arr[N], ans[N], num_check[N], cnt_check[N];
int sp, ep, max_cnt;
node query[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> query[i].s >> query[i].e;
		query[i].idx = i;
	}
}

void init()
{
	max_cnt = 0;
	sp = query[0].s;
	ep = query[0].e;

	for (int i = sp; i <= ep; i++)
	{
		int cnt = ++num_check[arr[i]];
		cnt_check[cnt]++;
		cnt_check[cnt - 1]--;
		max_cnt = max(max_cnt, cnt);
	}

	ans[query[0].idx] = max_cnt;
}

void solution()
{
	sort(query, query + q, cmp);
	init();

	for (int i = 1; i < q; i++)
	{
		int s = query[i].s;
		int e = query[i].e;
		int idx = query[i].idx;

		while (s > sp)
		{
			cnt_check[num_check[arr[sp]]]--; // cnt_cnt 줄여주기
			num_check[arr[sp]]--; // num_cnt 줄여주기
			cnt_check[num_check[arr[sp++]]]++; // 새로운 cnt_cnt 늘려주기
			if (cnt_check[max_cnt] == 0) // max_cnt가 갱신됐다면 줄여주기
				max_cnt--;
		}

		while (s < sp--)
		{
			cnt_check[num_check[arr[sp]]]--; // cnt_cnt 줄여주기
			num_check[arr[sp]]++; // num_cnt 늘려주기
			cnt_check[num_check[arr[sp]]]++; // 새로운 cnt_cnt 늘려주기
			if (cnt_check[max_cnt + 1] == 1) // max_cnt가 갱신됐다면 늘려주기
				max_cnt++;
		}

		while (e < ep)
		{
			cnt_check[num_check[arr[ep]]]--; // cnt_cnt 줄여주기
			num_check[arr[ep]]--; // num_cnt 줄여주기
			cnt_check[num_check[arr[ep--]]]++; // 새로운 cnt_cnt 늘려주기
			if (cnt_check[max_cnt] == 0) // max_cnt가 갱신됐다면 줄여주기
				max_cnt--;
		}

		while (e > ep++)
		{
			cnt_check[num_check[arr[ep]]]--; // cnt_cnt 줄여주기
			num_check[arr[ep]]++; // num_cnt 늘려주기
			cnt_check[num_check[arr[ep]]]++; // 새로운 cnt_cnt 늘려주기
			if (cnt_check[max_cnt + 1] == 1) // max_cnt가 갱신됐다면 늘려주기
				max_cnt++;
		}

		ans[idx] = max_cnt;
		sp = s;
		ep = e;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
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