#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // bをi冊読んだ時の最高時間を格納する
    vector<int> times(m + 1, 0);
    int n_a = 0;
    // bを一冊も読まないとき
    while (times[0] + a[n_a] <= k && n_a < n)
    {
        times[0] += a[n_a];
        n_a++;
    }

    // bを読んでいき，その時の最高時間を求めていく．
    int ans = n_a;
    for (int n_b = 1; n_b <= m; n_b++)
    {
        times[n_b] = times[n_b - 1] + b[n_b - 1];
        while (n_a > 0 && times[n_b] > k)
        {
            n_a--;
            times[n_b] -= a[n_a];
        }
        // aが0冊の状態でもkを超えてしまうなら，以降は計算する必要なし．
        if (times[n_b] > k)
        {
            break;
        }
        ans = max(ans, n_a + n_b);
    }
    cout << ans << endl;
}