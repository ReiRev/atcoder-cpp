#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> board;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }

    string ans = "";

    for (int i = 0; i < 8; i++)
    {
        size_t pos = board[i].find("*");
        if (pos != string::npos)
        {
            ans += 'a' + pos;
            ans += '0' + 8 - i;
        }
    }

    cout << ans << endl;
}