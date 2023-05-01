#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> C(N);
    for (int &c : C)
    {
        cin >> c;
    }
    for (int i = 0; i < N; i++)
    {
        if (A + B == C[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}