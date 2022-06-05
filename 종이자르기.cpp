#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> width, height;
int n, w, h, idx, val;

void input()
{
	cin >> w >> h;
	width.push_back(w);
	height.push_back(h);
	cin >> n;

	while (n--)
	{
		cin >> idx >> val;

		if (!idx)
			height.push_back(val);

		else
			width.push_back(val);
	}
}

void solution()
{
	sort(width.begin(), width.end());
	sort(height.begin(), height.end());

	w = width[0];
	h = height[0];

	for (int i = 1; i < width.size(); i++)
		w = max(w, width[i] - width[i - 1]);

	for (int i = 1; i < height.size(); i++)
		h = max(h, height[i] - height[i - 1]);

	cout << w * h;
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