#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e3 + 10;
#define INF 0x3f3f3f3f

vector<int> gra[MAXN];
int mincost[MAXN], din[MAXN];
int dfn[MAXN], low[MAXN], dfncnt, sta[MAXN], tp, sc, insta[MAXN], belong[MAXN];

struct point
{
    ll x, y, r, c;
} Point[MAXN];

bool check(point a, point b)
{
    ll tmp = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return 1ll * a.r * a.r >= tmp;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfncnt;
    sta[++tp] = u;
    insta[u] = 1;
    int len = gra[u].size();
    for (int i = 0; i <= len - 1; i++)
    {
        int v = gra[u][i];
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
    if (dfn[u] == low[u])
    {
        ++sc;
        ll cost = INF;
        while (1)
        {
            int v = sta[tp--];
            insta[v] = 0;
            belong[v] = sc;
            cost = min(cost, Point[v].c);
            if (u == v)
                break;
        }
        mincost[sc] = cost;
    }
}

int T;

int main()
{
    scanf("%d", &T);
    for (int k = 1; k <= T; k++)
    {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%lld%lld%lld%lld", &Point[i].x, &Point[i].y, &Point[i].r, &Point[i].c);
        for (int i = 0; i <= MAXN - 1; i++)
            gra[i].clear();
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        memset(sta, 0, sizeof(sta));
        memset(insta, 0, sizeof(insta));
        memset(belong, 0, sizeof(belong));
        memset(mincost, 0, sizeof(mincost));
        memset(din, 0, sizeof(din));
        dfncnt = tp = sc = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i != j)
                    if (check(Point[i], Point[j]))
                        gra[i].push_back(j);
        for (int i = 1; i <= N; i++)
            if (!dfn[i])
                tarjan(i);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < gra[i].size(); j++)
            {
                int v = gra[i][j];
                if (belong[i] != belong[v])
                    din[belong[v]]++;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= sc; i++)
            if (din[i] == 0)
                ans += (ll)mincost[i];
        printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}