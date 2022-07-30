#include <bits/stdc++.h>
#include <random>
typedef long long ll;
using namespace std;
#define MOD 998244353

ll tr[11][401][401], n, q, seed, lastans[2000000 + 5];

void add(int id, ll a, ll b, ll c)
{
    for (int i = a; i <= 400; i += ((i) & (-i)))
        for (int j = b; j <= 400; j += ((j) & (-j)))
            tr[id][i][j] = min(c, tr[id][i][j]);
}

bool check(int id, ll a, ll b, ll c)
{
    for (int i = a; i; i -= ((i) & (-i)))
        for (int j = b; j; j -= ((j) & (-j)))
            if (tr[id][i][j] <= c)
                return true;
    return false;
}

ll solve(ll a, ll b, ll c)
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
        if (check(i, a, b, c))
            ++ret;
    return ret;
}

int main()
{
    memset(tr, 0x3f, sizeof(tr));
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            ll a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            add(i, a, b, c);
        }
    }
    scanf("%lld", &seed);
    mt19937 rng(seed);
    uniform_int_distribution<> u(1, 400);
    ll p = 1, num = 0;
    for (int j = 1; j <= q; j++)
    {
        ll IQ = (u(rng) ^ lastans[j - 1]) % 400 + 1;
        ll EQ = (u(rng) ^ lastans[j - 1]) % 400 + 1;
        ll AQ = (u(rng) ^ lastans[j - 1]) % 400 + 1;
        lastans[j] = solve(IQ, EQ, AQ);
    }
    for (int j = q; j >= 1; j--)
    {
        num = (num + lastans[j] * p) % MOD;
        p = (p * seed) % MOD;
    }
    printf("%lld\n", num);
    return 0;
}