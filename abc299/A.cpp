#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool bar_found = false;
    bool treasure_found = false;
    for (char x : S)
    {
        if (x == '|')
        {
            if (bar_found)
            {
                break;
            }
            else
            {
                bar_found = true;
            }
        }

        if (x == '*')
        {
            if (bar_found)
            {
                treasure_found = true;
            }
        }
    }

    if (treasure_found)
    {
        cout << "in" << endl;
    }
    else
    {
        cout << "out" << endl;
    }
}