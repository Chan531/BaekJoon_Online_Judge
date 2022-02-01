#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, up = 0, down = 0;
	string name, prename = "";
	cin >> n;
	while (n--)
	{
		cin >> name;
		if (prename == "")
		{
			prename = name;
			continue;
		}
		if (name > prename)
			up++;
		else
			down++;
		prename = name;
	}
	if (up && down)
		cout << "NEITHER";
	else if (!up && down)
		cout << "DECREASING";
	else
		cout << "INCREASING";
	return 0;
}