#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e7 + 10;

ll t;
ll is_prime[MAXN], prime[MAXN];

ll Eratosthenes(ll n)
{
    ll p = 0;
    for (ll i = 0; i <= n; ++i)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[p++] = i;
            if (i * i <= n)
                for (ll j = i * i; j <= n; j += i)
                    is_prime[j] = 0;
        }
    }
    return p;
}

int main()
{
    int a = 2 ^ 56 ^ 4 ^ 5;
    int b = (2 ^ 56) ^ (4 ^ 5);
    cout << a << " " << b << endl;
    Eratosthenes(10000002);
    scanf("%lld", &t);
    while (t--)
    {
        ll n, ans = 0;
        scanf("%lld", &n);
        for (ll i = 3; i <= n; i++)
        {
            if (i % 2 == 0)
                ans += i;
            else if (is_prime[i])
                ans += 2 * i;
            else
                ans += i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
