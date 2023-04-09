#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define int long long

signed main()
{
    int A, B;
    cin >> A >> B;
    int ans = 0;
    while (A != B)
    {
        if (A > B)
        {
            ans += A / B;
            A = A % B;
            if (A == 0)
            {
                ans--;
                break;
            }
        }
        else
        {
            ans += B / A;
            B = B % A;
            if (B == 0)
            {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}