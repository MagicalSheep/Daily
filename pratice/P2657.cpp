#include <bits/stdc++.h>
typedef long long ll;
const int MAXN = 2e9 + 10;
using namespace std;

ll a, b, f[15][10];

void prework()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

ll solve(ll x)
{
    ll ans = 0, a[15] = {0}, index = 0;
    while (x)
    {
        a[++index] = x % 10;
        x /= 10;
    }
    for (int i = 1; i < index; i++)
        for (int j = 1; j <= 9; j++)
            ans += f[i][j];
    for (int i = 1; i < a[index]; i++)
        ans += f[index][i];
    for (int i = index - 1; i >= 1; i--)
    {
        for (int j = 0; j < a[i]; j++)
        {
            if (abs(j - a[i + 1]) >= 2)
                ans += f[i][j];
        }
        if (abs(a[i] - a[i + 1]) < 2)
            break;
    }
    return ans;
}

int main()
{
    cin >> a >> b;
    prework();
    cout << solve(b + 1) - solve(a) << endl;
    return 0;
}