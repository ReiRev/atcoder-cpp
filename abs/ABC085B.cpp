#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    cout << d.size() << endl;
}