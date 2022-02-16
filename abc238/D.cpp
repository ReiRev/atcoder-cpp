#include <iostream>
#include <vector>

using namespace std;

#define int long long

// bool hasinv(int x, int y)
// {
//     // 各桁において ? AND x = y　を満たす?が存在するかどうか
//     // すなわち，xが0でyが1という桁があるとまずい．どうやっても?を満たすものが存在しない
//     while (y > 0)
//     {
//         if ((y % 2) == 1 && (x % 2) == 0)
//         {
//             return false;
//         }
//         x >>= 1;
//         y >>= 1;
//     }
//     return true;
// }

// int num_digit(int x)
// {
//     int count = 0;
//     while (x > 0)
//     {
//         x >>= 1;
//         count++;
//     }
//     return count;
// }

// signed main()
// {
//     // y = s - x = s + ~x + 1
//     // x AND (s + ~x + 1) = a
//     // x AND (s+1) = a
//     // このとき，ある条件だとxは存在しえない．(hasinv参照)
//     // 存在するなら，x = a AND (s+1)としてやれば良い．

//     int t;
//     cin >> t;
//     vector<int> a(t), s(t);
//     for (int i = 0; i < t; i++)
//     {
//         cin >> a[i] >> s[i];
//     }
//     for (int i = 0; i < t; i++)
//     {
//         if (s[i] == 0 && a[i] == 0)
//         {
//             cout << "Yes" << endl;
//             continue;
//         }
//         else if (s[i] == 0)
//         {
//             cout << "No" << endl;
//             continue;
//         }
//         if (!hasinv(s[i] + 1, a[i]))
//         {
//             cout << "No" << endl;
//             continue;
//         }
//         int x = a[i] & (s[i] + 1);
//         int y = s[i] - x;
//         cout << x << "  " << y << endl;
//         if (x >= 0 && y >= 0)
//         {
//             cout << "Yes" << endl;
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }

//     // int a, b;
//     // cin >> a >> b;
//     // cout << hasinv(a, b) << endl;
// }

// 解説を参照した．x + y = x XOR y + 2 * (x AND y)を利用する．
// x XOR y = s-2a
// x AND y = a
signed main()
{
    int t;
    cin >> t;
    int a, s;
    for (int j = 0; j < t; j++)
    {
        cin >> a >> s;
        int d = s - 2 * a;
        int x, y;
        if (d >= 0 && (d & a) == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}