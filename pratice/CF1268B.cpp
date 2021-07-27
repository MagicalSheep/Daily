#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, black, white, flag;

int main()
{
    scanf("%I64d", &n);
    for (int i = 1; i <= n; i++)
    {
        ll tmp = 0;
        scanf("%I64d", &tmp);
        black += (flag) ? tmp - tmp / 2 : tmp / 2;
        white += (flag) ? tmp / 2 : tmp - tmp / 2;
        flag = !flag;
    }
    printf("%I64d\n", min(black, white));
    return 0;
}