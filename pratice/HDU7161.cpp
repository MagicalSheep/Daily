#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n;

pair<ll, ll> func(ll x)
{
    pair<ll, ll> ret = pair<ll, ll>(-1, -1);
    for (ll i = x / 31; i >= 0; i--)
    {
        if ((x - i * 31) % 7 == 0)
        {
            ret.first = i, ret.second = (x - i * 31) / 7;
            break;
        }
    }
    return ret;
}

ll solve()
{
    for (ll i = n / 365; i >= 0; i--)
    {
        auto c = func(n - i * 365);
        if (c.first == -1 || c.second == -1)
            continue;
        return c.first + c.second + i;
    }
    return -1;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", solve());
    }
    return 0;
}