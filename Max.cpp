#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(10001);

int main(void)
{
    int n, num;
    cin >> n;
    while (n--)
    {
        cin >> num;
        arr[num]++;
    }
    cout << *max_element(arr.begin(), arr.end());
    return 0;
}