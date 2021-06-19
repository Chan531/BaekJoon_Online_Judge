#include <iostream>
#include <vector>

using namespace std;

vector<int> sum;
int add = 0;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for (int i = 0; i < comb.size(); i++)
            add += comb[i];
        sum.push_back(add);
        add = 0;
    }
    else if (depth == arr.size())
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
	int n = 0;
	int s = 0;
    int answer = 0;
	cin >> n;
	cin >> s;
	vector<int> v;
    vector<int> r(3);
    int sub = 0;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
    Combination(v, r, 3, 0, 0);
    for (auto i : sum)
    {
        if (s - i == 0)
        {
            sub = i;
            break;
        }
        else if (s - i < 0)
        {

        }
        else if (s - i < s - sub)
            sub = i;
    }
    cout << sub;
    return 0;
}