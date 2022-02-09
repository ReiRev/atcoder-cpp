#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n;
    cin >> n;
    if (log(2) / 2. > log(n) / n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}