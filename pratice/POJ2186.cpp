#include <algorithm>
#include <cstdio>
typedef long long ll;
using namespace std;
const int MAXN = 5e4 + 10;

ll dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;
ll cnt, head[MAXN];
ll cd[MAXN], siz[MAXN];

struct edge
{
    ll to, next;
} Edge[MAXN];

void addEdge(ll u, ll v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(ll u)
{
    dfn[u] = low[u] = ++dfncnt;
    sta[++top] = u;
    insta[u] = 1;
    for (ll e = head[u]; e; e = Edge[e].next)
    {
        ll v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (insta[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++sc;
        while (1)
        {
            ll v = sta[top--];
            insta[v] = 0;
            belong[v] = sc;
            siz[sc]++;
            if (u == v)
                break;
        }
    }
}

ll N, M;

int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        ll A, B;
        scanf("%lld%lld", &A, &B);
        addEdge(A, B);
    }
    for (int i = 1; i <= N; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= N; i++)
    {
        for (ll e = head[i]; e; e = Edge[e].next)
        {
            ll v = Edge[e].to;
            if (belong[i] != belong[v])
                cd[belong[i]]++;
        }
    }
    ll ans = 0, flag = 0;
    for (int i = 1; i <= sc; i++)
        if (!cd[i])
            ans = siz[i], flag++;
    if (flag == 1)
        printf("%lld\n", ans);
    else
        printf("0\n");
    return 0;
}