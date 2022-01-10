#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;
ll a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        ll d = a + c - 2 * b;
        ll e = 0;
        if (d > 0)
            e = d % 3 - 3;
        else if (d < 0)
            e = d % 3 + 3;
        else
            e = 0;
        printf("%lld\n", min(abs(d % 3), abs(e % 3)));
    }
    return 0;
}