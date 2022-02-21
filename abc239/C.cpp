#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define pii pair<int, int>

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<pii> is1, is2;
    for (int i = 0; i < 8; i++)
    {
        pii p1 = make_pair(x1 + dx[i], y1 + dy[i]);
        pii p2 = make_pair(x2 + dx[i], y2 + dy[i]);
        is1.push_back(p1);
        is2.push_back(p2);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (is1[i] == is2[j])
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}