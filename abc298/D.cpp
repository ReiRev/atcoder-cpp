#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define MOD 998244353
#define int long long

int modinv(long long a)
{
    long long b = MOD, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
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

signed main()
{
    int Q;
    cin >> Q;
    deque<string> S;
    S.push_back("1");
    int S_mod = 1;
    int digit = 1;

    vector<int> mod_decimal;
    mod_decimal.push_back(0);
    mod_decimal.push_back(1);
    for (int i = 2; i < (int)6e5 + 10; i++)
    {
        mod_decimal.push_back(mod_decimal[i - 1] * 10 % MOD);
    }

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        int top;
        switch (q)
        {
        case 1:
            int x;
            cin >> x;
            S.push_back(to_string(x));
            S_mod = S_mod * 10 + x;
            S_mod %= MOD;
            digit++;
            break;
        case 2:
            top = stoi(S.front());
            S.pop_front();
            S_mod -= (mod_decimal[digit] * top) % MOD;
            S_mod %= MOD;
            if (S_mod < 0)
            {
                S_mod += MOD;
            }
            digit--;
            break;
        case 3:
            cout << S_mod << endl;
        default:
            break;
        }
    }
}