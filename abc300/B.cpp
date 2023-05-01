#include <iostream>
#include <vector>
#include <string>

using namespace std;

void shift_vertical(vector<string> &A, int s)
{
    for (int i = 0; i < s; i++)
    {
        A.push_back(A[0]);
        A.erase(A.begin());
    }
}

void shift_horizontal(vector<string> &A, int t)
{
    for (int i = 0; i < t; i++)
    {
        for (string &s : A)
        {
            s = s + s[0];
            s.erase(s.begin());
        }
    }
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    vector<string> B(H);

    for (string &s : A)
    {
        cin >> s;
    }
    for (string &s : B)
    {
        cin >> s;
    }

    for (int s = 0; s < H; s++)
    {
        for (int t = 0; t < W; t++)
        {
            vector<string> A_tmp = A;
            shift_vertical(A_tmp, s);
            shift_horizontal(A_tmp, t);
            if (A_tmp == B)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}