#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
	if (get<0>(a) == get<0>(b))
	{
		if (get<1>(a) == get<1>(b))
			return get<2>(a) > get<2>(b);
		return get<1>(a) > get<1>(b);
	}
	return get<0>(a) > get<0>(b);
}

int main(void)
{
	int n, m, num, g, s, b, gk, sk, bk;
	vector<tuple<int, int, int>> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> g >> s >> b;
		v.push_back(make_tuple(g, s, b));
		if (num == m)
		{
			gk = g;
			sk = s;
			bk = b;
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (gk == get<0>(v[i]) && sk == get<1>(v[i]) && bk == get<2>(v[i]))
		{
			cout << i + 1;
			break;
		}
	}
	return 0;
}