#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define MOD 998244353
#define int long long

int modinv(int a)
{
    int b = MOD, u = 1, v = 0;
    while (b)
    {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0)
        u += MOD;
    return u;
}

int modpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int sum(vector<int> &v)
{
    int res = 0;
    for (int x : v)
    {
        res = (res + x) % MOD;
    }
    return res;
}

signed main()
{
    int N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;

    vector<int> Takahashi(N + 1, 0);
    Takahashi[A] = 1;
    vector<int> Aoki(N + 1, 0);
    Aoki[B] = 1;

    int takahashi_turn = 0;
    int aoki_turn = 0;
    int ans = 0;

    while (true)
    {
        takahashi_turn++;

        vector<int> next_Takahashi(N + 1, 0);
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 1; j <= P; j++)
            {
                next_Takahashi[min(i + j, N)] += Takahashi[i];
                next_Takahashi[min(i + j, N)] %= MOD;
            }
        }
        Takahashi = next_Takahashi;
        ans += (Takahashi[N] * modinv(modpow(P, takahashi_turn)) % MOD) *
               (sum(Aoki) * modinv(modpow(Q, aoki_turn)) % MOD) % MOD;
        ans %= MOD;
        Takahashi[N] = 0;

        if (!sum(Takahashi))
        {
            break;
        }

        aoki_turn++;
        vector<int> next_Aoki(N + 1, 0);
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 1; j <= Q; j++)
            {
                next_Aoki[min(i + j, N)] += Aoki[i];
                next_Aoki[min(i + j, N)] %= MOD;
            }
        }
        Aoki = next_Aoki;
        Aoki[N] = 0;
    }

    cout << ans << endl;
}