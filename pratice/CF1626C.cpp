#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 100 + 10;

ll t, n, f[MAXN];
struct monster
{
    ll k, h;
} mms[MAXN];

int main()
{
    scanf("%lld", &t);
    int cnt = 0;
    while (t--)
    {
        ++cnt;
        memset(mms, 0, sizeof(mms));
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &mms[i].k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &mms[i].h), f[i] = mms[i].h;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (mms[j].k - mms[i].k >= mms[j].h)
                    continue;
                f[j] = max(f[j], f[i] + mms[j].k - mms[i].k);
            }
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (mms[i].k - mms[j].k >= f[i])
                    break;
                f[j] = max(f[j], f[i] - mms[i].k + mms[j].k);
            }
        }
        ll ans = 0, nex = 0x3f3f3f3f;
        for (int i = n; i >= 1; i--)
        {
            if (mms[i].k > nex)
                continue;
            nex = mms[i].k - f[i];
            ans += ((f[i] + 1) * f[i] / 2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}