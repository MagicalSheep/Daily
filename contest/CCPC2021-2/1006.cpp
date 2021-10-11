#include <bits/stdc++.h>
#define P 998244353
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int T;
ll f[10], cnt[MAXN];
char S[MAXN];

ll fpow_mod(ll a, ll b, ll c)
{
    a %= c;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ll ans = 0;
        scanf("%s", S + 1);
        int len = strlen(S + 1);
        for (int i = 0; i <= 9; i++)
            f[i] = 0;
        cnt[len + 1] = 0;
        for (int i = len; i >= 1; i--)
            cnt[i] = cnt[i + 1] + ((S[i] == 'a') ? 1 : 0);
        f[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            if (S[i] == 'n')
            {
                f[3] = (f[3] + f[2]) % P;
                f[1] = (f[1] + f[0]) % P;
            }
            else if (S[i] == 'u')
            {
                f[2] = (f[2] + f[1]) % P;
            }
            else if (S[i] == 'e')
            {
                f[8] = (f[8] + f[7]) % P;
                f[5] = (f[5] + f[4]) % P;
            }
            else if (S[i] == 'h')
            {
                f[9] = (f[9] + f[8]) % P;
                f[7] = (f[7] + f[6]) % P;
                f[6] = (f[6] + f[5]) % P;
                f[4] = (f[4] + f[3]) % P;
                ans = (ans + f[8] * (fpow_mod(2, cnt[i], P) - 1 + P) % P) % P;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}