#include <iostream>

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;
    int last_t;
    cin >> last_t;
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        int t;
        cin >> t;
        if (t - last_t <= D && ans == -1)
        {
            ans = t;
        }
        last_t = t;
    }
    cout << ans << endl;
}