#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int fa[MAXN];
int T;

struct edge
{
    int from, to, cost;
} Edge[MAXN];

bool cmp(const edge &a, const edge &b) { return a.cost < b.cost; }

int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void unionSet(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void solve()
{
    memset(fa, 0, sizeof(fa));
    memset(Edge, 0, sizeof(Edge));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> Edge[i].from >> Edge[i].to >> Edge[i].cost;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(Edge + 1, Edge + 1 + m, cmp);
    int ans = 0;
    int groupnum = n;
    for (int i = 1; i <= m; i++)
    {
        if (Edge[i].cost != Edge[i - 1].cost)
        {
            if (groupnum == k)
            {
                cout << ans << endl;
                return;
            }
        }
        if (find(Edge[i].from) == find(Edge[i].to))
            continue;
        groupnum--;
        unionSet(Edge[i].from, Edge[i].to);
        ans = Edge[i].cost;
    }
    cout << ((groupnum == k) ? ans : -1) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
        solve();
    return 0;
}