#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int cnt = m / 2;
        string x, y;
        for (int i = 1; i <= cnt; i++)
        {
            x.append((i & 1) ? "1 0 " : "0 1 ");
            y.append((i & 1) ? "0 1 " : "1 0 ");
        }
        cout << x << endl;
        for (int i = 1; i <= ((n - 2) / 2); i++)
            cout << ((i & 1) ? y : x) << endl
                 << ((i & 1) ? y : x) << endl;
        if (n % 4 == 0)
            cout << x << endl;
        else
            cout << y << endl;
    }
    return 0;
}