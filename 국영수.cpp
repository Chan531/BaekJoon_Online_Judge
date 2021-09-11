#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(tuple<int, int, int, string> t1, tuple<int, int, int, string> t2)
{
	if (get<0>(t1) == get<0>(t2))
	{
		if (get<1>(t1) == get<1>(t2))
		{
			if (get<2>(t1) == get<2>(t2))
				return get<3>(t1) < get<3>(t2);
			return get<2>(t1) > get<2>(t2);
		}
		return get<1>(t1) < get<1>(t2);
	}
	return get<0>(t1) > get<0>(t2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, e, m;
	vector<tuple<int, int, int, string>> v;
	string p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> k >> e >> m;
		v.push_back(make_tuple(k, e, m, p));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << get<3>(v[i]) << '\n';
	}
	return 0;
}