#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> card(21);
	for (int i = 1; i <= 20; i++)
		card[i] = i;
	int start, end;
	for (int i = 0; i < 10; i++)
	{
		cin >> start >> end;
		while (start < end)
			swap(card[start++], card[end--]);
	}
	for (int i = 1; i <= 20; i++)
		cout << card[i] << ' ';
	return 0;
}