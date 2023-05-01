#include <iostream>
#include <vector>

using namespace std;

#define int long long int

void set_is_primes(vector<bool> &is_primes)
{
    is_primes = vector<bool>(316228, true);
    is_primes[0] = false;
    is_primes[1] = false;
    for (int i = 2; i < is_primes.size(); i++)
    {
        if (!is_primes[i])
        {
            continue;
        }

        for (int j = 2 * i; j < is_primes.size(); j += i)
        {
            is_primes[j] = false;
        }
    }
}

template <class T>
bool overflow_if_mul(T a, T b)
{
    return (std::numeric_limits<T>::max() / a) < b;
}

bool ok(int i, int j, int k, int N)
{
    int mul = 1;
    vector<int> muls = {
        k, k, j, i, i};
    bool is_overflow = false;
    for (int x : muls)
    {
        if (overflow_if_mul(mul, x))
        {
            is_overflow = true;
            break;
        }
        mul *= x;
        if (mul > N)
        {
            break;
        }
    }

    return (!is_overflow && mul <= N);
}

signed main()
{
    int N;
    cin >> N;
    vector<bool> is_primes;
    set_is_primes(is_primes);

    vector<int> primes;
    for (int i = 0; i < is_primes.size(); i++)
    {
        if (is_primes[i])
        {
            primes.push_back(i);
            // cout << i << " ";
        }
    }

    int ans = 0;
    for (int i = 0; ok(primes[i], primes[i], primes[i], N); i++)
    {
        for (int j = i + 1; ok(primes[i], primes[j], primes[j], N); j++)
        {
            for (int k = j + 1; ok(primes[i], primes[j], primes[k], N); k++)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}