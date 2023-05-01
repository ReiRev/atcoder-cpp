#include <iostream>
#include <vector>

using namespace std;

int ask(int x)
{
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

int ok(vector<int> v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == -1)
        {
            continue;
        }
        if (v[i + 1] == -1)
        {
            continue;
        }
        if (v[i] != v[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;

    vector<int> v(N, -1);
    v[0] = 0;
    v[N - 1] = 1;

    int s = 0, e = N - 1;
    for (int i = 0; i < 20; i++)
    {
        int to_ask = (s + e) / 2;
        v[to_ask] = ask(to_ask + 1);

        if (v[to_ask] != v[s])
        {
            // cout << v[s] << v[to_ask] << endl;
            e = to_ask;
        }
        else
        {
            s = to_ask;
        }

        int ans = ok(v);
        if (ans != -1)
        {
            cout << "! " << ans + 1 << endl;
            return 0;
        }
    }
}