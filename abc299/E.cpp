#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> get_min_distances(int s, const vector<vector<int>> &g)
{
    // distance, edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distances(g.size(), numeric_limits<int>::max());
    pq.push(pair<int, int>(0, s));
    distances[s] = 0;

    while (!pq.empty())
    {
        int d = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (distances[from] < d)
        {
            continue;
        }

        for (int to : g[from])
        {
            if (d + 1 < distances[to])
            {
                distances[to] = d + 1;
                pq.push(pair<int, int>(d + 1, to));
            }
        }
    }

    // 距離ごとに頂点を保存
    vector<vector<int>> res(g.size() + 1);
    for (size_t i = 0; i < distances.size(); i++)
    {
        res[distances[i]].push_back(i);
    }
    return res;
}

bool solve(vector<int> &colors, vector<pair<int, int>> pds, const vector<vector<vector<int>>> &edges_min_distances)
{
    if (pds.empty())
    {
        return true;
    }

    // 後ろから条件を満たすように解いていく。(pop_backが使えるので)
    int e = pds.back().first;
    int d = pds.back().second;
    pds.pop_back();

    // 距離d未満の部分は必ず白でないといけない。
    for (int i = 0; i < d; i++)
    {
        for (int to_be_white : edges_min_distances[e][i])
        {
            if (colors[to_be_white] == 1)
            {
                return false;
            }
            colors[to_be_white] = 0;
        }
    }

    // すでに距離dのうちのいずれかが黒になっているのなら、そのままで大丈夫
    bool requirement_satisfied = false;
    for (int to_be_black : edges_min_distances[e][d])
    {
        if (colors[to_be_black] == 1)
        {
            requirement_satisfied = true;
            break;
        }
    }
    if (requirement_satisfied)
    {
        return solve(colors, pds, edges_min_distances);
    }

    // まだ距離dのうちのいずれかが黒になっていない場合
    // 距離dのものに対して、まだ未定のものを黒にして解けるか計算。
    for (int to_be_black : edges_min_distances[e][d])
    {
        if (colors[to_be_black] == -1)
        {
            vector<int> tmp_colors(colors.size());
            copy(colors.begin(), colors.end(), tmp_colors.begin());
            tmp_colors[to_be_black] = 1;
            bool solved = solve(tmp_colors, pds, edges_min_distances);
            if (solved)
            {
                copy(tmp_colors.begin(), tmp_colors.end(), colors.begin());
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int K;
    cin >> K;
    vector<pair<int, int>> pds(K);
    for (pair<int, int> &pd : pds)
    {
        cin >> pd.first >> pd.second;
        pd.first--;
    }

    // ここの計算時間がかかりすぎて、間に合わない。
    vector<vector<vector<int>>> edges_min_distances;
    for (int i = 0; i < N; i++)
    {
        edges_min_distances.push_back(get_min_distances(i, g));
    }

    vector<int> colors(N, -1);
    int solved = solve(colors, pds, edges_min_distances);
    if (!solved)
    {
        cout << "No" << endl;
    }

    if (solved)
    {
        cout << "Yes" << endl;
        for (int x : colors)
        {
            if (x == -1)
            {
                cout << 1;
            }
            else
            {
                cout << x;
            }
        }
        cout << endl;
    }
}