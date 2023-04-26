#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<map<int, int>> cards(N);
    map<int, map<int, int>> boxes;

    for (int i = 0; i < Q; i++)
    {
        int q, a, b;
        cin >> q >> a;
        a--;
        vector<int> tmp;
        switch (q)
        {
        case 1:
            cin >> b;
            b--;
            if (cards[b].find(a) == cards[b].end())
            {
                cards[b][a] = 1;
            }
            else
            {
                cards[b][a]++;
            }
            boxes[a][b] = 1;
            break;
        case 2:
            for (auto key_val : cards[a])
            {
                for (int j = 0; j < key_val.second; j++)
                {
                    cout << key_val.first + 1 << " ";
                }
            }
            cout << endl;
            break;
        case 3:
            for (auto key_val : boxes[a])
            {
                cout << key_val.first + 1 << " ";
            }
            cout << endl;
            break;
        default:
            break;
        }
    }
}