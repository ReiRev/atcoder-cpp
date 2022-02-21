#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    vector<int> n_div(n + 1, 1);
    int ans = 0;
    // 1~nの中で，iが約数に含まれるものをansに足していく．
    // ただし，個数ではなく，個数に，約数にする前の数をかけたものを足さないといけないことに注意．
    for (int i = 1; i <= n; i++)
    {
        int s = i;
        int e = i * (n / i);
        int m = n / i;
        ans += (s + e) * m / 2;
    }
    cout << ans << endl;
}