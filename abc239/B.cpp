#include <iostream>

using namespace std;

#define int long long

signed main()
{
    int x;
    cin >> x;
    if ((x / 10) * 10 <= x && x < (x / 10) * 10 + 10)
    {
        cout << (x / 10) << endl;
    }
    else
    {
        cout << x / 10 - 1 << endl;
    }
}