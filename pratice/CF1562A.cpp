#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, l, r;

int main()
{
    scanf("%I64d", &t);
    while (t--)
    {
        scanf("%I64d%I64d", &l, &r);
        if (l == r)
        {
            printf("0\n");
            continue;
        }
        ll x = (r & 1) ? ((r + 1) >> 1) : ((r + 2) >> 1);
        if (x < l)
            printf("%I64d\n", r % l);
        else
            printf("%I64d\n", r % x);
    }
    return 0;
}