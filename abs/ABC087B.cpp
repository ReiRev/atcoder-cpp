#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    rep(i, a + 1) rep(j, b + 1) rep(k, c + 1) if (i * 500 + j * 100 + k * 50 == x) ans++;

    cout << ans << endl;
}