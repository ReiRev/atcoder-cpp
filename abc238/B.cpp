#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // edge
    // 0~359個の切れ込みが入っていると考える．各施行においてどこが切れ目になるかを考える．
    vector<int> e;
    int current_angle = 0;
    e.push_back(current_angle);
    for (int i = 0; i < n; i++)
    {
        current_angle += v[i];
        current_angle %= 360;
        e.push_back(current_angle);
    }
    sort(e.begin(), e.end());
    int ans = 0;
    for (int i = 1; i < e.size(); i++)
    {
        int tmp_ans;
        if (i != e.size() - 1)
        {
            tmp_ans = e[i] - e[i - 1];
        }
        else
        {
            tmp_ans = 360 - e[i];
        }
        ans = max(ans, tmp_ans);
    }
    cout << ans << endl;
}