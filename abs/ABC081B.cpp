#include <iostream>
#include <algorithm>

using namespace std;

int f(int n)
{
    int res = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans = min(ans, f(a));
    }
    cout << ans << endl;
    return 0;
}