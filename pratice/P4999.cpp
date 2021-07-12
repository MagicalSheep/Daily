#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll T, f[18 + 5][10][10];

ll fpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

void prework()
{
    for (int i = 0; i <= 9; i++)
        f[1][i][i] = 1;
    for (int i = 2; i <= 19; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int l = 0; l <= 9; l++)
                for (int k = 0; k <= 9; k++)
                    f[i][j][k] += f[i - 1][l][k];
            f[i][j][j] += fpow(10, i - 1);
        }
    }
}

ll solve(ll x, ll p)
{
    ll ret = 0, num[19 + 5] = {0}, len = 0;
    for (; x; x /= 10)
        num[++len] = x % 10;
    for (int i = 1; i < len; i++)
        for (int j = 1; j <= 9; j++)
            ret += f[i][j][p];
    for (int i = 1; i < num[len]; i++)
        ret += f[len][i][p];
    for (int i = len - 1; i >= 1; i--)
    {
        for (int j = 0; j < num[i]; j++)
            ret += f[i][j][p];
        for (int j = len; j > i; j--)
            if (num[j] == p)
                ret += num[i] * fpow(10, i - 1); // TODO
    }
    return ret;
}

int main()
{
    prework();
    cin >> T;
    while (T--)
    {
        ll L = 0, R = 0;
        cin >> L >> R;
        ll tot[10] = {0};
        for (int i = 1; i <= 9; i++)
            tot[i] = (solve(R + 1, i) % MOD - solve(L, i) + MOD) % MOD; // TODO
        ll ans = 0;
        for (int i = 1; i <= 9; i++)
            ans = ((ans + i * tot[i] + MOD) % MOD + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}