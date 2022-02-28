#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))

int main()
{
    int n, y;
    cin >> n >> y;
    y /= 1000;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (y - i * 10 - j * 5 >= 0 && y - i * 10 - j * 5 == n - i - j)
            {
                cout << i << " " << j << " " << y - i * 10 - j * 5 << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}