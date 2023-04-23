#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> G;
vector<vector<int>> Gr;
vector<int> vs;
vector<bool> used;
map<int, int> group_size;

void dfs(int v)
{
    used[v] = true;
    for (int next : G[v])
    {
        if (used[next])
        {
            continue;
        }
        dfs(next);
    }
    vs.push_back(v);
}

int rdfs(int v)
{
    used[v] = true;
    int res = 1;
    for (int next : Gr[v])
    {
        if (used[next])
        {
            continue;
        }
        res += rdfs(next);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    G = vector<vector<int>>(N);
    Gr = vector<vector<int>>(N);
    used = vector<bool>(N, false);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        a--;
        G[i].push_back(a);
        Gr[a].push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }

    reverse(vs.begin(), vs.end());
    used = vector<bool>(N, false);
    int ans = 0;
    for (int v : vs)
    {
        if (!used[v])
        {
            int res = rdfs(v);
            if (res == 1 && find(G[v].begin(), G[v].end(), v) == G[v].end())
            {
                continue;
            }
            ans += res;
        }
    }
    cout << ans << endl;
}