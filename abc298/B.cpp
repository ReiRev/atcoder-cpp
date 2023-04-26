#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int r = 0; r < 4; r++)
    {
        vector<vector<int>> A_rotated(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A_rotated[i][j] = A[N - j - 1][i];
            }
        }

        bool ok = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (A_rotated[i][j] == 1 && B[i][j] != A_rotated[i][j])
                {
                    ok = false;
                }
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }

        A = A_rotated;
    }

    cout << "No" << endl;
}