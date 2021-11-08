#include <bits/stdc++.h>
typedef long long ll;
#define P 998244353
using namespace std;
const int MAXN = 2e5 + 10;

int N, M, vis[MAXN];
vector<int> G[MAXN];

ll fpow_mod(ll x, ll n, ll m)
{
    if (n == 0)
        return 1;
    x %= m;
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}

void dfs(int u, ll &vcnt, ll &ecnt)
{
    if (vis[u])
        return;
    vis[u] = 1;
    ++vcnt;
    for (auto v : G[u])
        ++ecnt, dfs(v, vcnt, ecnt);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    ll tmp = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            ll vcnt = 0, ecnt = 0;
            dfs(i, vcnt, ecnt);
            ecnt >>= 1;
            if (vcnt != ecnt)
            {
                printf("0\n");
                return 0;
            }
            ++tmp;
        }
    }
    printf("%lld\n", fpow_mod(2, tmp, P));
    return 0;
}