#include <iostream>
#include <cmath>

using namespace std;

#define int long long
#define MOD 998244353

int get_digit(int n)
{
    int digit = 0;
    while (n > 0)
    {
        n /= 10;
        digit++;
    }
    return digit;
}

// nの逆元を求める
long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

signed main()
{
    int N;
    cin >> N;
    int digit = get_digit(N);
    int ans = 0;

    // digit - 1以下の桁数の場合は全て足していけばいい．
    int decimal = 10;
    int two_inv = modinv(2, MOD);
    int ten_inv = modinv(10, MOD);
    int last_e;
    for (int i = 1; i <= digit - 1; i++)
    {
        int s = 1;
        int e = (decimal - (decimal * ten_inv) % MOD + MOD) % MOD;
        e %= MOD;
        ans += ((((s + e) * e) % MOD) * two_inv) % MOD;
        ans %= MOD;
        decimal *= 10;
        decimal %= MOD;
    }
    int s = 1;
    int e = (N - (decimal * ten_inv) % MOD + 1 + MOD) % MOD;
    ans += ((((s + e) * e) % MOD) * two_inv) % MOD;
    ans %= MOD;
    cout << ans << endl;
}