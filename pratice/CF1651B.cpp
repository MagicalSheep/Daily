#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n > 19)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1, j = 1; i <= n; i++, j *= 3)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}