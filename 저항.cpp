#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	string s;
	long long answer = 0;
	map<string, int> add;
	map<string, int> mul;
	add["black"] = 0;
	add["brown"] = 1;
	add["red"] = 2;
	add["orange"] = 3;
	add["yellow"] = 4;
	add["green"] = 5;
	add["blue"] = 6;
	add["violet"] = 7;
	add["grey"] = 8;
	add["white"] = 9;
	mul["black"] = 1;
	mul["brown"] = 10;
	mul["red"] = 100;
	mul["orange"] = 1000;
	mul["yellow"] = 10000;
	mul["green"] = 100000;
	mul["blue"] = 1000000;
	mul["violet"] = 10000000;
	mul["grey"] = 100000000;
	mul["white"] = 1000000000;
	for (int i = 0; i < 3; i++)
	{
		cin >> s;
		if (i < 1)
			answer += 10 * add[s];
		else if (i < 2)
			answer += add[s];
		else
			answer *= mul[s];
	}
	cout << answer;
	return 0;
}