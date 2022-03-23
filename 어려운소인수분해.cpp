#include <iostream>
#include <vector>

using namespace std;

int n, k, arr[5000001];
vector<int> ans;

void sosu()
{
	arr[1] = 1;
	for (int i = 2; i <= 5000000; i++)
	{
		if (!arr[i])
		{
			for (int j = i; j <= 5000000; j += i)
			{
				if (!arr[j])
					arr[j] = i;
			}
		}
	}
}

void solution(int k)
{
	if (k == 1)
		return;
	
	ans.push_back(arr[k]);
	solution(k / arr[k]);
}

void solve()
{
	sosu();
	cin >> n;
	while (n--)
	{
		cin >> k;
		solution(k);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
		ans.clear();
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