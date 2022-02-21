#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double h;
    cin >> h;

    cout << std::fixed << std::setprecision(15) << sqrt(h * (h + 12800000.)) << endl;
}