#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, connum, stunum, score, rank = 1;
	vector<tuple<int, int, int>> arr;
	vector<int> conmedal(101);
	cin >> n;
	while (n--)
	{
		cin >> connum >> stunum >> score;
		arr.push_back(make_tuple(score, connum, stunum));
	}
	sort(arr.begin(), arr.end());
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		if (conmedal[get<1>(arr[i])] != 2)
		{
			cout << get<1>(arr[i]) << ' ' << get<2>(arr[i]) << '\n';
			conmedal[get<1>(arr[i])]++;
			rank++;
		}
		if (rank == 4)
			break;
	}
	return 0;
}