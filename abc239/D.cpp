#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<bool> is_primes(b + d + 30, true);
    is_primes[0] = is_primes[1] = false;
    for (int i = 2; i < is_primes.size(); i++)
    {
        for (int j = i + i; j < is_primes.size(); j += i)
        {
            is_primes[j] = false;
        }
    }
    for (int i = a; i <= b; i++)
    {
        bool no_prime = true;
        for (int j = c; j <= d; j++)
        {
            if (is_primes[i + j])
            {
                no_prime = false;
                break;
            }
        }
        if (no_prime)
        {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
}