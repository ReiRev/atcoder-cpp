#include <iostream>
#include <climits>

using namespace std;

#define int long long
#define INF (2e18)

signed main()
{
    int N, M;
    cin >> N >> M;

    int ans = INF;
    for (int a = 1; a <= N; a++)
    {
        int b = (M + a - 1) / a;
        if (b <= N)
        {
            ans = min(ans, a * b);
        }
        if (b < a)
        {
            break;
        }
    }

    ans = ans == INF ? -1 : ans;
    cout << ans << endl;
    return 0;
}