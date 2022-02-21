#include <iostream>
#include <vector>

using namespace std;

string a, b;
int aidx, bidx, idx = 0, an, bn;
vector<int> ans(10001);

void solve()
{
	cin >> a >> b;
	aidx = a.length() - 1;
	bidx = b.length() - 1;
	while (aidx >= 0 || bidx >= 0)
	{
		if (aidx >= 0)
			an = a[aidx] - '0';
		else
			an = 0;

		if (bidx >= 0)
			bn = b[bidx] - '0';
		else
			bn = 0;

		ans[idx] += (an + bn);

		if (ans[idx] >= 10)
		{
			ans[idx + 1]++;
			ans[idx] %= 10;
		}

		aidx--;
		bidx--;
		idx++;
	}

	for (int i = idx; i >= 0; i--)
	{
		if (i == idx && ans[i] == 0)
			continue;

		cout << ans[i];
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}