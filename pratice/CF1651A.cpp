#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (1 << n) - 1 << endl;
    }
    return 0;
}