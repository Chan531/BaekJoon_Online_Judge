#include <vector>

using namespace std;

long long sum(std::vector<int>& a) {
	long long ans = 0;
	for (auto i : a)
		ans += i;
	return ans;
}

int main(void)
{
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	sum(v);
}