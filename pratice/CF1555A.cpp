#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%I64d", &n);
        ll ans = 5 * n;
        if (ans % 2 == 0)
            ans /= 2;
        else
            ans = (ans + 5) / 2;
        if (ans < 15)
            printf("15\n");
        else if (ans > 15 && ans < 20)
            printf("20\n");
        else if (ans > 20 && ans < 25)
            printf("25\n");
        else
            printf("%I64d\n", ans);
    }
    return 0;
}