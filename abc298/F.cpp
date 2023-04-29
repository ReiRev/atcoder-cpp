#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;

#define int long long

void map_set(map<int, int> &m, int p, int x)
{
    if (m.find(p) == m.end())
    {
        m[p] = 0;
    }
    m[p] += x;
}

signed main()
{
    int N;
    cin >> N;

    map<int, int> cols;
    map<int, int> rows;
    map<pair<int, int>, int> rcs;
    for (int i = 0; i < N; i++)
    {
        int r, c, x;
        cin >> r >> c >> x;
        map_set(rows, r, x);
        map_set(cols, c, x);
        rcs[pair<int, int>(r, c)] = x;
    }

    int ans = -1;

    // 入力値に存在する(r,c)を選んで最大値を選択する場合
    for (auto key_val : rcs)
    {
        int tmp_ans = rows[key_val.first.first] + cols[key_val.first.second] - key_val.second;
        ans = max(ans, tmp_ans);
    }

    // 入力値に存在しない(r,c)を選んで最大値を選択する場合
    priority_queue<pair<int, int>> rowq, colq;
    for (auto row_key_val : rows)
    {
        rowq.push(pair<int, int>(row_key_val.second, row_key_val.first));
    }
    for (auto col_key_val : cols)
    {
        colq.push(pair<int, int>(col_key_val.second, col_key_val.first));
    }
    while (!colq.empty())
    {
        if (colq.top().first + rowq.top().first <= ans)
        {
            break;
        }
        auto top = colq.top();
        colq.pop();
        int tmp_ans = top.first;
        int c = top.second;

        // ここで使用されたrowは、次のcolでは使われないはず。
        // 結果的に、ループは全体で最大N回しか回らない。
        vector<pair<int, int>> unused;
        while (!rowq.empty())
        {
            if (tmp_ans + rowq.top().first <= ans)
            {
                break;
            }
            if (!rcs[pair<int, int>(rowq.top().second, c)])
            {
                tmp_ans += rowq.top().first;
                rowq.pop();
                break;
            }
            else
            {
                unused.push_back(rowq.top());
                rowq.pop();
            }
        }

        for (auto x : unused)
        {
            rowq.push(x);
        }

        ans = max(tmp_ans, ans);
    }

    cout << ans << endl;
}