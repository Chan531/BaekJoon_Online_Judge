#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, start, end;
	priority_queue<pair<int, int>> endheap, startheap;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		endheap.push({ end, start });
	}
	while (!endheap.empty())
	{
		start = endheap.top().second;
		end = endheap.top().first;
		endheap.pop();

		if (startheap.empty() || startheap.top().first < end)
			startheap.push({ start, end });

		else
		{
			end = startheap.top().second;
			startheap.pop();
			startheap.push({ start, end });
		}
	}
	cout << startheap.size();
	return 0;
}