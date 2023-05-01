#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> horizontal_dir = {-1, 1};
vector<int> vertical_dir = {-1, 1};

int find_cross(vector<string> C, int x, int y)
{
    int ans = 0;
    if (C[y][x] != '#')
    {
        return ans;
    }

    while (true)
    {
        bool is_cross = true;
        for (int h : horizontal_dir)
        {
            for (int v : vertical_dir)
            {
                int x_ = x + h * (ans + 1);
                int y_ = y + v * (ans + 1);
                if (0 <= x_ && x_ < C[0].size() && 0 <= y_ && y_ < C.size())
                {
                    if (C[y_][x_] == '#')
                    {
                        continue;
                    }
                }
                is_cross = false;
            }
        }
        if (is_cross)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int H, W;
    cin >> H >> W;
    int N = min(H, W);
    vector<int> ans(N, 0);

    vector<string> C(H);
    for (string &s : C)
    {
        cin >> s;
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int count = find_cross(C, j, i);
            if (count > 0)
            {
                ans[count - 1]++;
            }
        }
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}