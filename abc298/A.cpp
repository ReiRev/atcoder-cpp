#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string S;

    cin >> N >> S;

    int n_good = 0;
    int n_reject = 0;
    for (char c : S)
    {
        if (c == 'o')
        {
            n_good++;
        }
        if (c == 'x')
        {
            n_reject++;
        }
    }

    if (n_good > 0 && n_reject == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}