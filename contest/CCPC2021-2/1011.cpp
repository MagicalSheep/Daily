// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 1e5 + 10;

// int T, n, a[MAXN];
// vector<int> ans[MAXN];
// int realans[MAXN];

// struct e
// {
//     int first, second;
// } edge[MAXN];

// int fa[MAXN];
// inline int Find(int x) { return (x == fa[x]) ? x : fa[x] = Find(fa[x]); }

// void dfs(int u, int c)
// {
//     realans[u] = c;
//     for (auto v : ans[u])
//         dfs(v, c + 1);
// }

// bool cmp(e x, e y) { return a[x.first] < a[y.first]; }

// int main()
// {
//     scanf("%d", &T);
//     while (T--)
//     {
//         scanf("%d", &n);
//         for (int i = 1; i < n; i++)
//             scanf("%d%d", &edge[i].first, &edge[i].second);
//         for (int i = 1; i <= n; i++)
//             scanf("%d", &a[i]), fa[i] = i;
//         if (n == 1)
//         {
//             printf("1\n");
//             continue;
//         }
//         for (int i = 1; i < n; i++)
//             if (a[edge[i].first] < a[edge[i].second])
//                 swap(edge[i].first, edge[i].second);
//         sort(edge + 1, edge + n, cmp);
//         for (int i = 1; i < n; i++)
//         {
//             int v = Find(edge[i].second);
//             ans[edge[i].first].emplace_back(v);
//             fa[v] = edge[i].first;
//         }
//         dfs(edge[n - 1].first, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             printf("%d\n", realans[i]);
//             ans[i].clear();
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int T, n, vis[MAXN], on_tree[MAXN];
int cnt, head[MAXN];
vector<int> ans[MAXN];
int realans[MAXN];

int fa[MAXN];
int Find(int x) { return (x == fa[x]) ? x : fa[x] = Find(fa[x]); }
void unionSet(int x, int y) { fa[Find(x)] = Find(y); }

struct node
{
    int idx, val;
} a[MAXN];

bool cmp(node x, node y) { return x.val < y.val; }

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int c)
{
    realans[u] = c;
    for (auto v : ans[u])
        dfs(v, c + 1);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        cnt = 0;
        memset(head, 0, sizeof(head));
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v), addEdge(v, u);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].val), a[i].idx = i, vis[i] = 0, fa[i] = i, on_tree[i] = 0;
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            int u = a[i].idx;
            if (vis[u])
                continue;
            vis[u] = 1;
            for (int e = head[u]; e; e = Edge[e].next)
            {
                int v = Edge[e].to;
                int lv = Find(v);
                if (vis[v] && !on_tree[lv])
                    ans[u].emplace_back(lv), on_tree[lv] = 1, unionSet(v, u);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (Find(i) == i)
            {
                dfs(i, 1);
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d\n", realans[i]), ans[i].clear(), realans[i] = 0;
    }
    return 0;
}