#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int t, n, m, a[MAXN][MAXN];

bool solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 3)
                return false;
    return true;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j + 1] = s[j] - '0';
        }
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}