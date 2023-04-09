#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int x = distance(S.begin(), find(S.begin(), S.end(), 'B'));
    int y = distance(S.begin(), find(S.begin() + x + 1, S.end(), 'B'));

    int r1 = distance(S.begin(), find(S.begin(), S.end(), 'R'));
    int r2 = distance(S.begin(), find(S.begin() + r1 + 1, S.end(), 'R'));
    int k = distance(S.begin(), find(S.begin(), S.end(), 'K'));

    if ((x % 2 + y % 2) == 1)
    {
        if (r1 < k && k < r2)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}