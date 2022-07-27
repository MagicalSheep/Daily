#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;

struct SHASH
{
    const ll MOD1 = 1e9 + 7;
    const ll MOD2 = 998244353;
    const ll b = 114514;

    ll b1[MAXN], b2[MAXN], f1[MAXN], f2[MAXN], slen;
    char *s;

    void init(char *str)
    {
        s = str;
        slen = strlen(s);
        b1[1] = b2[1] = b;
        for (ll i = 2; i < MAXN; i++)
        {
            b1[i] = (b1[i - 1] * b) % MOD1;
            b2[i] = (b2[i - 1] * b) % MOD2;
        }
        f1[1] = f2[1] = s[0];
        for (ll i = 2; i <= slen; i++)
        {
            f1[i] = ((f1[i - 1] * b) % MOD1 + s[i - 1]) % MOD1;
            f2[i] = ((f2[i - 1] * b) % MOD2 + s[i - 1]) % MOD2;
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

char s[MAXN];
SHASH sh;

int main()
{
    scanf("%s", s);
    sh.init(s);
    printf("%lld\n%lld\n", sh.hash1(1, 3), sh.hash1(4, 6));
    printf("%lld\n%lld\n", sh.hash2(1, 3), sh.hash2(4, 6));
    return 0;
}