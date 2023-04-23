#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

#define int long long
#define MOD 998244353
#define MAX (1000000 + 10)

int fac[MAX], finv[MAX], inv[MAX];

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

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main()
{
    int H, W, K;
    cin >> H >> W >> K;

    COMinit();

    int sum = 0;
    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (K > h * w)
            {
                continue;
            }
            int score = COM(h * w, K);
            if (h - 1 > 0)
                score -= 2 * COM((h - 1) * w, K);
            if (w - 1 > 0)
                score -= 2 * COM(h * (w - 1), K);
            if (h - 1 > 0 && w - 1 > 0)
                score += 4 * COM((h - 1) * (w - 1), K);
            if (h - 2 > 0)
                score += COM((h - 2) * w, K);
            if (w - 2 > 0)
                score += COM(h * (w - 2), K);
            if (h - 2 > 0 && w - 1 > 0)
                score -= 2 * COM((h - 2) * (w - 1), K);
            if (h - 1 > 0 && w - 2 > 0)
                score -= 2 * COM((h - 1) * (w - 2), K);
            if (h - 2 > 0 && w - 2 > 0)
                score += COM((h - 2) * (w - 2), K);

            score = (score % MOD + MOD) % MOD;
            score = (score * h * w) % MOD;
            score = (score * (H - h + 1)) % MOD;
            score = (score * (W - w + 1)) % MOD;
            // cout << h << " " << w << " " << score << endl;
            sum += score;
            sum %= MOD;
        }
    }

    // cout << sum << endl;
    cout << sum * modinv(COM(H * W, K), MOD) % MOD << endl;
}