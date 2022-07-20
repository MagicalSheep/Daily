#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;

ll t, n, a[MAXN];

bool solve()
{
    if (a[0] > 0)
        return true;
    ll x = 2;
    for (int i = 1; i <= n && x <= MAXN; i++)
    {
        if (a[i] >= x)
            return true;
        x = (x - a[i]) * 2;
    }
    return false;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 0; i <= n; i++)
            scanf("%lld", &a[i]);
        if (solve())
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}