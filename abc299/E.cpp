#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> get_min_distances(int s, const vector<vector<int>> &G)
{
    vector<int> res(G.size(), -1);

    queue<int> q;
    q.push(s);
    res[s] = 0;
    while (!q.empty())
    {
        int from = q.front();
        q.pop();
        for (int next : G[from])
        {
            if (res[next] != -1)
            {
                continue;
            }
            res[next] = res[from] + 1;
            q.push(next);
        }
    }
    return res;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int K;
    cin >> K;
    vector<pair<int, int>> pds;
    for (int i = 0; i < K; i++)
    {
        int p, d;
        cin >> p >> d;
        p--;
        pds.push_back(pair<int, int>(p, d));
    }

    vector<vector<int>> min_distances;
    for (int i = 0; i < N; i++)
    {
        min_distances.push_back(get_min_distances(i, G));
    }

    // ある頂点から距離に応じて頂点を格納
    // vs_distances[i][d]は、頂点iから距離dに位置する頂点の数
    vector<vector<vector<int>>> vs_distances(N, vector<vector<int>>(G.size() + 1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int d = min_distances[i][j];
            vs_distances[i][d].push_back(j);
        }
    }

    // -1: 未定、0: 白、1: 黒
    vector<int> colors(N, -1);
    // 白に塗らなければならないところは全て白にする
    for (pair<int, int> key_val : pds)
    {
        int p = key_val.first;
        int d = key_val.second;
        for (int i = 0; i < d; i++)
        {
            for (int v : vs_distances[p][i])
            {
                colors[v] = 0;
            }
        }
    }
    for (int &c : colors)
    {
        if (c == -1)
        {
            c = 1;
        }
    }
    // 条件を満たしているかチェック
    bool ok = true;

    // 1個以上黒があるかどうか
    int n_black = 0;
    for (int c : colors)
    {
        if (c == 1)
        {
            n_black++;
        }
    }
    if (n_black == 0)
    {
        ok = false;
    }

    // 距離の問題
    for (pair<int, int> key_val : pds)
    {
        int p = key_val.first;
        int d = key_val.second;
        for (int i = 0; i < d; i++)
        {
            for (int v : vs_distances[p][i])
            {
                if (colors[v] == 1)
                {
                    ok = false;
                }
            }
        }
        bool tmp_ok = false;
        for (int v : vs_distances[p][d])
        {
            if (colors[v] == 1)
            {
                tmp_ok = true;
            }
        }
        if (!tmp_ok)
        {
            ok = false;
        }
    }

    if (ok)
    {
        cout << "Yes" << endl;
        for (int c : colors)
        {
            cout << c;
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}