#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define int long long

signed main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // vector<int> min_vals;
    set<int> min_vals;
    min_vals.insert(0);
    for (int i = 0; i < K; i++)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        // next_lower_min以上の最小値を探したい
        int next_lower_min = *min_vals.rbegin() + 1;
        for (int j = 0; j < N; j++)
        {
            // A[j]を足して最小値となる場合、それはmin_valsで
            // next_lower_min-A[j]以上で最小のものの値を足したものであるはず
            auto it = min_vals.lower_bound(next_lower_min - A[j]);
            if (it != min_vals.end())
            {
                q.push(*it + A[j]);
            }
        }
        min_vals.insert(q.top());
    }

    cout << *min_vals.rbegin() << endl;
}