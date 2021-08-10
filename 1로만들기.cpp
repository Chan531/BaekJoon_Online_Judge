#include <iostream>
#include <vector>

using namespace std;
vector<int> v(1000001);
vector<int> w;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	w.push_back(n);
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i] == 1)
		{
			cout << v[w[i]];
			break;
		}
		if (w[i] % 3 == 0)
		{
			if (v[w[i] / 3] == 0 || v[w[i] / 3] > v[w[i]] + 1)
			{
				v[w[i] / 3] = v[w[i]] + 1;
				w.push_back(w[i] / 3);
			}
		}
		if (w[i] % 2 == 0)
		{
			if (v[w[i] / 2] == 0 || v[w[i] / 2] > v[w[i]] + 1)
			{

				v[w[i] / 2] = v[w[i]] + 1;
				w.push_back(w[i] / 2);
			}
		}
		if (v[w[i] - 1] == 0 || v[w[i] - 1] > v[w[i]] + 1)
		{
			v[w[i] - 1] = v[w[i]] + 1;
			w.push_back(w[i] - 1);
		}
	}
	return 0;
}