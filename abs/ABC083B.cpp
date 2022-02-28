#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int sum(int n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, n) if (a <= sum(i + 1) && sum(i + 1) <= b) ans += i + 1;
    cout << ans << endl;
}