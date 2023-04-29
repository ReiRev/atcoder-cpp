#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;

    int tmp_ans = 0;
    bool bar = false;
    for (char c : S)
    {
        if (c == '-')
        {
            ans = max(ans, tmp_ans);
            bar = true;
            tmp_ans = 0;
        }
        else if (c == 'o' && bar)
        {
            tmp_ans++;
        }
    }
    ans = max(ans, tmp_ans);

    reverse(S.begin(), S.end());
    tmp_ans = 0;
    bar = false;
    for (char c : S)
    {
        if (c == '-')
        {
            ans = max(ans, tmp_ans);
            bar = true;
            tmp_ans = 0;
        }
        else if (c == 'o' && bar)
        {
            tmp_ans++;
        }
    }
    ans = max(ans, tmp_ans);

    ans = ans == 0 ? -1 : ans;
    cout << ans << endl;
}