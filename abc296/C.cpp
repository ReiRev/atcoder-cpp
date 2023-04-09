#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        if (binary_search(A.begin() + i, A.end(), A[i] + X))
        {
            cout << "Yes" << endl;
            return 0;
        }
        if (binary_search(A.begin() + i, A.end(), A[i] - X))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}