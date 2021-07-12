#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, f[17][10][10];

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
    for (ll i = 0; i <= 9; i++)
        f[1][i][i] = 1;
    for (ll i = 2; i <= 16; i++)
    {
        for (ll j = 0; j <= 9; j++)
        {
            for (ll k = 0; k <= 9; k++)
                for (ll p = 0; p <= 9; p++)
                    f[i][j][p] += f[i - 1][k][p];
            f[i][j][j] += fpow(10, i - 1);
        }
    }
}

ll digit_num(ll k, ll *num)
{
    ll ret = 0;
    while (k)
    {
        num[++ret] = k % 10;
        k /= 10;
    }
    return ret;
}

ll work(ll k, ll p)
{
    ll ans = 0, nums[17] = {0};
    ll n = digit_num(k, nums);
    for (ll i = 1; i < n; i++)
        for (ll j = 1; j <= 9; j++)
            ans += f[i][j][p];
    for (ll i = 1; i < nums[n]; i++)
        ans += f[n][i][p];
    for (ll i = n - 1; i >= 1; i--)
    {
        for (ll j = 0; j < nums[i]; j++)
            ans += f[i][j][p];
        for (ll j = n; j > i; j--)
            if (nums[j] == p)
                ans += nums[i] * fpow(10, i - 1);
    }
    return ans;
}

int main()
{
    cin >> a >> b;
    prework();
    for (int i = 0; i <= 9; i++)
        cout << work(b + 1, i) - work(a, i) << " ";
    cout << endl;
    return 0;
}