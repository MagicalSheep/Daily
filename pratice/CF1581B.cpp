#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n, m, k;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        if ((n == 1 && m == 0 && k > 1) ||
            (m == n - 1 && k > 3) ||
            (m > n - 1 && m < n * (n - 1) / 2 && k > 3) ||
            (m == n * (n - 1) / 2 && k > 2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}