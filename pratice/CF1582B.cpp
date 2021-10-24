#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 60 + 10;

int t;
ll n, zero_num, one_num;

ll fpow(ll a, ll n)
{
    if (n == 0)
        return 1;
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

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        zero_num = one_num = 0;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            ll in;
            scanf("%lld", &in);
            if (in == 0)
                ++zero_num;
            else if (in == 1)
                ++one_num;
        }
        ll ans = fpow(2, zero_num) * one_num;
        printf("%lld\n", ans);
    }
    return 0;
}