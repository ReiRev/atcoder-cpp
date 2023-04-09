#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> table(H);
    for (int i = 0; i < H; i++)
    {
        cin >> table[i];
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W - 1; j++)
        {
            if (table[i][j] == 'T' && table[i][j + 1] == 'T')
            {
                table[i][j] = 'P';
                table[i][j + 1] = 'C';
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        cout << table[i] << endl;
    }

    return 0;
}