#include <iostream>

using namespace std;

int main(void)
{
	string mbti, ans = "";
	cin >> mbti;

	if (mbti[0] == 'E')
		ans += 'I';
	else
		ans += 'E';

	if (mbti[1] == 'S')
		ans += 'N';
	else
		ans += 'S';

	if (mbti[2] == 'F')
		ans += 'T';
	else
		ans += 'F';

	if (mbti[3] == 'P')
		ans += 'J';
	else
		ans += 'P';

	cout << ans;

	return 0;
}