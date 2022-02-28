#include <iostream>

using namespace std;

int main()
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        char s;
        cin >> s;
        ans += s - '0';
    }
    cout << ans << endl;
}