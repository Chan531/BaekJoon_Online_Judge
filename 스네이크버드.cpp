#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, h, fh;
	vector<int> fruitheight;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> fh;
		fruitheight.push_back(fh);
	}
	sort(fruitheight.begin(), fruitheight.end());
	for (int i = 0; i < n; i++)
	{
		if (h >= fruitheight[i])
			h++;
		else
			break;
	}
	cout << h;
	return 0;
}