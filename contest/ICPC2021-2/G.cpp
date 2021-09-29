#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll n, t, a[MAXN], b[MAXN];
ll sum1, sum2, sum3, sum4, sum5;

int main()
{
    scanf("%lld%lld", &n, &t);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    if (t == 0)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        sum1 += a[i] * b[i];
        sum2 += (-a[i] * b[i] * b[i]);
        sum3 += a[i] * b[i] * b[i] * b[i];
        sum4 += (-a[i] * b[i] * b[i] * b[i] * b[i]);
        sum5 += a[i] * b[i] * b[i] * b[i] * b[i] * b[i];
    }
    if (t == 1)
    {
        printf("%lld\n", sum1);
    }
    else if (t == 2)
    {
        if (sum1 == 0)
        {
            if (sum2 % 2 == 0)
                printf("%lld\n", sum2 >> 1);
            else
                printf("%lld/2\n", sum2);
        }
        else
        {
            printf("infinity\n");
        }
    }
    else if (t == 3)
    {
        if (sum1 == 0 && sum2 == 0)
        {
            if (sum3 % 3 == 0)
                printf("%lld\n", sum3 / 3);
            else
                printf("%lld/3\n", sum3);
        }
        else
        {
            printf("infinity\n");
        }
    }
    else if (t == 4)
    {
        if (sum1 == 0 && sum2 == 0 && sum3 == 0)
        {
            if (sum4 % 4 == 0)
                printf("%lld\n", sum4 / 4);
            else
                printf("%lld/%lld\n", sum4 / __gcd(sum4, 4LL), 4LL / __gcd(sum4, 4LL));
        }
        else
        {
            printf("infinity\n");
        }
    }
    else if (t == 5)
    {
        if (sum1 == 0 && sum2 == 0 && sum3 == 0 && sum4 == 0)
        {
            if (sum5 % 5 == 0)
                printf("%lld\n", sum5 / 5);
            else
                printf("%lld/5\n", sum5);
        }
        else
        {
            printf("infinity\n");
        }
    }
    return 0;
}