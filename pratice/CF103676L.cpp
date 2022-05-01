#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e5 + 10;

ll n, q, a[MAXN], bits[2][30 + 5];

int main()
{
    scanf("%lld%lld", &n, &q);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 0; i < 35; i++)
        bits[1][i] = 1;
    char op[5];
    while (q--)
    {
        ll in;
        scanf("%s%lld", op, &in);
        for (ll i = 0; i <= 30; i++)
        {
            if (op[0] == 'A')
            {
                bits[0][i] &= ((in >> i) & 1LL);
                bits[1][i] &= ((in >> i) & 1LL);
            }
            else if (op[0] == 'O')
            {
                bits[0][i] |= ((in >> i) & 1LL);
                bits[1][i] |= ((in >> i) & 1LL);
            }
            else
            {
                bits[0][i] ^= ((in >> i) & 1LL);
                bits[1][i] ^= ((in >> i) & 1LL);
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        ll ans = 0;
        for (ll j = 0; j <= 30; j++)
        {
            ll tmp = (a[i] >> j) & 1LL;
            if (tmp == 1LL)
                ans |= (bits[1][j] << j);
            else
                ans |= (bits[0][j] << j);
        }
        printf("%lld ", ans);
    }
    printf("\n");
    return 0;
}