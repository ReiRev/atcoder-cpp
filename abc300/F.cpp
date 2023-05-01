#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define int long long

int n_cross = 0;
vector<int> from_left;
vector<int> from_right;

void init(string S)
{
    n_cross = 0;
    for (char c : S)
    {
        if (c == 'x')
        {
            n_cross++;
        }
    }

    from_left = vector<int>(n_cross + 1, 0);
    int tmp_n_cross = 0;
    int n_circle = 0;
    for (char c : S)
    {
        if (c == 'x')
        {
            from_left[tmp_n_cross] = n_circle;
            n_circle++;
            tmp_n_cross++;
            continue;
        }
        if (c == 'o')
        {
            n_circle++;
        }
    }
    from_left[tmp_n_cross] = n_circle;

    from_right = vector<int>(n_cross + 1, 0);
    tmp_n_cross = 0;
    n_circle = 0;
    reverse(S.begin(), S.end());
    for (char c : S)
    {
        if (c == 'x')
        {
            from_right[tmp_n_cross] = n_circle;
            n_circle++;
            tmp_n_cross++;
            continue;
        }
        if (c == 'o')
        {
            n_circle++;
        }
    }
    from_right[tmp_n_cross] = n_circle;
}

int get_n_from_left(int n_delete)
{
    if (n_delete < 0)
    {
        return from_left[0];
    }
    if (n_delete > n_cross)
    {
        return from_left.back();
    }
    else
    {
        return from_left[n_delete];
    }
}

int get_n_from_right(int n_delete)
{
    if (n_delete < 0)
    {
        return from_right[0];
    }
    if (n_delete > n_cross)
    {
        return from_right.back();
    }
    else
    {
        return from_right[n_delete];
    }
}

signed main()
{
    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;

    init(S);

    // for (int x : from_right)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // for (int x : from_left)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    int ans = 0;

    if (M == 1)
    {
        ans = max(get_n_from_left(K), get_n_from_right(K));
    }
    else if (M == 2)
    {
        for (int i = 0; i <= K; i++)
        {
            ans = max(ans, get_n_from_left(i) + get_n_from_right(K - i));
        }
    }
    else
    {
        // M=2で考えられるようにする
        // while (true)
        // {
        //     if (K <= n_cross)
        //     {
        //         break;
        //     }
        //     if (M == 2)
        //     {
        //         break;
        //     }
        //     ans += N;
        //     K -= n_cross;
        //     M--;
        // }
        int n_serial = min(M - 2, K / n_cross);
        // if (n_serial == K / n_cross && K % n_cross == 0)
        // {
        //     n_serial--;
        // }
        K -= n_serial * n_cross;
        ans += N * n_serial;

        int tmp_ans = 0;

        // 左右から少しずつとる場合
        for (int i = 0; i <= K; i++)
        {
            tmp_ans = max(tmp_ans, get_n_from_left(i) + get_n_from_right(K - i));
        }

        for (int i = 0; i <= K + n_cross; i++)
        {
            // 左側からのみ取る場合
            tmp_ans = max(tmp_ans, get_n_from_right(i) + get_n_from_left(K + n_cross - i) - N);
            // 右側からのみ取る場合
            tmp_ans = max(tmp_ans, get_n_from_left(i) + get_n_from_right(K + n_cross - i) - N);
        }

        ans += tmp_ans;
    }

    cout << ans << endl;
}