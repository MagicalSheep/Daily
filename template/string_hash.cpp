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

    void init(char *s, ll len)
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

char s[MAXN];
SHASH sh;

int main()
{
    init();
    scanf("%s", s + 1);
    // start from one
    sh.init(s, strlen(s + 1));
    printf("%lld\n%lld\n", sh.hash1(1, 3), sh.hash1(4, 6));
    printf("%lld\n%lld\n", sh.hash2(1, 3), sh.hash2(4, 6));
    return 0;
}