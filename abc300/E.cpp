#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MOD 998244353
#define MODINV5 598946612
#define int long long

// int modinv(int a)
// {
//     int b = MOD, u = 1, v = 0;
//     while (b)
//     {
//         int t = a / b;
//         a -= t * b;
//         swap(a, b);
//         u -= t * v;
//         swap(u, v);
//     }
//     u %= MOD;
//     if (u < 0)
//         u += MOD;
//     return u;
// }

map<int, int> memo;
int solve(int x, int N)
{
    if (x == N)
    {
        return 1;
    }
    if (x > N)
    {
        return 0;
    }
    if (memo.find(x) != memo.end())
    {
        return memo[x];
    }

    int res = 0;
    for (int i = 2; i <= 6; i++)
    {
        res += solve(i * x, N);
        res %= MOD;
    }

    res = res * MODINV5 % MOD;
    memo[x] = res;
    return res;
}

signed main()
{
    int N;
    cin >> N;

    cout << solve(1, N) << endl;
}