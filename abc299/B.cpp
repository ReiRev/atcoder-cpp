#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> C(N);
    vector<int> R(N);

    for (int &x : C)
    {
        cin >> x;
    }
    for (int &x : R)
    {
        cin >> x;
    }

    int max_val = -1;
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if (T == C[i])
        {
            if (max_val < R[i])
            {
                max_val = R[i];
                ans = i + 1;
            }
        }
    }

    if (ans != -1)
    {
        cout << ans << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (C[0] == C[i])
        {
            if (max_val < R[i])
            {
                max_val = R[i];
                ans = i + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}