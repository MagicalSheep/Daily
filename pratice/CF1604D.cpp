#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, x, y;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &x, &y);
        if (x == y)
        {
            printf("%lld\n", x);
        }
        else if (x > y)
        {
            printf("%lld\n", x + y);
        }
        else
        {
            ll tmp = (y / x) * x;
            printf("%lld\n", (y + tmp) / 2);
        }
    }
    return 0;
}