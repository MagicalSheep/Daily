#include <bits/stdc++.h>
typedef long long ll;
#define P 1000000007
using namespace std;
const int MAXN = 1e5 + 10;

int t;

ll fpow_mod(ll x, ll n, ll m)
{
    x %= m;
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        char str[MAXN];
        scanf("%d%s", &n, str);
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (str[0] != str[i])
                break;
            if (str[0] == str[i])
                ans++;
        }
        printf("%lld\n", fpow_mod(2, ans, P));
    }
    return 0;
}