#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 6e5 + 5;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll b = 114514;

ll b1[MAXN], b2[MAXN];

void init()
{
    b1[1] = b2[1] = b;
    for (ll i = 2; i < MAXN; i++)
    {
        b1[i] = (b1[i - 1] * b) % MOD1;
        b2[i] = (b2[i - 1] * b) % MOD2;
    }
}

struct SHASH
{
    ll f1[MAXN], f2[MAXN], slen;

    void init(ll *s, ll len)
    {
        slen = len;
        f1[1] = f2[1] = s[1];
        for (ll i = 2; i <= slen; i++)
        {
            f1[i] = ((f1[i - 1] * b) % MOD1 + s[i]) % MOD1;
            f2[i] = ((f2[i - 1] * b) % MOD2 + s[i]) % MOD2;
        }
        return;
    }

    ll hash1(ll l, ll r)
    {
        return ((f1[r] - (f1[l - 1] * b1[r - l + 1]) % MOD1 + MOD1) % MOD1);
    }

    ll hash2(ll l, ll r)
    {
        return ((f2[r] - (f2[l - 1] * b2[r - l + 1]) % MOD2 + MOD2) % MOD2);
    }
};

int t, n, p[MAXN];
ll f[MAXN][2], pos[MAXN][2], q[MAXN], s[MAXN];
SHASH shq, shs;

ll solve()
{
    for (int i = 1; i <= n; i++)
        if (!pos[i][0] || !pos[i][1])
            return 0;
    for (int i = 0; i < 2; i++)
    {
        ll x = pos[p[1]][i];
        if (x == 1 || ((shq.hash1(1, x - 1) == shs.hash1(1, x - 1)) &&
                       (shq.hash2(1, x - 1) == shs.hash2(1, x - 1))))
            f[1][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!f[i][j])
                continue;
            ll x = pos[p[i]][j];
            for (int k = 0; k < 2; k++)
            {
                ll y = pos[p[i + 1]][k];
                if (y <= x)
                    continue;
                if (x + 1 == y || ((shq.hash1(x - i + 1, y - i - 1) == shs.hash1(x + 1, y - 1)) &&
                                   (shq.hash2(x - i + 1, y - i - 1) == shs.hash2(x + 1, y - 1))))
                    f[i + 1][k] = (f[i + 1][k] + f[i][j]) % MOD2;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 2; i++)
    {
        if (f[n][i])
        {
            int x = pos[p[n]][i];
            if (x == 2 * n || ((shq.hash1(x - n + 1, n) == shs.hash1(x + 1, 2 * n)) &&
                               (shq.hash2(x - n + 1, n) == shs.hash2(x + 1, 2 * n))))
                ans = (ans + f[n][i]) % MOD2;
        }
    }
    return ans;
}

int main()
{
    // freopen("D:\\1012.in", "r", stdin);
    // freopen("D:\\1012(2).out", "w", stdout);
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &p[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &q[i]);
        for (int i = 1; i <= 2 * n; i++)
        {
            scanf("%lld", &s[i]);
            if (!pos[s[i]][0])
                pos[s[i]][0] = i;
            else
                pos[s[i]][1] = i;
        }
        shq.init(q, n), shs.init(s, 2 * n);
        printf("%lld\n", solve());
        for (int i = 1; i <= n; i++)
            pos[i][0] = pos[i][1] = f[i][0] = f[i][1] = 0;
    }
    return 0;
}